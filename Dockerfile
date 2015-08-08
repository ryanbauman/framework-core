FROM ubuntu:14.04

RUN apt-get update -qq && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:redhawksdr/omnievents-2.7 && \
    apt-get install -y autoconf \
                       automake \
                       autotools-dev \
                       build-essential \
                       libboost-dev \
                       libboost-filesystem-dev \
                       libboost-regex-dev \
                       libboost-system-dev \
                       libboost-thread-dev \
                       libcos4-dev \
                       liblog4cxx10-dev \
                       libomnievents-dev \
                       libomniorb4-dev \
                       libtool \
                       libxml2-utils \
                       omnievents \
                       omniidl \
                       omniidl-python \
                       omniorb \
                       omniorb-idl \
                       openjdk-7-jdk \
                       python2.7-dev \
                       python-omniorb \
                       python-numpy \
                       uuid-dev \
                       xsdcxx && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY . /build
WORKDIR /build
VOLUME /build

RUN ./build_src.sh && make install

CMD ["/bin/bash", "-l"]
