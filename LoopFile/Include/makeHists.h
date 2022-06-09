#ifndef MAKEHISTS_HEADFILE
#define MAKEHISTS_HEADFILE
#include <iostream>
#include "TTree.h"

class TH1D;
class TH2D;
class TH2F;
class TH3F;
class TFile;
class TProfile;
class TProfile2D;
class makeHists{
    public:
        TFile *hf;

        TTree *totaltree;

        Float_t  total_Hbbscore;
        Float_t  total_Hbbmass;
        Float_t  total_Hbbmsoftdrop;
        Float_t  total_Hbbtau21;
        Float_t  total_Hbbtau32;
        Float_t  total_Hbbtau1;
        Float_t  total_Hbbtau2;
        Float_t  total_Hbbtau3;
        Float_t  total_HbbPt;

        Float_t  total_Zjetscore;
        Float_t  total_Zjetmass;
        Float_t  total_Zjetmsoftdrop;
        Float_t  total_Zjettau21;
        Float_t  total_Zjettau32;
        Float_t  total_Zjettau1;
        Float_t  total_Zjettau2;
        Float_t  total_Zjettau3;
        Float_t  total_ZjetPt;

        Float_t  total_Wjetscore;
        Float_t  total_Wjetmass;
        Float_t  total_Wjetmsoftdrop;
        Float_t  total_Wjettau21;
        Float_t  total_Wjettau32;
        Float_t  total_Wjettau1;
        Float_t  total_Wjettau2;
        Float_t  total_Wjettau3;
        Float_t  total_WjetPt;

        Float_t  total_leptonpt;
        Float_t  total_VBSMjj;
        Float_t  total_VBSdetajj;
        Float_t  total_VBSdphijj;
        Float_t  total_VBSPtjj;
        Float_t  total_trans_E;
        Float_t  total_MET;
        Float_t  total_weight;

        void bookHists(const char* fName);
        void saveHists();
};
#endif
