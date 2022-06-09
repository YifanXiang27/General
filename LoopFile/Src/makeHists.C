#include "makeHists.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TMath.h"
#include "TTree.h"
#include <vector>


using namespace std;
void makeHists::bookHists(const char* fName){
    hf = new TFile(fName, "RECREATE");

    totaltree = new TTree("totalEvents","yifan events");
    totaltree->Branch("Hbbscore",&total_Hbbscore,"&Hbbscore/F");
    totaltree->Branch("Hbbmass",&total_Hbbmass,"&Hbbmass/F");
    totaltree->Branch("Hbbmsoftdrop",&total_Hbbmsoftdrop,"&Hbbmsoftdrop/F");
    totaltree->Branch("Hbbtau21",&total_Hbbtau21,"&Hbbtau21/F");
    totaltree->Branch("Hbbtau32",&total_Hbbtau32,"&Hbbtau32/F");
    totaltree->Branch("Hbbtau1",&total_Hbbtau1,"&Hbbtau1/F");
    totaltree->Branch("Hbbtau2",&total_Hbbtau2,"&Hbbtau2/F");
    totaltree->Branch("Hbbtau3",&total_Hbbtau3,"&Hbbtau3/F");
    totaltree->Branch("HbbPt",&total_HbbPt,"&HbbPt/F");

    totaltree->Branch("Zjetscore",&total_Zjetscore,"&Zjetscore/F");
    totaltree->Branch("Zjetmass",&total_Zjetmass,"&Zjetmass/F");
    totaltree->Branch("Zjetmsoftdrop",&total_Zjetmsoftdrop,"&Zjetmsoftdrop/F");
    totaltree->Branch("Zjettau21",&total_Zjettau21,"&Zjettau21/F");
    totaltree->Branch("Zjettau32",&total_Zjettau32,"&Zjettau32/F");
    totaltree->Branch("Zjettau1",&total_Zjettau1,"&Zjettau1/F");
    totaltree->Branch("Zjettau2",&total_Zjettau2,"&Zjettau2/F");
    totaltree->Branch("Zjettau3",&total_Zjettau3,"&Zjettau3/F");
    totaltree->Branch("ZjetPt",&total_ZjetPt,"&ZjetPt/F");

    totaltree->Branch("Wjetscore",&total_Wjetscore,"&Wjetscore/F");
    totaltree->Branch("Wjetmass",&total_Wjetmass,"&Wjetmass/F");
    totaltree->Branch("Wjetmsoftdrop",&total_Wjetmsoftdrop,"&Wjetmsoftdrop/F");
    totaltree->Branch("Wjettau21",&total_Wjettau21,"&Wjettau21/F");
    totaltree->Branch("Wjettau32",&total_Wjettau32,"&Wjettau32/F");
    totaltree->Branch("Wjettau1",&total_Wjettau1,"&Wjettau1/F");
    totaltree->Branch("Wjettau2",&total_Wjettau2,"&Wjettau2/F");
    totaltree->Branch("Wjettau3",&total_Wjettau3,"&Wjettau3/F");
    totaltree->Branch("WjetPt",&total_WjetPt,"&WjetPt/F");

    totaltree->Branch("leptonpt",&total_leptonpt,"&leptonpt/F");
    totaltree->Branch("VBSMjj",&total_VBSMjj,"&VBSMjj/F");
    totaltree->Branch("VBSdetajj",&total_VBSdetajj,"&VBSdetajj/F");
    totaltree->Branch("VBSdphijj",&total_VBSdphijj,"&VBSdphijj/F");
    totaltree->Branch("VBSPtjj",&total_VBSPtjj,"&VBSPtjj/F");
    totaltree->Branch("trans_E",&total_trans_E,"&trans_E/F");
    totaltree->Branch("MET",&total_MET,"&MET/F");
    totaltree->Branch("weight",&total_weight,"&weight/F");
}

void makeHists::saveHists(){
    hf->cd();
    hf->Write();
    cout<<"root file save"<<endl;
    hf->Close();
}
