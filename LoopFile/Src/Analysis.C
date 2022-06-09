#define ANALYSIS_SOURCE
#include "Analysis.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TMath.h"
#include "TH1D.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "Math/VectorUtil.h"
#include "TH3F.h"
#include <TRandom3.h>
#include <TMinuit.h>
#include <TApplication.h>
#include "TEnv.h"
#include <TComplex.h>
#include <TGraph.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <iomanip>
#include "btagsf/BTagCalibrationStandalone.h"



using namespace std;

void Analysis::Loop(const char* TypeName, const char* yearName){

    TString InputName = TString(TypeName);
    TString InputYear = TString(yearName);
    std::string SInputYear(yearName);

    bool if2016 = ((SInputYear.find("2016",0)) != string::npos);
    bool if2017 = ((SInputYear.find("2017",0)) != string::npos);
    bool if2018 = ((SInputYear.find("2018",0)) != string::npos);
    

    if(fChain == 0) return;
    Int_t Nentries = fChain->GetEntries();

    Double_t weight_xsec = -1;

    if(InputYear == "TTTo2L2Nu2016APV")
        weight_xsec = 0.000520384;

    if(weight_xsec == -1) weight_xsec = 0;

    if(isData)
        weight_xsec = 1;

    if(isData)
        cout<<"start looping data : "<<Nentries<<" events "<<endl;
    else
        cout<<"start loopoing MC  : "<<Nentries<<" events "<<endl;

    cout<<InputYear<<endl;
    Nentries = 10000;

    for(int ii = 0 ; ii < Nentries ; ii ++){
        
        fChain->GetEntry(ii,0);

        Double_t weight = 1;
        Double_t generatorweight;

        //***********************************
        //****Get the MC Generator weight****
        //***********************************

        cout<<RGenerator_weight<<endl;
        weight *= RGenerator_weight;
        cout<<weight<<endl;

        if(isData) weight = 1;

        event_number_raw+=weight;

        //***********************************
        //*****Get the weight of Xsec********
        //***********************************
  
        weight = weight * weight_xsec;
        weighted_number_total += weight;
        weighted_error_total += (weight * weight);

        generatorweight = weight;

        //***********************************
        //*********good run in Data**********
        //***********************************

        if(isData){
            bool ifDataGoodRun = false;
            ifstream infile;
            infile.open("./Lib/goodrun.txt",ios::in);
            int goodrun;
            int goodlumimin;
            int goodlumimax;
            while(infile>>goodrun){
                infile>>goodlumimin;
                infile>>goodlumimax;
                if(Rrun == goodrun){
                    if(RluminosityBlock <= goodlumimax && RluminosityBlock >= goodlumimin)  ifDataGoodRun = true;
                }
            }
            infile.close();
            if(!ifDataGoodRun) continue;
        }

        //***********************************
        //**Selections on general Triggers***
        //***********************************
        
        if(!RFlag_goodVertices) continue;
        if(isData && (!RFlag_globalSuperTightHalo2016Filter)) continue;
        if(!RFlag_HBHENoiseFilter) continue;
        if(!RFlag_HBHENoiseIsoFilter) continue;
        if(!RFlag_EcalDeadCellTriggerPrimitiveFilter) continue;
        if(!RFlag_BadPFMuonFilter) continue;
        if(yearNumber == 2017 || yearNumber == 2018){
            if(!RFlag_ecalBadCalibFilter) continue; //V2 for not UL samples
        }

        //***********************************
        //***Selections on lepton Triggers***
        //***********************************

        bool passHLTtrigger = false;
        if(isData){
            if(SInputYear.find("SingleMuon2016",0) != string::npos){
                if(RHLT_IsoMu22 || RHLT_IsoTkMu22 || RHLT_IsoMu24 || RHLT_IsoTkMu24)  passHLTtrigger = true;
            }else if(SInputYear.find("SingleElectron2016",0) != string::npos){
                if(RHLT_Ele25_eta2p1_WPTight_Gsf || RHLT_Ele27_eta2p1_WPTight_Gsf)     passHLTtrigger = true;
            }else if(SInputYear.find("SingleMuon2017",0) != string::npos){
                if(RHLT_IsoMu24 || RHLT_IsoMu27)                                       passHLTtrigger = true;
            }else if(SInputYear.find("SingleElectron2017",0) != string::npos){
                if(RHLT_Ele35_WPTight_Gsf || RHLT_Ele32_WPTight_Gsf)                  passHLTtrigger = true;
            }else if(SInputYear.find("SingleMuon2018",0) != string::npos){
                if(RHLT_IsoMu24 || RHLT_IsoMu27)                                       passHLTtrigger = true;
            }else if(SInputYear.find("SingleElectron2018",0) != string::npos){
                if(RHLT_Ele35_WPTight_Gsf || RHLT_Ele32_WPTight_Gsf)                  passHLTtrigger = true;
            }else{
                cout<<"ERROR MESSAGE : From HLT Trigger part : should not see this message~"<<endl;
            }
        }
        if(isData && !passHLTtrigger) continue;

        //***********************************
        //******Selections on leptons********
        //***********************************

        int Idlep1 = -999;
        int Idxlep1 = -999;
        int Nlooselepton=0; //Number of Loose leptons
        int Ntightlepton=0; //Number of tight leptons
        int IdxLeptonJet1=-999; //the ak4 jet match to the lepton

        TLorentzVector LooseLeptons[20];

        TLorentzVector LooseTaus[20];
        int nLooseTaus = 0;

        int LooseLeptonsJetidx[20];


        for(int jj = 0 ; jj < RnElectron ; jj ++){
            if(electronIDVBS(jj,0)){ // If the electron pass ttH veto electron selection
                Nlooselepton ++;
            }else{                   // If the electron don't pass veto, it cannot pass tight
                continue;
            }
            if(electronIDVBS(jj,2)){ // If the electron pass ttH tight electron selection
                if(RElectron_pt[jj] <= 35) continue; //pt > 35 gev
                Ntightlepton ++;
                int idlepton;
                if(RElectron_charge[jj] > 0) idlepton = -11;
                else idlepton = 11;
                if(     Idlep1 == -999){
                    Idxlep1 = jj;
                    IdxLeptonJet1 = RElectron_jetIdx[jj];
                    Idlep1 = idlepton;
                }
            }
        }


        for(int jj = 0 ; jj < RnMuon ; jj ++){
            if(muonIDVBS(jj,0)){     //if the muon pass ttH veto muon selection
                Nlooselepton ++;
            }else{
                continue;
            }
            if(muonIDVBS(jj,2)){
                if(RMuon_pt[jj] <= 35) continue;
                Ntightlepton ++;
                int idlepton;
                if(RMuon_charge[jj] > 0) idlepton = -13;
                else idlepton = 13;
                if(     Idlep1 == -999){
                    Idxlep1 = jj;
                    IdxLeptonJet1 = RMuon_jetIdx[jj];
                    Idlep1 = idlepton;
                }
            }
        }

        if(Nlooselepton != 1) continue;
        if(Ntightlepton != 1) continue;

        TLorentzVector TRlepton1;
        if(abs(Idlep1) == 11)
            TRlepton1.SetPtEtaPhiM(RElectron_pt[Idxlep1],RElectron_eta[Idxlep1],RElectron_phi[Idxlep1],RElectron_mass[Idxlep1]);
        else if(abs(Idlep1) == 13)
            TRlepton1.SetPtEtaPhiM(RMuon_pt[Idxlep1],RMuon_eta[Idxlep1],RMuon_phi[Idxlep1],RMuon_mass[Idxlep1]);
        else{
            cout<<"Should not see this message: in preselection should already require e or mu as leptons"<<endl;
            continue;
        }

        if(abs(Idlep1) == 11 && TRlepton1.Pt() < 40) continue;//require the lepton pt > 40
        if(abs(Idlep1) == 13 && TRlepton1.Pt() < 40) continue;


        //***********************************
        //***Adding lepton Scale Factors*****
        //***********************************

        double leptonsf = 1;
        int    leptonsf_year = yearNumber;
        

        
        if(!isData){
            if(abs(Idlep1) == 11){
                double ElectronEta = fabs(TRlepton1.Eta());
                double ElectronPt = TRlepton1.Pt();
                if(ElectronPt >= 120 ) ElectronPt = 119;
                leptonsf = leptonsf*Elec_Eff_LooseID->GetBinContent(Elec_Eff_LooseID->FindBin(ElectronEta, ElectronPt));
                leptonsf = leptonsf*Elec_EGM2D->GetBinContent(Elec_EGM2D->FindBin(ElectronEta, ElectronPt));
            }
            else if(abs(Idlep1) == 13){
                double MuonEta = fabs(TRlepton1.Eta());
                double MuonPt = TRlepton1.Pt();
                if(MuonPt >= 120) MuonPt = 119;
                leptonsf = leptonsf*Muon_Eff_LooseID->GetBinContent(Muon_Eff_LooseID->FindBin(MuonEta, MuonPt));
                leptonsf = leptonsf*Muon_EGM2D->GetBinContent(Muon_EGM2D->FindBin(MuonEta, MuonPt));
            }
        }

        if(!isData) weight = weight * leptonsf;

        weighted_number_leptonptcut += weight;
        weighted_error_leptonptcut += (weight*weight);
        
        //***********************************
        //******Fat Higgs Selections*********
        //***********************************

        double highestak8score_Hbb = -1;
        int    idx_highesthbb = 0;


        for(int jj = 0 ; jj < RnFatJet ; jj ++){
            TLorentzVector TFatJet;
            TFatJet.SetPtEtaPhiM(RFatJet_pt[jj],RFatJet_eta[jj],RFatJet_phi[jj],RFatJet_mass[jj]);
            if(RFatJet_pt[jj] <= 250) continue;
            if(TFatJet.DeltaR(TRlepton1) < 0.8) continue;
            if(RFatJet_mass[jj] <= 50) continue;
            if(RFatJet_msoftdrop[jj] <= 40) continue;
            double Hbbscore = RFatJet_particleNet_HbbvsQCD[jj];
            if(Hbbscore > highestak8score_Hbb){
                highestak8score_Hbb = Hbbscore;
                idx_highesthbb = jj;
            }
        }

        if(highestak8score_Hbb < 0.9 ) continue;
        weighted_number_fatbtag_t += weight;
        weighted_error_fatbtag_t += (weight*weight);

        TLorentzVector TTHiggs;
        TTHiggs.SetPtEtaPhiM(RFatJet_pt[idx_highesthbb],RFatJet_eta[idx_highesthbb],RFatJet_phi[idx_highesthbb],RFatJet_mass[idx_highesthbb]);

        //***********************************
        //******Fat W/Z jet Selections*******
        //***********************************
        double highestak8score_Wjet = -1;
        double highestak8score_Zjet = -1;
        int    idx_highestwjet = 0;
        int    idx_highestzjet = 0;

        for(int jj = 0 ; jj < RnFatJet ; jj ++){
            TLorentzVector TFatJet;
            TFatJet.SetPtEtaPhiM(RFatJet_pt[jj],RFatJet_eta[jj],RFatJet_phi[jj],RFatJet_mass[jj]);
            if(RFatJet_pt[jj] <= 250) continue;
            if(TFatJet.DeltaR(TRlepton1) < 0.8) continue;
            if(TFatJet.DeltaR(TTHiggs) < 0.8) continue;
            if(RFatJet_mass[jj] <= 50) continue;
            if(RFatJet_msoftdrop[jj] <= 40) continue;
            double Wjetscore = RFatJet_particleNet_WvsQCD[jj];
            double Zjetscore = RFatJet_particleNet_ZvsQCD[jj];

            if(Wjetscore > highestak8score_Wjet){
                highestak8score_Wjet = Wjetscore;
                idx_highestwjet = jj;
            }
            if(Zjetscore > highestak8score_Zjet){
                highestak8score_Zjet = Zjetscore;
                idx_highestzjet = jj;
            }
        }
        
        if(highestak8score_Wjet < 0.9 ) continue;
        TLorentzVector TTWjet;
        TTWjet.SetPtEtaPhiM(RFatJet_pt[idx_highestwjet],RFatJet_eta[idx_highestwjet],RFatJet_phi[idx_highestwjet],RFatJet_mass[idx_highestwjet]);

        TLorentzVector TTZjet;
        TTZjet.SetPtEtaPhiM(RFatJet_pt[idx_highestzjet],RFatJet_eta[idx_highestzjet],RFatJet_phi[idx_highestzjet],RFatJet_mass[idx_highestzjet]);

        weighted_number_Wjet += weight;
        weighted_error_Wjet += (weight * weight);

        //**************************************************************
        //**************Selecting VBS jets******************************
        //**************************************************************

        int Nvbfjet1 = -999;
        int Nvbfjet2 = -999;
        double maxvbfjetp = 0;
        double secvbfjetp = 0;
        int nvbsjets = 0;
        TLorentzVector TRleadingvbsjet;
        TLorentzVector TRsubleadvbsjet;
        for(int jj = 0 ; jj < RnJet ; jj ++){
            TLorentzVector Tvbsjet;
            Tvbsjet.SetPtEtaPhiM(RJet_pt[jj],RJet_eta[jj],RJet_phi[jj],RJet_mass[jj]);
            if(RJet_pt[jj] < 30) continue;
            if(Tvbsjet.DeltaR(TRlepton1) < 0.4) continue;
            if(Tvbsjet.DeltaR(TTHiggs) < 0.8) continue;
            if(Tvbsjet.DeltaR(TTWjet) < 0.8) continue;
            nvbsjets++;
            if(Tvbsjet.Eta() > 0 && maxvbfjetp < Tvbsjet.P()){
                maxvbfjetp = Tvbsjet.P();
                Nvbfjet1 = jj;
            }else if(Tvbsjet.Eta() < 0 && secvbfjetp < Tvbsjet.P()){
                secvbfjetp = Tvbsjet.P();
                Nvbfjet2 = jj;
            }
        }
        if(nvbsjets < 2) continue;
        bool ifcalvbsp = false;
        if(Nvbfjet1 == -999 || Nvbfjet2 == -999) ifcalvbsp = true;
        if(!ifcalvbsp){
            TRleadingvbsjet.SetPtEtaPhiM(RJet_pt[Nvbfjet1],RJet_eta[Nvbfjet1],RJet_phi[Nvbfjet1],RJet_mass[Nvbfjet1]);
            TRsubleadvbsjet.SetPtEtaPhiM(RJet_pt[Nvbfjet2],RJet_eta[Nvbfjet2],RJet_phi[Nvbfjet2],RJet_mass[Nvbfjet2]);
            if(TRleadingvbsjet.P() < TRsubleadvbsjet.P()){
                TLorentzVector Ttrans;
                Ttrans          = TRleadingvbsjet;
                TRleadingvbsjet = TRsubleadvbsjet;
                TRsubleadvbsjet = Ttrans;
            }
        }
        maxvbfjetp = 0;
        secvbfjetp = 0;
        Nvbfjet1 = -999;
        Nvbfjet2 = -999;
        if(ifcalvbsp){
            for(int jj = 0 ; jj < RnJet ; jj ++){
                TLorentzVector Tvbsjet;
                Tvbsjet.SetPtEtaPhiM(RJet_pt[jj],RJet_eta[jj],RJet_phi[jj],RJet_mass[jj]);
                if(RJet_pt[jj] < 30) continue;
                if(Tvbsjet.DeltaR(TRlepton1) < 0.4) continue;
                if(Tvbsjet.DeltaR(TTHiggs) < 0.8) continue;
                if(Tvbsjet.DeltaR(TTWjet) < 0.8) continue;
                if(maxvbfjetp < Tvbsjet.P()){
                    secvbfjetp = maxvbfjetp;
                    maxvbfjetp = Tvbsjet.P();
                    Nvbfjet2 = Nvbfjet1;
                    Nvbfjet1 = jj;
                }else if(secvbfjetp < Tvbsjet.P()){
                    secvbfjetp = Tvbsjet.P();
                    Nvbfjet2 = jj;
                }
            }
            TRleadingvbsjet.SetPtEtaPhiM(RJet_pt[Nvbfjet1],RJet_eta[Nvbfjet1],RJet_phi[Nvbfjet1],RJet_mass[Nvbfjet1]);
            TRsubleadvbsjet.SetPtEtaPhiM(RJet_pt[Nvbfjet2],RJet_eta[Nvbfjet2],RJet_phi[Nvbfjet2],RJet_mass[Nvbfjet2]);
        }
        weighted_number_vbsjet += weight;
        weighted_error_vbsjet += (weight*weight);

        double splittree = myrandom->Uniform(1);
        
        myhists->total_Hbbscore = RFatJet_particleNet_HbbvsQCD[idx_highesthbb];
        myhists->total_Hbbmass = RFatJet_mass[idx_highesthbb];
        myhists->total_Hbbmsoftdrop = RFatJet_msoftdrop[idx_highesthbb];
        myhists->total_Hbbtau21 = (RFatJet_tau2[idx_highesthbb] / RFatJet_tau1[idx_highesthbb]);
        myhists->total_Hbbtau32 = (RFatJet_tau3[idx_highesthbb] / RFatJet_tau2[idx_highesthbb]);
        myhists->total_Hbbtau1 = RFatJet_tau1[idx_highesthbb];
        myhists->total_Hbbtau2 = RFatJet_tau2[idx_highesthbb];
        myhists->total_Hbbtau3 = RFatJet_tau3[idx_highesthbb];
        myhists->total_HbbPt = RFatJet_pt[idx_highesthbb];

        myhists->total_Wjetscore = RFatJet_particleNet_WvsQCD[idx_highestwjet];
        myhists->total_Wjetmass = RFatJet_mass[idx_highestwjet];
        myhists->total_Wjetmsoftdrop = RFatJet_msoftdrop[idx_highestwjet];
        myhists->total_Wjettau21 = (RFatJet_tau2[idx_highestwjet] / RFatJet_tau1[idx_highestwjet]);
        myhists->total_Wjettau32 = (RFatJet_tau3[idx_highestwjet] / RFatJet_tau2[idx_highestwjet]);
        myhists->total_Wjettau1 = RFatJet_tau1[idx_highestwjet];
        myhists->total_Wjettau2 = RFatJet_tau2[idx_highestwjet];
        myhists->total_Wjettau3 = RFatJet_tau3[idx_highestwjet];
        myhists->total_WjetPt = RFatJet_pt[idx_highestwjet];

        myhists->total_Zjetscore = RFatJet_particleNet_ZvsQCD[idx_highestzjet];
        myhists->total_Zjetmass = RFatJet_mass[idx_highestzjet];
        myhists->total_Zjetmsoftdrop = RFatJet_msoftdrop[idx_highestzjet];
        myhists->total_Zjettau21 = (RFatJet_tau2[idx_highestzjet] / RFatJet_tau1[idx_highestzjet]);
        myhists->total_Zjettau32 = (RFatJet_tau3[idx_highestzjet] / RFatJet_tau2[idx_highestzjet]);
        myhists->total_Zjettau1 = RFatJet_tau1[idx_highestzjet];
        myhists->total_Zjettau2 = RFatJet_tau2[idx_highestzjet];
        myhists->total_Zjettau3 = RFatJet_tau3[idx_highestzjet];
        myhists->total_ZjetPt = RFatJet_pt[idx_highestzjet];

        myhists->total_leptonpt = TRlepton1.Pt();
        myhists->total_VBSMjj = ((TRleadingvbsjet + TRsubleadvbsjet).M());
        myhists->total_VBSdetajj = fabs(TRleadingvbsjet.Eta()  - TRsubleadvbsjet.Eta());
        myhists->total_VBSdphijj = fabs(TRleadingvbsjet.Phi()  - TRsubleadvbsjet.Phi());
        myhists->total_VBSPtjj = ((TRleadingvbsjet + TRsubleadvbsjet).Pt());
        myhists->total_trans_E = TRlepton1.Pt() + TTHiggs.Pt() + TTWjet.Pt() + RMET_pt ;
        myhists->total_MET = RMET_pt;
        myhists->total_weight = weight;
        myhists->totaltree->Fill();
    }

}
