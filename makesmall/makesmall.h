//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep 27 23:14:27 2018 by ROOT version 6.06/01
// from TTree PKUCandidates/PKU Candidates
// found on file: treePKU.root
//////////////////////////////////////////////////////////

#ifndef makesmall_h
#define makesmall_h

#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TROOT.h>
#include <TStyle.h>
#include <iostream>
// Header file for the classes stored in the TTree if any.
using namespace std;

class makesmall {
private:
    TFile* fout;
    TTree* ExTree;
    double scalef;
    double scale_btag_up;
    double scale_btag_down;
    bool   use_f;  // use this to save fakephoton sample

public:
    TTree* fChain;    //!pointer to the analyzed TTree or TChain
    Int_t  fCurrent;  //!current Tree number in a TChain

    // Fixed size dimensions of array or collections stored in the TTree if any.
    const Int_t kMaxpassFilter_HBHE             = 1;
    const Int_t kMaxpassFilter_HBHEIso          = 1;
    const Int_t kMaxpassFilter_globalTightHalo  = 1;
    const Int_t kMaxpassFilter_ECALDeadCell     = 1;
    const Int_t kMaxpassFilter_GoodVtx          = 1;
    const Int_t kMaxpassFilter_EEBadSc          = 1;
    const Int_t kMaxpassFilter_badMuon          = 1;
    const Int_t kMaxpassFilter_badChargedHadron = 1;
    Double_t    theweight;
    // Declaration of leaf types
    Float_t  rawPt;
    Int_t    nevent;
    Int_t    run;
    Int_t    ls;
    Int_t    nVtx;
    Double_t theWeight;
    Double_t nump;
    Double_t numm;
    Double_t npT;
    Int_t    lep;
    Double_t ptVlep;
    Double_t ptVlepJEC;
    Double_t yVlepJEC;
    Double_t phiVlepJEC;
    Double_t massVlepJEC;
    Double_t mtVlepJECnew;
    Double_t ptVlepJEC_new;
    Double_t yVlepJEC_new;
    Double_t phiVlepJEC_new;
    Double_t massVlepJEC_new;
    Double_t mtVlepJECnew_new;
    Double_t ptVlepJEC_JEC_up;
    Double_t yVlepJEC_JEC_up;
    Double_t phiVlepJEC_JEC_up;
    Double_t massVlepJEC_JEC_up;
    Double_t mtVlepJECnew_JEC_up;
    Double_t ptVlepJEC_JEC_down;
    Double_t yVlepJEC_JEC_down;
    Double_t phiVlepJEC_JEC_down;
    Double_t massVlepJEC_JEC_down;
    Double_t mtVlepJECnew_JEC_down;
    Double_t ptVlepJEC_JER_up;
    Double_t yVlepJEC_JER_up;
    Double_t phiVlepJEC_JER_up;
    Double_t massVlepJEC_JER_up;
    Double_t mtVlepJECnew_JER_up;
    Double_t ptVlepJEC_JER_down;
    Double_t yVlepJEC_JER_down;
    Double_t phiVlepJEC_JER_down;
    Double_t massVlepJEC_JER_down;
    Double_t mtVlepJECnew_JER_down;
    Double_t Mla;
    Double_t Mla_f;
    Double_t Mva;
    Double_t Mva_f;
    Int_t    nlooseeles;
    Int_t    nloosemus;
    Double_t genjet_pt[6];
    Double_t genjet_eta[6];
    Double_t genjet_phi[6];
    Double_t genjet_e[6];
    Double_t photon_pt[6];
    Double_t photon_eta[6];
    Double_t photon_phi[6];
    Double_t photon_e[6];
    Double_t photonsc_eta[6];
    Double_t photonsc_phi[6];
    Bool_t   photon_pev[6];
    Bool_t   photon_pevnew[6];
    Bool_t   photon_ppsv[6];
    Double_t photon_hoe[6];
    Double_t photon_sieie[6];
    Double_t photon_sieie2[6];
    Double_t photon_chiso[6];
    Double_t photon_nhiso[6];
    Double_t photon_phoiso[6];
    Int_t    photon_isprompt[6];
    Double_t photon_drla[6];
    Double_t photon_mla[6];
    Bool_t   photonhaspixelseed;
    Bool_t   photonhaspixelseed_f;
    Bool_t   photonpasseleveto;
    Bool_t   photonpasseleveto_f;
    Double_t photonet;
    Double_t photonet_f;
    Double_t photoneta;
    Double_t photoneta_f;
    Double_t photonphi;
    Double_t photonphi_f;
    Double_t photone;
    Double_t photone_f;
    Double_t photonsceta;
    Double_t photonsceta_f;
    Double_t photonscphi;
    Double_t photonscphi_f;
    Int_t    iphoton;
    Int_t    iphoton_f;
    Double_t drla;
    Double_t drla_f;
    Int_t    isTrue;
    Int_t    isprompt;
    Int_t    ispromptLep;
    Int_t    ak4jet_hf[6];
    Int_t    ak4jet_pf[6];
    Int_t    jet1hf;
    Int_t    jet1pf;
    Int_t    jet2hf;
    Int_t    jet2pf;
    Int_t    jet1hf_f;
    Int_t    jet1pf_f;
    Int_t    jet2hf_f;
    Int_t    jet2pf_f;
    Double_t ak4jet_pt_old[6];
    Double_t ak4jet_pt_new[6];
    Double_t ak4jet_pt_JEC_up[6];
    Double_t ak4jet_pt_JEC_down[6];
    Double_t ak4jet_pt_JER_up[6];
    Double_t ak4jet_pt_JER_down[6];
    Double_t ak4jet_eta[6];
    Double_t ak4jet_phi[6];
    Double_t ak4jet_e_old[6];
    Double_t ak4jet_e_new[6];
    Double_t ak4jet_e_JEC_up[6];
    Double_t ak4jet_e_JEC_down[6];
    Double_t ak4jet_e_JER_up[6];
    Double_t ak4jet_e_JER_down[6];
    Double_t ak4jet_csv[6];
    Double_t ak4jet_icsv[6];
    Double_t jet1pt;
    Double_t jet1pt_new;
    Double_t jet1pt_JEC_up;
    Double_t jet1pt_JER_up;
    Double_t jet1pt_JEC_down;
    Double_t jet1pt_JER_down;
    Double_t jet1pt_f;
    Double_t jet1pt_new_f;
    Double_t jet1pt_JEC_up_f;
    Double_t jet1pt_JER_up_f;
    Double_t jet1pt_JEC_down_f;
    Double_t jet1pt_JER_down_f;
    Double_t jet1eta;
    Double_t jet1eta_new;
    Double_t jet1eta_JEC_up;
    Double_t jet1eta_JEC_down;
    Double_t jet1eta_JER_up;
    Double_t jet1eta_JER_down;
    Double_t jet1eta_f;
    Double_t jet1eta_new_f;
    Double_t jet1eta_JEC_up_f;
    Double_t jet1eta_JEC_down_f;
    Double_t jet1eta_JER_up_f;
    Double_t jet1eta_JER_down_f;
    Double_t jet1phi;
    Double_t jet1phi_new;
    Double_t jet1phi_JEC_up;
    Double_t jet1phi_JEC_down;
    Double_t jet1phi_JER_up;
    Double_t jet1phi_JER_down;
    Double_t jet1phi_f;
    Double_t jet1phi_new_f;
    Double_t jet1phi_JEC_up_f;
    Double_t jet1phi_JEC_down_f;
    Double_t jet1phi_JER_up_f;
    Double_t jet1phi_JER_down_f;
    Double_t jet1e;
    Double_t jet1e_new;
    Double_t jet1e_JEC_up;
    Double_t jet1e_JER_up;
    Double_t jet1e_JEC_down;
    Double_t jet1e_JER_down;
    Double_t jet1e_f;
    Double_t jet1e_new_f;
    Double_t jet1e_JEC_up_f;
    Double_t jet1e_JER_up_f;
    Double_t jet1e_JEC_down_f;
    Double_t jet1e_JER_down_f;
    Double_t jet1csv;
    Double_t jet1csv_new;
    Double_t jet1csv_JEC_up;
    Double_t jet1csv_JER_up;
    Double_t jet1csv_JEC_down;
    Double_t jet1csv_JER_down;
    Double_t jet1csv_f;
    Double_t jet1csv_new_f;
    Double_t jet1csv_JEC_up_f;
    Double_t jet1csv_JER_up_f;
    Double_t jet1csv_JEC_down_f;
    Double_t jet1csv_JER_down_f;
    Double_t jet1icsv;
    Double_t jet1icsv_new;
    Double_t jet1icsv_JEC_up;
    Double_t jet1icsv_JER_up;
    Double_t jet1icsv_JEC_down;
    Double_t jet1icsv_JER_down;
    Double_t jet1icsv_f;
    Double_t jet1icsv_new_f;
    Double_t jet1icsv_JEC_up_f;
    Double_t jet1icsv_JER_up_f;
    Double_t jet1icsv_JEC_down_f;
    Double_t jet1icsv_JER_down_f;
    Double_t jet2pt;
    Double_t jet2pt_new;
    Double_t jet2pt_JEC_up;
    Double_t jet2pt_JER_up;
    Double_t jet2pt_JEC_down;
    Double_t jet2pt_JER_down;
    Double_t jet2pt_f;
    Double_t jet2pt_new_f;
    Double_t jet2pt_JEC_up_f;
    Double_t jet2pt_JER_up_f;
    Double_t jet2pt_JEC_down_f;
    Double_t jet2pt_JER_down_f;
    Double_t jet2eta;
    Double_t jet2eta_new;
    Double_t jet2eta_JEC_up;
    Double_t jet2eta_JEC_down;
    Double_t jet2eta_JER_up;
    Double_t jet2eta_JER_down;
    Double_t jet2eta_f;
    Double_t jet2phi;
    Double_t jet2phi_new;
    Double_t jet2phi_JEC_up;
    Double_t jet2phi_JEC_down;
    Double_t jet2phi_JER_up;
    Double_t jet2phi_JER_down;
    Double_t jet2phi_f;
    Double_t jet2phi_new_f;
    Double_t jet2phi_JEC_up_f;
    Double_t jet2phi_JEC_down_f;
    Double_t jet2phi_JER_up_f;
    Double_t jet2phi_JER_down_f;
    Double_t jet2eta_new_f;
    Double_t jet2eta_JEC_up_f;
    Double_t jet2eta_JEC_down_f;
    Double_t jet2e;
    Double_t jet2e_new;
    Double_t jet2e_JEC_up;
    Double_t jet2e_JER_up;
    Double_t jet2e_JEC_down;
    Double_t jet2e_JER_down;
    Double_t jet2e_f;
    Double_t jet2e_new_f;
    Double_t jet2e_JEC_up_f;
    Double_t jet2e_JER_up_f;
    Double_t jet2e_JEC_down_f;
    Double_t jet2e_JER_down_f;
    Double_t jet2csv;
    Double_t jet2csv_new;
    Double_t jet2csv_JEC_up;
    Double_t jet2csv_JER_up;
    Double_t jet2csv_JEC_down;
    Double_t jet2csv_JER_down;
    Double_t jet2csv_f;
    Double_t jet2csv_new_f;
    Double_t jet2csv_JEC_up_f;
    Double_t jet2csv_JER_up_f;
    Double_t jet2csv_JEC_down_f;
    Double_t jet2csv_JER_down_f;
    Double_t jet2icsv;
    Double_t jet2icsv_new;
    Double_t jet2icsv_JEC_up;
    Double_t jet2icsv_JER_up;
    Double_t jet2icsv_JEC_down;
    Double_t jet2icsv_JER_down;
    Double_t jet2icsv_f;
    Double_t jet2icsv_new_f;
    Double_t jet2icsv_JEC_up_f;
    Double_t jet2icsv_JER_up_f;
    Double_t jet2icsv_JEC_down_f;
    Double_t jet2icsv_JER_down_f;
    Double_t drj1a;
    Double_t drj1a_new;
    Double_t drj1a_JEC_up;
    Double_t drj1a_JEC_down;
    Double_t drj1a_JER_up;
    Double_t drj1a_JER_down;
    Double_t drj1a_f;
    Double_t drj1a_new_f;
    Double_t drj1a_JEC_up_f;
    Double_t drj1a_JEC_down_f;
    Double_t drj1a_JER_up_f;
    Double_t drj1a_JER_down_f;
    Double_t drj2a;
    Double_t drj2a_new;
    Double_t drj2a_JEC_up;
    Double_t drj2a_JEC_down;
    Double_t drj2a_JER_up;
    Double_t drj2a_JER_down;
    Double_t drj2a_f;
    Double_t drj2a_new_f;
    Double_t drj2a_JEC_up_f;
    Double_t drj2a_JEC_down_f;
    Double_t drj2a_JER_up_f;
    Double_t drj2a_JER_down_f;
    Double_t drj1l;
    Double_t drj1l_new;
    Double_t drj1l_JEC_up;
    Double_t drj1l_JEC_down;
    Double_t drj1l_JER_up;
    Double_t drj1l_JER_down;
    Double_t drj1l_f;
    Double_t drj1l_new_f;
    Double_t drj1l_JEC_up_f;
    Double_t drj1l_JEC_down_f;
    Double_t drj1l_JER_up_f;
    Double_t drj1l_JER_down_f;
    Double_t drj2l;
    Double_t drj2l_new;
    Double_t drj2l_JEC_up;
    Double_t drj2l_JEC_down;
    Double_t drj2l_JER_up;
    Double_t drj2l_JER_down;
    Double_t drj2l_f;
    Double_t drj2l_new_f;
    Double_t drj2l_JEC_up_f;
    Double_t drj2l_JEC_down_f;
    Double_t drj2l_JER_up_f;
    Double_t drj2l_JER_down_f;
    Double_t Mjj;
    Double_t Mjj_new;
    Double_t Mjj_JEC_up;
    Double_t Mjj_JEC_down;
    Double_t Mjj_JER_up;
    Double_t Mjj_JER_down;
    Double_t Mjj_f;
    Double_t Mjj_new_f;
    Double_t Mjj_JEC_up_f;
    Double_t Mjj_JEC_down_f;
    Double_t Mjj_JER_up_f;
    Double_t Mjj_JER_down_f;
    Double_t deltaeta;
    Double_t deltaeta_new;
    Double_t deltaeta_JEC_up;
    Double_t deltaeta_JEC_down;
    Double_t deltaeta_JER_up;
    Double_t deltaeta_JER_down;
    Double_t deltaeta_f;
    Double_t deltaeta_new_f;
    Double_t deltaeta_JEC_up_f;
    Double_t deltaeta_JEC_down_f;
    Double_t deltaeta_JER_up_f;
    Double_t deltaeta_JER_down_f;
    Double_t zepp;
    Double_t zepp_new;
    Double_t zepp_JEC_up;
    Double_t zepp_JEC_down;
    Double_t zepp_JER_up;
    Double_t zepp_JER_down;
    Double_t zepp_f;
    Double_t zepp_new_f;
    Double_t zepp_JEC_up_f;
    Double_t zepp_JEC_down_f;
    Double_t zepp_JER_up_f;
    Double_t zepp_JER_down_f;
    Double_t ptlep1;
    Double_t etalep1;
    Double_t philep1;
    Double_t energylep1;
    Double_t j1metPhi;
    Double_t j1metPhi_new;
    Double_t j1metPhi_JEC_up;
    Double_t j1metPhi_JEC_down;
    Double_t j1metPhi_JER_up;
    Double_t j1metPhi_JER_down;
    Double_t j1metPhi_f;
    Double_t j1metPhi_new_f;
    Double_t j1metPhi_JEC_up_f;
    Double_t j1metPhi_JEC_down_f;
    Double_t j1metPhi_JER_up_f;
    Double_t j1metPhi_JER_down_f;
    Double_t j2metPhi;
    Double_t j2metPhi_new;
    Double_t j2metPhi_JEC_up;
    Double_t j2metPhi_JEC_down;
    Double_t j2metPhi_JER_up;
    Double_t j2metPhi_JER_down;
    Double_t j2metPhi_f;
    Double_t j2metPhi_new_f;
    Double_t j2metPhi_JEC_up_f;
    Double_t j2metPhi_JEC_down_f;
    Double_t j2metPhi_JER_up_f;
    Double_t j2metPhi_JER_down_f;
    Double_t Dphiwajj;
    Double_t Dphiwajj_new;
    Double_t Dphiwajj_JEC_up;
    Double_t Dphiwajj_JEC_down;
    Double_t Dphiwajj_JER_up;
    Double_t Dphiwajj_JER_down;

