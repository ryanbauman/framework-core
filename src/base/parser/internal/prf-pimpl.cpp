// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//
#include<iterator>
#include "prf-pimpl.h"
#include "ossie/debug.h"

// Unit_pimpl
//

using namespace prf;

CREATE_LOGGER(prf_parser)

void Unit_pimpl::
pre ()
{
}

std::string Unit_pimpl::
post_Unit ()
{
  const ::std::string& v (post_string ());

  return v;
}

// AccessType_pimpl
//

void AccessType_pimpl::
pre ()
{
}

::std::string AccessType_pimpl::
post_AccessType ()
{
  const ::std::string& v (post_string ());
  return v;
}

// action_pimpl
//

void action_pimpl::
pre ()
{
}

void action_pimpl::
type (const ::std::string& type)
{
    _type = type;
}

::std::string action_pimpl::
post_action ()
{
  return _type;
}

// ActionType_pimpl
//

void ActionType_pimpl::
pre ()
{
}

std::string ActionType_pimpl::
post_ActionType ()
{
  const ::std::string& v (post_string ());
  return v;
}

// configurationKind_pimpl
//

void configurationKind_pimpl::
pre ()
{
    _kindtype = "configure";
}

void configurationKind_pimpl::
kindtype (const ::std::string& kindtype)
{
    _kindtype = kindtype;
}

std::string configurationKind_pimpl::
post_configurationKind ()
{
    return _kindtype;
}

// enumeration_pimpl
//

void enumeration_pimpl::
pre ()
{
}

void enumeration_pimpl::
label (const ::std::string& label)
{
  // TODO
  //
}

void enumeration_pimpl::
value (const ::std::string& value)
{
  // TODO
  //
}

::std::map<std::string, std::string>::value_type enumeration_pimpl::
post_enumeration ()
{
    return std::map<std::string, std::string>::value_type("", "");
}

// enumerations_pimpl
//

void enumerations_pimpl::
pre ()
{
}

void enumerations_pimpl::
enumeration (const ::std::map<std::string, std::string>::value_type& enumeration)
{
  // TODO
  //
}

::std::map<std::string, std::string> enumerations_pimpl::
post_enumerations ()
{
    return std::map<std::string, std::string>();
}

// inputValue_pimpl
//

void inputValue_pimpl::
pre ()
{
}

void inputValue_pimpl::
simple (const ossie::Property* simple)
{
  // TODO
  //
}

void inputValue_pimpl::
post_inputValue ()
{
}

// kind_pimpl
//

void kind_pimpl::
pre ()
{
    _type = "configure"; // The default is configure
}

void kind_pimpl::
kindtype (const ::std::string& type)
{
    _type = type;
}

std::string kind_pimpl::
post_kind ()
{
    return _type;
}

// PropertyConfigurationType_pimpl
//

void PropertyConfigurationType_pimpl::
pre ()
{
}

std::string PropertyConfigurationType_pimpl::
post_PropertyConfigurationType ()
{
  const ::std::string& v (post_string ());
  return v;
}

// StructPropertyConfigurationType_pimpl
//

void StructPropertyConfigurationType_pimpl::
pre ()
{
}

::std::string StructPropertyConfigurationType_pimpl::
post_StructPropertyConfigurationType ()
{
  return post_PropertyConfigurationType ();
}

// properties_pimpl
//

void properties_pimpl::
pre ()
{
    this->_prf.reset(new ossie::PRF());
}

void properties_pimpl::
description (const ::std::string& description)
{
  // TODO
  //
}

void properties_pimpl::
simple (ossie::SimpleProperty* simple)
{
    LOG_TRACE(prf_parser, "Adding simple property")
    assert(_prf.get() != 0);
    assert(simple != 0);
    _prf->addProperty(simple);
}

void properties_pimpl::
simplesequence (ossie::SimpleSequenceProperty* simplesequence)
{
    LOG_TRACE(prf_parser, "Adding simple sequence property " << simplesequence->getID())
    assert(_prf.get() != 0);
    _prf->addProperty(simplesequence);
}

void properties_pimpl::
test ()
{
}

void properties_pimpl::
struct_ (ossie::StructProperty* struct_)
{
    LOG_TRACE(prf_parser, "Adding struct property " << struct_->getID())
    assert(_prf.get() != 0);
    _prf->addProperty(struct_);
}

void properties_pimpl::
structsequence (ossie::StructSequenceProperty* structsequence)
{
    LOG_TRACE(prf_parser, "Adding struct sequence property " << structsequence->getID())
    assert(_prf.get() != 0);
    _prf->addProperty(structsequence);
}

std::auto_ptr<ossie::PRF> properties_pimpl::
post_properties ()
{
    LOG_TRACE(prf_parser, "properties post")
    return _prf;
}

