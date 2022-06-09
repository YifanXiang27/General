#include "Analysis.h"

using namespace std;
bool Analysis::muonIDVBS(int imu, int id_level){

    if(RMuon_pt[imu] <= 5)                      return false;
    if(fabs(RMuon_eta[imu]) >= 2.4)             return false;
    if(fabs(RMuon_dxy[imu]) >= 0.05)            return false;
    if(fabs(RMuon_dz[imu]) >= 0.1)              return false;
    if(RMuon_sip3d[imu] >= 8)                   return false;
    if(RMuon_miniPFRelIso_all[imu] > 0.40)      return false;
    if(!RMuon_looseId[imu])                     return false;
    switch(id_level){
        case(0):
            return true;
            break;
        case(1):
            if(RMuon_mvaTTH[imu] <= 0.85){
                if(RMuon_jetRelIso[imu] >= 0.5) return false;
            }
            return true;
            break;
        case(2):
            if(!RMuon_mediumId[imu]) return false;
            if(RMuon_mvaTTH[imu] <= 0.85) return false;
            return true;
            break;
        default:
            cout<<"Muon Selection Error : ID Level wrong"<<endl;
            return false;
            break;
    }
    cout<<"Error from MuonSelection: should not see this message!!!!!"<<endl;
    return 0;
}

