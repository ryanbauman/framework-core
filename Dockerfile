FROM redhawkci/ubuntu-buildenv:14.04

RUN ./build_src.sh && cd src && make install

ONBUILD RUN apt-get update -qq && \
            apt-get upgrade -y && \
            apt-get clean && \
            rm -rf /var/lib/apt/lists/*

ONBUILD COPY . /build
ONBUILD WORKDIR /build
ONBUILD VOLUME /build
