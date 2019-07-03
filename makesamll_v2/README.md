### compile
- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/makesmall
- cd makesmall
- g++ -o small \`root-config --cflags --glibs\` runxx.C

### run
- write the files you want to make small into then type:\
`./small`
- before doing this, remember to modified the [PATH](https://github.com/PKUHEPEWK/VBS_WGamma/blob/9f1d950358a8a34f2812712072877701e4d320e3/makesmall/main.cpp#L4) to the file.
