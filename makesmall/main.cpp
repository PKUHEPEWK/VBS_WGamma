#include "makesmall.h"
int main(int argc, char* argv[]) {
    //gROOT->LoadMacro("xx.C");
    TString dir = "root://cmseos.fnal.gov//eos/uscms/store/user/qliphy/ori/";
    //TString dir        = "/eos/uscms/store/user/qliphy/ori/";
    TString infilename = argv[1];
    if (infilename.Contains(".root") == 0) {
        return 1;
    }
    TString outname = "out" + infilename;
    std::cout << outname << std::endl;

    TFile* file1 = TFile::Open(dir + infilename);

    TDirectory* dir1  = (TDirectory*)file1->Get("treeDumper");
    TTree*      tree1 = (TTree*)dir1->Get("PKUCandidates");
    makesmall   m1(tree1, outname);
    std::cout << outname << std::endl;
    m1.Loop();
    m1.endJob();
    return 0;
}
//g++ -o run `root-config --cflags --glibs` main.cpp makesmall.cpp
