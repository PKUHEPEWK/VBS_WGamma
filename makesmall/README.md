Steps
-------

- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/makesmall
- cd makesmall
- g++ -o small \`root-config --cflags --glibs\` main.cpp makesmall.cpp
- ./makesmall filename