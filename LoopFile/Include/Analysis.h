#ifndef ANALYSIS_HEADFILE
#define ANALYSIS_HEADFILE

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TMath.h"
#include "TH1F.h"
#include <iostream>
#include <vector>
#include "makeHists.h"
#include <fstream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include "TH3F.h"
#include <TRandom3.h>
#include <TMinuit.h>
#include <TApplication.h>
#include "TEnv.h"
#include <TComplex.h>
#include "TH2D.h"
#include "btagsf/BTagCalibrationStandalone.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"


using namespace std;
class Analysis{
    public:
        TTree *fChain;


        UInt_t         Rrun;
        UInt_t         RluminosityBlock;
        ULong64_t      Revent;
        Float_t        RGenerator_weight;

        Bool_t         RFlag_goodVertices;
        Bool_t         RFlag_globalSuperTightHalo2016Filter;
        Bool_t         RFlag_HBHENoiseFilter;
        Bool_t         RFlag_HBHENoiseIsoFilter;
        Bool_t         RFlag_EcalDeadCellTriggerPrimitiveFilter;
        Bool_t         RFlag_BadPFMuonFilter;
        Bool_t         RFlag_ecalBadCalibFilter;

        Float_t        RMET_pt;

        UInt_t         RnGenPart;
        UInt_t         RnElectron;
        UInt_t         RnMuon;
        UInt_t         RnTau;
        UInt_t         RnJet;
        UInt_t         RnFatJet;

        Bool_t         RElectron_convVeto[20];
        Int_t          RElectron_charge[20];
        Float_t        RElectron_deltaEtaSC[20];
        Float_t        RElectron_dxy[20];
        Float_t        RElectron_dz[20];
        Float_t        RElectron_eInvMinusPInv[20];
        Float_t        RElectron_eta[20];
        Float_t        RElectron_hoe[20];
        Float_t        RElectron_jetPtRelv2[20];
        Float_t        RElectron_jetRelIso[20];
        UChar_t        RElectron_lostHits[20];
        Float_t        RElectron_mass[20];
        Float_t        RElectron_miniPFRelIso_all[20];
        Float_t        RElectron_mvaFall17V2noIso[20];
        Float_t        RElectron_pfRelIso03_all[20];
        Float_t        RElectron_pfRelIso03_chg[20];
        Bool_t         RElectron_mvaFall17V2noIso_WPL[20];
        Bool_t         RElectron_mvaFall17V2noIso_WP80[20];
        Float_t        RElectron_phi[20];
        Float_t        RElectron_pt[20];
        Float_t        RElectron_sieie[20];
        Float_t        RElectron_sip3d[20];
        Int_t          RElectron_tightCharge[20];
        UChar_t        RElectron_genPartFlav[20];
        Float_t        RElectron_mvaTTH[20];
        Float_t        RElectron_mvaTTHUL[20];
        Int_t          RElectron_jetIdx[20];

        Int_t          RMuon_jetIdx[40];
        Float_t        RMuon_pt[40];
        Float_t        RMuon_eta[40];
        Float_t        RMuon_dxy[40];
        Float_t        RMuon_dz[40];
        Float_t        RMuon_sip3d[40];
        Float_t        RMuon_ptErr[40];
        Float_t        RMuon_phi[40];
        Float_t        RMuon_mass[40];
        Float_t        RMuon_jetPtRelv2[40];
        Float_t        RMuon_jetRelIso[40];
        Bool_t         RMuon_looseId[40];
        Bool_t         RMuon_mediumId[40];
        Float_t        RMuon_pfRelIso03_all[40];
        Float_t        RMuon_miniPFRelIso_all[40];
        Int_t          RMuon_charge[40];
        UChar_t        RMuon_genPartFlav[40];
        Float_t        RMuon_mvaTTH[40];
        Float_t        RMuon_mvaTTHUL[40];

        Float_t        RTau_pt[20];
        Float_t        RTau_dz[20];
        Float_t        RTau_eta[20];
        Float_t        RTau_phi[20];
        Float_t        RTau_mass[20];
        Int_t          RTau_jetIdx[20];
        Int_t          RTau_charge[20];
        UChar_t        RTau_idDeepTau2017v2p1VSe[20];
        UChar_t        RTau_idDeepTau2017v2p1VSmu[20];
        UChar_t        RTau_idDeepTau2017v2p1VSjet[20];
        Int_t          RTau_decayMode[20];

        Float_t        RJet_pt[80];
        Float_t        RJet_eta[80];
        Float_t        RJet_phi[80];
        Float_t        RJet_mass[80];
        Float_t        RJet_btagDeepFlavB[80];
        Int_t          RJet_genJetIdx[80];
        Float_t        RJet_btagDeepB[80];
        Int_t          RJet_partonFlavour[80];
        Int_t          RJet_jetId[80];

