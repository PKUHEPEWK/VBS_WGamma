// per compilare: g++ -Wall -o LOOP `root-config --cflags --glibs` -L $ROOTSYS/lib -lRooFit -lRooFitCore -lFoam -lHtml -lMinuit loop_plot.cc
// 
#include <Riostream.h>
#include <string>
#include <vector>

#include "CMSTDRStyle.h"
//#include "CMS_lumi.C"
#include "EDBRHistoMaker.h"
#include "EDBRHistoPlotter.h"
#include "TCanvas.h"
#include "TCollection.h"
#include "TError.h"
#include "TFile.h"
#include "THStack.h"
#include "TKey.h"
#include "TROOT.h"
#include <stdio.h>  /* printf, fgets */
#include <stdlib.h> /* atof */
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

using namespace std;

std::string              lumi_str;
double                   luminosity;
std::string              filepath;
std::vector<std::string> f_data;
std::vector<std::string> label_data;
std::vector<int>         color_data;
std::vector<std::string> f_mc;
std::vector<std::string> label_mc;
std::vector<int>         color_mc;
std::vector<std::string> f_mc_sig;
std::vector<std::string> label_mc_sig;
std::vector<int>         color_mc_sig;
TString                  scale_fakephoton;
TString                  scale_fakelepton;
TString                  scale_doublefake;
std::vector<std::string> histo_name;
std::vector<std::string> x_axis_title;
std::vector<std::string> y_axis_title;
std::vector<int>         bins;
std::vector<double>      low;
std::vector<double>      high;
std::vector<std::string> list_of_histos;
std::vector<TH1D*>       histo_of_data_files;
std::vector<TH1D*>       histo_of_mc_files;
std::vector<TH1D*>       histo_of_mc_sig_files;
Double_t                 xpositions[12] = {0.68, 0.68, 0.68, 0.68, 0.445, 0.445, 0.445, 0.445, 0.21, 0.21, 0.21, 0.21};
Double_t                 ypositions[12] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
Double_t                 xoffsetstart   = 0.1;
Double_t                 yoffsetstart   = 0.66;
Double_t                 xoffset        = 0.18;
Double_t                 yoffset        = 0.06;
TString                  region;
TString                  channel;

void     goodstyle();
void     set_parameters();
void     save_plots(string str);
void     make_stack(string str);
TLegend* draw_legend(double x1, double y1, TH1D* h1, TString label, TString option);
TLegend* draw_legend(double x1, double y1, TGraphAsymmErrors* h1, TString label, TString option);

int main(int argc, char** argv) {
//int loop_plot() {
    
    channel = argv[1];
    region  = argv[2];
    
    //channel = "muon";
    //region  = "barrel";
    
    cout << "channel:" << channel << "\t region:" << region << endl;
    goodstyle();
    set_parameters();
    for (auto str : f_data) {
        save_plots(str);
    }
    for (auto str : f_mc) {
        save_plots(str);
    }
    for (auto str : f_mc_sig) {
        save_plots(str);
    }
    // Open one of the histogram files just to get the list of histograms
    // produced, then loop over all the histograms inheriting
    // from TH1 contained in the file.
    TString onename = f_mc[0].c_str();
    onename.Remove(0, 3);
    TFile* oneFile = new TFile("histo_" + channel + region + onename);
    TIter  next(oneFile->GetListOfKeys());
    TKey*  key;
    while ((key = (TKey*)next())) {
        TClass* cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1"))
            continue;
        TH1*        hTMP  = (TH1*)key->ReadObj();
        std::string hName = hTMP->GetName();
        printf("Histogram found: %s\n", hName.c_str());
        //bool isMJJhisto=(hName.find("mJJ")!=std::string::npos);
        list_of_histos.push_back(hName);
        delete hTMP;
    }  //end while loop
    oneFile->Close();
    for (auto str : list_of_histos)
        make_stack(str);
//gObjectTable->Print();
return 0;
}