    Double_t Dphiwajj_f;
    Double_t METraw_et;
    Double_t METraw_phi;
    Double_t METraw_sumEt;
    Double_t genMET;
    Double_t MET_et;
    Double_t MET_et_new;
    Double_t MET_et_JEC_up;
    Double_t MET_et_JEC_down;
    Double_t MET_et_JER_up;
    Double_t MET_et_JER_down;
    Double_t MET_phi;
    Double_t MET_phi_new;
    Double_t MET_phi_JEC_up;
    Double_t MET_phi_JEC_down;
    Double_t MET_phi_JER_up;
    Double_t MET_phi_JER_down;
    Int_t    HLT_Ele1;
    Int_t    HLT_Ele2;
    Int_t    HLT_Mu1;
    Int_t    HLT_Mu2;
    Int_t    HLT_Mu3;
    Double_t lumiWeight;
    Double_t pileupWeight;

    // List of branches
    TBranch* b_rawPt;                 //!
    TBranch* b_nevent;                //!
    TBranch* b_run;                   //!
    TBranch* b_ls;                    //!
    TBranch* b_nVtx;                  //!
    TBranch* b_theWeight;             //!
    TBranch* b_nump;                  //!
    TBranch* b_numm;                  //!
    TBranch* b_npT;                   //!
    TBranch* b_lep;                   //!
    TBranch* b_ptVlep;                //!
    TBranch* b_ptVlepJEC;             //!
    TBranch* b_yVlepJEC;              //!
    TBranch* b_phiVlepJEC;            //!
    TBranch* b_massVlepJEC;           //!
    TBranch* b_mtVlepJECnew;          //!
    TBranch* b_ptVlepJEC_new;             //!
    TBranch* b_yVlepJEC_new;              //!
    TBranch* b_phiVlepJEC_new;            //!
    TBranch* b_massVlepJEC_new;           //!
    TBranch* b_mtVlepJECnew_new;          //!
    TBranch* b_ptVlepJEC_JEC_up;             //!
    TBranch* b_yVlepJEC_JEC_up;              //!
    TBranch* b_phiVlepJEC_JEC_up;            //!
    TBranch* b_massVlepJEC_JEC_up;           //!
    TBranch* b_mtVlepJECnew_JEC_up;          //!
    TBranch* b_ptVlepJEC_JEC_down;             //!
    TBranch* b_yVlepJEC_JEC_down;              //!
    TBranch* b_phiVlepJEC_JEC_down;            //!
    TBranch* b_massVlepJEC_JEC_down;           //!
    TBranch* b_mtVlepJECnew_JEC_down;          //!
    TBranch* b_ptVlepJEC_JER_up;             //!
    TBranch* b_yVlepJEC_JER_up;              //!
    TBranch* b_phiVlepJEC_JER_up;            //!
    TBranch* b_massVlepJEC_JER_up;           //!
    TBranch* b_mtVlepJECnew_JER_up;          //!
    TBranch* b_ptVlepJEC_JER_down;             //!
    TBranch* b_yVlepJEC_JER_down;              //!
    TBranch* b_phiVlepJEC_JER_down;            //!
    TBranch* b_massVlepJEC_JER_down;           //!
    TBranch* b_mtVlepJECnew_JER_down;          //!


    TBranch* b_Mla;                   //!
    TBranch* b_Mla_f;                 //!
    TBranch* b_Mva;                   //!
    TBranch* b_Mva_f;                 //!
    TBranch* b_nlooseeles;            //!
    TBranch* b_nloosemus;             //!
    TBranch* b_genjet_pt;             //!
    TBranch* b_genjet_eta;            //!
    TBranch* b_genjet_phi;            //!
    TBranch* b_genjet_e;              //!
    TBranch* b_photon_pt;             //!
    TBranch* b_photon_eta;            //!
    TBranch* b_photon_phi;            //!
    TBranch* b_photon_e;              //!
    TBranch* b_photonsc_eta;          //!
    TBranch* b_photonsc_phi;          //!
    TBranch* b_photon_pev;            //!
    TBranch* b_photon_pevnew;         //!
    TBranch* b_photon_ppsv;           //!
    TBranch* b_photon_hoe;            //!
    TBranch* b_photon_sieie;          //!
    TBranch* b_photon_sieie2;         //!
    TBranch* b_photon_chiso;          //!
    TBranch* b_photon_nhiso;          //!
    TBranch* b_photon_phoiso;         //!
    TBranch* b_photon_isprompt;       //!
    TBranch* b_photon_drla;           //!
    TBranch* b_photon_mla;            //!
    TBranch* b_photonhaspixelseed;    //!
    TBranch* b_photonhaspixelseed_f;  //!
    TBranch* b_photonpasseleveto;     //!
    TBranch* b_photonpasseleveto_F;   //!
    TBranch* b_photonet;              //!
    TBranch* b_photonet_f;            //!
    TBranch* b_photoneta;             //!
    TBranch* b_photoneta_f;           //!
    TBranch* b_photonphi;             //!
    TBranch* b_photonphi_f;           //!
    TBranch* b_photone;               //!
    TBranch* b_photone_f;             //!
    TBranch* b_photonsceta;           //!
    TBranch* b_photonsceta_f;         //!
    TBranch* b_photonscphi;           //!
    TBranch* b_photonscphi_f;         //!
    TBranch* b_iphoton;               //!
    TBranch* b_iphoton_f;             //!
    TBranch* b_drla;                  //!
    TBranch* b_drla_f;                //!
    TBranch* b_isTrue;                //!
    TBranch* b_isprompt;              //!
    TBranch* b_ispromptLep;           //!
    TBranch* b_ak4jet_hf;             //!
    TBranch* b_ak4jet_pf;             //!
    TBranch* b_jet1hf;                //!
    TBranch* b_jet1pf;                //!
    TBranch* b_jet2hf;                //!
    TBranch* b_jet2pf;                //!
    TBranch* b_jet1hf_f;              //!
    TBranch* b_jet1pf_f;              //!
    TBranch* b_jet2hf_f;              //!
    TBranch* b_jet2pf_f;              //!
    TBranch* b_ak4jet_csv;            //!
    TBranch* b_ak4jet_icsv;           //!
    TBranch* b_ak4jet_pt_old;         //!
    TBranch* b_ak4jet_pt_new;         //!
    TBranch* b_ak4jet_pt_JEC_up;      //!
    TBranch* b_ak4jet_pt_JEC_down;    //!
    TBranch* b_ak4jet_pt_JER_up;      //!
    TBranch* b_ak4jet_pt_JER_down;    //!
    TBranch* b_ak4jet_eta;            //!
    TBranch* b_ak4jet_phi;            //!
    TBranch* b_ak4jet_e_old;          //!
    TBranch* b_ak4jet_e_new;          //!
    TBranch* b_ak4jet_e_JEC_up;       //!
    TBranch* b_ak4jet_e_JEC_down;     //!
    TBranch* b_ak4jet_e_JER_up;       //!
    TBranch* b_ak4jet_e_JER_down;     //!
    TBranch* b_jet1pt;                //!
    TBranch* b_jet1pt_new;            //!
    TBranch* b_jet1pt_JEC_up;         //!
    TBranch* b_jet1pt_JER_up;         //!
    TBranch* b_jet1pt_JEC_down;       //!
    TBranch* b_jet1pt_JER_down;       //!
    TBranch* b_jet1pt_f;              //!
    TBranch* b_jet1pt_new_f;          //!
    TBranch* b_jet1pt_JEC_up_f;       //!
    TBranch* b_jet1pt_JER_up_f;       //!
    TBranch* b_jet1pt_JEC_down_f;     //!
    TBranch* b_jet1pt_JER_down_f;     //!
    TBranch* b_jet1eta;               //!
    TBranch* b_jet1eta_new;           //!
    TBranch* b_jet1eta_JEC_up;        //!
    TBranch* b_jet1eta_JEC_down;      //!
    TBranch* b_jet1eta_JER_up;        //!
    TBranch* b_jet1eta_JER_down;      //!
    TBranch* b_jet1eta_f;             //!
    TBranch* b_jet1eta_new_f;         //!
    TBranch* b_jet1eta_JEC_up_f;      //!
    TBranch* b_jet1eta_JEC_down_f;    //!
    TBranch* b_jet1eta_JER_up_f;      //!
    TBranch* b_jet1eta_JER_down_f;    //!
    TBranch* b_jet1phi;               //!
    TBranch* b_jet1phi_new;           //!
    TBranch* b_jet1phi_JEC_up;        //!
    TBranch* b_jet1phi_JEC_down;      //!
    TBranch* b_jet1phi_JER_up;        //!
    TBranch* b_jet1phi_JER_down;      //!
    TBranch* b_jet1phi_f;             //!
    TBranch* b_jet1phi_new_f;         //!
    TBranch* b_jet1phi_JEC_up_f;      //!
    TBranch* b_jet1phi_JEC_down_f;    //!
    TBranch* b_jet1phi_JER_up_f;      //!
    TBranch* b_jet1phi_JER_down_f;    //!
    TBranch* b_jet1e;                 //!
    TBranch* b_jet1e_new;             //!
    TBranch* b_jet1e_JEC_up;          //!
    TBranch* b_jet1e_JER_up;          //!
    TBranch* b_jet1e_JEC_down;        //!
    TBranch* b_jet1e_JER_down;        //!
    TBranch* b_jet1e_f;               //!
    TBranch* b_jet1e_new_f;           //!
    TBranch* b_jet1e_JEC_up_f;        //!
    TBranch* b_jet1e_JER_up_f;        //!
    TBranch* b_jet1e_JEC_down_f;      //!
    TBranch* b_jet1e_JER_down_f;      //!
    TBranch* b_jet1csv;               //!
    TBranch* b_jet1csv_new;           //!
    TBranch* b_jet1csv_JEC_up;        //!
    TBranch* b_jet1csv_JER_up;        //!
    TBranch* b_jet1csv_JEC_down;      //!
    TBranch* b_jet1csv_JER_down;      //!
    TBranch* b_jet1csv_f;             //!
    TBranch* b_jet1csv_new_f;         //!
    TBranch* b_jet1csv_JEC_up_f;      //!
    TBranch* b_jet1csv_JER_up_f;      //!
    TBranch* b_jet1csv_JEC_down_f;    //!
    TBranch* b_jet1csv_JER_down_f;    //!
    TBranch* b_jet1icsv;              //!
    TBranch* b_jet1icsv_new;          //!
    TBranch* b_jet1icsv_JEC_up;       //!
    TBranch* b_jet1icsv_JER_up;       //!
    TBranch* b_jet1icsv_JEC_down;     //!
    TBranch* b_jet1icsv_JER_down;     //!
    TBranch* b_jet1icsv_f;            //!
    TBranch* b_jet1icsv_new_f;        //!
    TBranch* b_jet1icsv_JEC_up_f;     //!
    TBranch* b_jet1icsv_JER_up_f;     //!
    TBranch* b_jet1icsv_JEC_down_f;   //!
    TBranch* b_jet1icsv_JER_down_f;   //!
    TBranch* b_jet2pt;                //!
    TBranch* b_jet2pt_new;            //!
    TBranch* b_jet2pt_JEC_up;         //!
    TBranch* b_jet2pt_JER_up;         //!
    TBranch* b_jet2pt_JEC_down;       //!
    TBranch* b_jet2pt_JER_down;       //!
    TBranch* b_jet2pt_f;              //!
    TBranch* b_jet2pt_new_f;          //!
    TBranch* b_jet2pt_JEC_up_f;       //!
    TBranch* b_jet2pt_JER_up_f;       //!
    TBranch* b_jet2pt_JEC_down_f;     //!
    TBranch* b_jet2pt_JER_down_f;     //!
    TBranch* b_jet2eta;               //!
    TBranch* b_jet2eta_new;           //!
    TBranch* b_jet2eta_JEC_up;        //!
    TBranch* b_jet2eta_JEC_down;      //!
    TBranch* b_jet2eta_JER_up;        //!
    TBranch* b_jet2eta_JER_down;      //!
    TBranch* b_jet2eta_f;             //!
    TBranch* b_jet2phi;               //!
    TBranch* b_jet2phi_new;           //!
    TBranch* b_jet2phi_JEC_up;        //!
    TBranch* b_jet2phi_JEC_down;      //!
    TBranch* b_jet2phi_JER_up;        //!
    TBranch* b_jet2phi_JER_down;      //!
    TBranch* b_jet2phi_f;             //!
    TBranch* b_jet2phi_new_f;         //!
    TBranch* b_jet2phi_JEC_up_f;      //!
    TBranch* b_jet2phi_JEC_down_f;    //!
    TBranch* b_jet2phi_JER_up_f;      //!
    TBranch* b_jet2phi_JER_down_f;    //!
    TBranch* b_jet2eta_new_f;         //!
    TBranch* b_jet2eta_JEC_up_f;      //!
    TBranch* b_jet2eta_JEC_down_f;    //!
    TBranch* b_jet2e;                 //!
    TBranch* b_jet2e_new;             //!
    TBranch* b_jet2e_JEC_up;          //!
    TBranch* b_jet2e_JER_up;          //!
    TBranch* b_jet2e_JEC_down;        //!
    TBranch* b_jet2e_JER_down;        //!
    TBranch* b_jet2e_f;               //!
    TBranch* b_jet2e_new_f;           //!
    TBranch* b_jet2e_JEC_up_f;        //!
    TBranch* b_jet2e_JER_up_f;        //!
    TBranch* b_jet2e_JEC_down_f;      //!
    TBranch* b_jet2e_JER_down_f;      //!
    TBranch* b_jet2csv;               //!
    TBranch* b_jet2csv_new;           //!
    TBranch* b_jet2csv_JEC_up;        //!
    TBranch* b_jet2csv_JER_up;        //!
    TBranch* b_jet2csv_JEC_down;      //!
    TBranch* b_jet2csv_JER_down;      //!
    TBranch* b_jet2csv_f;             //!
    TBranch* b_jet2csv_new_f;         //!
    TBranch* b_jet2csv_JEC_up_f;      //!
    TBranch* b_jet2csv_JER_up_f;      //!
    TBranch* b_jet2csv_JEC_down_f;    //!
    TBranch* b_jet2csv_JER_down_f;    //!
    TBranch* b_jet2icsv;              //!
    TBranch* b_jet2icsv_new;          //!
    TBranch* b_jet2icsv_JEC_up;       //!
    TBranch* b_jet2icsv_JER_up;       //!
    TBranch* b_jet2icsv_JEC_down;     //!
    TBranch* b_jet2icsv_JER_down;     //!
    TBranch* b_jet2icsv_f;            //!
    TBranch* b_jet2icsv_new_f;        //!
    TBranch* b_jet2icsv_JEC_up_f;     //!
    TBranch* b_jet2icsv_JER_up_f;     //!
    TBranch* b_jet2icsv_JEC_down_f;   //!
    TBranch* b_jet2icsv_JER_down_f;   //!
    TBranch* b_drj1a;                 //!
    TBranch* b_drj1a_new;             //!
    TBranch* b_drj1a_JEC_up;          //!
    TBranch* b_drj1a_JEC_down;        //!
    TBranch* b_drj1a_JER_up;          //!
    TBranch* b_drj1a_JER_down;        //!
    TBranch* b_drj1a_f;               //!
    TBranch* b_drj1a_new_f;           //!
    TBranch* b_drj1a_JEC_up_f;        //!
    TBranch* b_drj1a_JEC_down_f;      //!
    TBranch* b_drj1a_JER_up_f;        //!
    TBranch* b_drj1a_JER_down_f;      //!
    TBranch* b_drj2a;                 //!
    TBranch* b_drj2a_new;             //!
    TBranch* b_drj2a_JEC_up;          //!
    TBranch* b_drj2a_JEC_down;        //!
    TBranch* b_drj2a_JER_up;          //!
    TBranch* b_drj2a_JER_down;        //!
    TBranch* b_drj2a_f;               //!
    TBranch* b_drj2a_new_f;           //!
    TBranch* b_drj2a_JEC_up_f;        //!
    TBranch* b_drj2a_JEC_down_f;      //!
    TBranch* b_drj2a_JER_up_f;        //!
    TBranch* b_drj2a_JER_down_f;      //!
    TBranch* b_drj1l;                 //!
    TBranch* b_drj1l_new;             //!
    TBranch* b_drj1l_JEC_up;          //!
    TBranch* b_drj1l_JEC_down;        //!
    TBranch* b_drj1l_JER_up;          //!
    TBranch* b_drj1l_JER_down;        //!
    TBranch* b_drj1l_f;               //!
    TBranch* b_drj1l_new_f;           //!
    TBranch* b_drj1l_JEC_up_f;        //!
    TBranch* b_drj1l_JEC_down_f;      //!
    TBranch* b_drj1l_JER_up_f;        //!
    TBranch* b_drj1l_JER_down_f;      //!
    TBranch* b_drj2l;                 //!
    TBranch* b_drj2l_new;             //!
    TBranch* b_drj2l_JEC_up;          //!
    TBranch* b_drj2l_JEC_down;        //!
    TBranch* b_drj2l_JER_up;          //!
    TBranch* b_drj2l_JER_down;        //!
    TBranch* b_drj2l_f;               //!
    TBranch* b_drj2l_new_f;           //!
    TBranch* b_drj2l_JEC_up_f;        //!
    TBranch* b_drj2l_JEC_down_f;      //!
    TBranch* b_drj2l_JER_up_f;        //!
    TBranch* b_drj2l_JER_down_f;      //!
    TBranch* b_Mjj;                   //!
    TBranch* b_Mjj_new;               //!
    TBranch* b_Mjj_JEC_up;            //!
    TBranch* b_Mjj_JEC_down;          //!
    TBranch* b_Mjj_JER_up;            //!
    TBranch* b_Mjj_JER_down;          //!
    TBranch* b_Mjj_f;                 //!
    TBranch* b_Mjj_new_f;             //!
    TBranch* b_Mjj_JEC_up_f;          //!
    TBranch* b_Mjj_JEC_down_f;        //!
    TBranch* b_Mjj_JER_up_f;          //!
    TBranch* b_Mjj_JER_down_f;        //!
    TBranch* b_deltaeta;              //!
    TBranch* b_deltaeta_new;          //!
    TBranch* b_deltaeta_JEC_up;       //!
    TBranch* b_deltaeta_JEC_down;     //!
    TBranch* b_deltaeta_JER_up;       //!
    TBranch* b_deltaeta_JER_down;     //!
    TBranch* b_deltaeta_f;            //!
    TBranch* b_deltaeta_new_f;        //!
    TBranch* b_deltaeta_JEC_up_f;     //!
    TBranch* b_deltaeta_JEC_down_f;   //!
    TBranch* b_deltaeta_JER_up_f;     //!
    TBranch* b_deltaeta_JER_down_f;   //!
    TBranch* b_zepp;                  //!
    TBranch* b_zepp_new;              //!
    TBranch* b_zepp_JEC_up;           //!
    TBranch* b_zepp_JEC_down;         //!
    TBranch* b_zepp_JER_up;           //!
    TBranch* b_zepp_JER_down;         //!
    TBranch* b_zepp_f;                //!
    TBranch* b_zepp_new_f;            //!
    TBranch* b_zepp_JEC_up_f;         //!
    TBranch* b_zepp_JEC_down_f;       //!
    TBranch* b_zepp_JER_up_f;         //!
    TBranch* b_zepp_JER_down_f;       //!
    TBranch* b_ptlep1;                //!
    TBranch* b_etalep1;               //!
    TBranch* b_philep1;               //!
    TBranch* b_energylep1;            //!
    TBranch* b_j1metPhi;              //!
    TBranch* b_j1metPhi_new;          //!
    TBranch* b_j1metPhi_JEC_up;       //!
    TBranch* b_j1metPhi_JEC_down;     //!
    TBranch* b_j1metPhi_JER_up;       //!
    TBranch* b_j1metPhi_JER_down;     //!
    TBranch* b_j1metPhi_f;            //!
    TBranch* b_j1metPhi_new_f;        //!
    TBranch* b_j1metPhi_JEC_up_f;     //!
    TBranch* b_j1metPhi_JEC_down_f;   //!
    TBranch* b_j1metPhi_JER_up_f;     //!
    TBranch* b_j1metPhi_JER_down_f;   //!
    TBranch* b_j2metPhi;              //!
    TBranch* b_j2metPhi_new;          //!
    TBranch* b_j2metPhi_JEC_up;       //!
    TBranch* b_j2metPhi_JEC_down;     //!
    TBranch* b_j2metPhi_JER_up;       //!
    TBranch* b_j2metPhi_JER_down;     //!
    TBranch* b_j2metPhi_f;            //!
    TBranch* b_j2metPhi_new_f;        //!
    TBranch* b_j2metPhi_JEC_up_f;     //!
    TBranch* b_j2metPhi_JEC_down_f;   //!
    TBranch* b_j2metPhi_JER_up_f;     //!
    TBranch* b_j2metPhi_JER_down_f;   //!
    TBranch* b_Dphiwajj;              //!
    TBranch* b_Dphiwajj_new;              //!
    TBranch* b_Dphiwajj_JEC_up;              //!
    TBranch* b_Dphiwajj_JEC_down;              //!
    TBranch* b_Dphiwajj_JER_up;              //!
    TBranch* b_Dphiwajj_JER_down;              //!
    TBranch* b_Dphiwajj_f;            //!
    TBranch* b_METraw_et;             //!
    TBranch* b_METraw_phi;            //!
    TBranch* b_METraw_sumEt;          //!
    TBranch* b_genMET;                //!
    TBranch* b_MET_et;                //!
    TBranch* b_MET_et_new;            //!
    TBranch* b_MET_et_JEC_up;         //!
    TBranch* b_MET_et_JEC_down;       //!
    TBranch* b_MET_et_JER_up;         //!
    TBranch* b_MET_et_JER_down;       //!
    TBranch* b_MET_phi;               //!
    TBranch* b_MET_phi_new;           //!
    TBranch* b_MET_phi_JEC_up;        //!
    TBranch* b_MET_phi_JEC_down;      //!
    TBranch* b_MET_phi_JER_up;        //!
    TBranch* b_MET_phi_JER_down;      //!
    TBranch* b_HLT_Ele1;              //!
    TBranch* b_HLT_Ele2;              //!
    TBranch* b_HLT_Mu1;               //!
    TBranch* b_HLT_Mu2;               //!
    TBranch* b_HLT_Mu3;               //!
    TBranch* b_lumiWeight;            //!
    TBranch* b_pileupWeight;          //!