        Float_t        RFatJet_pt[50];
        Float_t        RFatJet_eta[50];
        Float_t        RFatJet_phi[50];
        Float_t        RFatJet_mass[50];
        Float_t        RFatJet_msoftdrop[50];
        Float_t        RFatJet_btagDDBvLV2[50];
        Float_t        RFatJet_deepTagMD_HbbvsQCD[50];
        Float_t        RFatJet_deepTagMD_WvsQCD[50];
        Float_t        RFatJet_particleNet_HbbvsQCD[50];
        Float_t        RFatJet_particleNet_WvsQCD[50];
        Float_t        RFatJet_particleNet_ZvsQCD[50];
        Float_t        RFatJet_particleNetMD_QCD[50];
        Float_t        RFatJet_particleNetMD_Xbb[50];
        Float_t        RFatJet_particleNetMD_Xcc[50];
        Float_t        RFatJet_particleNetMD_Xqq[50];
        Float_t        RFatJet_tau1[50];
        Float_t        RFatJet_tau2[50];
        Float_t        RFatJet_tau3[50];

//        Int_t          RGenPart_genPartIdxMother[500];
        Int_t          RGenPart_status[500];
        Int_t          RGenPart_pdgId[500];
        Float_t        RGenPart_eta[500];
        Float_t        RGenPart_phi[500];
        Float_t        RGenPart_pt[500];
        Float_t        RGenPart_mass[500];

        Bool_t         RHLT_IsoMu18;
        Bool_t         ifExistHLT_IsoMu18;
        Bool_t         RHLT_IsoMu20;
        Bool_t         ifExistHLT_IsoMu20;
        Bool_t         RHLT_IsoMu22;
        Bool_t         ifExistHLT_IsoMu22;
        Bool_t         RHLT_IsoMu24;
        Bool_t         ifExistHLT_IsoMu24;
        Bool_t         RHLT_IsoMu27;
        Bool_t         ifExistHLT_IsoMu27;
        Bool_t         RHLT_IsoTkMu18;
        Bool_t         ifExistHLT_IsoTkMu18;
        Bool_t         RHLT_IsoTkMu20;
        Bool_t         ifExistHLT_IsoTkMu20;
        Bool_t         RHLT_IsoTkMu22;
        Bool_t         ifExistHLT_IsoTkMu22;
        Bool_t         RHLT_IsoTkMu24;
        Bool_t         ifExistHLT_IsoTkMu24;
        Bool_t         RHLT_IsoTkMu27;
        Bool_t         ifExistHLT_IsoTkMu27;
        Bool_t         RHLT_Ele25_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele25_WPTight_Gsf;
        Bool_t         RHLT_Ele25_eta2p1_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele25_eta2p1_WPTight_Gsf;
        Bool_t         RHLT_Ele27_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele27_WPTight_Gsf;
        Bool_t         RHLT_Ele27_eta2p1_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele27_eta2p1_WPTight_Gsf;
        Bool_t         RHLT_Ele32_eta2p1_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele32_eta2p1_WPTight_Gsf;
        Bool_t         RHLT_Ele32_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele32_WPTight_Gsf;
        Bool_t         RHLT_Ele35_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele35_WPTight_Gsf;
        Bool_t         RHLT_Ele38_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele38_WPTight_Gsf;
        Bool_t         RHLT_Ele40_WPTight_Gsf;
        Bool_t         ifExistHLT_Ele40_WPTight_Gsf;

        //****************Statistic variables****************//
        //

        Double_t event_number_raw;
        Double_t weighted_number_total;
        Double_t weighted_number_leptonptcut;
        Double_t weighted_number_fatbtag_t;
        Double_t weighted_number_Wjet;
        Double_t weighted_number_vbsjet;



        Double_t event_error_raw;
        Double_t weighted_error_total;
        Double_t weighted_error_leptonptcut;
        Double_t weighted_error_fatbtag_t;
        Double_t weighted_error_Wjet;
        Double_t weighted_error_vbsjet;


        Int_t    yearNumber;

        double loose_deepflavor_bscore;
        double medium_deepflavor_bscore;
        double tight_deepflavor_bscore;

        bool   is_pd_ee;
        bool   is_pd_em;
        bool   is_pd_mm;
        bool   is_pd_se;
        bool   is_pd_sm;

        double year_lumi;

        bool   isData;
        

	    BTagCalibration* btagCalib;// = new BTagCalibration("DeepJet", "./btagsf/csv/DeepJet_2016LegacySF_V1.csv");
        BTagCalibrationReader* btagReaderTight;
        BTagCalibrationReader* btagReaderLoose;

        TRandom3 *myrandom;

        TH2D *Muon_Eff_LooseID;
        TH2D *Muon_EGM2D;
        TH2D *Elec_Eff_LooseID;
        TH2D *Elec_EGM2D;


