#!/bin/bash

SERVERS="openssl-1.0.2h mbedtls-2.2.0 wolfssl-3.9.8 matrixssl-3.8.4 boringssl-2883"

PORT_STEP=100

if [[ "$1" == "" ]]; then
    echo -e "Missing number of instances"
    exit 1
fi
N=$1

if [[ "$2" != "" ]]; then
    PORT_OFFSET=$2
else
    PORT_OFFSET=10000
fi

rm -f __sessions

for i in $(seq 0 $(($N-1))); do

    echo "Launching batch instance $(($i+1))/$N"

    let ISERVER=0
    for SERVER in $SERVERS
    do
        PORT=$((${PORT_OFFSET}+${PORT_STEP}*$i+$ISERVER))
        SESSION=${SERVER}_server_p${PORT}

        echo "$(printf ' [%5d]' $PORT) <--> $(printf '%-20s (%s)' $SERVER $SESSION)"

        screen -d -m -S $SESSION ./__launch_impl_${SERVER}_server.sh $PORT

        echo "$SESSION" >> __sessions

        let ISERVER=ISERVER+1
    done

done


