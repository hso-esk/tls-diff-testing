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
    wget \
    git

# set workdir
WORKDIR /home/experiments
ENV WORKDIR="/home/experiments"


# Download and install cryptopp
RUN wget https://github.com/weidai11/cryptopp/archive/CRYPTOPP_5_6_5.tar.gz  \
    && cd ${WORKDIR} \
    && tar -xzf CRYPTOPP_5_6_5.tar.gz \
    && mv cryptopp-CRYPTOPP_5_6_5 cryptopp \
    && cd cryptopp && make
# copy the files into docker
COPY tls-server-batch ${WORKDIR}/tls-server-batch
COPY tls-diff-testing ${WORKDIR}/tls-diff-testing
COPY main.sh ${WORKDIR}/main.sh

# Setup TLS implementations (servers).
# Download and build OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL
# Generate test input (TLS ClientHello messages)
RUN chmod +x main.sh \
    && cd ${WORKDIR}/tls-server-batch \
    && chmod +x *.sh \
    && cd ${WORKDIR}/tls-diff-testing/generator/macros \
    && chmod +x *.sh
# install pip & matplotlib
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
    DEBIAN_FRONTEND=noninteractive apt-get -y install \
    python3-pip \
    && pip install matplotlib

CMD ["bash","-c","${WORKDIR}/main.sh"]