#include "makesmall.h"
int main(int argc, char* argv[]) {
    //gROOT->LoadMacro("xx.C");
    TString dir = "root://cmseos.fnal.gov//eos/uscms/store/user/qliphy/jie/ori/";

    TString infilename = argv[1];
    if (infilename.Contains(".root") == 0) {
        return 1;
    }
    TString outname = "out" + infilename;

    cout << outname << endl;

    TFile*      file1 = TFile::Open(dir + infilename);
    TDirectory* dir1  = (TDirectory*)file1->Get("treeDumper");
    TTree*      tree1 = (TTree*)dir1->Get("PKUCandidates");
    makesmall   m1(tree1, outname);
    cout << outname << endl;
    m1.Loop();
    m1.endJob();
    return 0;
}
//g++ -o run `root-config --cflags --glibs` main.cpp makesmall.cpp