void goodstyle() {
    //##----------------------------------------------------------------------------
    //## Frame
    //##----------------------------------------------------------------------------
    gStyle->SetPadBorderMode(0);
    gStyle->SetOptStat(0);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadTopMargin(0.08);
    gStyle->SetPadBottomMargin(0.08);
    gStyle->SetPadRightMargin(0.03);
    gStyle->SetPadLeftMargin(0.10);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetAxisColor(1, "XYZ");
    gStyle->SetStripDecimals(kTRUE);
    gStyle->SetTickLength(0.03, "XYZ");
    gStyle->SetNdivisions(510, "XYZ");
    gStyle->SetTitleYOffset(1.25);
    gStyle->SetFrameFillStyle(0);
    gStyle->SetFrameFillColor(0);
    gStyle->SetFrameLineColor(1);
    gStyle->SetFrameLineStyle(0);
    gStyle->SetFrameLineWidth(2);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameBorderSize(10);
    gROOT->SetBatch(kTRUE);
}
void set_parameters() {
    std::cout << "****************** start setting parameters ******************" << std::endl;
    ifstream in("parameters_list.md");
    string   tmp;
    TString  tline;
    string   line;
    string   content;
    if (in) {
        while (getline(in, line)) {
            tline = line;
            if (tline.Contains("##")) {
                tmp = line;
            }
            else {
                stringstream sline(line);
                if (tmp == "## file path") {
                    sline >> filepath;
                }
                else if (tmp == "## luminosity") {
                    sline >> lumi_str;
                    luminosity = atof(lumi_str.c_str());
                }
                else if (tmp == "## data_sample color") {
                    sline >> content;
                    f_data.push_back(content);
                    sline >> content;
                    label_data.push_back(content);
                    sline >> content;
                    color_data.push_back(atoi(content.c_str()));
                }
                else if (tmp == "## background_mc_sample color") {
                    sline >> content;
                    f_mc.push_back(content);
                    sline >> content;
                    label_mc.push_back(content);
                    sline >> content;
                    color_mc.push_back(atoi(content.c_str()));
                }
                else if (tmp == "## signal_mc_sample color") {
                    sline >> content;
                    f_mc_sig.push_back(content);
                    sline >> content;
                    label_mc_sig.push_back(content);
                    sline >> content;
                    color_mc_sig.push_back(atoi(content.c_str()));
                }
                else if (tmp == "## scales_of_fakephoton_file") {
                    sline >> content;
                    scale_fakephoton = content;
                }
                else if (tmp == "## scales_of_fakelepton_file") {
                    sline >> content;
                    scale_fakelepton = content;
                }
                else if (tmp == "## scales_of_doublefake_file") {
                    sline >> content;
                    scale_doublefake = content;
                }
                else if (tmp == "## histogram_list x_axis_title y_axis_title bins low high") {
                    sline >> content;
                    histo_name.push_back(content);
                    cout << content << "\t";
                    sline >> content;
                    x_axis_title.push_back(content);
                    cout << content << "\t";
                    sline >> content;
                    y_axis_title.push_back(content);
                    cout << content << "\t";
                    sline >> content;
                    bins.push_back(atoi(content.c_str()));
                    cout << content << "\t";
                    sline >> content;
                    low.push_back(atof(content.c_str()));
                    cout << content << "\t";
                    sline >> content;
                    high.push_back(atof(content.c_str()));
                    cout << content << endl;
                }
            }
        }
    }
    std::cout << "****************** end of setting parameters ******************" << std::endl;
}

