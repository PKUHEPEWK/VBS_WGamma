// -- g++ -Wall -o template `root-config --cflags --glibs` -L $ROOTSYS/lib -lRooFit -lRooFitCore -lFoam -lHtml -lMinuit make_template.cc
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TMath.h"
#include "TROOT.h"
#include "TTree.h"
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
//Double_t ptlow[7]  = {20, 30, 40, 50, 70, 100, 135};

using namespace std;

void generate_template(string ismuon_, string isbarrel_, int template_type) {
    TString ismuon   = ismuon_;
    TString isbarrel = isbarrel_;
    // pt range
    Double_t ptlow[7]  = {25, 30, 40, 50, 70, 100, 135};
    Double_t pthigh[7] = {30, 40, 50, 70, 100, 135, 400};

    //data_template && photon_mla[iphoton] > 0. && abs(photon_mla[iphoton] - 91.2) > 10 && photon_drla[iphoton] > 0.5 && photon_pt[iphoton] > lowpt && photon_pt[iphoton] < highpt && photon_hoe[iphoton] < 0.0396 && (photon_nhiso[iphoton] < 2.725 + 0.0148 * photon_pt[iphoton] + 0.000017 * photon_pt[iphoton] * photon_pt[iphoton]) && (photon_phoiso[iphoton] < 2.571 + 0.0047 * photon_pt[iphoton]) && photon_chiso[iphoton] < 0.441 && fabs(photonsc_eta[iphoton]) < 1.4442 && !photon_ppsv[iphoton]
    //lep == 13 && nlooseeles < 1 && nloosemus < 2 && ptlep1 > 25 && fabs(etalep1) < 2.4 && MET_et > 35 && HLT_Mu2 == 1
    int      nBins, lepton_pid, nlooseeles_cut, nloosemus_cut, HLT_Mu2_cut, HLT_Ele2_cut;
    Double_t sieie_lower, sieie_upper, mla_cut, hoe_cut, chiso_cut_low, chiso_cut_high, photonsc_eta_cut_low, photonsc_eta_cut_high, lepton_pt_cut;
    Double_t nhiso_cut[3];
    Double_t phoiso_cut[2];

    if (ismuon.Contains("MUON")) {
        lepton_pid     = 13;
        nlooseeles_cut = 1;
        nloosemus_cut  = 2;
        HLT_Mu2_cut    = 1;
        mla_cut        = 10;  // -- -1 means no mla cut
        lepton_pt_cut  = 25;
    }
    else if (ismuon.Contains("ELECTRON")) {
        lepton_pid     = 11;
        nlooseeles_cut = 2;
        nloosemus_cut  = 1;
        HLT_Ele2_cut   = 1;
        mla_cut        = 10;  // -- -1 means no mla cut
        lepton_pt_cut  = 30;
    }

    if (isbarrel.Contains("BARREL")) {
        nBins          = 128;
        sieie_lower    = 0.00;
        sieie_upper    = 0.04;
        hoe_cut        = 0.0396;
        chiso_cut_low  = -10;  // -- -10 is the initial value is PKU ntuple
        chiso_cut_high = 0.441;
        nhiso_cut[0]   = 2.725;
        nhiso_cut[1]   = 0.0148;
        nhiso_cut[2]   = 0.000017;
        phoiso_cut[0]  = 2.571;
        phoiso_cut[1]  = 0.0047;
        // photon in barrel
        photonsc_eta_cut_low  = -1;
        photonsc_eta_cut_high = 1.4442;
    }
    else if (isbarrel.Contains("ENDCAP")) {
        nBins          = 20;
        sieie_lower    = 0.01;
        sieie_upper    = 0.06;
        hoe_cut        = 0.0219;
        chiso_cut_low  = -10;  // -- -10 is the initial value is PKU ntuple
        chiso_cut_high = 0.442;
        nhiso_cut[0]   = 1.715;
        nhiso_cut[1]   = 0.0163;
        nhiso_cut[2]   = 0.000014;
        phoiso_cut[0]  = 3.863;
        phoiso_cut[1]  = 0.0034;
        // photon in endcap
        photonsc_eta_cut_low  = 1.566;
        photonsc_eta_cut_high = 2.5;
    }

    // which template: data, fake or true?
    if (template_type == 1) {  // fake template
        chiso_cut_low  = 4;
        chiso_cut_high = 10;
    }
    // weight of all
    Double_t real_wgt;

    //histogram
    TH1D* histo = new TH1D("histo", "histo", nBins, sieie_lower, sieie_upper);
    histo->Sumw2();
    TH1D* hMla = new TH1D("hMla", "hMla", 100, 0, 200);

    TFile* ipt;

    if ((template_type == 0 || template_type == 1) && ismuon.Contains("MUON")) {
        ipt = TFile::Open("/home/pku/xiaoj/makesmall/draw_data/outSMu.root");
    }
    else if ((template_type == 0 || template_type == 1) && ismuon.Contains("ELECTRON")) {
        ipt = TFile::Open("/home/pku/xiaoj/makesmall/draw_data/outSEle.root");
    }
    else if (template_type == 2) {
        ipt = TFile::Open("/home/pku/xiaoj/makesmall/draw_data/outWA.root");
    }

    TTreeReader fReader("demo", ipt);  //!the tree reader

    // Readers to access the data (delete the ones you do not need).
    TTreeReaderValue<Double_t> scalef              = {fReader, "scalef"};
    TTreeReaderValue<Int_t>    nevent              = {fReader, "nevent"};
    TTreeReaderValue<Int_t>    run                 = {fReader, "run"};
    TTreeReaderValue<Int_t>    ls                  = {fReader, "ls"};
    TTreeReaderValue<Int_t>    nVtx                = {fReader, "nVtx"};
    TTreeReaderValue<Double_t> theWeight           = {fReader, "theWeight"};
    TTreeReaderValue<Double_t> npT                 = {fReader, "npT"};
    TTreeReaderValue<Int_t>    lep                 = {fReader, "lep"};
    TTreeReaderValue<Double_t> ptVlepJEC           = {fReader, "ptVlepJEC"};
    TTreeReaderValue<Double_t> yVlepJEC            = {fReader, "yVlepJEC"};
    TTreeReaderValue<Double_t> phiVlepJEC          = {fReader, "phiVlepJEC"};
    TTreeReaderValue<Double_t> mtVlepJECnew        = {fReader, "mtVlepJECnew"};
    TTreeReaderValue<Int_t>    nlooseeles          = {fReader, "nlooseeles"};
    TTreeReaderValue<Int_t>    nloosemus           = {fReader, "nloosemus"};
    TTreeReaderArray<Double_t> photon_pt           = {fReader, "photon_pt"};
    TTreeReaderArray<Double_t> photon_eta          = {fReader, "photon_eta"};
    TTreeReaderArray<Double_t> photon_phi          = {fReader, "photon_phi"};
    TTreeReaderArray<Bool_t>   photon_ppsv         = {fReader, "photon_ppsv"};
    TTreeReaderArray<Double_t> photon_hoe          = {fReader, "photon_hoe"};
    TTreeReaderArray<Double_t> photon_sieie        = {fReader, "photon_sieie"};
    TTreeReaderArray<Double_t> photon_sieie2       = {fReader, "photon_sieie2"};
    TTreeReaderArray<Double_t> photon_chiso        = {fReader, "photon_chiso"};
    TTreeReaderArray<Double_t> photon_nhiso        = {fReader, "photon_nhiso"};
    TTreeReaderArray<Double_t> photon_phoiso       = {fReader, "photon_phoiso"};
    TTreeReaderArray<Int_t>    photon_isprompt     = {fReader, "photon_isprompt"};
    TTreeReaderArray<Double_t> photon_drla         = {fReader, "photon_drla"};
    TTreeReaderArray<Double_t> photon_mla          = {fReader, "photon_mla"};
    TTreeReaderArray<Double_t> photonsc_eta        = {fReader, "photonsc_eta"};
    TTreeReaderArray<Double_t> photonsc_phi        = {fReader, "photonsc_phi"};
    TTreeReaderValue<Double_t> ptlep1              = {fReader, "ptlep1"};
    TTreeReaderValue<Double_t> etalep1             = {fReader, "etalep1"};
    TTreeReaderValue<Double_t> philep1             = {fReader, "philep1"};
    TTreeReaderValue<Int_t>    isprompt            = {fReader, "isprompt"};
    TTreeReaderValue<Int_t>    ispromptLep         = {fReader, "ispromptLep"};
    TTreeReaderValue<Double_t> MET_et              = {fReader, "MET_et"};
    TTreeReaderValue<Double_t> MET_phi             = {fReader, "MET_phi"};
    TTreeReaderValue<Int_t>    HLT_Ele1            = {fReader, "HLT_Ele1"};
    TTreeReaderValue<Int_t>    HLT_Ele2            = {fReader, "HLT_Ele2"};
    TTreeReaderValue<Int_t>    HLT_Mu1             = {fReader, "HLT_Mu1"};
    TTreeReaderValue<Int_t>    HLT_Mu2             = {fReader, "HLT_Mu2"};
    TTreeReaderValue<Int_t>    HLT_Mu3             = {fReader, "HLT_Mu3"};
    TTreeReaderValue<Double_t> lumiWeight          = {fReader, "lumiWeight"};
    TTreeReaderValue<Double_t> pileupWeight        = {fReader, "pileupWeight"};
    TTreeReaderValue<Int_t>    lep1_sign           = {fReader, "lep1_sign"};
    TTreeReaderValue<Int_t>    muon1_trackerLayers = {fReader, "muon1_trackerLayers"};
    TTreeReaderValue<Double_t> matchedgenMu1_pt    = {fReader, "matchedgenMu1_pt"};
    TTreeReaderValue<Double_t> photonsceta         = {fReader, "photonsceta"};
    TTreeReaderValue<Double_t> photonscphi         = {fReader, "photonscphi"};
    TTreeReaderValue<Double_t> Mla                 = {fReader, "Mla"};
    TTreeReaderValue<Bool_t>   photonhaspixelseed  = {fReader, "photonhaspixelseed"};
    TTreeReaderValue<Bool_t>   photonpasseleveto   = {fReader, "photonpasseleveto"};
    TTreeReaderValue<Double_t> photonet            = {fReader, "photonet"};
    TTreeReaderValue<Double_t> photoneta           = {fReader, "photoneta"};
    TTreeReaderValue<Double_t> photonphi           = {fReader, "photonphi"};
    TTreeReaderValue<Double_t> photone             = {fReader, "photone"};
    TTreeReaderValue<Double_t> photonsieie         = {fReader, "photonsieie"};
    TTreeReaderValue<Double_t> photonphoiso        = {fReader, "photonphoiso"};
    TTreeReaderValue<Double_t> photonchiso         = {fReader, "photonchiso"};
    TTreeReaderValue<Double_t> photonnhiso         = {fReader, "photonnhiso"};
    TTreeReaderValue<Double_t> drla                = {fReader, "drla"};
    TTreeReaderValue<Double_t> jet1pt              = {fReader, "jet1pt"};
    TTreeReaderValue<Double_t> jet1eta             = {fReader, "jet1eta"};
    TTreeReaderValue<Double_t> jet1phi             = {fReader, "jet1phi"};
    TTreeReaderValue<Double_t> jet1e               = {fReader, "jet1e"};
    TTreeReaderValue<Double_t> jet1icsv            = {fReader, "jet1icsv"};
    TTreeReaderValue<Double_t> jet2pt              = {fReader, "jet2pt"};
    TTreeReaderValue<Double_t> jet2eta             = {fReader, "jet2eta"};
    TTreeReaderValue<Double_t> jet2phi             = {fReader, "jet2phi"};
    TTreeReaderValue<Double_t> jet2e               = {fReader, "jet2e"};
    TTreeReaderValue<Double_t> jet2icsv            = {fReader, "jet2icsv"};
    TTreeReaderValue<Double_t> drj1a               = {fReader, "drj1a"};
    TTreeReaderValue<Double_t> drj2a               = {fReader, "drj2a"};
    TTreeReaderValue<Double_t> drj1l               = {fReader, "drj1l"};
    TTreeReaderValue<Double_t> drj2l               = {fReader, "drj2l"};
    TTreeReaderValue<Double_t> Mjj                 = {fReader, "Mjj"};
    TTreeReaderValue<Double_t> deltaeta            = {fReader, "deltaeta"};
    TTreeReaderValue<Double_t> zepp                = {fReader, "zepp"};
    TTreeReaderValue<Double_t> j1metPhi            = {fReader, "j1metPhi"};
    TTreeReaderValue<Double_t> j2metPhi            = {fReader, "j2metPhi"};
    TTreeReaderValue<Double_t> Dphiwajj            = {fReader, "Dphiwajj"};

    TFile*   opt;
    ofstream out;
    string   template_name;
    cout << "template_type:" << template_type << endl;
    if (template_type == 0) {
        template_name = "data";
    }
    else if (template_type == 1) {
        template_name = "fake";
    }
    else if (template_type == 2) {
        template_name = "true";
    }
    cout << "template_name:" << template_name << endl;

    for (int i = 0; i < 7; i++) {
        opt = TFile::Open(Form("%s_%s_%s_pt_%0.f_%0.f.root", template_name.c_str(), ismuon_.c_str(), isbarrel_.c_str(), ptlow[i], pthigh[i]), "recreate");
        out.open(Form("%s_template_%s_%s_pt_%0.f_%0.f.txt", template_name.c_str(), ismuon_.c_str(), isbarrel_.c_str(), ptlow[i], pthigh[i]), ios::out);

        Int_t sum = 0;
        out << "Pt range:" << ptlow[i] << "~" << pthigh[i] << "\n";
        out << "run \t lumi \t nevent \t Mla \n";

        Long64_t n = 0;

        Long64_t nentries = fReader.GetEntries(false);
        fReader.Restart();
        while (fReader.Next()) {
            if (n % 10000000 == 100) {
                //break;
                std::cout << "event\t " << n << "\t from \t" << nentries << std::endl;
            }
            n++;
            if (!((ismuon.Contains("MUON") && *lep == lepton_pid && *nlooseeles < nlooseeles_cut && *nloosemus < nloosemus_cut && (*ptlep1) > lepton_pt_cut && fabs(*etalep1) < 2.4 && *MET_et > 35 && *HLT_Mu2 == 1) || (ismuon.Contains("ELECTRON") && *lep == lepton_pid && *nlooseeles < nlooseeles_cut && *nloosemus < nloosemus_cut && (*ptlep1) > lepton_pt_cut && fabs(*etalep1) < 2.5 && *MET_et > 35 && *HLT_Ele2 == 1))) {
                continue;
            }

            Int_t    flag = -1;
            Double_t pt   = -1;
            for (int iphoton = 0; iphoton < 6; iphoton++) {
                if (template_type == 2 && photon_isprompt[iphoton] != 2) {
                    continue;
                }  // true template require photon is prompt
                //cout << "tagq1: is prompt" << endl;
                if (photon_mla[iphoton] > 0 && abs(photon_mla[iphoton] - 91.2) > mla_cut && photon_drla[iphoton] > 0.5 && photon_pt[iphoton] > ptlow[i] && photon_pt[iphoton] < pthigh[i] && photon_hoe[iphoton] < hoe_cut && (photon_nhiso[iphoton] < nhiso_cut[0] + nhiso_cut[1] * photon_pt[iphoton] + nhiso_cut[2] * photon_pt[iphoton] * photon_pt[iphoton]) && (photon_phoiso[iphoton] < phoiso_cut[0] + phoiso_cut[1] * photon_pt[iphoton]) && photon_chiso[iphoton] > chiso_cut_low && photon_chiso[iphoton] < chiso_cut_high && fabs(photonsc_eta[iphoton]) > photonsc_eta_cut_low && fabs(photonsc_eta[iphoton]) < photonsc_eta_cut_high && !photon_ppsv[iphoton]) {
                    //cout << "tag2: pass memdium" << endl;
                    if (pt < photon_pt[iphoton]) {
                        pt   = photon_pt[iphoton];
                        flag = iphoton;
                    }
                }
            }
            if (flag != -1) {
                // real weight
                if (template_type == 0) {
                    real_wgt = (*lumiWeight) * (*pileupWeight);
                }
                else if (template_type == 1) {
                    real_wgt = (*lumiWeight) * (*pileupWeight);
                }
                else if (template_type == 2) {
                    real_wgt = (*scalef) * (*lumiWeight) * (*pileupWeight);
                }
                out << *run << "\t" << *ls << "\t" << *nevent << "\t" << photon_mla[flag] << "\n";
                histo->Fill(photon_sieie[flag], real_wgt);
                hMla->Fill(photon_mla[flag], real_wgt);
                sum++;
            }
        }
        opt->cd();
        histo->Write();
        hMla->Write();
        opt->Write();
        opt->Close();
        out << "total entries:" << nentries << "\t total count:" << sum << "\n";
        out.close();
        histo->Reset();
        hMla->Reset();
    }
}
int main(int argc, char** argv) {
    cout << "DOU DOU" << endl;
    string ismuon        = argv[1];
    string isbarrel      = argv[2];
    int    template_type = atoi(argv[3]);
    std::cout << "channel:" << ismuon << "\t region:" << isbarrel << std::endl;
    generate_template(ismuon, isbarrel, template_type);
    return 0;
}
