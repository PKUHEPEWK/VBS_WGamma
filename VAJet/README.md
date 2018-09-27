#Steps:

- cmsrel CMSSW_8_0_26_patch1

- cd CMSSW_8_0_26_patch1/src
- cmsenv
- git cms-merge-topic cms-met:METRecipe_8020 -u
- git cms-merge-topic Sam-Harper:HEEPV70VID_8010_ReducedCheckout
- mkdir -p ../external/slc6_amd64_gcc530/data/RecoEgamma/ElectronIdentification/
- git clone git@github.com:cms-data/RecoEgamma-ElectronIdentification ../external/slc6_amd64_gcc530/data/RecoEgamma/ElectronIdentification/data
- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/VAJet
- scram b -j9