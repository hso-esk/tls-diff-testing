#!/usr/bin/python

import sys
import math
import matplotlib.pyplot as plot
import matplotlib
import itertools
import random
import os.path
import glob


matplotlib.rcParams.update({'font.size': 18})


#
# _____________________________________________________________________________
#
def main(argv):
 
    nMax = 100000
    nSteps = 1000
    mergeIterations = False
    shuffle = 0

    # Reduction function R1
    reduction = lambda s: '1' if s.startswith('HS') else '0'
    ylabel = r'Avg. # unique resp. discrp. $\overline{\Delta_{R_1}(\mathcal{P}, \mathcal{X}|_n)}$'

    # Reduction function R2
#    reduction = lambda s: '/'.join(s.split('/')[:2]) 
#    ylabel = r'Avg. # unique resp. discrp. $\overline{\Delta_{R_2}(\mathcal{P}, \mathcal{X}|_n)}$'

    # Reduction function R3
#    reduction = lambda s: '/'.join(s.split('/')[:4]) 
#    ylabel = r'Avg. # unique resp. discrp. $\overline{\Delta_{R_3}(\mathcal{P}, \mathcal{X}|_n)}$'
    
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
            'files' : [pathTheManTools + '/iteration-{0:03}/stimuli.hex.responses'.format(n) for n in range(0, 100)],
            'color': 'red',
            'linestyle': '-',
            'linewidth': 3.,
#            'drawMinMax': True,
        },

        # AFL
        {
            'name': 'American Fuzzy Lop',
            'files' : [ pathAFL + '/iteration-{0:03}/stimuli_*.txt.responses'.format(i + 1) for i in range(100)],
            'color': 'green',
            'linestyle': ':',
            'linewidth': 3.,
#            'drawMinMax': True,
        },

        # TLS-Attacker
        {
            'name': 'TLS-Attacker',
            'files': [pathTLSAttacker + '/iteration-{0:03}/stimuli_phase1.hex.accepted.responses'.format(i + 1) for i in range(100)],
            'color': 'blue',
            'linestyle': '--',
            'linewidth': 3.,
#            'drawMinMax': True,
        },

        # NEZHA
        {
            'name': 'NEZHA',
            'files' : [ pathNezha + '/iteration-{0:03}/stimuli_*.txt.responses'.format(i + 1) for i in range(96) ],                    
            'color': 'black',
            'linestyle': '-.',
            'linewidth': 3.,
#            'drawMinMax': True,
        },

    ]

    N = len(datasets)


    Ysum = [0.] * nMax
    Ysum2 = [0.] * nMax

    Xmax = 0
    Ymax = 0

    for dataset in datasets:

        # dataset name
        dsName = dataset.get('name', 'unnamed')

        print('Processing dataset "{0}" ...'.format(dsName))

        print('-> Reading / processing responses')
        N, xmax, ymax, ymeanmax, nResponses = processDataset(dataset,
                reduction=reduction,
                merge=mergeIterations,
                shuffle=shuffle,
                nMax=nMax)

        dataset['nIterations'] = N
        Xmax = max(Xmax, xmax)
        Ymax = max(Ymax, ymax)
        dataset['ymeanmax'] = ymeanmax
        dataset['minPerIt'] = min(nResponses)
        dataset['maxPerIt'] = max(nResponses)


    if mergeIterations:
        plot.xlabel(r'Test corpus size')
    else:
        plot.xlabel(r'Truncated test corpus size $n$')
    plot.ylabel(ylabel)

    #plot.xscale('log')

    plot.subplots_adjust(top=0.82, left=0.13, bottom=0.14, right=0.92)

    plot.xlim([0, Xmax])
    plot.ylim([0, Ymax*1.05])

    plot.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,
           ncol=2, mode="expand", borderaxespad=0., prop={'size': 18})

    plot.show()


    # print summary
    print('\nSummary:')

    for dataset in datasets:

        # dataset name
        dsName = dataset.get('name', 'unnamed')

        # The number of iterations
        nIterations = dataset.get('nIterations', 0)

        minPerIt = dataset.get('minPerIt', 0)
        maxPerIt = dataset.get('maxPerIt', 0)


        # The mean cumulative efficiency
        ymeanmax = dataset.get('ymeanmax', 0.)

        print('  Dataset "{0}":'.format(dsName))
        print('    nIterations = {0}'.format(nIterations))
        print('    minPerIt    = {0}'.format(minPerIt))
        print('    maxPerIt    = {0}'.format(maxPerIt))
        print('    ymeanmax    = {0:.2f}'.format(ymeanmax))
       