        //*************Analysis func******************//
        Analysis(const char* ifileName, const char* TypeName);
        virtual ~Analysis();
        virtual void  Initial(const char* RootName, int RootNumber, const char *yearName);
//        virtual void  Eventgetentry(int Evtnumber);
        virtual void  Loop(const char* TypeName, const char *yearName);
        virtual void  End(int RootNumber);
        virtual void  Finish(int RootNumber);
        virtual void  Output();
        virtual void  OutputTable(const char *yearName);

        //**************Electron Selection****************//
        virtual bool electronIDVBS(int iel, int id_level);
        virtual bool isTriggersafeNoIso(int iel);

        //*****************Muon Selection*****************//
        virtual bool muonIDVBS(int imu, int id_level);

        //*****************Tau  Selection*****************//
        virtual bool tauIDVBS(int ita, int id_level);
        virtual bool passesDeepTau(int ita, int id, string type);

        //******************Isolation func**************//
        virtual float getPtRel(int id, int idx);
        virtual float getPtRatio(int id, int idx);
        virtual float computePtRel(const TLorentzVector& lepp4, const TLorentzVector& jetp4);
        virtual bool passMultiIso(int id, int idx, float cutMiniIso, float cutPtRatio, float cutPtRel);

        makeHists *myhists;
        bool ifsavehists;

        //*****************BDT input *******************//
/*        TMVA::Reader *Hbbreader;// = new TMVA::Reader( "!Color:!Silent" );
        Float_t Hbbscore;
        Float_t HbbscoreMD;
        Float_t Hbbmass;
        Float_t Hbbmsoftdrop;
        Float_t Hbbtau21;
        Float_t Hbbtau32;
        Float_t Hbbtau1;
        Float_t Hbbtau2;
        Float_t Hbbtau3;

        TMVA::Reader *Wjetreader;// = new TMVA::Reader( "!Color:!Silent" );
        Float_t Wjetscore;
        Float_t WjetscoreMD;
        Float_t Wjetmass;
        Float_t Wjetmsoftdrop;
        Float_t Wjettau21;
        Float_t Wjettau32;
        Float_t Wjettau1;
        Float_t Wjettau2;
        Float_t Wjettau3;
*/
};
#endif


#ifdef ANALYSIS_SOURCE
Analysis::Analysis(const char* ifileName, const char* TypeName){
    myhists = new makeHists();
    TString histoname = (TString)TypeName + "_results.root";
    myhists->bookHists(histoname);
    ifsavehists = true;

    myrandom = new TRandom3(1);
    event_number_raw=0;
    weighted_number_total=0;
    weighted_number_leptonptcut=0;
    weighted_number_fatbtag_t=0;
    weighted_number_Wjet=0;
    weighted_number_vbsjet=0;



    event_error_raw=0;
    weighted_error_total=0;
    weighted_error_leptonptcut=0;
    weighted_error_fatbtag_t=0;
    weighted_error_Wjet=0;
    weighted_error_vbsjet=0;



}


void Analysis::End(int RootNumber){
    if(!fChain){
        cout<<"Big Error!!! No File loaded!!!"<<endl;
        return;
    }
    delete fChain->GetCurrentFile();
}

Analysis::~Analysis(){
}

void Analysis::Finish(int RootNumber){
    cout<<"Running "<<RootNumber<<"root file finished"<<endl;
    if(ifsavehists){
        myhists->saveHists();
        delete myhists;
    }
    cout<<"Running histogram saved"<<endl;
}

void Analysis::Output(){
    cout<<endl;
/*
    weighted_number_extra_Mjj1=0;
    weighted_number_extra_Mjj2=0;
    weighted_number_extra_Mjj3=0;
    weighted_number_extra_Mbb1=0;
    weighted_number_extra_Mbb2=0;
    weighted_number_extra_Hscore1=0;
    weighted_number_extra_Hscore2=0;
    weighted_number_extra_Hscore3=0;
    weighted_number_extra_Wscore1=0;
    weighted_number_extra_Wscore2=0;
    weighted_number_extra_Wscore3=0;
    weighted_number_extra_ST1=0;
    weighted_number_extra_ST2=0;*/

    cout<<"event_number_raw                                 : "<<event_number_raw<<endl;
    cout<<"weighted_number_total                            : "<<weighted_number_total<<endl;
    cout<<"weighted_number_leptonptcut                      : "<<weighted_number_leptonptcut<<endl;
    cout<<"weighted_number_fatbtag_t                        : "<<weighted_number_fatbtag_t<<endl;
    cout<<"weighted_number_Wjet                             : "<<weighted_number_Wjet<<endl;
    cout<<"weighted_number_vbsjet                           : "<<weighted_number_vbsjet<<endl;
   
    cout<<"weighted_error_total                             : "<<sqrt(weighted_error_total)<<endl;
    cout<<"weighted_error_leptonptcut                       : "<<sqrt(weighted_error_leptonptcut)<<endl;
    cout<<"weighted_error_fatbtag_t                         : "<<sqrt(weighted_error_fatbtag_t)<<endl;
    cout<<"weighted_error_Wjet                              : "<<sqrt(weighted_error_Wjet)<<endl;
    cout<<"weighted_error_vbsjet                            : "<<sqrt(weighted_error_vbsjet)<<endl;


    cout<<endl;
}