    TString m_dataset;
    makesmall(TTree* tree = 0, TString dataset = "");
    virtual ~makesmall();
    virtual Int_t    Cut(Long64_t entry);
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree* tree);
    virtual void     Loop();
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);

    virtual Double_t beff(Double_t x);
    virtual Double_t ceff(Double_t x);
    virtual Double_t leff(Double_t x);
    virtual Double_t central_b_scale(Double_t x);
    virtual Double_t central_c_scale(Double_t x);
    virtual Double_t central_l_scale(Double_t x);
    virtual Double_t up_b_scale(Double_t x);
    virtual Double_t up_c_scale(Double_t x);
    virtual Double_t up_l_scale(Double_t x);
    virtual Double_t down_b_scale(Double_t x);
    virtual Double_t down_c_scale(Double_t x);
    virtual Double_t down_l_scale(Double_t x);

    void endJob();
};

#endif

#ifdef makesmall_cxx
makesmall::makesmall(TTree* tree,TString dataset)
    : fChain(0) {
    // if parameter tree is not specified (or zero), connect the file
    // used to generate this class and read the Tree.
    if (tree == 0) {
        TFile* f = (TFile*)gROOT->GetListOfFiles()->FindObject("treePKU.root");
        if (!f || !f->IsOpen()) {
            f = new TFile("treePKU.root");
        }
        TDirectory* dir = (TDirectory*)f->Get("treePKU.root:/treeDumper");
        dir->GetObject("PKUCandidates", tree);
    }
    // Jie
    m_dataset = dataset;
    fout      = TFile::Open(m_dataset, "RECREATE");
    ExTree    = new TTree("demo", "demo");
    if (m_dataset.Contains("fakephoton")) {
        use_f = true;
    }
    else
        use_f = false;
    // XIAO
    Init(tree);
    std::cout<<"1111111111111"<<std::endl;
}

makesmall::~makesmall() {
    if (!fChain)
        return;
    delete fChain->GetCurrentFile();
}

Int_t makesmall::GetEntry(Long64_t entry) {
    // Read contents of entry.
    if (!fChain)
        return 0;
    return fChain->GetEntry(entry);
}
Long64_t makesmall::LoadTree(Long64_t entry) {
    // Set the environment to read one entry
    if (!fChain)
        return -5;
    Long64_t centry = fChain->LoadTree(entry);
    if (centry < 0)
        return centry;
    if (fChain->GetTreeNumber() != fCurrent) {
        fCurrent = fChain->GetTreeNumber();
        Notify();
    }
    return centry;
}

