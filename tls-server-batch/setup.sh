#!/bin/bash

# Require
# go -> BoringSSL
# cmake -> BoringSSL
# autoconf -> BoringSSL, WolfSSL
# automake -> WolfSSL
# libtool -> WolfSSL

#
# _____________________________________________________________________________
#
START_DIR=$(pwd)
IMPL_DIR_PREFIX=impl_


#
# _____________________________________________________________________________
#
function join_by {
    local IFS="$1"
    shift
    echo "$*"
}


#
# _____________________________________________________________________________
#
function clean() {

    shopt -s nullglob

    rm -f __launch_${IMPL_DIR_PREFIX}*.sh

    DIRS=(${IMPL_DIR_PREFIX}*/)

    echo "${DIRS[@]}"

    if [ ${#DIRS[@]} -ne 0 ]; then
        while true; do
            echo -e "\n\033[1mDelete the following directories?\033[0m"
            for dir in ${DIRS[@]}; do
                echo -e "\033[1m --> $dir\033[0m"
            done
            echo -e -n "\033[1mYes [Yy] or No [Nn]?\033[0m "
            
            read yn
            case $yn in
                [Yy]* ) rm -rf ${DIRS[@]}; break;;
                [Nn]* ) break;;
                * ) echo -e "\033[1;33mPlease answer Yes [Yy] or No [Nn]\033[0m ";;
            esac
        done
    fi

}


#
# _____________________________________________________________________________
#
function set_dir_name() {

    DIR="${IMPL_DIR_PREFIX}$1"

}


#
# _____________________________________________________________________________
#
function prepare_dir() {

    set_dir_name $1

    if [ -d "$DIR" ]; then
        echo -e "\033[1;33mWarning: Directory '$DIR' already exists\033[0m"
        return 1
    fi

    echo -e "\033[1;32mInfo: Creating directory '$DIR'\033[0m"
    mkdir -p $DIR

    return 0

}


#
# _____________________________________________________________________________
#
function check() {

    if [ -f $1 ]; then
        echo -e "[   \033[1;32mFound\033[0m   ]"
    else
        echo -e "[ \033[1;31mNOT Found\033[0m ]"
    fi
}


