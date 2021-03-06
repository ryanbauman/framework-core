#
# This file is protected by Copyright. Please refer to the COPYRIGHT file
# distributed with this source distribution.
#
# This file is part of REDHAWK core.
#
# REDHAWK core is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see http://www.gnu.org/licenses/.
#

import unittest
from _unitTestHelpers import scatest
from omniORB import any as _any
from ossie.cf import CF
from ossie.cf import ExtendedCF
from ossie import properties

class ConnectionManagerTest(scatest.CorbaTestCase):
    def setUp(self):
        super(ConnectionManagerTest,self).setUp()
        nb, self._domMgr = self.launchDomainManager()
        nb, self._devMgr = self.launchDeviceManager('/nodes/test_PortTestDevice_node/DeviceManager.dcd.xml')
        self._connMgr = self._domMgr._get_connectionMgr()

        # Device IDs taken from the DCD
        self.devId1 = 'DCE:322fb9b2-de57-42a2-ad03-217bcb244262'
        self.devId2 = 'DCE:47dc45d8-19b5-4b7e-bcd4-b165babe5b84'

    def _createApp(self, sadPath):
        self.assertNotEqual(self._domMgr, None)
        self.assertNotEqual(len(self._domMgr._get_deviceManagers()), 0)
        self._domMgr.installApplication(sadPath)
        self.assertEqual(len(self._domMgr._get_applicationFactories()), 1)
        appFact = self._domMgr._get_applicationFactories()[0]

        try:
            return appFact.create(appFact._get_name(), [], [])
        except:
            self.fail("Did not create application " + sadPath)

    def _findConnection(self, connectionId):
        for connection in self._connMgr._get_connections():
            if connection.connectionId == connectionId:
                return connection
        return None

    def test_DeviceConnections(self):
        # The DCD has one connection, verify that it is listed
        connections = self._connMgr._get_connections()
        self.assertEqual(len(connections), 1)

        # Use the first device's resource_out port as the uses endpoint
        uses = CF.ConnectionManager.EndpointResolutionType(deviceId=self.devId2)
        uses = CF.ConnectionManager.EndpointRequest(uses, 'resource_out')

        # Use the device itself as the provides endpoint
        provides = CF.ConnectionManager.EndpointResolutionType(deviceId=self.devId1)
        provides = CF.ConnectionManager.EndpointRequest(provides, '')

        # Create a new connection with a known ID
        self._connMgr.connect(uses, provides, 'test_connection')

        # Make sure the new connection is listed
        self.assertEqual(len(self._connMgr._get_connections()), 2)
        connection = self._findConnection('test_connection')
        self.assertFalse(connection is None)

        # The connection should have been resolved immediately
        self.assertTrue(connection.connected)
        self.assertEqual(connection.usesEndpoint.portName, 'resource_out')
        self.assertEqual(connection.providesEndpoint.portName, '')

        # Verify that the connection was really made
        connections = connection.usesEndpoint.endpointObject._get_connections()
        self.assertTrue(len(connections) == 1)
        self.assertEqual(connections[0].connectionId, 'test_connection')
        self.assertEqual(connections[0].port._get_identifier(), self.devId1)

        # Break the connection and make sure the connection went away
        self._connMgr.disconnect('test_connection')
        connections = self._connMgr._get_connections()
        self.assertEqual(len(self._connMgr._get_connections()), 1)

    def test_ApplicationConnections(self):
        app = self._createApp('/waveforms/PortConnectExternalPortRename/PortConnectExternalPortRename.sad.xml')
        
        # Connect the application's external uses port to the first device's
        # provides port
        uses = CF.ConnectionManager.EndpointResolutionType(waveformId=app._get_identifier())
        uses = CF.ConnectionManager.EndpointRequest(uses, 'rename_resource_out')
        provides = CF.ConnectionManager.EndpointResolutionType(deviceId=self.devId1)
        provides = CF.ConnectionManager.EndpointRequest(provides, 'resource_in')
        self._connMgr.connect(uses, provides, 'test_connection')

        # Make sure the new connection is listed
        self.assertEqual(len(self._connMgr._get_connections()), 2)
        connection = self._findConnection('test_connection')
        self.assertFalse(connection is None)

        # The connection should have been resolved immediately
        self.assertTrue(connection.connected)
        self.assertEqual(connection.usesEndpoint.portName, 'rename_resource_out')
        self.assertEqual(connection.providesEndpoint.portName, 'resource_in')

        # Verify that the connection was really made
        connections = connection.usesEndpoint.endpointObject._get_connections()
        self.assertTrue(len(connections) == 1)
        self.assertEqual(connections[0].connectionId, 'test_connection')
        self.assertEqual(connections[0].port._get_identifier(), self.devId1+'/resource_in')

        # Break the connection and make sure the connection went away
        self._connMgr.disconnect('test_connection')
        connections = self._connMgr._get_connections()
        self.assertEqual(len(self._connMgr._get_connections()), 1)

        app.releaseObject()

    def test_DeferredConnections(self):
        app = self._createApp('/waveforms/PortConnectExternalPortRename/PortConnectExternalPortRename.sad.xml')

        # Try to connect the application's external uses port to a device that
        # has not started yet
        devId = 'DCE:8f3478e3-626e-45c3-bd01-0a8117dbe59b'
        uses = CF.ConnectionManager.EndpointResolutionType(waveformId=app._get_identifier())
        uses = CF.ConnectionManager.EndpointRequest(uses, 'rename_resource_out')
        provides = CF.ConnectionManager.EndpointResolutionType(deviceId=devId)
        provides = CF.ConnectionManager.EndpointRequest(provides, '')
        self._connMgr.connect(uses, provides, 'test_connection')

        # Make sure the new connection is listed
        self.assertEqual(len(self._connMgr._get_connections()), 2)
        connection = self._findConnection('test_connection')
        self.assertFalse(connection is None)

        # The provides side should not have been resolved yet
        self.assertFalse(connection.connected)
        self.assertEqual(connection.usesEndpoint.portName, 'rename_resource_out')
        self.assertEqual(connection.providesEndpoint.endpointObject, None)

        # Launch the second node, which should cause the connection to be
        # resolved now
        nb, devMgr2 = self.launchDeviceManager('/nodes/test_BasicTestDevice_node/DeviceManager.dcd.xml')

        # Verify that the connection was really made
        connection = self._findConnection('test_connection')
        self.assertFalse(connection is None)
        self.assertTrue(connection.connected)
        connections = connection.usesEndpoint.endpointObject._get_connections()
        self.assertTrue(len(connections) == 1)
        self.assertEqual(connections[0].connectionId, 'test_connection')
        self.assertEqual(connections[0].port._get_identifier(), devId)

        # Release the application and check that the connection is broken
        app.releaseObject()
        connection = self._findConnection('test_connection')
        self.assertFalse(connection is None)
        self.assertFalse(connection.connected)
