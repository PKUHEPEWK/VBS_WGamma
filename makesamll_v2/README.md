### compile
- svn checkout https://github.com/PKUHEPEWK/VBS_WGamma/trunk/makesamll_v2
- cd makesmall
- g++ -o small \`root-config --cflags --glibs\` runxx.C

### run
- write the files you want to make small into [filelist](https://github.com/PKUHEPEWK/VBS_WGamma/blob/master/makesamll_v2/filelist) then type:\
`./small`
- before doing this, remember to modified the [PATH](https://github.com/PKUHEPEWK/VBS_WGamma/blob/4fa88b7a7056c1be16fcd1a84b774f319a39877d/makesamll_v2/runxx.C#L6) to the file.
