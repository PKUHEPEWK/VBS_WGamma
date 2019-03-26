#include "makesmall.h"
int main(int argc, char* argv[]) {
    //gROOT->LoadMacro("xx.C");
    TString dir = "/home/pku/xiaoj/wgammadata/singleele/";
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
    cout<<"doudou"<<endl;
    TH1D* hwgt=(TH1D*)dir1->Get("thWeight");
    Double_t npp=(Double_t)hwgt->GetBinContent(2);
    Double_t nmm=(Double_t)hwgt->GetBinContent(1);
    
    makesmall   m1(tree1,npp,nmm, outname);
    std::cout << outname <<": \t npp:"<<npp<<"\t nmm:"<<nmm<< std::endl;
    m1.Loop();
    m1.endJob();
    return 0;
}
//g++ -o small `root-config --cflags --glibs` main.cpp makesmall.cpp
