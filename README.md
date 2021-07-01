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

  1. :airplane: Download src code 

     ```bash
     git clone <tls-diff-testing.git>
     ```

2. :hammer: Build a docker image from Dockerfile

   maybe it nee 10min- 30min, just wait and check log 

   ```bash
   docker build . -t the-diff-testing
   ```

3. :arrow_forward: Run docker container

   ==**after build image, Enter the container and continue to execute the following commands**==

   ```bash
   docker exec -it <containerID> /bin/bash
   ```


4. :dart: ​Send test input to TLS servers

   ```bash
    $ pushd tls-server-batch
    # Launch servers (20 instances per implementation, adapt the number "20" to the performance of your machine)
    # You will need the "screen" tool for that.
    $ ./launch.sh 20
    $ popd
    
    $ pushd tls-diff-testing/apps/stimulator
    # Stimulate TLS servers (adapt "-s20" to the number chosen above)
    for fin in $(ls ../../generator/iteration-*/stimuli.hex); do
        ./stimulator -S5 -s20 $fin | tee ${fin}.responses
    done
    $ popd
   ```

5. Plot data. You need to have `Python 2.7.x` and `Matplotlib` for Python installed.

   ```bash
   $ pushd tls-diff-testing/apps/python_plot_urs
   # Read response data and plot (adapt paths within Python script before)
   ./plot_urs.py
   $ popd
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






​    


​    

```

```