void save_plots(string str) {
    std::cout << "****************** start saving plots of " << str << " ******************" << std::endl;
    TString fname = str;
    int     type  = 0;
    TString data_sample;
    TString fake_lepton;
    if (channel.Contains("muon")) {
        data_sample = "outSMu";
        fake_lepton = "fakemuon";
    }
    else {
        data_sample = "outSEle";
        fake_lepton = "fakeelectron";
    }
    if (fname.Contains(data_sample)) {
        type = 0;
    }
    else if (fname.Contains("fakephoton")) {
        type = 2;
    }
    else if (fname.Contains(fake_lepton)) {
        type = 3;
    }
    else if (fname.Contains("doublefake")) {
        type = 4;
    }
    else if (fname.Contains("electronfakephoton")) {
        type = 5;
    }
    else {
        type = 1;
    }
    TFile* ipt = TFile::Open(filepath.c_str() + fname);
    fname.Remove(0, 3);
    // create output file
    TFile* opt = TFile::Open("histo_" + channel + region + fname, "RECREATE");
    // create histograms in output file
    std::map<std::string, TH1D> theHistograms;
    TString                     buffer;
    char                        buffer2[256];
    for (size_t i = 0; i < histo_name.size(); i++) {
        buffer = histo_name[i];
        buffer = buffer + channel + region;
        sprintf(buffer2, "%s;%s;%s;", histo_name[i].c_str(), x_axis_title[i].c_str(), y_axis_title[i].c_str());
        TH1D tmp_histo(buffer, buffer2, bins[i], low[i], high[i]);
        theHistograms[histo_name[i]] = tmp_histo;
    }
    // fake photon weight
    TFile* ipt_plj_wgt = TFile::Open(filepath.c_str() + channel + "_" + region + "_" + scale_fakephoton);
    TH1D*  plj_wgt     = (TH1D*)ipt_plj_wgt->Get("histo");
    // fake lepton weight
    TString tmp_fake_muon_wgt="fake_muon.root";
    TFile* ipt_fakelepton_wgt = TFile::Open(filepath.c_str()+tmp_fake_muon_wgt);
    TH2D*  fakelepton_wgt     = (TH2D*)ipt_fakelepton_wgt->Get("fake_muon_weight");
    // double fake weight
    //TFile* ipt_difake_wgt = TFile::Open(filepath.c_str() + channel + "_" + region + "_" + scale_doublefake);
    //TH1D*  difake_wgt     = (TH1D*)ipt_difake_wgt->Get("histo");

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

    Long64_t maxEntries = fReader.GetEntries(false);
    std::cout << "Number of events to be analyzed : " << maxEntries << std::endl;
    int i = 0;
    while (fReader.Next()) {
        if (i % 10000 == 1000) {
            //break;
            std::cout << "Analyzing event " << i << "\r" << std::flush;
        }
        i++;
        bool commonselec = (!(*photonhaspixelseed) && *lep == 13 && *nlooseeles < 1 && *nloosemus < 2 && *HLT_Mu2 == 1 && *mtVlepJECnew > 35 && *ptlep1 > 25 && fabs(*etalep1) < 2.4 && *drla > 0.5 && *MET_et > 30 && *jet1pt > 40 && *jet2pt > 30 && fabs(*jet1eta) < 4.7 && fabs(*jet2eta) < 4.7 && *Mjj > 200 && *Mjj < 400 && *drj1a > 0.5 && *drj2a > 0.5 && *drj1l > 0.5 && *drj2l > 0.5 && *j1metPhi > 0.4 && *j2metPhi > 0.4 && *jet1icsv < 0.8484 && *jet2icsv < 0.8484 && *deltaeta > 0.5 && *photonet > 25 && *photonet < 400);
        bool which_region;
        if (region.Contains("barrel"))
            which_region = (fabs(*photonsceta) < 1.4442);
        if (region.Contains("endcap"))
            which_region = (fabs(*photonsceta) > 1.566 && fabs(*photonsceta) < 2.5);
        double actualWeight;
        if (type == 0 && commonselec && which_region) {
            actualWeight = (*lumiWeight) * (*pileupWeight);
        }
        else if (type == 1 && commonselec && *isprompt == 2 && *ispromptLep == 1 && which_region) {
            actualWeight = (*scalef) * (*lumiWeight) * (*pileupWeight) * luminosity;
        }
        else if (type == 2 && commonselec && which_region) {
            actualWeight = plj_wgt->GetBinContent(plj_wgt->GetXaxis()->FindFixBin(*photonet));
        }
        else if (type == 3 && commonselec && which_region) {
            //actualWeight = 1.88489;
            Int_t xbin1=fakelepton_wgt->GetXaxis()->FindFixBin(fabs(*etalep1));
            Int_t ybin1=fakelepton_wgt->GetYaxis()->FindFixBin(*ptlep1);
            actualWeight = fakelepton_wgt->GetBinContent(xbin1,ybin1);
        }
        else if (type == 4 && commonselec && which_region) {
            //actualWeight = difake_wgt->GetBinContent(difake_wgt->GetXaxis()->FindFixBin(*photonet));
            Int_t xbin2=fakelepton_wgt->GetXaxis()->FindFixBin(fabs(*etalep1));
            Int_t ybin2=fakelepton_wgt->GetYaxis()->FindFixBin(*ptlep1);
            actualWeight = (plj_wgt->GetBinContent(plj_wgt->GetXaxis()->FindFixBin(*photonet)))*(fakelepton_wgt->GetBinContent(xbin2,ybin2));
        }
        else if (type == 5 && commonselec && *isprompt == 3 && *ispromptLep == 1) {
            actualWeight = (*scalef) * (*lumiWeight) * (*pileupWeight) * luminosity;
        }
        else
            continue;
        (theHistograms["nVtx"]).Fill(*nVtx, actualWeight);
        (theHistograms["ptlep1"]).Fill(*ptlep1, actualWeight);
        (theHistograms["etalep1"]).Fill(*etalep1, actualWeight);
        (theHistograms["mtVlepJECnew"]).Fill(*mtVlepJECnew, actualWeight);
        (theHistograms["ptVlepJEC"]).Fill(*ptVlepJEC, actualWeight);
        (theHistograms["photonet"]).Fill(*photonet, actualWeight);
        (theHistograms["photoneta"]).Fill(*photonsceta, actualWeight);
        (theHistograms["jet1pt"]).Fill(*jet1pt, actualWeight);
        (theHistograms["jet1eta"]).Fill(*jet1eta, actualWeight);
        (theHistograms["jet2pt"]).Fill(*jet2pt, actualWeight);
        (theHistograms["jet2eta"]).Fill(*jet2eta, actualWeight);
        (theHistograms["Mjj"]).Fill(*Mjj, actualWeight);
        (theHistograms["zepp"]).Fill(*zepp, actualWeight);
        (theHistograms["deltaeta"]).Fill(*deltaeta, actualWeight);
        (theHistograms["MET_et"]).Fill(*MET_et, actualWeight);
        (theHistograms["Dphiwajj"]).Fill(*Dphiwajj, actualWeight);
        (theHistograms["Mla"]).Fill(*Mla, actualWeight);
        (theHistograms["photonsceta"]).Fill(*photonsceta, actualWeight);
    }
    opt->cd();
    /*(theHistograms["nVtx"]).Write();
    (theHistograms["ptlep1"]).Write();
    (theHistograms["etalep1"]).Write();
    (theHistograms["mtVlepJECnew"]).Write();
    (theHistograms["ptVlepJEC"]).Write();
    (theHistograms["photonet"]).Write();
    (theHistograms["photoneta"]).Write();
    (theHistograms["jet1pt"]).Write();
    (theHistograms["jet1eta"]).Write();
    (theHistograms["jet2pt"]).Write();
    (theHistograms["jet2eta"]).Write();
    (theHistograms["Mjj"]).Write();
    (theHistograms["zepp"]).Write();
    (theHistograms["deltaeta"]).Write();
    (theHistograms["MET_et"]).Write();
    (theHistograms["Dphiwajj"]).Write();
    (theHistograms["Mla"]).Write();
    (theHistograms["photonsceta"]).Write();*/
    opt->Write();
    opt->Close();
    ipt_plj_wgt->Close();
    //ipt_fakelepton_wgt->Close();
    //ipt_difake_wgt->Close();
    delete opt;
    //delete plj_wgt;
    //delete difake_wgt;
    //delete ipt_difake_wgt;
    //delete ipt_plj_wgt; 
    std::cout << "****************** end of saving plots of " << str << " ******************" << std::endl;
}

