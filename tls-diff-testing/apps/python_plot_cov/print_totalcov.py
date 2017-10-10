#!/usr/bin/python

import sys
import math
import matplotlib.pyplot as plot
import itertools
import random
from bitarray import bitarray
import glob


#
# _____________________________________________________________________________
#
def main(argv):

    # TODO: Change paths to point to your response files
    pathBase            = 'tls-diff-testing'    
    pathTheManTools     = pathBase + '/stimuli-20170607-the-man-tools'
    pathAFL             = pathBase + '/stimuli-20170607-afl'
    pathTLSAttacker     = pathBase + '/stimuli-20170607-TLSAttacker'
    pathNezha           = pathBase + '/stimuli-20170607-nezha'

    datasets = [

        # the-man-tools
        {
            'name': 'Our approach',
            'master': True,
            'files' : [pathTheManTools + '/iteration-{0:03}/stimuli.hex.cumulative-coverage'.format(n) for n in range(0, 100)],
            'color': 'red',
            'linestyle': '-',
            'linewidth': 2.,
        },

        # AFL
        {
            'name': '\\afl',
            'files' : [pathAFL + '/iteration-{0:03}/stimuli_0000000x.txt.cumulative-coverage'.format(n + 1) for n in range(0, 100)],
            'color': 'green',
            'linestyle': '-',
            'linewidth': 2.,
        },

        # TLS-Attacker
        {
            'name': '\\tlsattacker',
            'files' : [pathTLSAttacker + '/iteration-{0:03}/stimuli_phase1.hex.accepted.cumulative-coverage'.format(n + 1) for n in range(0, 100)],
            'color': 'blue',
            'linestyle': '-',
            'linewidth': 2.,
        },

        # Nezha
        {
            'name': '\\nezha',
            'files' : [pathNezha + '/iteration-{0:03}/stimuli_0000000x.txt.cumulative-coverage'.format(n) for n in range(1, 101)],
            'color': 'black',
            'linestyle': '-',
            'linewidth': 2.,
        },

    ]


    for dataset in datasets:
        cov = readCoverageFiles(dataset['files'])

        N = len(cov)
        s = sum(cov)     
        s2 = sum(map(lambda x: x**2, cov))     

        mean = s / N
        stdv = math.sqrt(s2*N - s**2) / (N - 1)

        dataset['cov'] = cov
        dataset['mean'] = mean
        dataset['stdv'] = stdv


#    for dataset in datasets:
#        cov = map(lambda c: c / masterCov, dataset['cov'])
#        cov = dataset['cov']
#        plot.hist(cov, bins=20, range=(20, 30), histtype='stepfilled', alpha=0.75,
#            color=dataset.get('color', 'black'),
#            linestyle=dataset.get('linestyle', '-'),
#            linewidth=dataset.get('linewidth', 0.5))

    

    for cov, index in sorted([(-ds['mean'], index) \
            for index, ds in enumerate(datasets)]):

        dataset = datasets[index]

        print('{0:25} & {1:2.1f} $\\pm$ {2:2.1f} \\\\'.format(dataset['name'], dataset['mean'], dataset['stdv']))

    plot.show()

#
# _____________________________________________________________________________
#
def readCoverage(filename):

    f = open(filename)

    # get last line
    for line in f:
        pass

    cov = float(line.split(':')[1].split('%')[0])

    return cov


#
# _____________________________________________________________________________
#
def readCoverageFiles(filenames, nmax=None):

    coverage = []

    for pattern in filenames:
        print('   -> File pattern: "{0}"'.format(pattern))
        files = sorted(glob.glob(pattern))
        if len(files) == 0:
            print('      -> no matching files')
            continue

        for filename in files:
            print('      -> Reading file "{0}" ...'.format(filename))
            coverage += [readCoverage(filename)]

    print('Read {0} coverage files!'.format(len(coverage)))

    return coverage


#
# _____________________________________________________________________________
#
if __name__ == "__main__":
    main(sys.argv[1:])