void makesmall::Init(TTree* tree) {
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).

    // Set branch addresses and branch pointers
    if (!tree)
        return;
    fChain   = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);
    ExTree->Branch("scalef", &scalef, "scalef/D");
    //ExTree->Branch("rawPt", &rawPt, "rawPt/F");
    ExTree->Branch("nevent", &nevent, "nevent/I");
    ExTree->Branch("run", &run, "run/I");
    ExTree->Branch("ls", &ls, "ls/I");
    ExTree->Branch("nVtx", &nVtx, "nVtx/I");
    ExTree->Branch("theWeight", &theWeight, "theWeight/D");
    ExTree->Branch("nump", &nump, "nump/D");
    ExTree->Branch("numm", &numm, "numm/D");
    ExTree->Branch("npT", &npT, "npT/D");
    ExTree->Branch("lep", &lep, "lep/I");
    //ExTree->Branch("ptVlep", &ptVlep, "ptVlep/D");
    ExTree->Branch("ptVlepJEC", &ptVlepJEC, "ptVlepJEC/D");
    ExTree->Branch("yVlepJEC", &yVlepJEC, "yVlepJEC/D");
    ExTree->Branch("phiVlepJEC", &phiVlepJEC, "phiVlepJEC/D");
    ExTree->Branch("massVlepJEC", &massVlepJEC, "massVlepJEC/D");
    ExTree->Branch("mtVlepJECnew", &mtVlepJECnew, "mtVlepJECnew/D");
    ExTree->Branch("ptVlepJEC_new", &ptVlepJEC_new, "ptVlepJEC_new/D");
    ExTree->Branch("yVlepJEC_new", &yVlepJEC_new, "yVlepJEC_new/D");
    ExTree->Branch("phiVlepJEC_new", &phiVlepJEC_new, "phiVlepJEC_new/D");
    ExTree->Branch("massVlepJEC_new", &massVlepJEC_new, "massVlepJEC_new/D");
    ExTree->Branch("mtVlepJECnew_new", &mtVlepJECnew_new, "mtVlepJECnew_new/D");
    ExTree->Branch("ptVlepJEC_JEC_up", &ptVlepJEC_JEC_up, "ptVlepJEC_JEC_up/D");
    ExTree->Branch("yVlepJEC_JEC_up", &yVlepJEC_JEC_up, "yVlepJEC_JEC_up/D");
    ExTree->Branch("phiVlepJEC_JEC_up", &phiVlepJEC_JEC_up, "phiVlepJEC_JEC_up/D");
    ExTree->Branch("massVlepJEC_JEC_up", &massVlepJEC_JEC_up, "massVlepJEC_JEC_up/D");
    ExTree->Branch("mtVlepJECnew_JEC_up", &mtVlepJECnew_JEC_up, "mtVlepJECnew_JEC_up/D");
    ExTree->Branch("ptVlepJEC_JEC_down", &ptVlepJEC_JEC_down, "ptVlepJEC_JEC_down/D");
    ExTree->Branch("yVlepJEC_JEC_down", &yVlepJEC_JEC_down, "yVlepJEC_JEC_down/D");
    ExTree->Branch("phiVlepJEC_JEC_down", &phiVlepJEC_JEC_down, "phiVlepJEC_JEC_down/D");
    ExTree->Branch("massVlepJEC_JEC_down", &massVlepJEC_JEC_down, "massVlepJEC_JEC_down/D");
    ExTree->Branch("mtVlepJECnew_JEC_down", &mtVlepJECnew_JEC_down, "mtVlepJECnew_JEC_down/D");
    ExTree->Branch("ptVlepJEC_JER_up", &ptVlepJEC_JER_up, "ptVlepJEC_JER_up/D");
    ExTree->Branch("yVlepJEC_JER_up", &yVlepJEC_JER_up, "yVlepJEC_JER_up/D");
    ExTree->Branch("phiVlepJEC_JER_up", &phiVlepJEC_JER_up, "phiVlepJEC_JER_up/D");
    ExTree->Branch("massVlepJEC_JER_up", &massVlepJEC_JER_up, "massVlepJEC_JER_up/D");
    ExTree->Branch("mtVlepJECnew_JER_up", &mtVlepJECnew_JER_up, "mtVlepJECnew_JER_up/D");
    ExTree->Branch("ptVlepJEC_JER_down", &ptVlepJEC_JER_down, "ptVlepJEC_JER_down/D");
    ExTree->Branch("yVlepJEC_JER_down", &yVlepJEC_JER_down, "yVlepJEC_JER_down/D");
    ExTree->Branch("phiVlepJEC_JER_down", &phiVlepJEC_JER_down, "phiVlepJEC_JER_down/D");
    ExTree->Branch("massVlepJEC_JER_down", &massVlepJEC_JER_down, "massVlepJEC_JER_down/D");
    ExTree->Branch("mtVlepJECnew_JER_down", &mtVlepJECnew_JER_down, "mtVlepJECnew_JER_down/D");
    ExTree->Branch("nlooseeles", &nlooseeles, "nlooseeles/I");
    ExTree->Branch("nloosemus", &nloosemus, "nloosemus/I");
    //ExTree->Branch("ngoodmus", &ngoodmus, "ngoodmus/I");
    //ExTree->Branch("genphoton_pt", genphoton_pt, "genphoton_pt[6]/D");
    //ExTree->Branch("genphoton_eta", genphoton_eta, "genphoton_eta[6]/D");
    //ExTree->Branch("genphoton_phi", genphoton_phi, "genphoton_phi[6]/D");
    //ExTree->Branch("genmuon_pt", genmuon_pt, "genmuon_pt[6]/D");
    //ExTree->Branch("genmuon_eta", genmuon_eta, "genmuon_eta[6]/D");
    //ExTree->Branch("genmuon_phi", genmuon_phi, "genmuon_phi[6]/D");
    ///ExTree->Branch("genmuon_pid", genmuon_pid, "genmuon_pid[6]/I");
    //ExTree->Branch("genelectron_pt", genelectron_pt, "genelectron_pt[6]/D");
    //ExTree->Branch("genelectron_eta", genelectron_eta, "genelectron_eta[6]/D");
    //ExTree->Branch("genelectron_phi", genelectron_phi, "genelectron_phi[6]/D");
    ExTree->Branch("photon_pt", photon_pt, "photon_pt[6]/D");
    ExTree->Branch("photon_eta", photon_eta, "photon_eta[6]/D");
    ExTree->Branch("photon_phi", photon_phi, "photon_phi[6]/D");
    //ExTree->Branch("photon_e", photon_e, "photon_e[6]/D");
    //ExTree->Branch("photon_pev", photon_pev, "photon_pev[6]/O");
    //ExTree->Branch("photon_pevnew", photon_pevnew, "photon_pevnew[6]/O");
    ExTree->Branch("photon_ppsv", photon_ppsv, "photon_ppsv[6]/O");
    //ExTree->Branch("photon_iseb", photon_iseb, "photon_iseb[6]/O");
    //ExTree->Branch("photon_isee", photon_isee, "photon_isee[6]/O");
    ExTree->Branch("photon_hoe", photon_hoe, "photon_hoe[6]/D");
    ExTree->Branch("photon_sieie", photon_sieie, "photon_sieie[6]/D");
    ExTree->Branch("photon_sieie2", photon_sieie2, "photon_sieie2[6]/D");
    ExTree->Branch("photon_chiso", photon_chiso, "photon_chiso[6]/D");
    ExTree->Branch("photon_nhiso", photon_nhiso, "photon_nhiso[6]/D");
    gStyle->SetOptStat(0);
    ExTree->Branch("photon_phoiso", photon_phoiso, "photon_phoiso[6]/D");
    ///ExTree->Branch("photon_istrue", photon_istrue, "photon_istrue[6]/I");
    ExTree->Branch("photon_isprompt", photon_isprompt, "photon_isprompt[6]/I");
    ExTree->Branch("photon_drla", photon_drla, "photon_drla[6]/D");
    ExTree->Branch("photon_mla", photon_mla, "photon_mla[6]/D");
    ExTree->Branch("photonsc_eta", photonsc_eta, "photonsc_eta[6]/D");
    ExTree->Branch("photonsc_phi", photonsc_phi, "photonsc_phi[6]/D");
    //ExTree->Branch("photon_mva", photon_mva, "photon_mva[6]/D");
    //ExTree->Branch("passEleVeto", &passEleVeto, "passEleVeto/O");
    //ExTree->Branch("passEleVetonew", &passEleVetonew, "passEleVetonew/O");
    //ExTree->Branch("passPixelSeedVeto", &passPixelSeedVeto, "passPixelSeedVeto/O");
    ExTree->Branch("ptlep1", &ptlep1, "ptlep1/D");
    ExTree->Branch("etalep1", &etalep1, "etalep1/D");
    ExTree->Branch("philep1", &philep1, "philep1/D");

    ExTree->Branch("isprompt", &isprompt, "isprompt/I");
    ExTree->Branch("ispromptLep", &ispromptLep, "ispromptLep/I");

    ExTree->Branch("photonsceta", &photonsceta, "photonsceta/D");
    ExTree->Branch("photonscphi", &photonscphi, "photonscphi/D");
    ExTree->Branch("Mla", &Mla, "Mla/D");
    //ExTree->Branch("Mva", &Mva, "Mva/D");
    ExTree->Branch("photonhaspixelseed", &photonhaspixelseed, "photonhaspixelseed/O");
    ExTree->Branch("photonpasseleveto", &photonpasseleveto, "photonpasseleveto/O");
    ExTree->Branch("photonet", &photonet, "photonet/D");
    ExTree->Branch("photoneta", &photoneta, "photoneta/D");
    ExTree->Branch("photonphi", &photonphi, "photonphi/D");
    ExTree->Branch("photone", &photone, "photone/D");
    //  ExTree->Branch("iphoton", &iphoton, "iphoton/I");
    ExTree->Branch("drla", &drla, "drla/D");
    //ExTree->Branch("jet1hf", &jet1hf_f, "jet1hf/I");
    //ExTree->Branch("jet1pf", &jet1pf_f, "jet1pf/I");
    //ExTree->Branch("jet2hf", &jet2hf_f, "jet2hf/I");
    //ExTree->Branch("jet2pf", &jet2pf_f, "jet2pf/I");
    ExTree->Branch("jet1pt", &jet1pt, "jet1pt/D");
    ExTree->Branch("jet1pt_new", &jet1pt_new, "jet1pt_new/D");
    ExTree->Branch("jet1pt_JEC_up", &jet1pt_JEC_up, "jet1pt_JEC_up/D");
    ExTree->Branch("jet1pt_JER_up", &jet1pt_JER_up, "jet1pt_JER_up/D");
    ExTree->Branch("jet1pt_JEC_down", &jet1pt_JEC_down, "jet1pt_JEC_down/D");
    ExTree->Branch("jet1pt_JER_down", &jet1pt_JER_down, "jet1pt_JER_down/D");
    ExTree->Branch("jet1eta", &jet1eta, "jet1eta/D");
    ExTree->Branch("jet1eta_new", &jet1eta_new, "jet1eta_new/D");
    ExTree->Branch("jet1eta_JEC_up", &jet1eta_JEC_up, "jet1eta_JEC_up/D");
    ExTree->Branch("jet1eta_JEC_down", &jet1eta_JEC_down, "jet1eta_JEC_down/D");
    ExTree->Branch("jet1eta_JER_up", &jet1eta_JER_up, "jet1eta_JER_up/D");
    ExTree->Branch("jet1eta_JER_down", &jet1eta_JER_down, "jet1eta_JER_down/D");
    ExTree->Branch("jet1phi", &jet1phi, "jet1phi/D");
    ExTree->Branch("jet1phi_new", &jet1phi_new, "jet1phi_new/D");
    ExTree->Branch("jet1phi_JEC_up", &jet1phi_JEC_up, "jet1phi_JEC_up/D");
    ExTree->Branch("jet1phi_JEC_down", &jet1phi_JEC_down, "jet1phi_JEC_down/D");
    ExTree->Branch("jet1phi_JER_up", &jet1phi_JER_up, "jet1phi_JER_up/D");
    ExTree->Branch("jet1phi_JER_down", &jet1phi_JER_down, "jet1phi_JER_down/D");
    ExTree->Branch("jet1e", &jet1e, "jet1e/D");
    ExTree->Branch("jet1e_new", &jet1e_new, "jet1e_new/D");
    ExTree->Branch("jet1e_JEC_up", &jet1e_JEC_up, "jet1e_JEC_up/D");
    ExTree->Branch("jet1e_JER_up", &jet1e_JER_up, "jet1e_JER_up/D");
    ExTree->Branch("jet1e_JEC_down", &jet1e_JEC_down, "jet1e_JEC_down/D");
    ExTree->Branch("jet1e_JER_down", &jet1e_JER_down, "jet1e_JER_down/D");
    ExTree->Branch("jet1csv", &jet1csv, "jet1csv/D");
    ExTree->Branch("jet1csv_new", &jet1csv_new, "jet1csv_new/D");
    ExTree->Branch("jet1csv_JEC_up", &jet1csv_JEC_up, "jet1csv_JEC_up/D");
    ExTree->Branch("jet1csv_JER_up", &jet1csv_JER_up, "jet1csv_JER_up/D");
    ExTree->Branch("jet1csv_JEC_down", &jet1csv_JEC_down, "jet1csv_JEC_down/D");
    ExTree->Branch("jet1csv_JER_down", &jet1csv_JER_down, "jet1csv_JER_down/D");
    ExTree->Branch("jet1icsv", &jet1icsv, "jet1icsv/D");
    ExTree->Branch("jet1icsv_new", &jet1icsv_new, "jet1icsv_new/D");
    ExTree->Branch("jet1icsv_JEC_up", &jet1icsv_JEC_up, "jet1icsv_JEC_up/D");
    ExTree->Branch("jet1icsv_JER_up", &jet1icsv_JER_up, "jet1icsv_JER_up/D");
    ExTree->Branch("jet1icsv_JEC_down", &jet1icsv_JEC_down, "jet1icsv_JEC_down/D");
    ExTree->Branch("jet1icsv_JER_down", &jet1icsv_JER_down, "jet1icsv_JER_down/D");
    ExTree->Branch("jet2pt", &jet2pt, "jet2pt/D");
    ExTree->Branch("jet2pt_new", &jet2pt_new, "jet2pt_new/D");
    ExTree->Branch("jet2pt_JEC_up", &jet2pt_JEC_up, "jet2pt_JEC_up/D");
    ExTree->Branch("jet2pt_JER_up", &jet2pt_JER_up, "jet2pt_JER_up/D");
    ExTree->Branch("jet2pt_JEC_down", &jet2pt_JEC_down, "jet2pt_JEC_down/D");
    ExTree->Branch("jet2pt_JER_down", &jet2pt_JER_down, "jet2pt_JER_down/D");
    ExTree->Branch("jet2eta", &jet2eta, "jet2eta/D");
    ExTree->Branch("jet2eta_new", &jet2eta_new, "jet2eta_new/D");
    ExTree->Branch("jet2eta_JEC_up", &jet2eta_JEC_up, "jet2eta_JEC_up/D");
    ExTree->Branch("jet2eta_JEC_down", &jet2eta_JEC_down, "jet2eta_JEC_down/D");
    ExTree->Branch("jet2eta_JER_up", &jet2eta_JER_up, "jet2eta_JER_up/D");
    ExTree->Branch("jet2eta_JER_down", &jet2eta_JER_down, "jet2eta_JER_down/D");
    ExTree->Branch("jet2phi", &jet2phi, "jet2phi/D");
    ExTree->Branch("jet2phi_new", &jet2phi_new, "jet2phi_new/D");
    ExTree->Branch("jet2phi_JEC_up", &jet2phi_JEC_up, "jet2phi_JEC_up/D");
    ExTree->Branch("jet2phi_JEC_down", &jet2phi_JEC_down, "jet2phi_JEC_down/D");
    ExTree->Branch("jet2phi_JER_up", &jet2phi_JER_up, "jet2phi_JER_up/D");
    ExTree->Branch("jet2phi_JER_down", &jet2phi_JER_down, "jet2phi_JER_down/D");
    ExTree->Branch("jet2e", &jet2e, "jet2e/D");
    ExTree->Branch("jet2e_new", &jet2e_new, "jet2e_new/D");
    ExTree->Branch("jet2e_JEC_up", &jet2e_JEC_up, "jet2e_JEC_up/D");
    ExTree->Branch("jet2e_JER_up", &jet2e_JER_up, "jet2e_JER_up/D");
    ExTree->Branch("jet2e_JEC_down", &jet2e_JEC_down, "jet2e_JEC_down/D");
    ExTree->Branch("jet2csv", &jet2csv, "jet2csv/D");
    ExTree->Branch("jet2csv_new", &jet2csv_new, "jet2csv_new/D");
    ExTree->Branch("jet2csv_JEC_up", &jet2csv_JEC_up, "jet2csv_JEC_up/D");
    ExTree->Branch("jet2csv_JER_up", &jet2csv_JER_up, "jet2csv_JER_up/D");
    ExTree->Branch("jet2csv_JEC_down", &jet2csv_JEC_down, "jet2csv_JEC_down/D");
    ExTree->Branch("jet2csv_JER_down", &jet2csv_JER_down, "jet2csv_JER_down/D");
    ExTree->Branch("jet2icsv", &jet2icsv, "jet2icsv/D");
    ExTree->Branch("jet2icsv_new", &jet2icsv_new, "jet2icsv_new/D");
    ExTree->Branch("jet2icsv_JEC_up", &jet2icsv_JEC_up, "jet2icsv_JEC_up/D");
    ExTree->Branch("jet2icsv_JER_up", &jet2icsv_JER_up, "jet2icsv_JER_up/D");
    ExTree->Branch("jet2icsv_JEC_down", &jet2icsv_JEC_down, "jet2icsv_JEC_down/D");
    ExTree->Branch("jet2icsv_JER_down", &jet2icsv_JER_down, "jet2icsv_JER_down/D");
    ExTree->Branch("drj1a", &drj1a, "drj1a/D");
    ExTree->Branch("drj1a_new", &drj1a_new, "drj1a_new/D");
    ExTree->Branch("drj1a_JEC_up", &drj1a_JEC_up, "drj1a_JEC_up/D");
    ExTree->Branch("drj1a_JEC_down", &drj1a_JEC_down, "drj1a_JEC_down/D");
    ExTree->Branch("drj1a_JER_up", &drj1a_JER_up, "drj1a_JER_up/D");
    ExTree->Branch("drj1a_JER_down", &drj1a_JER_down, "drj1a_JER_down/D");
    ExTree->Branch("drj2a", &drj2a, "drj2a/D");
    ExTree->Branch("drj2a_new", &drj2a_new, "drj2a_new/D");
    ExTree->Branch("drj2a_JEC_up", &drj2a_JEC_up, "drj2a_JEC_up/D");
    ExTree->Branch("drj2a_JEC_down", &drj2a_JEC_down, "drj2a_JEC_down/D");
    ExTree->Branch("drj2a_JER_up", &drj2a_JER_up, "drj2a_JER_up/D");
    ExTree->Branch("drj2a_JER_down", &drj2a_JER_down, "drj2a_JER_down/D");
    ExTree->Branch("drj1l", &drj1l, "drj1l/D");
    ExTree->Branch("drj1l_new", &drj1l_new, "drj1l_new/D");
    ExTree->Branch("drj1l_JEC_up", &drj1l_JEC_up, "drj1l_JEC_up/D");
    ExTree->Branch("drj1l_JEC_down", &drj1l_JEC_down, "drj1l_JEC_down/D");
    ExTree->Branch("drj1l_JER_up", &drj1l_JER_up, "drj1l_JER_up/D");
    ExTree->Branch("drj1l_JER_down", &drj1l_JER_down, "drj1l_JER_down/D");
    ExTree->Branch("drj2l", &drj2l, "drj2l/D");
    ExTree->Branch("drj2l_new", &drj2l_new, "drj2l_new/D");
    ExTree->Branch("drj2l_JEC_up", &drj2l_JEC_up, "drj2l_JEC_up/D");
    ExTree->Branch("drj2l_JEC_down", &drj2l_JEC_down, "drj2l_JEC_down/D");
    ExTree->Branch("drj2l_JER_up", &drj2l_JER_up, "drj2l_JER_up/D");
    ExTree->Branch("drj2l_JER_down", &drj2l_JER_down, "drj2l_JER_down/D");
    ExTree->Branch("Mjj", &Mjj, "Mjj/D");
    ExTree->Branch("Mjj_new", &Mjj_new, "Mjj_new/D");
    ExTree->Branch("Mjj_JEC_up", &Mjj_JEC_up, "Mjj_JEC_up/D");
    ExTree->Branch("Mjj_JEC_down", &Mjj_JEC_down, "Mjj_JEC_down/D");
    ExTree->Branch("Mjj_JER_up", &Mjj_JER_up, "Mjj_JER_up/D");
    ExTree->Branch("Mjj_JER_down", &Mjj_JER_down, "Mjj_JER_down/D");
    ExTree->Branch("deltaeta", &deltaeta, "deltaeta/D");
    ExTree->Branch("deltaeta_new", &deltaeta_new, "deltaeta_new/D");
    ExTree->Branch("deltaeta_JEC_up", &deltaeta_JEC_up, "deltaeta_JEC_up/D");
    ExTree->Branch("deltaeta_JEC_down", &deltaeta_JEC_down, "deltaeta_JEC_down/D");
    ExTree->Branch("deltaeta_JER_up", &deltaeta_JER_up, "deltaeta_JER_up/D");
    ExTree->Branch("deltaeta_JER_down", &deltaeta_JER_down, "deltaeta_JER_down/D");
    ExTree->Branch("zepp", &zepp, "zepp/D");
    ExTree->Branch("zepp_new", &zepp_new, "zepp_new/D");
    ExTree->Branch("zepp_JEC_up", &zepp_JEC_up, "zepp_JEC_up/D");
    ExTree->Branch("zepp_JEC_down", &zepp_JEC_down, "zepp_JEC_down/D");
    ExTree->Branch("zepp_JER_up", &zepp_JER_up, "zepp_JER_up/D");
    ExTree->Branch("zepp_JER_down", &zepp_JER_down, "zepp_JER_down/D");
    ExTree->Branch("j1metPhi", &j1metPhi, "j1metPhi/D");
    ExTree->Branch("j1metPhi_new", &j1metPhi_new, "j1metPhi_new/D");
    ExTree->Branch("j1metPhi_JEC_up", &j1metPhi_JEC_up, "j1metPhi_JEC_up/D");
    ExTree->Branch("j1metPhi_JEC_down", &j1metPhi_JEC_down, "j1metPhi_JEC_down/D");
    ExTree->Branch("j1metPhi_JER_up", &j1metPhi_JER_up, "j1metPhi_JER_up/D");
    ExTree->Branch("j1metPhi_JER_down", &j1metPhi_JER_down, "j1metPhi_JER_down/D");
    ExTree->Branch("j2metPhi", &j2metPhi, "j2metPhi/D");
    ExTree->Branch("j2metPhi_new", &j2metPhi_new, "j2metPhi_new/D");
    ExTree->Branch("j2metPhi_JEC_up", &j2metPhi_JEC_up, "j2metPhi_JEC_up/D");
    ExTree->Branch("j2metPhi_JEC_down", &j2metPhi_JEC_down, "j2metPhi_JEC_down/D");
    ExTree->Branch("j2metPhi_JER_up", &j2metPhi_JER_up, "j2metPhi_JER_up/D");
    ExTree->Branch("j2metPhi_JER_down", &j2metPhi_JER_down, "j2metPhi_JER_down/D");
    ExTree->Branch("Dphiwajj", &Dphiwajj, "Dphiwajj/D");
    ExTree->Branch("Dphiwajj_new", &Dphiwajj_new, "Dphiwajj_new/D");
    ExTree->Branch("Dphiwajj_JEC_up", &Dphiwajj_JEC_up, "Dphiwajj_JEC_up/D");
    ExTree->Branch("Dphiwajj_JEC_down", &Dphiwajj_JEC_down, "Dphiwajj_JEC_down/D");
    ExTree->Branch("Dphiwajj_JER_up", &Dphiwajj_JER_up, "Dphiwajj_JER_up/D");
    ExTree->Branch("Dphiwajj_JER_down", &Dphiwajj_JER_down, "Dphiwajj_JER_down/D");
    ExTree->Branch("METraw_et", &METraw_et, "METraw_et/D");
    ExTree->Branch("METraw_phi", &METraw_phi, "METraw_phi/D");
    ExTree->Branch("METraw_sumEt", &METraw_sumEt, "METraw_sumEt/D");
    ExTree->Branch("genMET", &genMET, "genMET/D");
    ExTree->Branch("MET_et", &MET_et, "MET_et/D");
    ExTree->Branch("MET_et_new", &MET_et_new, "MET_et_new/D");
    ExTree->Branch("MET_et_JEC_up", &MET_et_JEC_up, "MET_et_JEC_up/D");
    ExTree->Branch("MET_et_JEC_down", &MET_et_JEC_down, "MET_et_JEC_down/D");
    ExTree->Branch("MET_et_JER_up", &MET_et_JER_up, "MET_et_JER_up/D");
    ExTree->Branch("MET_et_JER_down", &MET_et_JER_down, "MET_et_JER_down/D");
    ExTree->Branch("MET_phi", &MET_phi, "MET_phi/D");
    ExTree->Branch("MET_phi_new", &MET_phi_new, "MET_phi_new/D");
    ExTree->Branch("MET_phi_JEC_up", &MET_phi_JEC_up, "MET_phi_JEC_up/D");
    ExTree->Branch("MET_phi_JEC_down", &MET_phi_JEC_down, "MET_phi_JEC_down/D");
    ExTree->Branch("MET_phi_JER_up", &MET_phi_JER_up, "MET_phi_JER_up/D");
    ExTree->Branch("MET_phi_JER_down", &MET_phi_JER_down, "MET_phi_JER_down/D");
    ExTree->Branch("HLT_Ele1", &HLT_Ele1, "HLT_Ele1/I");
    ExTree->Branch("HLT_Ele2", &HLT_Ele2, "HLT_Ele2/I");
    ExTree->Branch("HLT_Mu1", &HLT_Mu1, "HLT_Mu1/I");
    ExTree->Branch("HLT_Mu2", &HLT_Mu2, "HLT_Mu2/I");
    ExTree->Branch("HLT_Mu3", &HLT_Mu3, "HLT_Mu3/I");
    ExTree->Branch("lumiWeight", &lumiWeight, "lumiWeight/D");
    ExTree->Branch("pileupWeight", &pileupWeight, "pileupWeight/D");
    std::cout<<"22222222222222"<<std::endl;
    fChain->SetBranchAddress("rawPt", &rawPt, &b_rawPt);
    fChain->SetBranchAddress("nevent", &nevent, &b_nevent);
    fChain->SetBranchAddress("run", &run, &b_run);
    fChain->SetBranchAddress("ls", &ls, &b_ls);
    fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
    fChain->SetBranchAddress("theWeight", &theWeight, &b_theWeight);
    fChain->SetBranchAddress("nump", &nump, &b_nump);
    fChain->SetBranchAddress("numm", &numm, &b_numm);
    fChain->SetBranchAddress("npT", &npT, &b_npT);
    fChain->SetBranchAddress("lep", &lep, &b_lep);
    fChain->SetBranchAddress("ptVlep", &ptVlep, &b_ptVlep);
    fChain->SetBranchAddress("ptVlepJEC", &ptVlepJEC, &b_ptVlepJEC);
    fChain->SetBranchAddress("yVlepJEC", &yVlepJEC, &b_yVlepJEC);
    fChain->SetBranchAddress("phiVlepJEC", &phiVlepJEC, &b_phiVlepJEC);
    fChain->SetBranchAddress("massVlepJEC", &massVlepJEC, &b_massVlepJEC);
    fChain->SetBranchAddress("mtVlepJECnew", &mtVlepJECnew, &b_mtVlepJECnew);
    fChain->SetBranchAddress("ptVlepJEC_new", &ptVlepJEC_new, &b_ptVlepJEC_new);
    fChain->SetBranchAddress("yVlepJEC_new", &yVlepJEC_new, &b_yVlepJEC_new);
    fChain->SetBranchAddress("phiVlepJEC_new", &phiVlepJEC_new, &b_phiVlepJEC_new);
    fChain->SetBranchAddress("massVlepJEC_new", &massVlepJEC_new, &b_massVlepJEC_new);
    fChain->SetBranchAddress("mtVlepJECnew_new", &mtVlepJECnew_new, &b_mtVlepJECnew_new);
    fChain->SetBranchAddress("ptVlepJEC_JEC_up", &ptVlepJEC_JEC_up, &b_ptVlepJEC_JEC_up);
    fChain->SetBranchAddress("yVlepJEC_JEC_up", &yVlepJEC_JEC_up, &b_yVlepJEC_JEC_up);
    fChain->SetBranchAddress("phiVlepJEC_JEC_up", &phiVlepJEC_JEC_up, &b_phiVlepJEC_JEC_up);
    fChain->SetBranchAddress("massVlepJEC_JEC_up", &massVlepJEC_JEC_up, &b_massVlepJEC_JEC_up);
    fChain->SetBranchAddress("mtVlepJECnew_JEC_up", &mtVlepJECnew_JEC_up, &b_mtVlepJECnew_JEC_up);
    fChain->SetBranchAddress("ptVlepJEC_JEC_down", &ptVlepJEC_JEC_down, &b_ptVlepJEC_JEC_down);
    fChain->SetBranchAddress("yVlepJEC_JEC_down", &yVlepJEC_JEC_down, &b_yVlepJEC_JEC_down);
    fChain->SetBranchAddress("phiVlepJEC_JEC_down", &phiVlepJEC_JEC_down, &b_phiVlepJEC_JEC_down);
    fChain->SetBranchAddress("massVlepJEC_JEC_down", &massVlepJEC_JEC_down, &b_massVlepJEC_JEC_down);
    fChain->SetBranchAddress("mtVlepJECnew_JEC_down", &mtVlepJECnew_JEC_down, &b_mtVlepJECnew_JEC_down);
    fChain->SetBranchAddress("ptVlepJEC_JER_up", &ptVlepJEC_JER_up, &b_ptVlepJEC_JER_up);
    fChain->SetBranchAddress("yVlepJEC_JER_up", &yVlepJEC_JER_up, &b_yVlepJEC_JER_up);
    fChain->SetBranchAddress("phiVlepJEC_JER_up", &phiVlepJEC_JER_up, &b_phiVlepJEC_JER_up);
    fChain->SetBranchAddress("massVlepJEC_JER_up", &massVlepJEC_JER_up, &b_massVlepJEC_JER_up);
    fChain->SetBranchAddress("mtVlepJECnew_JER_up", &mtVlepJECnew_JER_up, &b_mtVlepJECnew_JER_up);
    fChain->SetBranchAddress("ptVlepJEC_JER_down", &ptVlepJEC_JER_down, &b_ptVlepJEC_JER_down);
    fChain->SetBranchAddress("yVlepJEC_JER_down", &yVlepJEC_JER_down, &b_yVlepJEC_JER_down);
    fChain->SetBranchAddress("phiVlepJEC_JER_down", &phiVlepJEC_JER_down, &b_phiVlepJEC_JER_down);
    fChain->SetBranchAddress("massVlepJEC_JER_down", &massVlepJEC_JER_down, &b_massVlepJEC_JER_down);
    fChain->SetBranchAddress("mtVlepJECnew_JER_down", &mtVlepJECnew_JER_down, &b_mtVlepJECnew_JER_down);

    fChain->SetBranchAddress("Mla", &Mla, &b_Mla);
    fChain->SetBranchAddress("Mla_f", &Mla_f, &b_Mla_f);
    fChain->SetBranchAddress("Mva", &Mva, &b_Mva);
    fChain->SetBranchAddress("Mva_f", &Mva_f, &b_Mva_f);
    fChain->SetBranchAddress("nlooseeles", &nlooseeles, &b_nlooseeles);
    fChain->SetBranchAddress("nloosemus", &nloosemus, &b_nloosemus);
    fChain->SetBranchAddress("genjet_pt", genjet_pt, &b_genjet_pt);
    fChain->SetBranchAddress("genjet_eta", genjet_eta, &b_genjet_eta);
    fChain->SetBranchAddress("genjet_phi", genjet_phi, &b_genjet_phi);
    fChain->SetBranchAddress("genjet_e", genjet_e, &b_genjet_e);
    fChain->SetBranchAddress("photon_pt", photon_pt, &b_photon_pt);
    fChain->SetBranchAddress("photon_eta", photon_eta, &b_photon_eta);
    fChain->SetBranchAddress("photon_phi", photon_phi, &b_photon_phi);
    fChain->SetBranchAddress("photon_e", photon_e, &b_photon_e);
    fChain->SetBranchAddress("photonsc_eta", photonsc_eta, &b_photonsc_eta);
    fChain->SetBranchAddress("photonsc_phi", photonsc_phi, &b_photonsc_phi);
    fChain->SetBranchAddress("photon_pev", photon_pev, &b_photon_pev);
    fChain->SetBranchAddress("photon_pevnew", photon_pevnew, &b_photon_pevnew);
    fChain->SetBranchAddress("photon_ppsv", photon_ppsv, &b_photon_ppsv);
    fChain->SetBranchAddress("photon_hoe", photon_hoe, &b_photon_hoe);
    fChain->SetBranchAddress("photon_sieie", photon_sieie, &b_photon_sieie);
    fChain->SetBranchAddress("photon_sieie2", photon_sieie2, &b_photon_sieie2);
    fChain->SetBranchAddress("photon_chiso", photon_chiso, &b_photon_chiso);
    fChain->SetBranchAddress("photon_nhiso", photon_nhiso, &b_photon_nhiso);
    fChain->SetBranchAddress("photon_phoiso", photon_phoiso, &b_photon_phoiso);
    fChain->SetBranchAddress("photon_isprompt", photon_isprompt, &b_photon_isprompt);
    fChain->SetBranchAddress("photon_drla", photon_drla, &b_photon_drla);
    fChain->SetBranchAddress("photon_mla", photon_mla, &b_photon_mla);
    fChain->SetBranchAddress("photonhaspixelseed", &photonhaspixelseed, &b_photonhaspixelseed);
    fChain->SetBranchAddress("photonhaspixelseed_f", &photonhaspixelseed_f, &b_photonhaspixelseed_f);
    fChain->SetBranchAddress("photonpasseleveto", &photonpasseleveto, &b_photonpasseleveto);
    fChain->SetBranchAddress("photonpasseleveto_f", &photonpasseleveto_f, &b_photonpasseleveto_F);
    fChain->SetBranchAddress("photonet", &photonet, &b_photonet);
    fChain->SetBranchAddress("photonet_f", &photonet_f, &b_photonet_f);
    fChain->SetBranchAddress("photoneta", &photoneta, &b_photoneta);
    fChain->SetBranchAddress("photoneta_f", &photoneta_f, &b_photoneta_f);
    fChain->SetBranchAddress("photonphi", &photonphi, &b_photonphi);
    fChain->SetBranchAddress("photonphi_f", &photonphi_f, &b_photonphi_f);
    fChain->SetBranchAddress("photone", &photone, &b_photone);
    fChain->SetBranchAddress("photone_f", &photone_f, &b_photone_f);
    fChain->SetBranchAddress("photonsceta", &photonsceta, &b_photonsceta);
    fChain->SetBranchAddress("photonsceta_f", &photonsceta_f, &b_photonsceta_f);
    fChain->SetBranchAddress("photonscphi", &photonscphi, &b_photonscphi);
    fChain->SetBranchAddress("photonscphi_f", &photonscphi_f, &b_photonscphi_f);
    fChain->SetBranchAddress("iphoton", &iphoton, &b_iphoton);
    fChain->SetBranchAddress("iphoton_f", &iphoton_f, &b_iphoton_f);
    fChain->SetBranchAddress("drla", &drla, &b_drla);
    fChain->SetBranchAddress("drla_f", &drla_f, &b_drla_f);
    fChain->SetBranchAddress("isTrue", &isTrue, &b_isTrue);
    fChain->SetBranchAddress("isprompt", &isprompt, &b_isprompt);
    fChain->SetBranchAddress("ispromptLep", &ispromptLep, &b_ispromptLep);
    fChain->SetBranchAddress("ak4jet_hf", ak4jet_hf, &b_ak4jet_hf);
    fChain->SetBranchAddress("ak4jet_pf", ak4jet_pf, &b_ak4jet_pf);
    fChain->SetBranchAddress("jet1hf", &jet1hf, &b_jet1hf);
    fChain->SetBranchAddress("jet1pf", &jet1pf, &b_jet1pf);
    fChain->SetBranchAddress("jet2hf", &jet2hf, &b_jet2hf);
    fChain->SetBranchAddress("jet2pf", &jet2pf, &b_jet2pf);
    fChain->SetBranchAddress("jet1hf_f", &jet1hf_f, &b_jet1hf_f);
    fChain->SetBranchAddress("jet1pf_f", &jet1pf_f, &b_jet1pf_f);
    fChain->SetBranchAddress("jet2hf_f", &jet2hf_f, &b_jet2hf_f);
    fChain->SetBranchAddress("jet2pf_f", &jet2pf_f, &b_jet2pf_f);
    fChain->SetBranchAddress("ak4jet_csv", ak4jet_csv, &b_ak4jet_csv);
    fChain->SetBranchAddress("ak4jet_icsv", ak4jet_icsv, &b_ak4jet_icsv);
    fChain->SetBranchAddress("ak4jet_pt_old", ak4jet_pt_old, &b_ak4jet_pt_old);
    fChain->SetBranchAddress("ak4jet_pt_new", ak4jet_pt_new, &b_ak4jet_pt_new);
    fChain->SetBranchAddress("ak4jet_pt_JEC_up", ak4jet_pt_JEC_up, &b_ak4jet_pt_JEC_up);
    fChain->SetBranchAddress("ak4jet_pt_JEC_down", ak4jet_pt_JEC_down, &b_ak4jet_pt_JEC_down);
    fChain->SetBranchAddress("ak4jet_pt_JER_up", ak4jet_pt_JER_up, &b_ak4jet_pt_JER_up);
    fChain->SetBranchAddress("ak4jet_pt_JER_down", ak4jet_pt_JER_down, &b_ak4jet_pt_JER_down);
    fChain->SetBranchAddress("ak4jet_eta", ak4jet_eta, &b_ak4jet_eta);
    fChain->SetBranchAddress("ak4jet_phi", ak4jet_phi, &b_ak4jet_phi);
    fChain->SetBranchAddress("ak4jet_e_old", ak4jet_e_old, &b_ak4jet_e_old);
    fChain->SetBranchAddress("ak4jet_e_new", ak4jet_e_new, &b_ak4jet_e_new);
    fChain->SetBranchAddress("ak4jet_e_JEC_up", ak4jet_e_JEC_up, &b_ak4jet_e_JEC_up);
    fChain->SetBranchAddress("ak4jet_e_JEC_down", ak4jet_e_JEC_down, &b_ak4jet_e_JEC_down);
    fChain->SetBranchAddress("ak4jet_e_JER_up", ak4jet_e_JER_up, &b_ak4jet_e_JER_up);
    fChain->SetBranchAddress("ak4jet_e_JER_down", ak4jet_e_JER_down, &b_ak4jet_e_JER_down);
    //    fChain->SetBranchAddress("ak4jet_csv", ak4jet_csv, &b_ak4jet_csv);
    //    fChain->SetBranchAddress("ak4jet_icsv", ak4jet_icsv, &b_ak4jet_icsv);
    fChain->SetBranchAddress("jet1pt", &jet1pt, &b_jet1pt);
    fChain->SetBranchAddress("jet1pt_new", &jet1pt_new, &b_jet1pt_new);
    fChain->SetBranchAddress("jet1pt_JEC_up", &jet1pt_JEC_up, &b_jet1pt_JEC_up);
    fChain->SetBranchAddress("jet1pt_JER_up", &jet1pt_JER_up, &b_jet1pt_JER_up);
    fChain->SetBranchAddress("jet1pt_JEC_down", &jet1pt_JEC_down, &b_jet1pt_JEC_down);
    fChain->SetBranchAddress("jet1pt_JER_down", &jet1pt_JER_down, &b_jet1pt_JER_down);
    fChain->SetBranchAddress("jet1pt_f", &jet1pt_f, &b_jet1pt_f);
    fChain->SetBranchAddress("jet1pt_new_f", &jet1pt_new_f, &b_jet1pt_new_f);
    fChain->SetBranchAddress("jet1pt_JEC_up_f", &jet1pt_JEC_up_f, &b_jet1pt_JEC_up_f);
    fChain->SetBranchAddress("jet1pt_JER_up_f", &jet1pt_JER_up_f, &b_jet1pt_JER_up_f);
    fChain->SetBranchAddress("jet1pt_JEC_down_f", &jet1pt_JEC_down_f, &b_jet1pt_JEC_down_f);
    fChain->SetBranchAddress("jet1pt_JER_down_f", &jet1pt_JER_down_f, &b_jet1pt_JER_down_f);
    fChain->SetBranchAddress("jet1eta", &jet1eta, &b_jet1eta);
    fChain->SetBranchAddress("jet1eta_new", &jet1eta_new, &b_jet1eta_new);
    fChain->SetBranchAddress("jet1eta_JEC_up", &jet1eta_JEC_up, &b_jet1eta_JEC_up);
    fChain->SetBranchAddress("jet1eta_JEC_down", &jet1eta_JEC_down, &b_jet1eta_JEC_down);
    fChain->SetBranchAddress("jet1eta_JER_up", &jet1eta_JER_up, &b_jet1eta_JER_up);
    fChain->SetBranchAddress("jet1eta_JER_down", &jet1eta_JER_down, &b_jet1eta_JER_down);
    fChain->SetBranchAddress("jet1eta_f", &jet1eta_f, &b_jet1eta_f);
    fChain->SetBranchAddress("jet1eta_new_f", &jet1eta_new_f, &b_jet1eta_new_f);
    fChain->SetBranchAddress("jet1eta_JEC_up_f", &jet1eta_JEC_up_f, &b_jet1eta_JEC_up_f);
    fChain->SetBranchAddress("jet1eta_JEC_down_f", &jet1eta_JEC_down_f, &b_jet1eta_JEC_down_f);
    fChain->SetBranchAddress("jet1eta_JER_up_f", &jet1eta_JER_up_f, &b_jet1eta_JER_up_f);
    fChain->SetBranchAddress("jet1eta_JER_down_f", &jet1eta_JER_down_f, &b_jet1eta_JER_down_f);
    fChain->SetBranchAddress("jet1phi", &jet1phi, &b_jet1phi);
    fChain->SetBranchAddress("jet1phi_new", &jet1phi_new, &b_jet1phi_new);
    fChain->SetBranchAddress("jet1phi_JEC_up", &jet1phi_JEC_up, &b_jet1phi_JEC_up);
    fChain->SetBranchAddress("jet1phi_JEC_down", &jet1phi_JEC_down, &b_jet1phi_JEC_down);
    fChain->SetBranchAddress("jet1phi_JER_up", &jet1phi_JER_up, &b_jet1phi_JER_up);
    fChain->SetBranchAddress("jet1phi_JER_down", &jet1phi_JER_down, &b_jet1phi_JER_down);
    fChain->SetBranchAddress("jet1phi_f", &jet1phi_f, &b_jet1phi_f);
    fChain->SetBranchAddress("jet1phi_new_f", &jet1phi_new_f, &b_jet1phi_new_f);
    fChain->SetBranchAddress("jet1phi_JEC_up_f", &jet1phi_JEC_up_f, &b_jet1phi_JEC_up_f);
    fChain->SetBranchAddress("jet1phi_JEC_down_f", &jet1phi_JEC_down_f, &b_jet1phi_JEC_down_f);
    fChain->SetBranchAddress("jet1phi_JER_up_f", &jet1phi_JER_up_f, &b_jet1phi_JER_up_f);
    fChain->SetBranchAddress("jet1phi_JER_down_f", &jet1phi_JER_down_f, &b_jet1phi_JER_down_f);
    fChain->SetBranchAddress("jet1e", &jet1e, &b_jet1e);
    fChain->SetBranchAddress("jet1e_new", &jet1e_new, &b_jet1e_new);
    fChain->SetBranchAddress("jet1e_JEC_up", &jet1e_JEC_up, &b_jet1e_JEC_up);
    fChain->SetBranchAddress("jet1e_JER_up", &jet1e_JER_up, &b_jet1e_JER_up);
    fChain->SetBranchAddress("jet1e_JEC_down", &jet1e_JEC_down, &b_jet1e_JEC_down);
    fChain->SetBranchAddress("jet1e_JER_down", &jet1e_JER_down, &b_jet1e_JER_down);
    fChain->SetBranchAddress("jet1e_f", &jet1e_f, &b_jet1e_f);
    fChain->SetBranchAddress("jet1e_new_f", &jet1e_new_f, &b_jet1e_new_f);
    fChain->SetBranchAddress("jet1e_JEC_up_f", &jet1e_JEC_up_f, &b_jet1e_JEC_up_f);
    fChain->SetBranchAddress("jet1e_JER_up_f", &jet1e_JER_up_f, &b_jet1e_JER_up_f);
    fChain->SetBranchAddress("jet1e_JEC_down_f", &jet1e_JEC_down_f, &b_jet1e_JEC_down_f);
    fChain->SetBranchAddress("jet1e_JER_down_f", &jet1e_JER_down_f, &b_jet1e_JER_down_f);
    fChain->SetBranchAddress("jet1csv", &jet1csv, &b_jet1csv);
    fChain->SetBranchAddress("jet1csv_new", &jet1csv_new, &b_jet1csv_new);
    fChain->SetBranchAddress("jet1csv_JEC_up", &jet1csv_JEC_up, &b_jet1csv_JEC_up);
    fChain->SetBranchAddress("jet1csv_JER_up", &jet1csv_JER_up, &b_jet1csv_JER_up);
    fChain->SetBranchAddress("jet1csv_JEC_down", &jet1csv_JEC_down, &b_jet1csv_JEC_down);
    fChain->SetBranchAddress("jet1csv_JER_down", &jet1csv_JER_down, &b_jet1csv_JER_down);
    fChain->SetBranchAddress("jet1csv_f", &jet1csv_f, &b_jet1csv_f);
    fChain->SetBranchAddress("jet1csv_new_f", &jet1csv_new_f, &b_jet1csv_new_f);
    fChain->SetBranchAddress("jet1csv_JEC_up_f", &jet1csv_JEC_up_f, &b_jet1csv_JEC_up_f);
    fChain->SetBranchAddress("jet1csv_JER_up_f", &jet1csv_JER_up_f, &b_jet1csv_JER_up_f);
    fChain->SetBranchAddress("jet1csv_JEC_down_f", &jet1csv_JEC_down_f, &b_jet1csv_JEC_down_f);
    fChain->SetBranchAddress("jet1csv_JER_down_f", &jet1csv_JER_down_f, &b_jet1csv_JER_down_f);
    fChain->SetBranchAddress("jet1icsv", &jet1icsv, &b_jet1icsv);
    fChain->SetBranchAddress("jet1icsv_new", &jet1icsv_new, &b_jet1icsv_new);
    fChain->SetBranchAddress("jet1icsv_JEC_up", &jet1icsv_JEC_up, &b_jet1icsv_JEC_up);
    fChain->SetBranchAddress("jet1icsv_JER_up", &jet1icsv_JER_up, &b_jet1icsv_JER_up);
    fChain->SetBranchAddress("jet1icsv_JEC_down", &jet1icsv_JEC_down, &b_jet1icsv_JEC_down);
    fChain->SetBranchAddress("jet1icsv_JER_down", &jet1icsv_JER_down, &b_jet1icsv_JER_down);
    fChain->SetBranchAddress("jet1icsv_f", &jet1icsv_f, &b_jet1icsv_f);
    fChain->SetBranchAddress("jet1icsv_new_f", &jet1icsv_new_f, &b_jet1icsv_new_f);
    fChain->SetBranchAddress("jet1icsv_JEC_up_f", &jet1icsv_JEC_up_f, &b_jet1icsv_JEC_up_f);
    fChain->SetBranchAddress("jet1icsv_JER_up_f", &jet1icsv_JER_up_f, &b_jet1icsv_JER_up_f);
    fChain->SetBranchAddress("jet1icsv_JEC_down_f", &jet1icsv_JEC_down_f, &b_jet1icsv_JEC_down_f);
    fChain->SetBranchAddress("jet1icsv_JER_down_f", &jet1icsv_JER_down_f, &b_jet1icsv_JER_down_f);
    fChain->SetBranchAddress("jet2pt", &jet2pt, &b_jet2pt);
    fChain->SetBranchAddress("jet2pt_new", &jet2pt_new, &b_jet2pt_new);
    fChain->SetBranchAddress("jet2pt_JEC_up", &jet2pt_JEC_up, &b_jet2pt_JEC_up);
    fChain->SetBranchAddress("jet2pt_JER_up", &jet2pt_JER_up, &b_jet2pt_JER_up);
    fChain->SetBranchAddress("jet2pt_JEC_down", &jet2pt_JEC_down, &b_jet2pt_JEC_down);
    fChain->SetBranchAddress("jet2pt_JER_down", &jet2pt_JER_down, &b_jet2pt_JER_down);
    fChain->SetBranchAddress("jet2pt_f", &jet2pt_f, &b_jet2pt_f);
    fChain->SetBranchAddress("jet2pt_new_f", &jet2pt_new_f, &b_jet2pt_new_f);
    fChain->SetBranchAddress("jet2pt_JEC_up_f", &jet2pt_JEC_up_f, &b_jet2pt_JEC_up_f);
    fChain->SetBranchAddress("jet2pt_JER_up_f", &jet2pt_JER_up_f, &b_jet2pt_JER_up_f);
    fChain->SetBranchAddress("jet2pt_JEC_down_f", &jet2pt_JEC_down_f, &b_jet2pt_JEC_down_f);
    fChain->SetBranchAddress("jet2pt_JER_down_f", &jet2pt_JER_down_f, &b_jet2pt_JER_down_f);
    fChain->SetBranchAddress("jet2eta", &jet2eta, &b_jet2eta);
    fChain->SetBranchAddress("jet2eta_new", &jet2eta_new, &b_jet2eta_new);
    fChain->SetBranchAddress("jet2eta_JEC_up", &jet2eta_JEC_up, &b_jet2eta_JEC_up);
    fChain->SetBranchAddress("jet2eta_JEC_down", &jet2eta_JEC_down, &b_jet2eta_JEC_down);
    fChain->SetBranchAddress("jet2eta_JER_up", &jet2eta_JER_up, &b_jet2eta_JER_up);
    fChain->SetBranchAddress("jet2eta_JER_down", &jet2eta_JER_down, &b_jet2eta_JER_down);
    fChain->SetBranchAddress("jet2eta_f", &jet2eta_f, &b_jet2eta_f);
    fChain->SetBranchAddress("jet2phi", &jet2phi, &b_jet2phi);
    fChain->SetBranchAddress("jet2phi_new", &jet2phi_new, &b_jet2phi_new);
    fChain->SetBranchAddress("jet2phi_JEC_up", &jet2phi_JEC_up, &b_jet2phi_JEC_up);
    fChain->SetBranchAddress("jet2phi_JEC_down", &jet2phi_JEC_down, &b_jet2phi_JEC_down);
    fChain->SetBranchAddress("jet2phi_JER_up", &jet2phi_JER_up, &b_jet2phi_JER_up);
    fChain->SetBranchAddress("jet2phi_JER_down", &jet2phi_JER_down, &b_jet2phi_JER_down);
    fChain->SetBranchAddress("jet2phi_f", &jet2phi_f, &b_jet2phi_f);
    fChain->SetBranchAddress("jet2phi_new_f", &jet2phi_new_f, &b_jet2phi_new_f);
    fChain->SetBranchAddress("jet2phi_JEC_up_f", &jet2phi_JEC_up_f, &b_jet2phi_JEC_up_f);
    fChain->SetBranchAddress("jet2phi_JEC_down_f", &jet2phi_JEC_down_f, &b_jet2phi_JEC_down_f);
    fChain->SetBranchAddress("jet2phi_JER_up_f", &jet2phi_JER_up_f, &b_jet2phi_JER_up_f);
    fChain->SetBranchAddress("jet2phi_JER_down_f", &jet2phi_JER_down_f, &b_jet2phi_JER_down_f);
    fChain->SetBranchAddress("jet2eta_new_f", &jet2eta_new_f, &b_jet2eta_new_f);
    fChain->SetBranchAddress("jet2eta_JEC_up_f", &jet2eta_JEC_up_f, &b_jet2eta_JEC_up_f);
    fChain->SetBranchAddress("jet2eta_JEC_down_f", &jet2eta_JEC_down_f, &b_jet2eta_JEC_down_f);
    fChain->SetBranchAddress("jet2e", &jet2e, &b_jet2e);
    fChain->SetBranchAddress("jet2e_new", &jet2e_new, &b_jet2e_new);
    fChain->SetBranchAddress("jet2e_JEC_up", &jet2e_JEC_up, &b_jet2e_JEC_up);
    fChain->SetBranchAddress("jet2e_JER_up", &jet2e_JER_up, &b_jet2e_JER_up);
    fChain->SetBranchAddress("jet2e_JEC_down", &jet2e_JEC_down, &b_jet2e_JEC_down);
    fChain->SetBranchAddress("jet2e_JER_down", &jet2e_JER_down, &b_jet2e_JER_down);
    fChain->SetBranchAddress("jet2e_f", &jet2e_f, &b_jet2e_f);
    fChain->SetBranchAddress("jet2e_new_f", &jet2e_new_f, &b_jet2e_new_f);
    fChain->SetBranchAddress("jet2e_JEC_up_f", &jet2e_JEC_up_f, &b_jet2e_JEC_up_f);
    fChain->SetBranchAddress("jet2e_JER_up_f", &jet2e_JER_up_f, &b_jet2e_JER_up_f);
    fChain->SetBranchAddress("jet2e_JEC_down_f", &jet2e_JEC_down_f, &b_jet2e_JEC_down_f);
    fChain->SetBranchAddress("jet2e_JER_down_f", &jet2e_JER_down_f, &b_jet2e_JER_down_f);
    fChain->SetBranchAddress("jet2csv", &jet2csv, &b_jet2csv);
    fChain->SetBranchAddress("jet2csv_new", &jet2csv_new, &b_jet2csv_new);
    fChain->SetBranchAddress("jet2csv_JEC_up", &jet2csv_JEC_up, &b_jet2csv_JEC_up);
    fChain->SetBranchAddress("jet2csv_JER_up", &jet2csv_JER_up, &b_jet2csv_JER_up);
    fChain->SetBranchAddress("jet2csv_JEC_down", &jet2csv_JEC_down, &b_jet2csv_JEC_down);
    fChain->SetBranchAddress("jet2csv_JER_down", &jet2csv_JER_down, &b_jet2csv_JER_down);
    fChain->SetBranchAddress("jet2csv_f", &jet2csv_f, &b_jet2csv_f);
    fChain->SetBranchAddress("jet2csv_new_f", &jet2csv_new_f, &b_jet2csv_new_f);
    fChain->SetBranchAddress("jet2csv_JEC_up_f", &jet2csv_JEC_up_f, &b_jet2csv_JEC_up_f);
    fChain->SetBranchAddress("jet2csv_JER_up_f", &jet2csv_JER_up_f, &b_jet2csv_JER_up_f);
    fChain->SetBranchAddress("jet2csv_JEC_down_f", &jet2csv_JEC_down_f, &b_jet2csv_JEC_down_f);
    fChain->SetBranchAddress("jet2csv_JER_down_f", &jet2csv_JER_down_f, &b_jet2csv_JER_down_f);
    fChain->SetBranchAddress("jet2icsv", &jet2icsv, &b_jet2icsv);
    fChain->SetBranchAddress("jet2icsv_new", &jet2icsv_new, &b_jet2icsv_new);
    fChain->SetBranchAddress("jet2icsv_JEC_up", &jet2icsv_JEC_up, &b_jet2icsv_JEC_up);
    fChain->SetBranchAddress("jet2icsv_JER_up", &jet2icsv_JER_up, &b_jet2icsv_JER_up);
    fChain->SetBranchAddress("jet2icsv_JEC_down", &jet2icsv_JEC_down, &b_jet2icsv_JEC_down);
    fChain->SetBranchAddress("jet2icsv_JER_down", &jet2icsv_JER_down, &b_jet2icsv_JER_down);
    fChain->SetBranchAddress("jet2icsv_f", &jet2icsv_f, &b_jet2icsv_f);
    fChain->SetBranchAddress("jet2icsv_new_f", &jet2icsv_new_f, &b_jet2icsv_new_f);
    fChain->SetBranchAddress("jet2icsv_JEC_up_f", &jet2icsv_JEC_up_f, &b_jet2icsv_JEC_up_f);
    fChain->SetBranchAddress("jet2icsv_JER_up_f", &jet2icsv_JER_up_f, &b_jet2icsv_JER_up_f);
    fChain->SetBranchAddress("jet2icsv_JEC_down_f", &jet2icsv_JEC_down_f, &b_jet2icsv_JEC_down_f);
    fChain->SetBranchAddress("jet2icsv_JER_down_f", &jet2icsv_JER_down_f, &b_jet2icsv_JER_down_f);
    fChain->SetBranchAddress("drj1a", &drj1a, &b_drj1a);
    fChain->SetBranchAddress("drj1a_new", &drj1a_new, &b_drj1a_new);
    fChain->SetBranchAddress("drj1a_JEC_up", &drj1a_JEC_up, &b_drj1a_JEC_up);
    fChain->SetBranchAddress("drj1a_JEC_down", &drj1a_JEC_down, &b_drj1a_JEC_down);
    fChain->SetBranchAddress("drj1a_JER_up", &drj1a_JER_up, &b_drj1a_JER_up);
    fChain->SetBranchAddress("drj1a_JER_down", &drj1a_JER_down, &b_drj1a_JER_down);
    fChain->SetBranchAddress("drj1a_f", &drj1a_f, &b_drj1a_f);
    fChain->SetBranchAddress("drj1a_new_f", &drj1a_new_f, &b_drj1a_new_f);
    fChain->SetBranchAddress("drj1a_JEC_up_f", &drj1a_JEC_up_f, &b_drj1a_JEC_up_f);
    fChain->SetBranchAddress("drj1a_JEC_down_f", &drj1a_JEC_down_f, &b_drj1a_JEC_down_f);
    fChain->SetBranchAddress("drj1a_JER_up_f", &drj1a_JER_up_f, &b_drj1a_JER_up_f);
    fChain->SetBranchAddress("drj1a_JER_down_f", &drj1a_JER_down_f, &b_drj1a_JER_down_f);
    fChain->SetBranchAddress("drj2a", &drj2a, &b_drj2a);
    fChain->SetBranchAddress("drj2a_new", &drj2a_new, &b_drj2a_new);
    fChain->SetBranchAddress("drj2a_JEC_up", &drj2a_JEC_up, &b_drj2a_JEC_up);
    fChain->SetBranchAddress("drj2a_JEC_down", &drj2a_JEC_down, &b_drj2a_JEC_down);
    fChain->SetBranchAddress("drj2a_JER_up", &drj2a_JER_up, &b_drj2a_JER_up);
    fChain->SetBranchAddress("drj2a_JER_down", &drj2a_JER_down, &b_drj2a_JER_down);
    fChain->SetBranchAddress("drj2a_f", &drj2a_f, &b_drj2a_f);
    fChain->SetBranchAddress("drj2a_new_f", &drj2a_new_f, &b_drj2a_new_f);
    fChain->SetBranchAddress("drj2a_JEC_up_f", &drj2a_JEC_up_f, &b_drj2a_JEC_up_f);
    fChain->SetBranchAddress("drj2a_JEC_down_f", &drj2a_JEC_down_f, &b_drj2a_JEC_down_f);
    fChain->SetBranchAddress("drj2a_JER_up_f", &drj2a_JER_up_f, &b_drj2a_JER_up_f);
    fChain->SetBranchAddress("drj2a_JER_down_f", &drj2a_JER_down_f, &b_drj2a_JER_down_f);
    fChain->SetBranchAddress("drj1l", &drj1l, &b_drj1l);
    fChain->SetBranchAddress("drj1l_new", &drj1l_new, &b_drj1l_new);
    fChain->SetBranchAddress("drj1l_JEC_up", &drj1l_JEC_up, &b_drj1l_JEC_up);
    fChain->SetBranchAddress("drj1l_JEC_down", &drj1l_JEC_down, &b_drj1l_JEC_down);
    fChain->SetBranchAddress("drj1l_JER_up", &drj1l_JER_up, &b_drj1l_JER_up);
    fChain->SetBranchAddress("drj1l_JER_down", &drj1l_JER_down, &b_drj1l_JER_down);
    fChain->SetBranchAddress("drj1l_f", &drj1l_f, &b_drj1l_f);
    fChain->SetBranchAddress("drj1l_new_f", &drj1l_new_f, &b_drj1l_new_f);
    fChain->SetBranchAddress("drj1l_JEC_up_f", &drj1l_JEC_up_f, &b_drj1l_JEC_up_f);
    fChain->SetBranchAddress("drj1l_JEC_down_f", &drj1l_JEC_down_f, &b_drj1l_JEC_down_f);
    fChain->SetBranchAddress("drj1l_JER_up_f", &drj1l_JER_up_f, &b_drj1l_JER_up_f);
    fChain->SetBranchAddress("drj1l_JER_down_f", &drj1l_JER_down_f, &b_drj1l_JER_down_f);
    fChain->SetBranchAddress("drj2l", &drj2l, &b_drj2l);
    fChain->SetBranchAddress("drj2l_new", &drj2l_new, &b_drj2l_new);
    fChain->SetBranchAddress("drj2l_JEC_up", &drj2l_JEC_up, &b_drj2l_JEC_up);
    fChain->SetBranchAddress("drj2l_JEC_down", &drj2l_JEC_down, &b_drj2l_JEC_down);
    fChain->SetBranchAddress("drj2l_JER_up", &drj2l_JER_up, &b_drj2l_JER_up);
    fChain->SetBranchAddress("drj2l_JER_down", &drj2l_JER_down, &b_drj2l_JER_down);
    fChain->SetBranchAddress("drj2l_f", &drj2l_f, &b_drj2l_f);
    fChain->SetBranchAddress("drj2l_new_f", &drj2l_new_f, &b_drj2l_new_f);
    fChain->SetBranchAddress("drj2l_JEC_up_f", &drj2l_JEC_up_f, &b_drj2l_JEC_up_f);
    fChain->SetBranchAddress("drj2l_JEC_down_f", &drj2l_JEC_down_f, &b_drj2l_JEC_down_f);
    fChain->SetBranchAddress("drj2l_JER_up_f", &drj2l_JER_up_f, &b_drj2l_JER_up_f);
    fChain->SetBranchAddress("drj2l_JER_down_f", &drj2l_JER_down_f, &b_drj2l_JER_down_f);
    fChain->SetBranchAddress("Mjj", &Mjj, &b_Mjj);
    fChain->SetBranchAddress("Mjj_new", &Mjj_new, &b_Mjj_new);
    fChain->SetBranchAddress("Mjj_JEC_up", &Mjj_JEC_up, &b_Mjj_JEC_up);
    fChain->SetBranchAddress("Mjj_JEC_down", &Mjj_JEC_down, &b_Mjj_JEC_down);
    fChain->SetBranchAddress("Mjj_JER_up", &Mjj_JER_up, &b_Mjj_JER_up);
    fChain->SetBranchAddress("Mjj_JER_down", &Mjj_JER_down, &b_Mjj_JER_down);
    fChain->SetBranchAddress("Mjj_f", &Mjj_f, &b_Mjj_f);
    fChain->SetBranchAddress("Mjj_new_f", &Mjj_new_f, &b_Mjj_new_f);
    fChain->SetBranchAddress("Mjj_JEC_up_f", &Mjj_JEC_up_f, &b_Mjj_JEC_up_f);
    fChain->SetBranchAddress("Mjj_JEC_down_f", &Mjj_JEC_down_f, &b_Mjj_JEC_down_f);
    fChain->SetBranchAddress("Mjj_JER_up_f", &Mjj_JER_up_f, &b_Mjj_JER_up_f);
    fChain->SetBranchAddress("Mjj_JER_down_f", &Mjj_JER_down_f, &b_Mjj_JER_down_f);
    fChain->SetBranchAddress("deltaeta", &deltaeta, &b_deltaeta);
    fChain->SetBranchAddress("deltaeta_new", &deltaeta_new, &b_deltaeta_new);
    fChain->SetBranchAddress("deltaeta_JEC_up", &deltaeta_JEC_up, &b_deltaeta_JEC_up);
    fChain->SetBranchAddress("deltaeta_JEC_down", &deltaeta_JEC_down, &b_deltaeta_JEC_down);
    fChain->SetBranchAddress("deltaeta_JER_up", &deltaeta_JER_up, &b_deltaeta_JER_up);
    fChain->SetBranchAddress("deltaeta_JER_down", &deltaeta_JER_down, &b_deltaeta_JER_down);
    fChain->SetBranchAddress("deltaeta_f", &deltaeta_f, &b_deltaeta_f);
    fChain->SetBranchAddress("deltaeta_new_f", &deltaeta_new_f, &b_deltaeta_new_f);
    fChain->SetBranchAddress("deltaeta_JEC_up_f", &deltaeta_JEC_up_f, &b_deltaeta_JEC_up_f);
    fChain->SetBranchAddress("deltaeta_JEC_down_f", &deltaeta_JEC_down_f, &b_deltaeta_JEC_down_f);
    fChain->SetBranchAddress("deltaeta_JER_up_f", &deltaeta_JER_up_f, &b_deltaeta_JER_up_f);
    fChain->SetBranchAddress("deltaeta_JER_down_f", &deltaeta_JER_down_f, &b_deltaeta_JER_down_f);
    fChain->SetBranchAddress("zepp", &zepp, &b_zepp);
    fChain->SetBranchAddress("zepp_new", &zepp_new, &b_zepp_new);
    fChain->SetBranchAddress("zepp_JEC_up", &zepp_JEC_up, &b_zepp_JEC_up);
    fChain->SetBranchAddress("zepp_JEC_down", &zepp_JEC_down, &b_zepp_JEC_down);
    fChain->SetBranchAddress("zepp_JER_up", &zepp_JER_up, &b_zepp_JER_up);
    fChain->SetBranchAddress("zepp_JER_down", &zepp_JER_down, &b_zepp_JER_down);
    fChain->SetBranchAddress("zepp_f", &zepp_f, &b_zepp_f);
    fChain->SetBranchAddress("zepp_new_f", &zepp_new_f, &b_zepp_new_f);
    fChain->SetBranchAddress("zepp_JEC_up_f", &zepp_JEC_up_f, &b_zepp_JEC_up_f);
    fChain->SetBranchAddress("zepp_JEC_down_f", &zepp_JEC_down_f, &b_zepp_JEC_down_f);
    fChain->SetBranchAddress("zepp_JER_up_f", &zepp_JER_up_f, &b_zepp_JER_up_f);
    fChain->SetBranchAddress("zepp_JER_down_f", &zepp_JER_down_f, &b_zepp_JER_down_f);
    fChain->SetBranchAddress("ptlep1", &ptlep1, &b_ptlep1);
    fChain->SetBranchAddress("etalep1", &etalep1, &b_etalep1);
    fChain->SetBranchAddress("philep1", &philep1, &b_philep1);
    fChain->SetBranchAddress("energylep1", &energylep1, &b_energylep1);
    fChain->SetBranchAddress("j1metPhi", &j1metPhi, &b_j1metPhi);
    fChain->SetBranchAddress("j1metPhi_new", &j1metPhi_new, &b_j1metPhi_new);
    fChain->SetBranchAddress("j1metPhi_JEC_up", &j1metPhi_JEC_up, &b_j1metPhi_JEC_up);
    fChain->SetBranchAddress("j1metPhi_JEC_down", &j1metPhi_JEC_down, &b_j1metPhi_JEC_down);
    fChain->SetBranchAddress("j1metPhi_JER_up", &j1metPhi_JER_up, &b_j1metPhi_JER_up);
    fChain->SetBranchAddress("j1metPhi_JER_down", &j1metPhi_JER_down, &b_j1metPhi_JER_down);
    fChain->SetBranchAddress("j1metPhi_f", &j1metPhi_f, &b_j1metPhi_f);
    fChain->SetBranchAddress("j1metPhi_new_f", &j1metPhi_new_f, &b_j1metPhi_new_f);
    fChain->SetBranchAddress("j1metPhi_JEC_up_f", &j1metPhi_JEC_up_f, &b_j1metPhi_JEC_up_f);
    fChain->SetBranchAddress("j1metPhi_JEC_down_f", &j1metPhi_JEC_down_f, &b_j1metPhi_JEC_down_f);
    fChain->SetBranchAddress("j1metPhi_JER_up_f", &j1metPhi_JER_up_f, &b_j1metPhi_JER_up_f);
    fChain->SetBranchAddress("j1metPhi_JER_down_f", &j1metPhi_JER_down_f, &b_j1metPhi_JER_down_f);
    fChain->SetBranchAddress("j2metPhi", &j2metPhi, &b_j2metPhi);
    fChain->SetBranchAddress("j2metPhi_new", &j2metPhi_new, &b_j2metPhi_new);
    fChain->SetBranchAddress("j2metPhi_JEC_up", &j2metPhi_JEC_up, &b_j2metPhi_JEC_up);
    fChain->SetBranchAddress("j2metPhi_JEC_down", &j2metPhi_JEC_down, &b_j2metPhi_JEC_down);
    fChain->SetBranchAddress("j2metPhi_JER_up", &j2metPhi_JER_up, &b_j2metPhi_JER_up);
    fChain->SetBranchAddress("j2metPhi_JER_down", &j2metPhi_JER_down, &b_j2metPhi_JER_down);
    fChain->SetBranchAddress("j2metPhi_f", &j2metPhi_f, &b_j2metPhi_f);
    fChain->SetBranchAddress("j2metPhi_new_f", &j2metPhi_new_f, &b_j2metPhi_new_f);
    fChain->SetBranchAddress("j2metPhi_JEC_up_f", &j2metPhi_JEC_up_f, &b_j2metPhi_JEC_up_f);
    fChain->SetBranchAddress("j2metPhi_JEC_down_f", &j2metPhi_JEC_down_f, &b_j2metPhi_JEC_down_f);
    fChain->SetBranchAddress("j2metPhi_JER_up_f", &j2metPhi_JER_up_f, &b_j2metPhi_JER_up_f);
    fChain->SetBranchAddress("j2metPhi_JER_down_f", &j2metPhi_JER_down_f, &b_j2metPhi_JER_down_f);
    fChain->SetBranchAddress("Dphiwajj", &Dphiwajj, &b_Dphiwajj);
    fChain->SetBranchAddress("Dphiwajj_new", &Dphiwajj_new, &b_Dphiwajj_new);
    fChain->SetBranchAddress("Dphiwajj_JEC_up", &Dphiwajj_JEC_up, &b_Dphiwajj_JEC_up);
    fChain->SetBranchAddress("Dphiwajj_JEC_down", &Dphiwajj_JEC_down, &b_Dphiwajj_JEC_down);
    fChain->SetBranchAddress("Dphiwajj_JER_up", &Dphiwajj_JER_up, &b_Dphiwajj_JER_up);
    fChain->SetBranchAddress("Dphiwajj_JER_down", &Dphiwajj_JER_down, &b_Dphiwajj_JER_down);
    fChain->SetBranchAddress("Dphiwajj_f", &Dphiwajj_f, &b_Dphiwajj_f);
    fChain->SetBranchAddress("METraw_et", &METraw_et, &b_METraw_et);
    fChain->SetBranchAddress("METraw_phi", &METraw_phi, &b_METraw_phi);
    fChain->SetBranchAddress("METraw_sumEt", &METraw_sumEt, &b_METraw_sumEt);
    fChain->SetBranchAddress("genMET", &genMET, &b_genMET);
    fChain->SetBranchAddress("MET_et", &MET_et, &b_MET_et);
    fChain->SetBranchAddress("MET_et_new", &MET_et_new, &b_MET_et_new);
    fChain->SetBranchAddress("MET_et_JEC_up", &MET_et_JEC_up, &b_MET_et_JEC_up);
    fChain->SetBranchAddress("MET_et_JEC_down", &MET_et_JEC_down, &b_MET_et_JEC_down);
    fChain->SetBranchAddress("MET_et_JER_up", &MET_et_JER_up, &b_MET_et_JER_up);
    fChain->SetBranchAddress("MET_et_JER_down", &MET_et_JER_down, &b_MET_et_JER_down);
    fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
    fChain->SetBranchAddress("MET_phi_new", &MET_phi_new, &b_MET_phi_new);
    fChain->SetBranchAddress("MET_phi_JEC_up", &MET_phi_JEC_up, &b_MET_phi_JEC_up);
    fChain->SetBranchAddress("MET_phi_JEC_down", &MET_phi_JEC_down, &b_MET_phi_JEC_down);
    fChain->SetBranchAddress("MET_phi_JER_up", &MET_phi_JER_up, &b_MET_phi_JER_up);
    fChain->SetBranchAddress("MET_phi_JER_down", &MET_phi_JER_down, &b_MET_phi_JER_down);
    fChain->SetBranchAddress("HLT_Ele1", &HLT_Ele1, &b_HLT_Ele1);
    fChain->SetBranchAddress("HLT_Ele2", &HLT_Ele2, &b_HLT_Ele2);
    fChain->SetBranchAddress("HLT_Mu1", &HLT_Mu1, &b_HLT_Mu1);
    fChain->SetBranchAddress("HLT_Mu2", &HLT_Mu2, &b_HLT_Mu2);
    fChain->SetBranchAddress("HLT_Mu3", &HLT_Mu3, &b_HLT_Mu3);
    fChain->SetBranchAddress("lumiWeight", &lumiWeight, &b_lumiWeight);
    fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
    Notify();
}