void Analysis::OutputTable(const char *yearName){
    ofstream outputtablefile("table.txt",ios::app);
    outputtablefile<<yearName<<endl;
    outputtablefile<<"event number raw                                 : "<<event_number_raw<<endl;
    outputtablefile<<"weighted number total                            : "<<weighted_number_total<<endl;

    //weighted_error_vbsjetpcut;
    //weighted_error_Mjjcut;
    //weighted_error_detacut;
    //weighted_error_Mbbcut;
    //weighted_error_Mjj1000cut;
    //weighted_error_Mjj2000cut;


//    outputtablefile<<"weighted number total                     : "<<weighted_number_total<<endl;


    outputtablefile.close();

    std::string outfiledataname(yearName);
    outfiledataname = "data_"+outfiledataname+".txt";
    ofstream outputdatafile(outfiledataname,ios::app);
    outputdatafile<<"SAMPLENAME     "<<yearName<<endl;
    outputdatafile<<"event_number_raw                                  "<<event_number_raw<<endl;
    outputdatafile<<"weighted_number_total                             "<<weighted_number_total<<endl;
    outputdatafile<<"weighted_number_leptonptcut                       "<<weighted_number_leptonptcut<<endl;
    outputdatafile<<"weighted_number_fatbtag_t                         "<<weighted_number_fatbtag_t<<endl;
    outputdatafile<<"weighted_number_Wjet                              "<<weighted_number_Wjet<<endl;
    outputdatafile<<"weighted_number_vbsjet                            "<<weighted_number_vbsjet<<endl;
    outputdatafile<<"weighted_error_total                              "<<sqrt(weighted_error_total)<<endl;
    outputdatafile<<"weighted_error_leptonptcut                        "<<sqrt(weighted_error_leptonptcut)<<endl;
    outputdatafile<<"weighted_error_fatbtag_t                          "<<sqrt(weighted_error_fatbtag_t)<<endl;
    outputdatafile<<"weighted_error_Wjet                               "<<sqrt(weighted_error_Wjet)<<endl;
    outputdatafile<<"weighted_error_vbsjet                             "<<sqrt(weighted_error_vbsjet)<<endl;
    outputdatafile.close();
}



