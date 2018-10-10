Steps
-------

- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/makesmall
- g++ -o makesmall \`root-config --cflags --glibs\` main.cpp makesmall.cpp
- ./makesmall <filename>
