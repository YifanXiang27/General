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
    infile1.open("Plot_1D.txt");

    ifstream infile2;
    infile2.open("Plot_2D.txt");

    ofstream outputfile_H;
    outputfile_H.open("headfile.txt",ios::out);

    ofstream outputfile_C1;
    outputfile_C1.open("cppfile1.txt",ios::out);

    ofstream outputfile_C2;
    outputfile_C2.open("cppfile2.txt",ios::out);
    
    ofstream outputfile_C3;
    outputfile_C3.open("anafile.txt",ios::out);

    string read;
    int    nbins1,nbins2;
    double xstart,xend,ystart,yend;
    while(infile1>>read){
        if(read == "END") {
            outputfile_H<<endl;
            outputfile_C1<<endl;
            outputfile_C2<<endl;
            outputfile_C3<<endl;
            continue;
        }
        infile1>>nbins1;
        infile1>>xstart;
        infile1>>xend;
        outputfile_H<<"        ";
        outputfile_H<<"TH1D *"<<read<<";"<<endl;

        outputfile_C1<<"    ";
        outputfile_C1<<read<<" = new TH1D(\""<<read<<"\",\""<<read<<"\","<<nbins1<<","<<xstart<<","<<xend<<");"<<endl;

        outputfile_C2<<"    ";
        outputfile_C2<<read<<"->Sumw2();"<<endl;

        outputfile_C3<<"myhists->"<<read<<"->Fill(,weight);"<<endl;

    }
//    while(infile2>>read){
//        outputfile<<"         ";
//        outputfile<<"TH2D *"<<read<<";"<<endl;
//    }

    

}
