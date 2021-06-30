FROM ubuntu:20.04

#install common dependencies
RUN apt-get update && \
    apt-get -y install \
    apt-utils \
    build-essential \
    make \
    cmake \
    automake \
    autoconf \
    libtool \
    python3-pip \
    wget

# set workdir
WORKDIR /home/experiments

# Download and install cryptopp
RUN wget -p ${WORKDIR} https://github.com/weidai11/cryptopp/archive/CRYPTOPP_5_6_5.tar.gz  \
    && cd ${WORKDIR} \
    && tar -xzf CRYPTOPP_5_6_5.tar.gz \
    && mv cryptopp-CRYPTOPP_5_6_5 cryptopp \
    && cd cryptopp && make

COPY tls-server-batch ${WORKDIR}/tls-server-batch
COPY tls-diff-testing ${WORKDIR}/tls-diff-testing

# Setup TLS implementations (servers).
# Download and build OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL
RUN cd ${WORKDIR}/tls-server-batch
CMD ["setup.sh"]