Bool_t makesmall::Notify() {
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.

    return kTRUE;
}

void makesmall::Show(Long64_t entry) {
    // Print contents of entry.
    // If entry is not specified, print current entry
    if (!fChain)
        return;
    fChain->Show(entry);
}
// Qiang
void makesmall::endJob() {
    fout->cd();
    ExTree->Write();
    fout->Write();
    fout->Close();
    delete fout;
}
// Li
Int_t makesmall::Cut(Long64_t entry) {
    // This function may be called from Loop.
    // returns  1 if entry is accepted.
    // returns -1 otherwise.
    return 1;
}

Double_t makesmall::beff(Double_t x)  // befficiency   x=pt
{
    if (x >= 20 && x < 30)
        return 0.485341;
    if (x >= 30 && x < 50)
        return 0.596646;
    if (x >= 50 && x < 70)
        return 0.630344;
    if (x >= 70 && x < 100)
        return 0.643833;
    if (x >= 100 && x < 140)
        return 0.641825;
    if (x >= 140 && x < 200)
        return 0.629161;
    if (x >= 200 && x < 300)
        return 0.59098;
    if (x >= 300 && x < 600)
        return 0.532817;
    if (x >= 600 && x < 1000)
        return 0.461068;
    if (x >= 1000 && x < 3000)
        return 0.410098;
    else
        return 0.5;
}
Double_t makesmall::ceff(Double_t x)  // befficiency   x=pt
{
    if (x >= 20 && x < 30)
        return 0.101911;
    if (x >= 30 && x < 50)
        return 0.125278;
    if (x >= 50 && x < 70)
        return 0.122174;
    if (x >= 70 && x < 100)
        return 0.129021;
    if (x >= 100 && x < 140)
        return 0.134605;
    if (x >= 140 && x < 200)
        return 0.137201;
    if (x >= 200 && x < 300)
        return 0.130896;
    if (x >= 300 && x < 600)
        return 0.128562;
    if (x >= 600 && x < 1000)
        return 0.136062;
    if (x >= 1000 && x < 3000)
        return 0.138842;
    else
        return 0.1;
}
Double_t makesmall::leff(Double_t x)  // befficiency   x=pt
{
    if (x >= 20 && x < 200)
        return 0.0111077;
    if (x >= 200 && x < 500)
        return 0.0171203;
    if (x >= 500 && x < 1000)
        return 0.0299113;
    if (x >= 1000 && x < 3000)
        return 0.042927;
    else
        return 0.02;
}

