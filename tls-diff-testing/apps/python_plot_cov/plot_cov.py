#!/usr/bin/python

import sys
import matplotlib.pyplot as plot
import itertools
import random
from bitarray import bitarray


#
# _____________________________________________________________________________
#
def main(argv):

    files1 = ['/home/walz/data/tls-diff-testing/stimuli-20170511-the-man-tools/iteration-{0:03}/stimuli.hex.accepted.coverage'.format(i) for i in range(10)]

    files2 = ['/home/walz/data/tls-diff-testing/stimuli-20170510-afl/stimuli_{0:08}.txt.accepted.coverage'.format(i) for i in range(1, 11)]

    files3 = ['/home/walz/data/tls-diff-testing/stimuli-20170511-TLSAttacker/iteration-{0:03}/stimuli_phase{1}.hex.accepted.coverage'.format(i, j) for i, j in itertools.product(range(7), range(1, 4))]

    plotCoverage(readCoverage(files1), 'red')
    plotCoverage(readCoverage(files2), 'blue')
    plotCoverage(readCoverage(files3), 'green')

    plot.xscale('log')

    plot.show()


#
# _____________________________________________________________________________
#
def plotCoverage(coverage, color):

    accu = None

    X = range(len(coverage) + 1)
    Y = [0]

    for cov in coverage:
        if accu is None:
            accu = bitarray(len(cov))
        elif len(accu) != len(cov):
            print('Inconsistent lengths!!')
            return            
        accu = accu | cov
        Y += [accu.count(True)]

    plot.plot(X, Y, color=color)


#
# _____________________________________________________________________________
#
def readCoverage(filenames, nmax=None):

    coverage = []

#    left, right = 0, 479
#    left, right = 479, 1320
#    left, right = 1320, 1614
    left, right = 479, 1614

    for filename in filenames:
        print('Reading file {0} ...'.format(filename))
        for line in open(filename):
            (myid, mycov) = line.split(':')[:2]
            coverage.append(bitarray(mycov.strip()[left:right]))

    print('Read {0} coverage entries!'.format(len(coverage)))

    return coverage


#
# _____________________________________________________________________________
#
if __name__ == "__main__":
    main(sys.argv[1:])




