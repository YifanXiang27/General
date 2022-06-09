#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TChain.h>
#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TROOT.h>
#include <TFile.h>
#include <TMath.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <Math/LorentzVector.h>
#include <Math/Point3D.h>
#include <TBranch.h>
#include <TTree.h>
#include <TBits.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void Generate(){
    ifstream infile1;
    infile1.open("initial.txt");
    ifstream infile2;
    infile2.open("initial2.txt");

    ofstream outputfile;
    outputfile.open("crosscheck.txt",ios::out);

    ofstream out_headfile;
    out_headfile.open("headfile.txt",ios::out);
    ofstream out_anaheadfile;
    out_anaheadfile.open("anaheadfile.txt",ios::out);

    ofstream out_cppfile;
    out_cppfile.open("cppfile.txt",ios::out);
    ofstream out_anacppfile;
    out_anacppfile.open("anacppfile.txt",ios::out);

    ofstream out_analysis;
    out_analysis.open("analysisfile.txt",ios::out);

    ofstream out_analysis1;
    ofstream out_analysis2;
    out_analysis1.open("analysisfile1.txt",ios::out);
    out_analysis2.open("analysisfile2.txt",ios::out);


    ofstream out_check;
    out_check.open("checkfile.txt",ios::out);

    string readtype;
    string readdata;
    while(infile1 >> readtype){
        infile1>>readdata;
        //outputfile<<readtype<<"  "<<readdata<<endl;
        out_headfile<<"        "<<setw(15)<<left<<readtype<<readdata<<";"<<endl;
        out_anaheadfile<<"        "<<setw(15)<<left<<readtype<<"R"<<readdata<<";"<<endl;

        out_cppfile<<"    mytree->Branch(\""<<readdata<<"\",&"<<readdata<<",\""<<readdata;
        if(readtype == "Int_t")             out_cppfile<<"/I\");"<<endl;
        else if(readtype == "UInt_t")       out_cppfile<<"/i\");"<<endl;
        else if(readtype == "Float_t")      out_cppfile<<"/F\");"<<endl;
        else if(readtype == "Double_t")     out_cppfile<<"/D\");"<<endl;
        else if(readtype == "Bool_t")       out_cppfile<<"/O\");"<<endl;
        else if(readtype == "ULong64_t")    out_cppfile<<"/l\");"<<endl;
        else if(readtype == "UChar_t")      out_cppfile<<"/b\");"<<endl;
        else {
            cout<<"there is additional types in the files : "<<readtype<<endl;
            cout<<"please look at https://root.cern.ch/doc/master/classTTree.html "<<endl;
            return;
        }

        out_anacppfile<<"    fChain->SetBranchAddress(\""<<readdata<<"\",&R"<<readdata<<");"<<endl;

        out_analysis<<"        "<<"myhists->"<<readdata<<" = R"<<readdata<<";"<<endl;

        out_check<<"    if(treeobj->FindObject(\""<<readdata<<"\") == NULL) cout<<\""<<readdata<<" not exist\"<<endl;"<<endl;
        
    }

    while(infile2 >> readtype){
        infile2>>readdata;
        string subtype;
        int Num;
        subtype = readdata.substr(0,readdata.find("_"));
        if(subtype ==  "Electron")     Num = 20;
        else if(subtype == "Muon")     Num = 40;
        else if(subtype == "Tau")      Num = 20;
        else if(subtype == "Jet")      Num = 80;
        else if(subtype == "FatJet")   Num = 50;
        else if(subtype == "GenPart")  Num = 500;
        else{
            cout<<"there is additional subtype in the file : "<<readdata<<endl;
            cout<<"please check and add addtional line in Generate.cpp"<<endl;
        }
        out_headfile<<"        "<<setw(15)<<left<<readtype<<readdata<<"["<<Num<<"];"<<endl;
        out_anaheadfile<<"        "<<setw(15)<<left<<readtype<<"R"<<readdata<<"["<<Num<<"];"<<endl;

        out_cppfile<<"    mytree->Branch(\""<<readdata<<"\",&"<<readdata<<",\""<<readdata<<"["<<Num<<"]";
        if(readtype == "Int_t")             out_cppfile<<"/I\");"<<endl;
        else if(readtype == "UInt_t")       out_cppfile<<"/i\");"<<endl;
        else if(readtype == "Float_t")      out_cppfile<<"/F\");"<<endl;
        else if(readtype == "Double_t")     out_cppfile<<"/D\");"<<endl;
        else if(readtype == "Bool_t")       out_cppfile<<"/O\");"<<endl;
        else if(readtype == "ULong64_t")    out_cppfile<<"/l\");"<<endl;
        else if(readtype == "UChar_t")      out_cppfile<<"/b\");"<<endl;
        else {
            cout<<"there are additional types in the files : "<<readtype<<endl;
            cout<<"please look at https://root.cern.ch/doc/master/classTTree.html "<<endl;
            return;
        }
        out_anacppfile<<"    fChain->SetBranchAddress(\""<<readdata<<"\",&R"<<readdata<<");"<<endl;

        out_analysis1<<"            "<<"myhists->"<<readdata<<"[jj] = R"<<readdata<<"[jj];"<<endl;
        out_analysis2<<"            "<<"myhists->"<<readdata<<"[jj] = 0;"<<endl;
        out_check<<"    if(treeobj->FindObject(\""<<readdata<<"\") == NULL) cout<<\""<<readdata<<" not exist\"<<endl;"<<endl;
    }
}