Double_t
makesmall::central_b_scale(Double_t x)  // central scale   x=pt partonflavour b=5  c=4
{
    if (x > 20 && x < 1000)
        return 0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)));
    else
        return 1;
}
Double_t
makesmall::central_c_scale(Double_t x)  // central scale   x=pt partonflavour b=5  c=4
{
    if (x > 20 && x < 1000)
        return 0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)));
    else
        return 1;
}
Double_t
makesmall::central_l_scale(Double_t x)  // central scale   x=pt partonflavour b=5  c=4
{
    if (x > 20 && x < 1000)
        return 1.0589 + 0.000382569 * x + -2.4252e-07 * x * x + 2.20966e-10 * x * x * x;
    else
        return 1;
}

Double_t makesmall::up_b_scale(Double_t x)  // up scale   x=pt partonflavour b=5  c=4
{
    if (x >= 20 && x < 30)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.040213499218225479;
    if (x >= 30 && x < 50)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.014046305790543556;
    if (x >= 50 && x < 70)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.012372690252959728;
    if (x >= 70 && x < 100)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.012274007312953472;
    if (x >= 100 && x < 140)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.011465910822153091;
    if (x >= 140 && x < 200)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.012079551815986633;
    if (x >= 200 && x < 300)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.014995276927947998;
    if (x >= 300 && x < 600)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.021414462476968765;
    if (x >= 600 && x < 1000)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.032377112656831741;
    else
        return 1;
}
Double_t makesmall::up_c_scale(Double_t x)  // up scale   x=pt partonflavour b=5  c=4
{
    if (x >= 20 && x < 30)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.12064050137996674;
    if (x >= 30 && x < 50)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.042138919234275818;
    if (x >= 50 && x < 70)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.03711806982755661;
    if (x >= 70 && x < 100)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.036822021007537842;
    if (x >= 100 && x < 140)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.034397732466459274;
    if (x >= 140 && x < 200)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.0362386554479599;
    if (x >= 200 && x < 300)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.044985830783843994;
    if (x >= 300 && x < 600)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.064243391156196594;
    if (x >= 600 && x < 1000)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) + 0.097131341695785522;
    else
        return 1;
}
Double_t makesmall::up_l_scale(Double_t x)  // up scale   x=pt partonflavour b=5  c=4
{
    if (x >= 20 && x < 1000)
        return (1.0589 + 0.000382569 * x + -2.4252e-07 * x * x + 2.20966e-10 * x * x * x) * (1 + (0.100485 + 3.95509e-05 * x + -4.90326e-08 * x * x));
    else
        return 1;
}

