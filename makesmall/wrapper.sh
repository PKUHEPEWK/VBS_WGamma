#!/bin/bash
# small.sh

printf "Start time: "; /bin/date
printf "Job is running on node: "; /bin/hostname
printf "Job running as user: "; /usr/bin/id
printf "Job is running in directory: "; /bin/pwd
#First, setup the CMS environment
source /cvmfs/cms.cern.ch/cmsset_default.sh

#Then, get a release
INITDIR="$PWD"
export SCRAM_ARCH="slc6_amd64_gcc491"
CMS_VERSION="CMSSW_8_0_26_patch1"
scramv1 project CMSSW ${CMS_VERSION}
cd ${CMS_VERSION}
eval `scram runtime -sh`
cd $INITDIR
./small $@
rm -rf CMSSW_8_0_26_patch1
printf "End time: "; /bin/date