void Analysis::Initial(const char* RootName, int RootNumber, const char *yearName){
    TTree *tree = NULL;
    TFile *file = TFile::Open(RootName);

    //TFile *file = (TFile *)gROOT->GetListOfFiles()->FindObject(RootName);
    std::string InputRoot(RootName);
    cout<<"CHECK    ROOTNAME   "<<RootName<<"   "<<RootNumber<<"   "<<yearName<<endl;
    isData = false;
    is_pd_ee = ( ((InputRoot.find("DoubleEG",0)) != string::npos) || ((InputRoot.find("EGamma",0)) != string::npos));
    is_pd_em =   ((InputRoot.find("MuonEG",0)) != string::npos);
    is_pd_mm =   ((InputRoot.find("DoubleMuon",0)) != string::npos);
    is_pd_se = ( ((InputRoot.find("SingleElectron",0)) != string::npos) || ((InputRoot.find("EGamma",0)) != string::npos));
    is_pd_sm =   ((InputRoot.find("SingleMuon",0)) != string::npos);

    
    std::string InputYear(yearName);
    if(!file)
        file = new TFile(RootName);
    tree = (TTree *)gDirectory->Get("Events");

    bool if2016 = ((InputYear.find("2016",0)) != string::npos && (InputYear.find("2016APV",0)) == string::npos);
    bool if2016APV = ((InputYear.find("2016APV",0)) != string::npos);
    bool if2017 = ((InputYear.find("2017",0)) != string::npos);
    bool if2018 = ((InputYear.find("2018",0)) != string::npos);
    if(((InputYear.find("SingleElectron",0)) != string::npos)) isData = true;
    if(((InputYear.find("SingleMuon",0)) != string::npos)) isData = true;

    cout<<"CHECK_isData   "<<isData<<endl;
    cout<<InputYear<<"   "<<(InputYear.find("2018",0))<<endl;

    TFile *file_Muon_Eff_ID = new TFile("./Include/ttHSF/MuonSFs/MuonEff.root");
    if(if2016APV){
        Muon_Eff_LooseID = (TH2D *)file_Muon_Eff_ID->Get("plot_2016HIPM_Muon_Eff_LooseID_tracker");
        TFile *file_Muon_EGM2D = new TFile("./Include/ttHSF/MuonSFs/egammaEffi2016APV_iso_EGM2D.root");
        Muon_EGM2D = (TH2D *)file_Muon_EGM2D->Get("EGamma_SF2D");
        TFile *file_Elec_Eff_LooseID = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2016APV_recoToloose_EGM2D.root");
        Elec_Eff_LooseID = (TH2D *)file_Elec_Eff_LooseID->Get("EGamma_SF2D");
        TFile *file_Elec_EGM2D = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2016APV_iso_EGM2D.root");
        Elec_EGM2D = (TH2D *)file_Elec_EGM2D->Get("EGamma_SF2D");
    }else if(if2016){
        Muon_Eff_LooseID = (TH2D *)file_Muon_Eff_ID->Get("plot_2016_Muon_Eff_LooseID_tracker");
        TFile *file_Muon_EGM2D = new TFile("./Include/ttHSF/MuonSFs/egammaEffi2016_iso_EGM2D.root");
        Muon_EGM2D = (TH2D *)file_Muon_EGM2D->Get("EGamma_SF2D");
        TFile *file_Elec_Eff_LooseID = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2016_recoToloose_EGM2D.root");
        Elec_Eff_LooseID = (TH2D *)file_Elec_Eff_LooseID->Get("EGamma_SF2D");
        TFile *file_Elec_EGM2D = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2016_iso_EGM2D.root");
        Elec_EGM2D = (TH2D *)file_Elec_EGM2D->Get("EGamma_SF2D");
    }else if(if2017){
        Muon_Eff_LooseID = (TH2D *)file_Muon_Eff_ID->Get("plot_2017_Muon_Eff_LooseID_tracker");
        TFile *file_Muon_EGM2D = new TFile("./Include/ttHSF/MuonSFs/egammaEffi2017_iso_EGM2D.root");
        Muon_EGM2D = (TH2D *)file_Muon_EGM2D->Get("EGamma_SF2D");
        TFile *file_Elec_Eff_LooseID = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2017_recoToloose_EGM2D.root");
        Elec_Eff_LooseID = (TH2D *)file_Elec_Eff_LooseID->Get("EGamma_SF2D");
        TFile *file_Elec_EGM2D = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2017_iso_EGM2D.root");
        Elec_EGM2D = (TH2D *)file_Elec_EGM2D->Get("EGamma_SF2D");
    }else if(if2018){
        Muon_Eff_LooseID = (TH2D *)file_Muon_Eff_ID->Get("plot_2018_Muon_Eff_LooseID_tracker");
        TFile *file_Muon_EGM2D = new TFile("./Include/ttHSF/MuonSFs/egammaEffi2018_iso_EGM2D.root");
        Muon_EGM2D = (TH2D *)file_Muon_EGM2D->Get("EGamma_SF2D");
        TFile *file_Elec_Eff_LooseID = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2018_recoToloose_EGM2D.root");
        Elec_Eff_LooseID = (TH2D *)file_Elec_Eff_LooseID->Get("EGamma_SF2D");
        TFile *file_Elec_EGM2D = new TFile("./Include/ttHSF/ElecSFs/egammaEffi2018_iso_EGM2D.root");
        Elec_EGM2D = (TH2D *)file_Elec_EGM2D->Get("EGamma_SF2D");
    }

    

    if(if2016APV){
        yearNumber = 20160;
        loose_deepflavor_bscore = 0.0614;
        medium_deepflavor_bscore = 0.3093;
        tight_deepflavor_bscore = 0.7221;
        year_lumi = 19.52;//35.9;
    }
    else if( if2016 )     {
        yearNumber = 2016;
        loose_deepflavor_bscore = 0.0614;
        medium_deepflavor_bscore = 0.3093;
        tight_deepflavor_bscore = 0.7221;
        year_lumi = 16.81;//35.9;
    }else if( if2017 ) {
        yearNumber = 2017;
        loose_deepflavor_bscore = 0.0521;
        medium_deepflavor_bscore = 0.3033;
        tight_deepflavor_bscore = 0.7489;
        year_lumi = 41.529;
    }else if( if2018 ) {
        yearNumber = 2018;
        loose_deepflavor_bscore = 0.0494;
        medium_deepflavor_bscore = 0.2770;
        tight_deepflavor_bscore = 0.7264;
        year_lumi = 59.7;
    }
    else{
        cout<<"Error! Cannot find the year"<<endl;
        return;
    }
    
    cout<<"setting year to : "<<yearNumber<<"   "<<if2016<<"   "<<if2017<<"   "<<if2018<<endl;
    cout<<isData<<endl;

    if(tree == NULL)
        cout<<"No Such Tree!!!"<<endl;

    fChain = tree;

    fChain->SetBranchAddress("run",&Rrun);
    fChain->SetBranchAddress("luminosityBlock",&RluminosityBlock);
    fChain->SetBranchAddress("event",&Revent);
    fChain->SetBranchAddress("Generator_weight",&RGenerator_weight);

    fChain->SetBranchAddress("Flag_goodVertices",&RFlag_goodVertices);
    fChain->SetBranchAddress("Flag_globalSuperTightHalo2016Filter",&RFlag_globalSuperTightHalo2016Filter);
    fChain->SetBranchAddress("Flag_HBHENoiseFilter",&RFlag_HBHENoiseFilter);
    fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter",&RFlag_HBHENoiseIsoFilter);
    fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter",&RFlag_EcalDeadCellTriggerPrimitiveFilter);
    fChain->SetBranchAddress("Flag_BadPFMuonFilter",&RFlag_BadPFMuonFilter);
    if(if2017 || if2018)
        fChain->SetBranchAddress("Flag_ecalBadCalibFilter",&RFlag_ecalBadCalibFilter);//V2 for not UL samples

    fChain->SetBranchAddress("MET_pt",&RMET_pt);
    fChain->SetBranchAddress("nGenPart",&RnGenPart);
    fChain->SetBranchAddress("nElectron",&RnElectron);
    fChain->SetBranchAddress("nMuon",&RnMuon);
    fChain->SetBranchAddress("nTau",&RnTau);
    fChain->SetBranchAddress("nJet",&RnJet);
    fChain->SetBranchAddress("nFatJet",&RnFatJet);

    fChain->SetBranchAddress("Electron_convVeto",&RElectron_convVeto);
    fChain->SetBranchAddress("Electron_charge",&RElectron_charge);
    fChain->SetBranchAddress("Electron_deltaEtaSC",&RElectron_deltaEtaSC);
    fChain->SetBranchAddress("Electron_dxy",&RElectron_dxy);
    fChain->SetBranchAddress("Electron_dz",&RElectron_dz);
    fChain->SetBranchAddress("Electron_eInvMinusPInv",&RElectron_eInvMinusPInv);
    fChain->SetBranchAddress("Electron_eta",&RElectron_eta);
    fChain->SetBranchAddress("Electron_hoe",&RElectron_hoe);
    fChain->SetBranchAddress("Electron_jetPtRelv2",&RElectron_jetPtRelv2);
    fChain->SetBranchAddress("Electron_jetRelIso",&RElectron_jetRelIso);
    fChain->SetBranchAddress("Electron_lostHits",&RElectron_lostHits);
    fChain->SetBranchAddress("Electron_mass",&RElectron_mass);
    fChain->SetBranchAddress("Electron_miniPFRelIso_all",&RElectron_miniPFRelIso_all);
    fChain->SetBranchAddress("Electron_mvaFall17V2noIso",&RElectron_mvaFall17V2noIso);
    fChain->SetBranchAddress("Electron_pfRelIso03_all",&RElectron_pfRelIso03_all);
    fChain->SetBranchAddress("Electron_pfRelIso03_chg",&RElectron_pfRelIso03_chg);
    fChain->SetBranchAddress("Electron_mvaFall17V2noIso_WPL",&RElectron_mvaFall17V2noIso_WPL);
    fChain->SetBranchAddress("Electron_mvaFall17V2noIso_WP80",&RElectron_mvaFall17V2noIso_WP80);
    fChain->SetBranchAddress("Electron_phi",&RElectron_phi);
    fChain->SetBranchAddress("Electron_pt",&RElectron_pt);
    fChain->SetBranchAddress("Electron_sieie",&RElectron_sieie);
    fChain->SetBranchAddress("Electron_sip3d",&RElectron_sip3d);
    fChain->SetBranchAddress("Electron_tightCharge",&RElectron_tightCharge);
    fChain->SetBranchAddress("Electron_genPartFlav",&RElectron_genPartFlav);
    fChain->SetBranchAddress("Electron_mvaTTH",&RElectron_mvaTTH);
    if(!isData)
        fChain->SetBranchAddress("Electron_mvaTTHUL",&RElectron_mvaTTHUL);
    fChain->SetBranchAddress("Electron_jetIdx",&RElectron_jetIdx);

    fChain->SetBranchAddress("Muon_jetIdx",&RMuon_jetIdx);
    fChain->SetBranchAddress("Muon_pt",&RMuon_pt);
    fChain->SetBranchAddress("Muon_eta",&RMuon_eta);
    fChain->SetBranchAddress("Muon_dxy",&RMuon_dxy);
    fChain->SetBranchAddress("Muon_dz",&RMuon_dz);
    fChain->SetBranchAddress("Muon_sip3d",&RMuon_sip3d);
    fChain->SetBranchAddress("Muon_ptErr",&RMuon_ptErr);
    fChain->SetBranchAddress("Muon_phi",&RMuon_phi);
    fChain->SetBranchAddress("Muon_mass",&RMuon_mass);
    fChain->SetBranchAddress("Muon_jetPtRelv2",&RMuon_jetPtRelv2);
    fChain->SetBranchAddress("Muon_jetRelIso",&RMuon_jetRelIso);
    fChain->SetBranchAddress("Muon_looseId",&RMuon_looseId);
    fChain->SetBranchAddress("Muon_mediumId",&RMuon_mediumId);
    fChain->SetBranchAddress("Muon_pfRelIso03_all",&RMuon_pfRelIso03_all);
    fChain->SetBranchAddress("Muon_miniPFRelIso_all",&RMuon_miniPFRelIso_all);
    fChain->SetBranchAddress("Muon_charge",&RMuon_charge);
    fChain->SetBranchAddress("Muon_genPartFlav",&RMuon_genPartFlav);
    fChain->SetBranchAddress("Muon_mvaTTH",&RMuon_mvaTTH);
    if(!isData)
        fChain->SetBranchAddress("Muon_mvaTTHUL",&RMuon_mvaTTHUL);

    fChain->SetBranchAddress("Tau_pt",&RTau_pt);
    fChain->SetBranchAddress("Tau_dz",&RTau_dz);
    fChain->SetBranchAddress("Tau_eta",&RTau_eta);
    fChain->SetBranchAddress("Tau_phi",&RTau_phi);
    fChain->SetBranchAddress("Tau_mass",&RTau_mass);
    fChain->SetBranchAddress("Tau_jetIdx",&RTau_jetIdx);
    fChain->SetBranchAddress("Tau_charge",&RTau_charge);
    fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSe",&RTau_idDeepTau2017v2p1VSe);
    fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSmu",&RTau_idDeepTau2017v2p1VSmu);
    fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSjet",&RTau_idDeepTau2017v2p1VSjet);
    fChain->SetBranchAddress("Tau_decayMode",&RTau_decayMode);

    fChain->SetBranchAddress("Jet_pt",&RJet_pt);
    fChain->SetBranchAddress("Jet_eta",&RJet_eta);
    fChain->SetBranchAddress("Jet_phi",&RJet_phi);
    fChain->SetBranchAddress("Jet_mass",&RJet_mass);
    fChain->SetBranchAddress("Jet_btagDeepFlavB",&RJet_btagDeepFlavB);
    fChain->SetBranchAddress("Jet_genJetIdx",&RJet_genJetIdx);
    fChain->SetBranchAddress("Jet_btagDeepB",&RJet_btagDeepB);
    fChain->SetBranchAddress("Jet_partonFlavour",&RJet_partonFlavour);
    fChain->SetBranchAddress("Jet_jetId",&RJet_jetId);

    fChain->SetBranchAddress("FatJet_pt",&RFatJet_pt);
    fChain->SetBranchAddress("FatJet_eta",&RFatJet_eta);
    fChain->SetBranchAddress("FatJet_phi",&RFatJet_phi);
    fChain->SetBranchAddress("FatJet_mass",&RFatJet_mass);
    fChain->SetBranchAddress("FatJet_msoftdrop",&RFatJet_msoftdrop);
    fChain->SetBranchAddress("FatJet_btagDDBvLV2",&RFatJet_btagDDBvLV2);
    fChain->SetBranchAddress("FatJet_deepTagMD_HbbvsQCD",&RFatJet_deepTagMD_HbbvsQCD);
    fChain->SetBranchAddress("FatJet_deepTagMD_WvsQCD",&RFatJet_deepTagMD_WvsQCD);
    fChain->SetBranchAddress("FatJet_particleNet_HbbvsQCD",&RFatJet_particleNet_HbbvsQCD);
    fChain->SetBranchAddress("FatJet_particleNet_WvsQCD",&RFatJet_particleNet_WvsQCD);
    fChain->SetBranchAddress("FatJet_particleNet_ZvsQCD",&RFatJet_particleNet_ZvsQCD);
    fChain->SetBranchAddress("FatJet_particleNetMD_QCD",&RFatJet_particleNetMD_QCD);
    fChain->SetBranchAddress("FatJet_particleNetMD_Xbb",&RFatJet_particleNetMD_Xbb);
    fChain->SetBranchAddress("FatJet_particleNetMD_Xcc",&RFatJet_particleNetMD_Xcc);
    fChain->SetBranchAddress("FatJet_particleNetMD_Xqq",&RFatJet_particleNetMD_Xqq);
    fChain->SetBranchAddress("FatJet_tau1",&RFatJet_tau1);
    fChain->SetBranchAddress("FatJet_tau2",&RFatJet_tau2);
    fChain->SetBranchAddress("FatJet_tau3",&RFatJet_tau3);

//    fChain->SetBranchAddress("GenPart_genPartIdxMother",&RGenPart_genPartIdxMother);
    fChain->SetBranchAddress("GenPart_status",&RGenPart_status);
    fChain->SetBranchAddress("GenPart_pdgId",&RGenPart_pdgId);
    fChain->SetBranchAddress("GenPart_eta",&RGenPart_eta);
    fChain->SetBranchAddress("GenPart_phi",&RGenPart_phi);
    fChain->SetBranchAddress("GenPart_pt",&RGenPart_pt);
    fChain->SetBranchAddress("GenPart_mass",&RGenPart_mass);

    TObject *br;

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoMu18");
    if(br){
        fChain->SetBranchAddress("HLT_IsoMu18",&RHLT_IsoMu18);
        ifExistHLT_IsoMu18 = true;
    }else{
        ifExistHLT_IsoMu18 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoMu20");
    if(br){
        fChain->SetBranchAddress("HLT_IsoMu20",&RHLT_IsoMu20);
        ifExistHLT_IsoMu20 = true;
    }else{
        ifExistHLT_IsoMu20 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoMu22");
    if(br){
        fChain->SetBranchAddress("HLT_IsoMu22",&RHLT_IsoMu22);
        ifExistHLT_IsoMu22 = true;
    }else{
        ifExistHLT_IsoMu22 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoMu24");
    if(br){
        fChain->SetBranchAddress("HLT_IsoMu24",&RHLT_IsoMu24);
        ifExistHLT_IsoMu24 = true;
    }else{
        ifExistHLT_IsoMu24 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoMu27");
    if(br){
        fChain->SetBranchAddress("HLT_IsoMu27",&RHLT_IsoMu27);
        ifExistHLT_IsoMu27 = true;
    }else{
        ifExistHLT_IsoMu27 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoTkMu18");
    if(br){
        fChain->SetBranchAddress("HLT_IsoTkMu18",&RHLT_IsoTkMu18);
        ifExistHLT_IsoTkMu18 = true;
    }else{
        ifExistHLT_IsoTkMu18 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoTkMu20");
    if(br){
        fChain->SetBranchAddress("HLT_IsoTkMu20",&RHLT_IsoTkMu20);
        ifExistHLT_IsoTkMu20 = true;
    }else{
        ifExistHLT_IsoTkMu20 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoTkMu22");
    if(br){
        fChain->SetBranchAddress("HLT_IsoTkMu22",&RHLT_IsoTkMu22);
        ifExistHLT_IsoTkMu22 = true;
    }else{
        ifExistHLT_IsoTkMu22 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoTkMu24");
    if(br){
        fChain->SetBranchAddress("HLT_IsoTkMu24",&RHLT_IsoTkMu24);
        ifExistHLT_IsoTkMu24 = true;
    }else{
        ifExistHLT_IsoTkMu24 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_IsoTkMu27");
    if(br){
        fChain->SetBranchAddress("HLT_IsoTkMu27",&RHLT_IsoTkMu27);
        ifExistHLT_IsoTkMu27 = true;
    }else{
        ifExistHLT_IsoTkMu27 = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele25_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele25_WPTight_Gsf",&RHLT_Ele25_WPTight_Gsf);
        ifExistHLT_Ele25_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele25_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele25_eta2p1_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele25_eta2p1_WPTight_Gsf",&RHLT_Ele25_eta2p1_WPTight_Gsf);
        ifExistHLT_Ele25_eta2p1_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele25_eta2p1_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele27_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele27_WPTight_Gsf",&RHLT_Ele27_WPTight_Gsf);
        ifExistHLT_Ele27_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele27_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele27_eta2p1_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele27_eta2p1_WPTight_Gsf",&RHLT_Ele27_eta2p1_WPTight_Gsf);
        ifExistHLT_Ele27_eta2p1_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele27_eta2p1_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele32_eta2p1_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele32_eta2p1_WPTight_Gsf",&RHLT_Ele32_eta2p1_WPTight_Gsf);
        ifExistHLT_Ele32_eta2p1_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele32_eta2p1_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele32_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele32_WPTight_Gsf",&RHLT_Ele32_WPTight_Gsf);
        ifExistHLT_Ele32_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele32_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele35_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele35_WPTight_Gsf",&RHLT_Ele35_WPTight_Gsf);
        ifExistHLT_Ele35_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele35_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele38_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele38_WPTight_Gsf",&RHLT_Ele38_WPTight_Gsf);
        ifExistHLT_Ele38_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele38_WPTight_Gsf = false;
    }

    br = fChain->GetListOfBranches()->FindObject("HLT_Ele40_WPTight_Gsf");
    if(br){
        fChain->SetBranchAddress("HLT_Ele40_WPTight_Gsf",&RHLT_Ele40_WPTight_Gsf);
        ifExistHLT_Ele40_WPTight_Gsf = true;
    }else{
        ifExistHLT_Ele40_WPTight_Gsf = false;
    }

    cout<<"finishing reading trees"<<endl;


}
#endif