// PropertyValueType_pimpl
//

void PropertyValueType_pimpl::
pre ()
{
}

std::string PropertyValueType_pimpl::
post_PropertyValueType ()
{
  const ::std::string& v (post_string ());

  return v;
}

// range_pimpl
//

void range_pimpl::
pre ()
{
}

void range_pimpl::
max (const ::std::string& max)
{
    range.second = max;
}

void range_pimpl::
min (const ::std::string& min)
{
    range.first = min;
}

::std::pair<std::string, std::string> range_pimpl::
post_range ()
{
    return range;
}

// resultValue_pimpl
//

void resultValue_pimpl::
pre ()
{
}

void resultValue_pimpl::
simple (const ossie::Property* simple)
{
  // TODO
  //
}

void resultValue_pimpl::
post_resultValue ()
{
}

// simple_pimpl
//

void simple_pimpl::
pre ()
{
    _id = "";
    _name = "";
    _type = "";
    _mode = "";
    _action = "";
    _kinds.clear();
    _value.reset();
}

void simple_pimpl::
description (const ::std::string& description)
{
}

void simple_pimpl::
value (const ::std::string& value)
{
    LOG_TRACE(prf_parser, "simple_pimpl value " << value)
    _value = std::auto_ptr<std::string>(new std::string(value));
}

void simple_pimpl::
units ()
{
}

void simple_pimpl::
range (const ::std::vector<std::string>& range)
{
  // TODO
  //
}

void simple_pimpl::
enumerations (const ::std::map<std::string, std::string>& enumerations)
{
  // TODO
  //
}

void simple_pimpl::
kind (const ::std::string& kind)
{
    LOG_TRACE(prf_parser, "simple_pimpl kind " << kind)
    _kinds.push_back(kind);
}

void simple_pimpl::
action (const ::std::string& action)
{
    LOG_TRACE(prf_parser, "simple_pimpl action " << action)
    _action = action;
}

void simple_pimpl::
id (const ::std::string& id)
{
    LOG_TRACE(prf_parser, "simple_pimpl id " << id)
    _id = id;
}

void simple_pimpl::
mode (const ::std::string& mode)
{
    LOG_TRACE(prf_parser, "simple_pimpl mode " << mode)
    _mode = mode;
}

void simple_pimpl::
name (const ::std::string& name)
{
    LOG_TRACE(prf_parser, "simple_pimpl name " << name)
    _name = name;
}

void simple_pimpl::
type (const ::std::string& type)
{
    LOG_TRACE(prf_parser, "simple_pimpl type " << type)
    _type = type;
}

ossie::SimpleProperty* simple_pimpl::
post_simple ()
{
  if (_value.get()  != 0) {
      LOG_TRACE(prf_parser, "simple_pimpl post " << _id << " " << _name << " " << _value->c_str())
      return new ossie::SimpleProperty(_id, _name, _type, _mode, _action, _kinds, _value.get());
  } else {
      LOG_TRACE(prf_parser, "simple_pimpl post " << _id << " " << _name << " None")
      return new ossie::SimpleProperty(_id, _name, _type, _mode, _action, _kinds, 0);
  }
}

// simpleRef_pimpl
//

void simpleRef_pimpl::
pre ()
{
    _refid = "";
    _value = "";
}

void simpleRef_pimpl::
refid (const ::std::string& refid)
{
    _refid = refid;
}

void simpleRef_pimpl::
value (const ::std::string& value)
{
    _value = value;
}

::std::map<std::string, std::string>::value_type simpleRef_pimpl::
post_simpleRef ()
{
    return ::std::map<std::string, std::string>::value_type(_refid, _value);
}

// simpleSequence_pimpl
//

void simpleSequence_pimpl::
pre ()
{
    _id = "";
    _name = "";
    _type = "";
    _mode = "";
    _action = "";
    _kinds.clear();
    _values.clear();
}

void simpleSequence_pimpl::
description (const ::std::string& description)
{
  // TODO
  //
}

void simpleSequence_pimpl::
values (const ::std::vector<std::string>& values)
{
    _values.clear();
    std::copy(values.begin(), values.end(), std::back_inserter(_values));
}

void simpleSequence_pimpl::
units ()
{
}

void simpleSequence_pimpl::
range (const ::std::vector<std::string>& range)
{
  // TODO
  //
}

void simpleSequence_pimpl::
kind (const ::std::string& kind)
{
    _kinds.push_back(kind);
}

void simpleSequence_pimpl::
action (const ::std::string& action)
{
    _action = action;
}

void simpleSequence_pimpl::
id (const ::std::string& id)
{
    _id = id;
}

void simpleSequence_pimpl::
mode (const ::std::string& mode)
{
    _mode = mode;
}