void make_stack(string str_tmp) {
    std::cout << "****************** start making stack of " << str_tmp << " ******************" << std::endl;
    histo_of_data_files.clear();
    histo_of_mc_files.clear();
    histo_of_mc_sig_files.clear();
    TString  hname = str_tmp;
    TString  fname;
    TFile*   ftmp;
    TH1D*    htmp;
    TH1D*    hdata;
    TH1D*    hsum_mc;
    THStack* hs = new THStack("hs", "");

    TCanvas* cv     = new TCanvas("cv_" + hname, "cv_" + hname, 400, 400);
    TPad*    fPads1 = new TPad("pad1", "", 0.00, 0.25, 1.00, 1.00);
    TPad*    fPads2 = new TPad("pad2", "", 0.00, 0.00, 1.00, 0.25);
    fPads1->SetFillColor(0);
    fPads1->SetLineColor(0);
    fPads2->SetFillColor(0);
    fPads2->SetLineColor(0);
    fPads1->SetBottomMargin(0);
    fPads2->SetTopMargin(0);
    fPads2->SetBottomMargin(0.4);
    fPads1->Draw();
    fPads2->Draw();
    fPads1->cd();
    for (int i = 0; i < f_data.size(); i++) {
        fname = f_data.at(i);
        cout << "data name:" << fname << endl;
        fname.Remove(0, 3);
        ftmp = TFile::Open("histo_" + channel + region + fname);
        htmp = (TH1D*)ftmp->Get(hname);
        histo_of_data_files.push_back(htmp);
    }
    hdata = (TH1D*)(histo_of_data_files.at(0)->Clone("masterdata"));
    hdata->Reset();
    // Make a histogram just for the sum
    for (size_t i = 0; i < histo_of_data_files.size(); i++) {
        histo_of_data_files.at(i)->SetLineColor(0);
        histo_of_data_files.at(i)->SetLineWidth(0);
        hdata->Add(histo_of_data_files.at(i));
    }
    hdata->SetMarkerStyle(8);
    hdata->SetMarkerSize(0.8);
    hdata->SetLineWidth(3);
    hdata->SetLineColor(kBlack);

    TString hiso_name_tmp = histo_of_data_files.at(0)->GetXaxis()->GetTitle();
    int     ifakephoton   = 0;
    int     ifakemuon     = 0;
    int     idoublefake   = 0;
    for (int i = 0; i < f_mc.size(); i++) {
        fname = f_mc.at(i);
        if (fname.Contains("fakephoton")) {
            ifakephoton = i;
        }
        else if (fname.Contains("fakemuon")) {
            ifakemuon = i;
        }
        else if (fname.Contains("doublefake")) {
            idoublefake = i;
        }
        fname.Remove(0, 3);
        ftmp = TFile::Open("histo_" + channel + region + fname);
        htmp = (TH1D*)ftmp->Get(hname);
        //if (!(fname.Contains("fakephoton") || fname.Contains("fakemuon") || fname.Contains("doublefake"))) {
        //    htmp->Scale(luminosity);
        //}
        histo_of_mc_files.push_back(htmp);
    }
    histo_of_mc_files.at(ifakephoton)->Add(histo_of_mc_files.at(idoublefake), -1);
    histo_of_mc_files.at(ifakemuon)->Add(histo_of_mc_files.at(idoublefake), -1);

    for (int i = 0; i < f_mc_sig.size(); i++) {
        fname = f_mc_sig.at(i);
        fname.Remove(0, 3);
        ftmp = TFile::Open("histo_" + channel + region + fname);
        htmp = (TH1D*)ftmp->Get(hname);
        histo_of_mc_sig_files.push_back(htmp);
    }
    // Make a histogram just for the sum
    hsum_mc = (TH1D*)(histo_of_mc_files.at(0)->Clone("masterMC"));
    hsum_mc->Reset();
    for (size_t i = 0; i < histo_of_mc_files.size(); i++) {
        histo_of_mc_files.at(i)->SetFillColor(color_mc.at(i));
        histo_of_mc_files.at(i)->SetLineColor(0);
        histo_of_mc_files.at(i)->SetLineWidth(0);
        hsum_mc->Add(histo_of_mc_files.at(i));
        hs->Add(histo_of_mc_files.at(i));
    }
    for (size_t i = 0; i < histo_of_mc_sig_files.size(); i++) {
        histo_of_mc_sig_files.at(i)->SetFillColor(color_mc_sig.at(i));
        histo_of_mc_sig_files.at(i)->SetLineColor(0);
        histo_of_mc_sig_files.at(i)->SetLineWidth(0);
        hsum_mc->Add(histo_of_mc_sig_files.at(i));
        hs->Add(histo_of_mc_sig_files.at(i));
    }
    hsum_mc->SetFillStyle(0);
    hs->Draw("HIST");
    hs->GetYaxis()->SetTitle("Events/bin");
    hs->GetYaxis()->SetTitleSize(0.05);
    hs->GetYaxis()->SetTitleOffset(0.95);
    double maximumMC       = 1.5 * hsum_mc->GetMaximum();
    double maximumDATA     = 1.5 * hdata->GetMaximum();
    double maximumForStack = (maximumMC > maximumDATA ? maximumMC : maximumDATA);

    hs->SetMaximum(maximumForStack);
    // Some hacks for better aestetics
    // Extra vertical space in eta plots
    hs->SetMinimum(0.01);

    hdata->GetXaxis()->SetTitle(hiso_name_tmp);
    hdata->GetYaxis()->SetTitle("Events/bin");
    hdata->Draw("SAME APE");

    // For the legend, we have to tokenize the name "histos_XXX.root"
    TLegend* leg;
    int      j = -1;

    for (size_t i = 0; i < histo_of_mc_files.size(); i++) {
        j++;
        leg = draw_legend(xpositions[j], ypositions[j] * yoffset, histo_of_mc_files.at(i), label_mc.at(i), "f");
        leg->Draw("same");
    }

    for (size_t i = 0; i < histo_of_mc_sig_files.size(); i++) {
        j++;
        leg = draw_legend(xpositions[j], ypositions[j] * yoffset, histo_of_mc_sig_files.at(i), label_mc_sig.at(i), "f");
        leg->Draw("same");
    }

    leg = draw_legend(xpositions[11], ypositions[11] * yoffset, hdata, label_data.at(0), "lp");
    leg->Draw("same");

    // ratio plot
    int    binnumber = hsum_mc->GetNbinsX();
    double nsigma_x[binnumber], nsigma_y[binnumber];
    double Data[binnumber], Bkg[binnumber], eData[binnumber], eBkg[binnumber], x[binnumber], y[binnumber], halfwidth[binnumber], ex[binnumber], ey[binnumber], sigma[binnumber], ey_bkg[binnumber];

    for (int ibin = 0; ibin != binnumber; ++ibin) {
        Data[ibin]      = hdata->GetBinContent(ibin + 1);
        Bkg[ibin]       = hsum_mc->GetBinContent(ibin + 1);
        eData[ibin]     = hdata->GetBinError(ibin + 1);
        eBkg[ibin]      = hsum_mc->GetBinError(ibin + 1);
        x[ibin]         = hdata->GetBinCenter(ibin + 1);
        y[ibin]         = 1;
        halfwidth[ibin] = hsum_mc->GetBinWidth(ibin + 1) / 2;

        double diff = Data[ibin] - Bkg[ibin];
        sigma[ibin] = sqrt((eData[ibin] * eData[ibin]) + (eBkg[ibin] * eBkg[ibin]));

        //if (Bkg[ibin] != 0.0 && Data[ibin] != 0.0) {
        nsigma_x[ibin] = x[ibin];
        nsigma_y[ibin] = Data[ibin] / Bkg[ibin];  //diff / sigma;
        ex[ibin]       = 0;
        ey[ibin]       = sqrt(eData[ibin] * eData[ibin] / (Bkg[ibin] * Bkg[ibin]) + Data[ibin] * Data[ibin] * eBkg[ibin] * eBkg[ibin] / (Bkg[ibin] * Bkg[ibin] * Bkg[ibin] * Bkg[ibin]));
        ey_bkg[ibin]   = sqrt(2) * fabs(eBkg[ibin] / Bkg[ibin]);
        /*  }
        else {
            nsigma_x[ibin] = x[ibin];
            nsigma_y[ibin] = +99999999;
            ex[ibin]       = 0;
            ey[ibin]       = +99999999;
        }*/
    }
    fPads1->cd();
    double xlow  = x[0] - halfwidth[0];
    double xhigh = x[binnumber - 1] + halfwidth[binnumber - 1];

    TGraphAsymmErrors* gr = new TGraphAsymmErrors(binnumber, x, Bkg, halfwidth, halfwidth, eBkg, eBkg);
    gr->SetFillStyle(3005);
    gr->Draw("2same");
    leg = draw_legend(xpositions[10], ypositions[10] * yoffset, gr, "MC unc", "f");
    leg->Draw("same");
    fPads1->Update();

    fPads2->cd();
    //    fPads2->SetGridx();
    fPads2->SetGridy();
    //    if (nsigma_x.GetNoElements() != 0) {
    //TGraph *nsigmaGraph = new TGraph(nsigma_x, nsigma_y);
    // MC/MC
    TGraphErrors* nsigmaGraph_bkg = new TGraphErrors(binnumber, x, y, halfwidth, ey_bkg);
    nsigmaGraph_bkg->SetTitle("");
    double thisYmin = 0.51;  //-5
    double thisYmax = 1.49;  //5
    nsigmaGraph_bkg->GetYaxis()->SetRangeUser(thisYmin, thisYmax);
    nsigmaGraph_bkg->GetYaxis()->SetTitle("Data/MC");  //("(Data-Bkg)/#sigma");
    nsigmaGraph_bkg->GetYaxis()->CenterTitle();
    nsigmaGraph_bkg->GetYaxis()->SetTitleSize(0.15);
    nsigmaGraph_bkg->GetYaxis()->SetLabelSize(0.07);
    //nsigmaGraph_bkg->GetYaxis()->SetTitleOffset(0.5);
    nsigmaGraph_bkg->GetXaxis()->SetTitle(hiso_name_tmp);
    nsigmaGraph_bkg->GetXaxis()->SetTitleSize(0.1);
    //nsigmaGraph_bkg->GetXaxis()->SetTitleOffset(0.20);
    nsigmaGraph_bkg->GetXaxis()->SetLimits(hsum_mc->GetXaxis()->GetXmin(), hsum_mc->GetXaxis()->GetXmax());
    //nsigmaGraph->GetXaxis()->SetRangeUser(hsum_mc->GetXaxis()->GetXmin(), hsum_mc->GetXaxis()->GetXmax());
    nsigmaGraph_bkg->GetXaxis()->SetLabelSize(0.10);
    nsigmaGraph_bkg->SetFillColor(20);
    //nsigmaGraph_bkg->SetMarkerSize(0.8);
    nsigmaGraph_bkg->Draw("a2");
    // Data/MC
    TGraphErrors* nsigmaGraph = new TGraphErrors(binnumber, nsigma_x, nsigma_y, ex, ey);
    nsigmaGraph->SetTitle("");
    nsigmaGraph->GetYaxis()->SetRangeUser(thisYmin, thisYmax);
    nsigmaGraph->GetYaxis()->SetTitle("Data/MC");  //("(Data-Bkg)/#sigma");
    nsigmaGraph->GetYaxis()->CenterTitle();
    nsigmaGraph->GetYaxis()->SetTitleSize(0.15);
    nsigmaGraph->GetYaxis()->SetLabelSize(0.07);
    nsigmaGraph_bkg->GetYaxis()->SetTitleOffset(0.23);
    nsigmaGraph->GetXaxis()->SetTitle(hiso_name_tmp);
    nsigmaGraph->GetXaxis()->SetTitleSize(0.13);
    nsigmaGraph->GetXaxis()->SetLimits(hsum_mc->GetXaxis()->GetXmin(), hsum_mc->GetXaxis()->GetXmax());
    //nsigmaGraph->GetXaxis()->SetRangeUser(hsum_mc->GetXaxis()->GetXmin(), hsum_mc->GetXaxis()->GetXmax());
    nsigmaGraph->GetXaxis()->SetLabelSize(0.10);
    nsigmaGraph->GetXaxis()->SetTitleOffset(1.20);
    //nsigmaGraph->SetFillColor(0);
    nsigmaGraph->SetMarkerStyle(kFullCircle);
    nsigmaGraph->SetMarkerColor(kBlack);
    nsigmaGraph->SetLineColor(kBlack);
    //nsigmaGraph->SetLineWidth(3);
    nsigmaGraph->SetMarkerSize(0.8);
    nsigmaGraph->Draw("pe same");
    TLine* lineAtZero = new TLine(hsum_mc->GetXaxis()->GetXmin(), 1, hsum_mc->GetXaxis()->GetXmax(), 1);
    lineAtZero->SetLineColor(kBlack);
    lineAtZero->SetLineWidth(2);
    lineAtZero->Draw();
    CMS_lumi(fPads1, 4, 0, lumi_str.c_str());

    // Save the picture
    cv->SetLogy(false);
    cv->SaveAs("can_" + channel + "_" + region + "_" + str_tmp.c_str() + ".pdf");

    fPads1->cd();
    fPads1->SetLogy(true);
    //-- resize y axis --
    hs->SetMaximum(100 * maximumForStack);
    //
    cv->SetLogy(true);
    cv->Update();
    cv->Modified(true);
    cv->Draw();
    // cv->SaveAs(buffer);
    cv->SaveAs("LOG_can_" + channel + "_" + region + "_" + str_tmp.c_str() + ".pdf");
     
    // delete all
    delete htmp;
    delete hdata;
    delete hsum_mc;
    delete hs;

    //delete cv;
    //delete fPads1;
    //delete fPads2;
    //delete lineAtZero;
    //delete nsigmaGraph;
    //delete nsigmaGraph_bkg; 
    
    //ftmp->Close();

    std::cout << "****************** end of making stack of " << str_tmp << " ******************" << std::endl;
}
TLegend* draw_legend(double x1, double y1, TH1D* h1, TString label, TString option) {
    TLegend* legend = new TLegend(x1 + xoffsetstart, y1 + yoffsetstart, x1 + xoffsetstart + xoffset, y1 + yoffsetstart + yoffset);

    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->SetFillColor(0);
    legend->SetTextAlign(12);
    legend->SetTextFont(42);
    legend->SetTextSize(0.040);

    legend->AddEntry(h1, label, option);
    return legend;
}
TLegend* draw_legend(double x1, double y1, TGraphAsymmErrors* h1, TString label, TString option) {
    TLegend* legend = new TLegend(x1 + xoffsetstart, y1 + yoffsetstart, x1 + xoffsetstart + xoffset, y1 + yoffsetstart + yoffset);

    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->SetFillColor(0);
    legend->SetTextAlign(12);
    legend->SetTextFont(42);
    legend->SetTextSize(0.040);

    legend->AddEntry(h1, label, option);

    return legend;
}