Double_t makesmall::down_b_scale(Double_t x)  // down scale   x=pt partonflavour b=5 c=4
{
    if (x >= 20 && x < 30)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.040213499218225479;
    if (x >= 30 && x < 50)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.014046305790543556;
    if (x >= 50 && x < 70)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.012372690252959728;
    if (x >= 70 && x < 100)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.012274007312953472;
    if (x >= 100 && x < 140)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.011465910822153091;
    if (x >= 140 && x < 200)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.012079551815986633;
    if (x >= 200 && x < 300)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.014995276927947998;
    if (x >= 300 && x < 600)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.021414462476968765;
    if (x >= 600 && x < 1000)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.032377112656831741;
    else
        return 1;
}
Double_t makesmall::down_c_scale(Double_t x)  // down scale   x=pt partonflavour b=5 c=4
{
    if (x >= 20 && x < 30)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.12064050137996674;
    if (x >= 30 && x < 50)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.042138919234275818;
    if (x >= 50 && x < 70)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.03711806982755661;
    if (x >= 70 && x < 100)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.036822021007537842;
    if (x >= 100 && x < 140)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.034397732466459274;
    if (x >= 140 && x < 200)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.0362386554479599;
    if (x >= 200 && x < 300)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.044985830783843994;
    if (x >= 300 && x < 600)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.064243391156196594;
    if (x >= 600 && x < 1000)
        return (0.561694 * ((1. + (0.31439 * x)) / (1. + (0.17756 * x)))) - 0.097131341695785522;
    else
        return 1;
}
Double_t makesmall::down_l_scale(Double_t x)  // down scale   x=pt partonflavour b=5 c=4
{
    if (x > 20 && x < 1000)
        return (1.0589 + 0.000382569 * x + -2.4252e-07 * x * x + 2.20966e-10 * x * x * x) * (1 - (0.100485 + 3.95509e-05 * x + -4.90326e-08 * x * x));
    else
        return 1;
}
#endif  // #ifdef makesmall_cxx
