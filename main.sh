#!/bin/bash


# Setup TLS implementations (servers). Some of them might require additional software/libraries to be installed.
${WORKDIR}/tls-server-batch/setup.sh fork

# Build tls-diff-testing components
cd ${WORKDIR}/tls-diff-testing
make

# Generate test input (TLS ClientHello messages)
# it contains 100 independent test corpora, Each corpus contains 10w random stimuli.
# So it will last a long time
${WORKDIR}/tls-diff-testing/generator/macros/generate_multi.sh fork

