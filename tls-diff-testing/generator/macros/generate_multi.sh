#!/bin/bash

DATADIR=.
NSETS=100
NPERSET=100000

for i in $(seq 1 $NSETS); do

    ISTR=$(printf 'iteration-%03i' $i)
    echo "$ISTR:"
    mkdir -p $DATADIR/$ISTR

    echo " --> Generate random file ..."
    dd if=/dev/urandom of=$DATADIR/$ISTR/random.bin bs=1024 count=10240 >/dev/null

    echo " --> Generating TLS messages ..."
    ./generate $DATADIR/$ISTR/random.bin $DATADIR/$ISTR/stimuli.hex $NPERSET | tee $DATADIR/$ISTR/generation_log.txt

done

