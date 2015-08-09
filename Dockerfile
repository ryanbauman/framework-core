FROM redhawkci/ubuntu-buildenv:14.04

RUN ./build_src.sh && cd src && make install

ENV OSSIEHOME /usr/local/redhawk/core
ENV SDRROOT /var/redhawk/sdr
ENV PYTHONPATH /usr/local/redhawk/core/lib64/python:/usr/local/redhawk/core/lib/python
ENV PATH /usr/local/redhawk/core/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

ONBUILD RUN apt-get update -qq && \
            apt-get upgrade -y && \
            apt-get clean && \
            rm -rf /var/lib/apt/lists/*

ONBUILD COPY . /build
ONBUILD WORKDIR /build
ONBUILD VOLUME /build
