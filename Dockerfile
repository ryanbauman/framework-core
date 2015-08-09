FROM redhawkci/ubuntu-buildenv:14.04

RUN ./build_src.sh && cd src && make install

CMD ["/bin/bash", "-l"]
