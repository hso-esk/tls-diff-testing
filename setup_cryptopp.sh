#!/bin/bash

wget https://github.com/weidai11/cryptopp/archive/CRYPTOPP_5_6_5.tar.gz \
&& tar -xzf CRYPTOPP_5_6_5.tar.gz \
&& mv cryptopp-CRYPTOPP_5_6_5 cryptopp \
&& cd cryptopp \
&& make

