#define hatsTrees_cxx
#include "hatsTrees.h"
#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <iostream>

/**     HATS comment
 * First we modify the Loop() method such that we can pass it arguments
 * Also note that above, we added the includes want for basic things
 * including TLorentzVectors, which are very slow in pyROOT
 */

void hatsTrees::Loop(std::string outFileName)
{
//   In a ROOT session, you can do:
//      root> .L hatsTrees.C
//      root> hatsTrees t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:

/**     HATS comment
 *   For the HATS, we will use Method 1
 *   We'll activate only the branches we need to get (AK4) dijet invariant mass 
 *   and other interesting variables.
 */

// METHOD1:
    fChain->SetBranchStatus("*",0);  // disable all branches
    //fChain->SetBranchStatus("branchname"           , 1 );  
    //
    fChain->SetBranchStatus("jetAK4_pt"            , 1 );  
    fChain->SetBranchStatus("jetAK4_eta"           , 1 );  
    fChain->SetBranchStatus("jetAK4_mass"          , 1 );  
    fChain->SetBranchStatus("jetAK4_phi"           , 1 );  
    fChain->SetBranchStatus("jetAK4_e"             , 1 );  
    fChain->SetBranchStatus("jetAK4_jec"           , 1 );  
    fChain->SetBranchStatus("jetAK4_IDLoose"       , 1 );  
    
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;


   /**     HATS comment
    * First we'll make an output file and output tree
    * and define the histograms we want
    */ 
   TFile* hatsDijetsFile  = new TFile(outFileName.c_str(), "RECREATE");
   TTree* hatsDijetsTree  = new TTree("hatsDijets", "hatsDijets");

   /**     HATS comment
    * First we'll make an output file and output tree
    * We will initialize our TLorentzVectors outside the loop
    */ 
   TLorentzVector leadingJet      =  TLorentzVector()  ;
   TLorentzVector subleadingJet   =  TLorentzVector()  ;
   TLorentzVector boostedLeading  =  TLorentzVector()  ;
   TLorentzVector dijet           =  TLorentzVector()  ;

   /**     HATS comment
    * Now we can define the variables we want to compute and store in our output
    */ 
   float leadingEta      =  -100 ;
   float subleadingEta   =  -100 ;
   float cosThetaStar    =  -100 ;
   float dijetEtBalance  =  -100 ;
   float dijetMass       =  -100 ;

   /**     HATS comment
    * Now we can define the variables we want to compute and store in our output
    */ 
   hatsDijetsTree->Branch("leadingEta"     ,   &leadingEta      );
   hatsDijetsTree->Branch("subleadingEta"  ,   &subleadingEta   );
   hatsDijetsTree->Branch("cosThetaStar"   ,   &cosThetaStar    );
   hatsDijetsTree->Branch("dijetEtBalance" ,   &dijetEtBalance  );
   hatsDijetsTree->Branch("dijetMass"      ,   &dijetMass       );
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      /**    HATS comment
       * It just so happens that the jets are ordered by pT
       * so we can get the leading and subleading jets easily 
       */
      leadingJet.SetPtEtaPhiE(jetAK4_pt->at(0), jetAK4_eta->at(0), jetAK4_phi->at(0), jetAK4_e->at(0));
      subleadingJet.SetPtEtaPhiE(jetAK4_pt->at(1), jetAK4_eta->at(1), jetAK4_phi->at(1), jetAK4_e->at(1));
      
      leadingEta = leadingJet.Eta();
      subleadingEta = subleadingJet.Eta();
      /**    HATS comment
       * Now we can calculate some interesting things
       */
      dijet = leadingJet + subleadingJet;
      dijetMass = dijet.M();
      dijetEtBalance = subleadingJet.Et() / leadingJet.Et();
      boostedLeading.SetPtEtaPhiE(jetAK4_pt->at(0), jetAK4_eta->at(0), jetAK4_phi->at(0), jetAK4_e->at(0));
      boostedLeading.Boost(-(dijet.BoostVector()));
      cosThetaStar = boostedLeading.Pz()/boostedLeading.P();
        
      /**  HATS comment
       * And we fill out tree 
       */
      hatsDijetsTree->Fill();

      // if (Cut(ientry) < 0) continue;
   }
   hatsDijetsFile->cd();
   hatsDijetsTree->Write();
   hatsDijetsFile->Close();
}
