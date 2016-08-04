/**
This Macro   
1. Apply the cuts of the channel to the root file produced by the MiniAOD code

Need to specify
1. See Declare Constants
*/
/////
//   To run: root -l TriggerEff_13TeV.cc+
/////
/////
//   Prepare Root and Roofit
/////
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF2.h"
#include "THStack.h"
#include "TLegend.h"
//#include "TPaletteAxis.h"
#include "TGaxis.h"
#include "TLine.h"
#include "TColor.h"
#include "TTree.h"
#include "TTreePlayer.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TEllipse.h"
#include "TArc.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;
/////
//   Declare constants
/////
//Path - channel - samples - selection  
const string path       = "/afs/cern.ch/work/c/cfgonzal/public/Zprime/TriggerEfficiency2016/CMSSW_8_0_14/src/FastAnalyzer/";
const char *samples[] = {"OutTree"};//, "ST_tW", "ST_tbarW"};
const string channel    = "tautau";


TFile* Call_TFile(string rootpla);
/*float PZetaVis(double muphi, double tauphi);
*/
//void setTDRStyle();
/////
//   Main function
/////
void TriggerEff_13TeV() {
  // setTDRStyle();
 //Loop over samples

  //  string filename = path+samples+".root";
  //  cout << filename << endl;

  //  TFile* file = TFile::Open();
  
 vector<string> rootplas(samples, samples + sizeof(samples)/sizeof(samples[0]));
 //root files loop
 for(uint i=0; i<rootplas.size(); i++){

   cout<<"root file is "<<rootplas[i]+".root"<<endl;

  //For plots
   
  TCanvas* c1 = new TCanvas(rootplas[i].c_str(),rootplas[i].c_str(),100,100,700,475);
  TFile* file = Call_TFile(rootplas[i]);
  TTree* tree; file->GetObject("miniAOD",tree);

  TH1D *h_var = new TH1D(rootplas[i].c_str(),rootplas[i].c_str(),20,-3.5,3.5);

  //  TH1F *hnseg = new TH1F("hnseg","Number of segments for selected tracks",20,-3.5,3.5);
   
  //Call tree  

  // TFile* f = Call_TFile(rootplas[i]); 
  

  if (file == 0) {
    // if we cannot open the file, print an error message and return immediatly
    printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
    return;
  }else{
    cout << "Root file opened successfully!" << endl;
  }
  float muphi,tauphi;  



  /*  TTree* BOOM = (TTree*)f->Get("TNT/BOOM");
  int nentries = (int) BOOM->GetEntries();
  setBranchAddress(BOOM);
  */
  //TTree* tree = (TTree*) file.Get("miniAOD");
  /*
  f->cd("miniAOD");
  TTree* tree; f->GetObject("miniAOD",tree);
  &f.ls();*/
  //  int nentries = (int) tree->GetEntries();
  //  setBranchAddress(tree);



  //  muphi = muphidis->GetEntries();
  //  file->GetObject(muphidis->GetEntries());

/*
    for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
      tree->GetEntry(i);
      // use mass, charge
    }
  */

  /*
  TTreeReaderValue<float> muphi(reader, "muphidis"); // template type must match datatype
  TTreeReaderValue<float> tauphi(reader, "tauphidis"); // name must match branchname
  */
  /*
    while (reader.Next()) {
      // use *mass, *charge, ...
    }
  */

  /*
  TTree* tree; f->GetObject("miniAOD",tree);

  for(uint s=0; s<rootplas.size(); s++){
    cout<<"Sig is "<<rootplas[s]<<endl;
    cout << "Size " << rootplas.size() << endl;
    }*/

  /*
  //loop in root file events
  for(uint s=0; s<rootplas.size(); s++){
    cout<<"Sig is "<<rootplas[s]<<endl;
    hnseg->SetBinContent(binX,1);
  double muphi =0,tauphi;
  //  tree->GetEntries("muphidis");
  //  muphi = tree->GetEntries(Form("muphidis"));
  tree->SetBranchAddress("muphidis",&muphi);
  tree->SetBranchAddress("tauphidis",&tauphi);
  }
  */
  //Call variables
  /*
  double mupt,mueta,muphi,muenergy,mucharge;
  double metpt,metpx,metpy,metpz,metphi,metsumET;
  double taupt,taueta,tauphi,tauenergy,taucharge;
  */
  /*  tree->SetBranchAddress("muptdis",&mupt);
  tree->SetBranchAddress("muetadis",&mueta);
  tree->SetBranchAddress("muenergydis",&muenergy);
  tree->SetBranchAddress("muchdis",&mucharge);*/
  /*  
  tree->SetBranchAddress("muphidis",&muphi);
  tree->SetBranchAddress("tauphidis",&tauphi);
  */

  //  std::cout << "zeta " << PZetaVis(muphi,tauphi) << std::endl ;

  //  TH2F *h_var = new TH2F(rootplas[i].c_str(),20,-3.5,3.5);

  /*
  tree->SetBranchAddress("METptdis",&metpt);
  tree->SetBranchAddress("METpt_x_dis",&metpx);
  tree->SetBranchAddress("METpt_y_dis",&metpy);
  tree->SetBranchAddress("METpt_z_dis",&metpz);
  tree->SetBranchAddress("METenergydis",&metsumET);
  tree->SetBranchAddress("METphidis",&metphi);
  */
  string name = rootplas[i]+"test.pdf";
  c1->SaveAs(name.c_str());
  cout<<endl;
 }
}
/////
//   Call TFile to be read
/////

TFile* Call_TFile(string rootpla) {
 string file_name = path+rootpla+".root";
 // TFile* f = TFile::Open(file_name.c_str());
 TFile* f =  new TFile(file_name.c_str(),"update");
 return f;
}
/*
float PZetaVis(double muphi, double tauphi){
  //	float zetax = TMath::Cos(muphi) + TMath::Cos(tauphi) ;
	float zetax = muphi + tauphi;
	return zetax;
}
*/