#
# _____________________________________________________________________________
#
def processDataset(dataset, **args):

    # dataset name
    dsName = dataset.get('name', 'unnamed')

    # Skip compatible responses
    skipCompatible = dataset.get('skipCompatible', True)

    # Draw uncertainty?
    drawUncertainty = dataset.get('drawUncertainty', True)

    # Draw min/max?
    drawMinMax = dataset.get('drawMinMax', False)


    # The maximum number of runs to be read per iteration
    nMax = args.get('nMax', None)

    # The reduction function to apply
    reduction = args.get('reduction', None)

    # The step width 
    step = args.get('step', 1000)

    # True if iterations shall be merged into one
    merge = args.get('merge', False)

    # Shuffle items?
    shuffle = args.get('shuffle', 0)


    def handleIteration(responses, shuffle, step, sum1, sum2, mineff, maxeff):

        # The number of shuffle iterations
        N = 0

        nResponses = len(responses)

        for i in range(max(1, shuffle)):

            if shuffle:
                print('-> Shuffle #{0} ...'.format(i + 1))
                order = random.sample(range(nResponses), nResponses)
            else:
                # Linear scan
                print('-> Linear run ...')
                order = range(nResponses)

            # Calculate URS trace
            print('   -> Calculating URS trace {0}...'.format(
                    '(skipping compatible responses)' if skipCompatible else ''))
            trace = urs_trace(responses, order, skipCompatible)

            print('   -> Calculating URS efficiency ...')
            eff = urs_efficiency(trace, step, nResponses)

            # Expand
            if sum1 is None:
                sum1 = [0.] * len(eff)
            if sum2 is None:
                sum2 = [0.] * len(eff)
            if mineff is None:
                mineff = [x for x in eff]
            if maxeff is None:
                maxeff = [x for x in eff]

            # Sum
            N += 1
            sum1 = [sum(x) for x in zip(sum1, eff)]
            sum2 = [sum(x) for x in zip(sum2, map(lambda y: y**2, eff))]

            # Min / max
            mineff = [min(x) for x in zip(eff, mineff)]
            maxeff = [max(x) for x in zip(eff, maxeff)]

        return N, sum1, sum2, mineff, maxeff


    # The dataset's files
    files = dataset['files']

    # Efficiency over all iterations
    sum1 = None
    sum2 = None
    mineff = None
    maxeff = None

    N = 0
    responsesMerged = []

    # The list of the number of responses in each iteration of this dataset
    nResponses = []

    for iteration in files:

        # Read responses
        if isinstance(iteration, str):
            # >>> Just a single file in iteration >>>
            responses = readResponses([iteration], reduction, nMax=nMax)
        elif isinstance(iteration, list):
            # >>> Multiple files in iteration >>>
            responses = readResponses(iteration, reduction, nMax=nMax)

        nResponses += [len(responses)]

        if merge:
            # Merge responses from all iterations before processing
            responsesMerged = responsesMerged + responses
        else:
            # Handle each iteration individually
            n, sum1, sum2, mineff, maxeff = handleIteration(
                    responses, shuffle, step, sum1, sum2, mineff, maxeff)
            N += n

    if merge:
        # Handle merged responses
        N, sum1, sum2, mineff, maxeff = handleIteration(
                responsesMerged, shuffle, step, sum1, sum2, mineff, maxeff)

    # There is no point in drawing an uncertainty band with N = 1
    if N < 2:
        drawUncertainty = False

    X = map(lambda x: x*step, range(len(sum1)))
    Xmax = max(X)

    Ymean = []
    Yvarup = []
    Yvardown = []
    for s, s2 in zip(sum1, sum2):
        mean = s / N