#
# _____________________________________________________________________________
#
function download_wolfssl() {

    WOLFSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Downloading WolfSSL ${WOLFSSL_VERSION}\033[0m"
    
    cd $START_DIR
    prepare_dir wolfssl-${WOLFSSL_VERSION}
    
    if [ $? -ne 0 ]; then
        echo -e "\033[1;31mError: Failed to setup clean directory for WolfSSL ${WOLFSSL_VERSION}. Skipping ...\033[0m"
        return 1
    fi

    git clone https://github.com/wolfSSL/wolfssl.git $DIR
    cd $DIR
    git checkout v${WOLFSSL_VERSION}
    cd $START_DIR

}


#
# _____________________________________________________________________________
#
function build_wolfssl() {

    WOLFSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Building WolfSSL ${WOLFSSL_VERSION}\033[0m"
    
    cd $START_DIR
    set_dir_name wolfssl-${WOLFSSL_VERSION}

    cd $DIR

    make clean
    ./autogen.sh
    ./configure --enable-ecc --enable-certgen --enable-certreq --enable-certext --enable-sep --enable-compkey --enable-eccencrypt --enable-hkdf --enable-psk --enable-oldtls --enable-maxfragment --enable-truncatedhmac --enable-secure-renegotiation --enable-supportedcurves --enable-session-ticket --enable-tlsx --enable-static=yes --enable-shared=no
    make clean
    make    

    cd $START_DIR

    # write launch script
    LAUNCH_SCRIPT=__launch_${DIR}_server.sh
# ===== Begin Here Document =====
    cat << 'EOF' > $LAUNCH_SCRIPT
#!/bin/bash
if [ ! -f XXXX/examples/server/server ]; then
    echo -e "WolfSSL server application not found"
    exit 1
fi
if [[ "$1" == "" ]]; then
    echo -e "Missing port number"
    exit 1
fi
cd XXXX/examples/server
while true; do ./server -p $1 -c ../cert.pem -k ../key.pem; done
EOF
# ====== End Here Document ======

    sed -i -e "s/XXXX/${DIR}/g" $LAUNCH_SCRIPT
    chmod +x $LAUNCH_SCRIPT

}


#
# _____________________________________________________________________________
#
function check_wolfssl() {

    WOLFSSL_VERSION=$1

    IMPL="WolfSSL ${WOLFSSL_VERSION}:"
    echo -n "`printf '%-25s' "$IMPL"`"
    set_dir_name wolfssl-${WOLFSSL_VERSION}
    check $DIR/examples/server/server
}


#
# _____________________________________________________________________________
#
function download_matrixssl() {

    MATRIXSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Downloading MatrixSSL ${MATRIXSSL_VERSION}\033[0m"
    
    cd $START_DIR
    prepare_dir matrixssl-${MATRIXSSL_VERSION}
    
    if [ $? -ne 0 ]; then
        echo -e "\033[1;31mError: Failed to setup clean directory for MatrixSSL ${MATRIXSSL_VERSION}. Skipping ...\033[0m"
        return 1
    fi

    git clone https://github.com/matrixssl/matrixssl.git $DIR
    cd $DIR
    git checkout ${MATRIXSSL_VERSION//./-}-open

# ===== Begin Here Document =====
    patch -t -R apps/ssl/Makefile << 'EOF' 
14,16d13
< # AW: Added to allow gcov finding files
< SRC:=$(abspath $(SRC))
< 
EOF
# ====== End Here Document ======
# ===== Begin Here Document =====
    patch -t -R core/Makefile << 'EOF' 
15,17d14
< # AW: Added to allow gcov finding files
< SRC:=$(abspath $(SRC))
< 
EOF
# ====== End Here Document ======
# ===== Begin Here Document =====
    patch -t -R crypto/Makefile << 'EOF' 
58,60d57
< # AW: Added to allow gcov finding files
< SRC:=$(abspath $(SRC))
< 
EOF
# ====== End Here Document ======
# ===== Begin Here Document =====
    patch -t -R matrixssl/Makefile << 'EOF' 
27,29d26
< # AW: Added to allow gcov finding files
< SRC:=$(abspath $(SRC))
< 
EOF
# ====== End Here Document ======

    cd $START_DIR

}


#
# _____________________________________________________________________________
#
function build_matrixssl() {

    MATRIXSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Building MatrixSSL ${MATRIXSSL_VERSION}\033[0m"
    
    cd $START_DIR
    set_dir_name matrixssl-${MATRIXSSL_VERSION}

    cd $DIR

    # build
    make clean
    make    

    # substitute CA file
    rm testkeys/RSA/2048_RSA_CA.pem
    ln -s $START_DIR/cacert.pem testkeys/RSA/2048_RSA_CA.pem

    cd $START_DIR

    # write launch script
    LAUNCH_SCRIPT=__launch_${DIR}_server.sh
# ===== Begin Here Document =====
    cat << 'EOF' > $LAUNCH_SCRIPT
#!/bin/bash
if [ ! -f XXXX/apps/ssl/server ]; then
    echo -e "MatrixSSL server application not found"
    exit 1
fi
if [[ "$1" == "" ]]; then
    echo -e "Missing port number"
    exit 1
fi
cd XXXX/apps/ssl
while true; do ./server -P $1 -c ../../../cert.pem -k ../../../key.pem; done
EOF
# ====== End Here Document ======

    sed -i -e "s/XXXX/${DIR}/g" $LAUNCH_SCRIPT
    chmod +x $LAUNCH_SCRIPT

}


#
# _____________________________________________________________________________
#
function check_matrixssl() {

    MATRIXSSL_VERSION=$1

    IMPL="MatrixSSL ${MATRIXSSL_VERSION}:"
    echo -n "`printf '%-25s' "$IMPL"`"
    set_dir_name matrixssl-${MATRIXSSL_VERSION}
    check $DIR/apps/ssl/server
}


#
# _____________________________________________________________________________
#
function download_mbedtls() {

    MBEDTLS_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Downloading mbedTLS ${MBEDTLS_VERSION}\033[0m"
    
    cd $START_DIR
    prepare_dir mbedtls-${MBEDTLS_VERSION}
    
    if [ $? -ne 0 ]; then
        echo -e "\033[1;31mError: Failed to setup clean directory for mbedTLS ${MBEDTLS_VERSION}. Skipping ...\033[0m"
        return 1
    fi

    git clone https://github.com/ARMmbed/mbedtls.git $DIR
    cd $DIR
    git checkout mbedtls-${MBEDTLS_VERSION}
    cd $START_DIR

}


#
# _____________________________________________________________________________
#
function build_mbedtls() {

    MBEDTLS_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Building mbedTLS ${MBEDTLS_VERSION}\033[0m"
    
    cd $START_DIR
    set_dir_name mbedtls-${MBEDTLS_VERSION}

    cd $DIR

    make clean
    make    

    cd $START_DIR

    # write launch script
    LAUNCH_SCRIPT=__launch_${DIR}_server.sh
# ===== Begin Here Document =====
    cat << 'EOF' > $LAUNCH_SCRIPT
#!/bin/bash
if [ ! -f XXXX/programs/ssl/ssl_server2 ]; then
    echo -e "mbedTLS server application not found"
    exit 1
fi
if [[ "$1" == "" ]]; then
    echo -e "Missing port number"
    exit 1
fi
cd XXXX/programs/ssl
while true; do ./ssl_server2 server_port=$1 crt_file=../../../cert.pem key_file=../../../key.pem; done
EOF
# ====== End Here Document ======

    sed -i -e "s/XXXX/${DIR}/g" $LAUNCH_SCRIPT
    chmod +x $LAUNCH_SCRIPT

}


#
# _____________________________________________________________________________
#
function check_mbedtls() {

    MBEDTLS_VERSION=$1

    IMPL="mbedTLS ${MBEDTLS_VERSION}:"
    echo -n "`printf '%-25s' "$IMPL"`"
    set_dir_name mbedtls-${MBEDTLS_VERSION}
    check $DIR/programs/ssl/ssl_server2
}


#
# _____________________________________________________________________________
#
function download_boringssl() {

    BORINGSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Downloading BoringSSL ${BORINGSSL_VERSION}\033[0m"
    
    cd $START_DIR
    prepare_dir boringssl-${BORINGSSL_VERSION}
    
    if [ $? -ne 0 ]; then
        echo -e "\033[1;31mError: Failed to setup clean directory for BoringSSL ${BORINGSSL_VERSION}. Skipping ...\033[0m"
        return 1
    fi

    git clone https://boringssl.googlesource.com/boringssl $DIR
    cd $DIR
    git checkout ${BORINGSSL_VERSION}

# ===== Begin Here Document =====
    patch -t -R tool/transport_common.cc << 'EOF' 
161,165d160
< #if defined(OPENSSL_WINDOWS)
<   const BOOL enable = TRUE;
< #else
<   const int enable = 1;
< #endif
172,177d166
<     goto out;
<   }
< 
<   if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&enable,
<                  sizeof(enable)) < 0) {
<     perror("setsockopt");
EOF
# ====== End Here Document ======

    cd $START_DIR

}


#
# _____________________________________________________________________________
#
function build_boringssl() {

    BORINGSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Building BoringSSL ${BORINGSSL_VERSION}\033[0m"
    
    cd $START_DIR
    set_dir_name boringssl-${BORINGSSL_VERSION}

    cd $DIR

    rm -rf build
    mkdir build
    cd build
    cmake ..
    make

    cd $START_DIR

    # write launch script
    LAUNCH_SCRIPT=__launch_${DIR}_server.sh
# ===== Begin Here Document =====
    cat << 'EOF' > $LAUNCH_SCRIPT
#!/bin/bash
if [ ! -f XXXX/build/tool/bssl ]; then
    echo -e "BoringSSL server application not found"
    exit 1
fi
if [[ "$1" == "" ]]; then
    echo -e "Missing port number"
    exit 1
fi
cd XXXX/build/tool
cat ../../../key.pem ../../../cert.pem ../../../cacert.pem > keycertchain.pem
while true; do ./bssl server -accept $1 -key keycertchain.pem; done
EOF
# ====== End Here Document ======

    sed -i -e "s/XXXX/${DIR}/g" $LAUNCH_SCRIPT
    chmod +x $LAUNCH_SCRIPT

}


#
# _____________________________________________________________________________
#
function check_boringssl() {

    BORINGSSL_VERSION=$1

    IMPL="BoringSSL ${BORINGSSL_VERSION}:"
    echo -n "`printf '%-25s' "$IMPL"`"
    set_dir_name boringssl-${BORINGSSL_VERSION}
    check $DIR/build/tool/bssl
}


#
# _____________________________________________________________________________
#
function download_openssl() {

    OPENSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Downloading OpenSSL ${OPENSSL_VERSION}\033[0m"
    
    cd $START_DIR
    prepare_dir openssl-${OPENSSL_VERSION}
    
    if [ $? -ne 0 ]; then
        echo -e "\033[1;31mError: Failed to setup clean directory for OpenSSL ${OPENSSL_VERSION}. Skipping ...\033[0m"
        return 1
    fi

    git clone https://github.com/openssl/openssl.git $DIR
    cd $DIR
    git checkout OpenSSL_${OPENSSL_VERSION//./_}
    cd $START_DIR

}


#
# _____________________________________________________________________________
#
function build_openssl() {

    OPENSSL_VERSION=$1

    echo -e "\n\n\033[1;32mInfo: Building OpenSSL ${OPENSSL_VERSION}\033[0m"
    
    cd $START_DIR
    set_dir_name openssl-${OPENSSL_VERSION}

    cd $DIR

    make clean
    ./config
    make depend
    make clean
    make    

    cd $START_DIR

    # write launch script
    LAUNCH_SCRIPT=__launch_${DIR}_server.sh
# ===== Begin Here Document =====
    cat << 'EOF' > $LAUNCH_SCRIPT
#!/bin/bash
if [ ! -f XXXX/apps/openssl ]; then
    echo -e "OpenSSL server application not found"
    exit 1
fi
if [[ "$1" == "" ]]; then
    echo -e "Missing port number"
    exit 1
fi
cd XXXX/apps
while true; do ./openssl s_server -accept $1 -key ../../key.pem -cert ../../cert.pem; done
EOF
# ====== End Here Document ======

    sed -i -e "s/XXXX/${DIR}/g" $LAUNCH_SCRIPT
    chmod +x $LAUNCH_SCRIPT

}


#
# _____________________________________________________________________________
#
function check_openssl() {

    OPENSSL_VERSION=$1

    IMPL="OpenSSL ${OPENSSL_VERSION}:"
    echo -n "`printf '%-25s' "$IMPL"`"
    set_dir_name openssl-${OPENSSL_VERSION}
    check $DIR/apps/openssl
}


#
# _____________________________________________________________________________
#

if [[ "$1" == "clean" ]]; then
    clean
    exit 0
fi

if [[ "$1" == "check" ]]; then
    check_wolfssl 3.9.8
    check_matrixssl 3.8.4
    check_mbedtls 2.2.0
    check_boringssl 2883
    check_openssl 1.0.2h
    exit 0
fi

clean

download_wolfssl 3.9.8
download_matrixssl 3.8.4
download_mbedtls 2.2.0
download_boringssl 2883
download_openssl 1.0.2h

build_wolfssl 3.9.8
build_matrixssl 3.8.4
build_mbedtls 2.2.0
build_boringssl 2883
build_openssl 1.0.2h

check_wolfssl 3.9.8
check_matrixssl 3.8.4
check_mbedtls 2.2.0
check_boringssl 2883
check_openssl 1.0.2h



