# Differential fuzz testing of the TLS handshake 

This is the software implementing our differential fuzz test approach for the
TLS handshake as presented in our manuscript "Exploiting Dissent: Towards 
Fuzzing-based Differential Black-Box Testing of TLS Implementations". The paper
will soon appear in IEEE Transactions on Dependable and Secure Computing (TDSC).
A [preprint](https://ivesk.hs-offenburg.de/fileadmin/Einrichtungen/ivesk/files/preprint_TLS-Diff-Fuzzing_IEEE-TDSC.pdf) is available from our [institute's homepage](https://ivesk.hs-offenburg.de).

The software consists of 3 main components:

* A shell script ("tls-server-batch") allowing to set up the five TLS server implementations
  we used in our paper (OpenSSL, MatrixSSL, wolfSSL, mbedTLS and BoringSSL).
* A C++ framework and some Python scripts ("tls-diff-testing") for generating TLS
  test messages, stimulating the five TLS servers, and for analyzing and visualizing 
  data.
* Dockerfile, use docker to package & test in docker container 

Please note: our software is evolving and is likely going to be subject to
refactoring and restructuring. We cannot guarantee API stability in any form.


## How to use the code?

In order to use our software:

  1. :airplane: Download src code 

     ```bash
     git clone <tls-diff-testing.git>
     ```

2. :hammer: Build a docker image from Dockerfile

   This process may take several hours(4h - 20h), 
   You can get the main process information from `main.sh`, 
   which includes generating 100 independent test corpora, 
   each corpus contains 10w test data. So this process will last a very long time
   just wait and check log 
   
   On my laptop,`Intel(R) Core(TM) i7-6700HQ CPU @ 2.60GHz (8 CPUs), ~2.6GHz
   Memory: 16384MB RAM` it took nearly **18 hours**
   
   If you want to directly generate your own data, please execute the following command 
   ```bash
   docker build . -t the-diff-testing
   ```
    ![image-20210702081226553](https://gitee.com/sizaif/images/raw/master/img/20210702081229.png)
    
    If you don't want to wait for this process, please annotation the last line in `main.sh`
    like this:
    ![image-20210702124649695](https://gitee.com/sizaif/images/raw/master/img/20210702124652.png)
    then execute
    ```bash
    docker build . -t the-diff-testing
    ```
    you can get the data from the link belw,unzip and put into docker container in `<project>/tls-diff-testing/generator/`
    link：https://pan.baidu.com/s/1H97CWkevV63tak8ZdYdDRQ 
    code：yfjz 
    >If the link fails, please contact sizaif2000@gmail.com
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

5. Plot data. You need to have `Python 2.7.x +` and `Matplotlib` for Python installed.

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

11222
