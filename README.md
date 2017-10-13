# Differential fuzz testing of the TLS handshake

This is the software implementing our differential fuzz test approach for the
TLS handshake as presented in our manuscript "Exploiting Dissent: Towards 
Fuzzing-based Differential Black-Box Testing of TLS Implementations". The paper
will soon appear in IEEE Transactions on Dependable and Secure Computing (TDSC).
A [preprint](https://ivesk.hs-offenburg.de/fileadmin/Einrichtungen/ivesk/files/preprint_TLS-Diff-Fuzzing_IEEE-TDSC.pdf) is available from our [institute's homepage](https://ivesk.hs-offenburg.de).

The software consists of two main components:
* A shell script ("tls-server-batch") allowing to set up the five TLS server implementations
we used in our paper (OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL).
* A C++ framework and some Python scripts ("tls-diff-testing") for generating TLS
test messages, stimulating the five TLS servers, and for analyzing and visualizing 
data.

Please note: our software is evolving and is likely going to be subject to
refactoring and restructuring. We cannot guarantee API stability in any form.


## How to use the code?

In order to use our software:

1. Download and build cryptopp

Our software uses the [Crypto++ Cryptographic Library](https://www.cryptopp.com/) for cryptographic operations. You need to download and build Crypto++ before building our software. Everything is condensed in the shell script setup_cryptopp.sh:

```bash
# Download and build cryptopp
./setup_cryptopp.sh
```

2. Setup TLS implementations (servers). Some of them might require additional software/libraries to be installed.

```bash
pushd tls-server-batch
# Download and build OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL
./setup.sh
popd
```

3. Build tls-diff-testing components

```bash
pushd tls-diff-testing
# Build tls-diff-testing components
make
```

4. Generate test input (TLS ClientHello messages)

```bash
pushd generator
# Run input generation tool multiple times (adapt parameters to your needs within shell script)
./macros/generate_multi.sh
popd
popd
```

5. Send test input to TLS servers

```bash
pushd tls-server-batch
# Launch servers (20 instances per implementation, adapt the number "20" to the performance of your machine)
# You will need the "screen" tool for that.
./launch.sh 20
popd

pushd tls-diff-testing/apps/stimulator
# Stimulate TLS servers (adapt "-s20" to the number chosen above)
for fin in $(ls ../../generator/iteration-*/stimuli.hex); do
    ./stimulator -S5 -s20 $fin | tee ${fin}.responses
done
popd
```

6. Plot data. You need to have Python 2.7.x and Matplotlib for Python installed.

```bash
pushd tls-diff-testing/apps/python_plot_urs
# Read response data and plot (adapt paths within Python script before)
./plot_urs.py
popd
```


## Contact

In case you have any questions or suggestions regarding our approach or our software tools, please contact: Andreas Walz [andreas.walz@hs-offenburg.de].


## Copyright and License

This software is licensed under the 3-clause BSD license. This license gives
everyone the right to use and distribute the code, either in binary or source
code format, as long as the copyright license is retained in the source code.

Copyright (C) 2017  
Andreas Walz [andreas.walz@hs-offenburg.de]  
Offenburg University of Applied Sciences  
Institute of Reliable Embedded Systems and Communications Electronics (ivESK)  
[https://ivesk.hs-offenburg.de/]  
All rights reserved.  






    


    