#        stdv = math.sqrt(s2/N - mean**2)
        Ymean += [mean]
        if drawUncertainty:
            stdv = math.sqrt(s2*N - s**2) / (N - 1)
            Yvarup += [mean + stdv]
            Yvardown += [mean - stdv]

    if drawUncertainty:
        Ymax = max(Yvarup)
        plot.fill_between(X, Yvardown, Yvarup, color='lightgrey')
    else:
        Ymax = max(Ymean)

    plot.plot(X, Ymean,
            label=dsName,
            color=dataset.get('color', 'black'),
            linestyle=dataset.get('linestyle', '-'),
            linewidth=dataset.get('linewidth', 0.5))

    if drawMinMax:
        plot.plot(X, maxeff,
                color=dataset.get('color', 'black'),
                linestyle=dataset.get('linestyle', '-'),
                linewidth=0.3 * dataset.get('linewidth', 0.5))
        plot.plot(X, mineff,
                color=dataset.get('color', 'black'),
                linestyle=dataset.get('linestyle', '-'),
                linewidth=0.3 * dataset.get('linewidth', 0.5))


    return N, Xmax, Ymax, max(Ymean), nResponses
       

#
# _____________________________________________________________________________
#
def sample(n, k, m):
    # n: population size
    # k: group size
    # m: number of groups
    return 


#
# _____________________________________________________________________________
#
def linear(k):
    # n: population size
    # k: group size
    # m: number of groups
    return [range(k)]
        

#
# _____________________________________________________________________________
#
def urs_trace(responses, group, skipCompatible=True):
    # The efficiency dictionary of Unique Response Signatures (URS)
    trace = {}
    for n, gi in enumerate(group):
        # The current Response Signature (RS)
        rs = responses[gi]

        if skipCompatible and len(set(rs.split('-'))) == 1:
            continue

        if rs not in trace:
            trace[rs] = n
    return sorted(trace.values())        

#
# _____________________________________________________________________________
#
def urs_efficiency(trace, step=1000, end=None):

    eff = [0]

    # current trace index
    j = 0

    # current number of runs
    n = step

    while j < len(trace):
        if n >= trace[j]:
            j += 1
            if j == len(trace):
                eff.append(j)
        else:
            eff.append(j)
            n += step
        
    if end is not None:    
        while n < end:
            eff.append(eff[-1])
            n += step        

    return eff

#
# _____________________________________________________________________________
#
def urs_frequency(responses):

    frequency = {}
    for resp in responses:
        frequency[resp] = frequency.get(resp, 0) + 1
    return frequency


#
# _____________________________________________________________________________
#
def readResponses(filenames, reduction=None, **kwargs):

    # The maximum number of runs to read
    nMax = kwargs.get('nMax', None)

    # The maximum number of runs to read per file
    nMaxPerFile = kwargs.get('nMaxPerFile', None)


    # To store the resonses read from file
    responses = []

    # Becomes True once nMax has been reached
    done = False

    for pattern in filenames:
        print('   -> File pattern: "{0}"'.format(pattern))
        files = sorted(glob.glob(pattern))
        if len(files) == 0:
            print('      -> no matching files')
            continue         

        for filename in files:
            print('      -> Reading file "{0}" ...'.format(filename))
            for line in open(filename):
                (myid, mysig) = line.split(':')[:2]
                if reduction is not None:
                    sig = '-'.join(map(reduction, mysig.split(';')))
                else:
                    sig = '-'.join(mysig.split(';'))
                responses.append(sig)

                n = len(responses)
                if nMax is not None and nMax <= n:
                    done = True
                    break
                if nMaxPerFile is not None and nMaxPerFile <= n:
                    break
            if done:
                break
        if done:
            break

    print('         -> Read {0} responses ({1} unique)!' \
            .format(len(responses), len(set(responses))))

    return responses


#
# _____________________________________________________________________________
#
if __name__ == "__main__":
    main(sys.argv[1:])




