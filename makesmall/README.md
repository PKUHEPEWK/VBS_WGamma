Steps
-------

- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/makesmall
- cd makesmall
- chmod +x wrapper.sh
- g++ -o small \`root-config --cflags --glibs\` main.cpp makesmall.cpp
- condor_submit submit.jdl

`Please make sure you can use condor or cms connect, if you want to do the last step`