void simpleSequence_pimpl::
name (const ::std::string& name)
{
    _name = name;
}

void simpleSequence_pimpl::
type (const ::std::string& type)
{
    _type = type;
}

ossie::SimpleSequenceProperty* simpleSequence_pimpl::
post_simpleSequence ()
{
    return new ossie::SimpleSequenceProperty(_id, _name, _type, _mode, _action, _kinds, _values);
}

// struct_pimpl
//

void struct_pimpl::
pre ()
{
    _id = "";
    _name = "";
    _type = "";
    _mode = "";
    _kinds.clear();
    _value.clear();
}

void struct_pimpl::
description (const ::std::string& desciption)
{
}

void struct_pimpl::
simple (ossie::SimpleProperty* property)
{
    _value.push_back(*property);
    delete property;
}

void struct_pimpl::
configurationkind (const ::std::string& kind)
{
    _kinds.push_back(kind);
}

void struct_pimpl::
id (const ::std::string& id)
{
    _id = id;
}

void struct_pimpl::
mode (const ::std::string& mode)
{
    _mode = mode;
}

void struct_pimpl::
name (const ::std::string& name)
{
    _name = name;
}

ossie::StructProperty* struct_pimpl::
post_struct ()
{
    LOG_TRACE(prf_parser, "struct_pimpl post " << _id << " " << _name);
    for (std::vector<std::string>::const_iterator ii = _kinds.begin(); ii != _kinds.end(); ++ii) {
        LOG_TRACE(prf_parser, "    kind " << *ii);
    }
    std::vector<ossie::SimpleProperty>::iterator i;
    for ( i = _value.begin(); i != _value.end(); ++i) {
        LOG_TRACE(prf_parser, "    value " << *i)
    }
    return new ossie::StructProperty(_id, _name, _mode, _kinds, _value);
}

// structSequence_pimpl
//

void structSequence_pimpl::
pre ()
{
    _id = "";
    _name = "";
    _type = "";
    _mode = "";
    _kinds.clear();
    _struct.reset(0);
    _values.clear();
}

void structSequence_pimpl::
description (const ::std::string& description)
{
  // TODO
  //
}

void structSequence_pimpl::
struct_ (ossie::StructProperty* structProp)
{
    _struct.reset(structProp);
}

void structSequence_pimpl::
structvalue (const std::map<std::string, std::string>& value)
{
    std::vector<ossie::SimpleProperty> propValue;
    const std::vector<ossie::SimpleProperty>& defaults = _struct->getValue();
    for (std::vector<ossie::SimpleProperty>::const_iterator prop = defaults.begin(); prop != defaults.end(); ++prop) {
        const std::string id = prop->getID();
        std::map<std::string, std::string>::const_iterator ii = value.find(id);
        if (ii != value.end()) {
            propValue.push_back(ossie::SimpleProperty(id, prop->getName(), prop->getType(), prop->getMode(), prop->getAction(), prop->getKinds(), ii->second));
        } else {
            propValue.push_back(*prop);
        }
    }
    _values.push_back(ossie::StructProperty(_struct->getID(), _struct->getName(), _struct->getMode(), _struct->getKinds(), propValue));
}

void structSequence_pimpl::
configurationkind (const ::std::string& kind)
{
    _kinds.push_back(kind);
}

void structSequence_pimpl::
id (const ::std::string& id)
{
    _id = id;
}

void structSequence_pimpl::
mode (const ::std::string& mode)
{
    _mode = mode;
}

void structSequence_pimpl::
name (const ::std::string& name)
{
    _name = name;
}

ossie::StructSequenceProperty* structSequence_pimpl::
post_structSequence ()
{
    return new ossie::StructSequenceProperty(_id, _name, _mode, *_struct, _kinds, _values);
}

// structValue_pimpl
//

void structValue_pimpl::
pre ()
{
    _values.clear();
}

void structValue_pimpl::simpleref (const ::std::map<std::string, std::string>::value_type& value)
{
    _values.insert(value);
}

::std::map<std::string, std::string> structValue_pimpl::
post_structValue ()
{
    return _values;
}

// test_pimpl
//

void test_pimpl::
pre ()
{
}

void test_pimpl::
description (const ::std::string& description)
{
  // TODO
  //
}

void test_pimpl::
inputvalue ()
{
}

void test_pimpl::
resultvalue ()
{
}

void test_pimpl::
id (const ::std::string& id)
{
  // TODO
  //
}

void test_pimpl::
post_test ()
{
}

// values_pimpl
//

void values_pimpl::
pre ()
{
    values.clear();
}

void values_pimpl::
value (const ::std::string& value)
{
    values.push_back(value);
}

::std::vector<std::string> values_pimpl::
post_values ()
{
  return values;
}