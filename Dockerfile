FROM ubuntu:20.04

ADD sources.list /etc/apt/
#install common dependencies
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
    DEBIAN_FRONTEND=noninteractive apt-get -y upgrade && \
    DEBIAN_FRONTEND=noninteractive apt-get -y install \
    build-essential \
    cmake \
    automake \
    autoconf \
    libtool \
    wget

# set workdir
WORKDIR /home/experiments
ENV WORKDIR="/home/experiments"


# Download and install cryptopp
RUN wget https://github.com/weidai11/cryptopp/archive/CRYPTOPP_5_6_5.tar.gz  \
    && cd ${WORKDIR} \
    && tar -xzf CRYPTOPP_5_6_5.tar.gz \
    && mv cryptopp-CRYPTOPP_5_6_5 cryptopp \
    && cd cryptopp && make
# copy the file into docker
COPY tls-server-batch ${WORKDIR}/tls-server-batch
COPY tls-diff-testing ${WORKDIR}/tls-diff-testing
#
## Setup TLS implementations (servers).
## Download and build OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL
#RUN cd ${WORKDIR}/tls-server-batch
#CMD ["setup.sh"]