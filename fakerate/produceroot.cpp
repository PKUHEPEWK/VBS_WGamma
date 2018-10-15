#include "TCanvas.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TTree.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

Double_t ptlow[8]  = {25, 30, 40, 50, 70, 100, 135};
Double_t pthigh[8] = {30, 40, 50, 70, 100, 135, 400};

void slectree(TTree* t1, Int_t isprom, Double_t ptlow, Double_t pthigh) {
    TTree* t;
    t = t1;
    Int_t    lep;
    Int_t    nlooseeles;
    Int_t    nloosemus;
    Double_t mtVlepJECnew;
    Double_t massVlep;
    Double_t ptlep1;
    Double_t ptlep2;
    Double_t etalep1;
    Double_t etalep2;
    Double_t MET_et;
    Int_t    photon_isprompt[6];
    Double_t photon_drla[6];
    Double_t photon_drla2[6];
    Double_t photon_hoe[6];
    Double_t photon_nhiso[6];
    Double_t photon_phoiso[6];
    Double_t photon_chiso[6];
    Double_t photon_sieie[6];
    Double_t photon_pt[6];
    Double_t photon_eta[6];
    Double_t scalef;
    Double_t lumiWeight;
    Double_t pileupWeight;

    t->SetBranchAddress("lumiWeight", &lumiWeight);
    t->SetBranchAddress("pileupWeight", &pileupWeight);
    t->SetBranchAddress("scalef", &scalef);
    t->SetBranchAddress("lep", &lep);
    t->SetBranchAddress("nlooseeles", &nlooseeles);
    t->SetBranchAddress("nloosemus", &nloosemus);
    t->SetBranchAddress("mtVlepJECnew", &mtVlepJECnew);
    t->SetBranchAddress("ptlep1", &ptlep1);
    //t->SetBranchAddress("ptlep2",&ptlep2);
    t->SetBranchAddress("etalep1", &etalep1);
    t->SetBranchAddress("MET_et", &MET_et);
    //t->SetBranchAddress("etalep2",&etalep2);
    t->SetBranchAddress("photon_isprompt", photon_isprompt);
    t->SetBranchAddress("photon_drla", photon_drla);
    //t->SetBranchAddress("photon_drla2",photon_drla2);
    t->SetBranchAddress("photon_hoe", photon_hoe);
    t->SetBranchAddress("photon_nhiso", photon_nhiso);
    t->SetBranchAddress("photon_phoiso", photon_phoiso);
    t->SetBranchAddress("photon_chiso", photon_chiso);
    t->SetBranchAddress("photon_sieie", photon_sieie);
    t->SetBranchAddress("photon_pt", photon_pt);
    t->SetBranchAddress("photon_eta", photon_eta);
    //t->SetBranchAddress("massVlep",&massVlep);

    Double_t sieie_med;
    Double_t chiso_med;
    TFile*   opt;
    if (isprom == 0) {
        opt = new TFile(Form("wa_%0.f_%0.f_true.root", ptlow, pthigh), "recreate");
    }
    if (isprom == 1) {
        opt = new TFile(Form("wajet_%0.f_%0.f_fake.root", ptlow, pthigh), "recreate");
    }
    if (isprom == 2) {
        opt = new TFile(Form("wajet_%0.f_%0.f_data.root", ptlow, pthigh), "recreate");
    }
    TTree* medtree = new TTree("medtree", "medium_id");
    medtree->Branch("sieie_med", &sieie_med, "sieie_med/D");
    medtree->Branch("chiso_med", &chiso_med, "chiso_med/D");
    medtree->Branch("scalef", &scalef, "scalef/D");

    Int_t    nBins = 100;
    Double_t bins[101];
    for (Int_t i = 0; i < 101; i++) {
        bins[i] = 0.0002 + 0.0002 * i;
    }
    TH1D* histo = new TH1D("histo", "histo", nBins, bins);

    bool     wjet;
    bool     photon_cut;
    bool     medium;
    bool     loose;
    bool     tmp[3];
    bool     Leading_photon[6], medium_cut[6];
    Double_t fakerate = 0., truerate = 0., datarate = 0.;
    //bool loose5;
    Double_t pho_pt[3];
    Int_t    flag[3];
    Double_t total[3] = {0};
    Long64_t nentries = t->GetEntries();
    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        t->GetEntry(jentry);
        pho_pt[0] = 0.;
        pho_pt[1] = 0.;
        pho_pt[2] = 0.;
        flag[0]   = 100;
        flag[1]   = 100;
        flag[2]   = 100;
        for (int j = 0; j < 6; j++) {
            /*Zjets[j] = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110;
      Leading_photon[j]= photon_drla[j]>0.7 && photon_drla2[j]>0.7&&photon_pt[j]<pthigh &&photon_pt[j]>ptlow;
      medium_cut[j]= photon_hoe[j]<0.0396  && photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
      tmp[0]=(photon_isprompt[j] == 1);
      tmp[1]=(photon_isprompt[j] != 1);
      tmp[2]=true;*/
            //wjet   = (lep == 11 && nlooseeles < 2 && nloosemus == 0 && mtVlepJECnew > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && MET_et > 30); // for elec channel
            wjet   = (lep == 13 && nlooseeles == 0 && nloosemus < 2 && mtVlepJECnew > 30 && ptlep1 > 25 && fabs(etalep1) < 2.4 && MET_et > 20);  // for muon channel
            tmp[0] = (photon_isprompt[j] == 2);
            //tmp[1]=(photon_isprompt[j] != 1);
            tmp[1]     = true;
            tmp[2]     = true;
            photon_cut = (photon_drla[j] > 0.7 && photon_pt[j] > ptlow && photon_pt[j] < pthigh);
            medium     = (fabs(photon_eta[j]) < 1.442 && photon_hoe[j] < 0.0396) && (photon_nhiso[j] < 2.725 + 0.0148 * photon_pt[j] + 0.000017 * photon_pt[j] * photon_pt[j]) && (photon_phoiso[j] < 2.571 + 0.0047 * photon_pt[j]);
            //medium = photon_hoe[j]<5*0.0597 && photon_nhiso[j]<5*(10.910+0.0148*photon_pt[j]+0.000017*photon_pt[j]*photon_pt[j]) && photon_phoiso[j]<5*(3.630+0.0047*photon_pt[j]);
            //medium = photon_hoe[j]<0.0597 && photon_nh(iso[j]<(10.910+0.0148*photon_pt[j]+0.000017*photon_pt[j]*photon_pt[j]) && photon_phoiso[j]<(3.630+0.0047*photon_pt[j]);
            //loose = photon_hoe[j] < 0.0597 && photon_nhiso[j] < (10.910 + 0.0148 * photon_pt[j] + 0.000017 * photon_pt[j] * photon_pt[j]) && photon_phoiso[j] < (3.630 + 0.0047 * photon_pt[j]);
            if (wjet && photon_cut && tmp[isprom]) {
                //cout<<"isprom"<<isprom<<"\t"<<"Zjets:"<<Zjets[j]<<"\t"<<"Leading_photon:"<<Leading_photon[j]<<"\t"<<"medium_cut:"<<medium_cut[j]<<endl;
                //if ( Zjets[j] && Leading_photon[j] && tmp[isprom]) {
                /*if (loose5) {
            total[0]++;
            if (pho_pt[0]<photon_pt[j]){
              pho_pt[0]=photon_pt[j];
              flag[0]=j;
            }
          }*/
                if (medium) {
                    if (pho_pt[0] < photon_pt[j]) {
                        pho_pt[0] = photon_pt[j];
                        flag[0]   = j;
                    }
                }
            }
            /*if ( j==5 && flag[0]!=100) {
        sieie_los5=photon_sieie[flag[0]];
        chiso_los5=photon_chiso[flag[0]];
        scalef0=scalef;
        los5tree->Fill();
      }*/
            if (j == 5 && flag[0] != 100) {
                sieie_med = photon_sieie[flag[0]];
                scalef    = scalef * lumiWeight * pileupWeight;
                medtree->Fill();
                if (isprom == 0 && chiso_med < 0.441) {
                    histo->Fill(sieie_med, scalef);
                }
                if (isprom == 1 && chiso_med > 4 && chiso_med < 10) {
                    histo->Fill(sieie_med, scalef);
                }
                if (isprom == 2 && chiso_med < 0.4410) {
                    histo->Fill(sieie_med, scalef);
                }
            }

            //cout<<sieie_los5<<"\t"<<sieie_los<<"\t"<<sieie_med<<endl;
        }
    }
    opt->Write();
}
int produceroot() {
    /*Tt *t = new Tt("treeDumper/PKUCandidates");
  t->Add("../treePKU*.root");*/
    TFile* f  = TFile::Open("preslecpreoutWA.root");
    TTree* t  = (TTree*)f->Get("demo");
    TFile* f1 = TFile::Open("prepreoutSMu.root");
    TTree* t1 = (TTree*)f1->Get("demo");
    for (int i = 0; i < 8; i++) {
        slectree(t, 0, ptlow[i], pthigh[i]);
        slectree(t1, 1, ptlow[i], pthigh[i]);
        slectree(t1, 2, ptlow[i], pthigh[i]);
    }
    return 0;
}
