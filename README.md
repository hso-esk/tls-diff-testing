# Differential fuzz testing of the TLS handshake


 
Institute of Reliable Embedded Systems and Communication Electronics
Offenburg University of Applied Sciences



This is the software implementing our differential fuzz test approach for the TLS handhsake as presented in our manuscript "Exploiting Dissent: Towards Fuzzing-based Differential Black-Box Testing of TLS Implementations". The software consists of two main components

-> a shell script ("tls-server-batch") setting up the five TLS server implementations
   we used
-> A C++ framework and some Python scripts ("tls-diff-testing") for input generation,
   server stimulation, and data visualization


Institute of Reliable Embedded Systems and Communication Electronics
Offenburg University of Applied Sciences

Please note: our software is evolving and is likely going to be subject to refactoring and restructuring. We cannot guarantee API stability in any form.


## How to use the code?


In order to use our software:

1. Download and build cryptopp

Our software uses the Crypto++ Cryptographic Library [https://www.cryptopp.com/] for cryptographic operations. You need to download and build Crypto++ before building our software. Everything is condensed in the shell script setup_cryptopp.sh:

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

3. Build tls-diff-testing and corresponding apps

```bash
pushd tls-diff-testing
# Build fundamental tools
make
```

```bash
pushd tls-diff-fuzzing
# Build input generation tool
make
popd
```

```bash
pushd apps/stimulate_servers_2
# Build server stimulation tool
make
popd
```

4. Generate test input (TLS ClientHello messages)

```bash
pushd tls-diff-fuzzing
# Run input generation tool multiple times (adapt parameters to your needs within shell script)
./macros/generate_multi.sh
popd
popd
```

5. Send test input to TLS servers

```bash
pushd tls-server-batch
# Launch servers (20 instances per implementation, adapt number to the performance of your machine)
./launch 20
popd

pushd tls-diff-testing/apps/stimulate_servers_2
# Stimulate servers (adapt "-s20" to the number chosen above)
for fin in $(ls ../../tls-diff-fuzzing/*/stimuli.hex); do
    ./stimulate_servers_2 -S5 -s20 $fin | tee ${fin}.responses
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




    


    


