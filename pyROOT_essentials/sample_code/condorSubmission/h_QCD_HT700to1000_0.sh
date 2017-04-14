#!/bin/bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd /my/cmssw/directory/CMSSW_9_x_x/src
eval `scramv1 runtime -sh`
cd /my/exercises/directory/pyROOT_essentials/sample_code
python runHatsTrees.py -i QCD_HT700to1000_0_${1} -o QCD_HT700to1000_0_${1} -l -t 'ntuplizer/tree'
