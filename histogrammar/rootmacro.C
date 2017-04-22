#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>

#include <TChain.h>
#include <TH1D.h>
#include <TLorentzVector.h>

double diff(struct timeval endTime, struct timeval startTime) {
  return (1000L * 1000L * (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec)) / 1000.0 / 1000.0;
}

void rootmacro() {
    struct timeval startTime, endTime;

    auto tchain = new TChain();
    tchain->Add("root://cmseos.fnal.gov//store/user/hats/PyRoot/2017/qcd_samples/shuffled_sig/sig_shuffled_0.root/tree");
    tchain->Add("root://cmseos.fnal.gov//store/user/hats/PyRoot/2017/qcd_samples/shuffled_sig/sig_shuffled_1.root/tree");
    tchain->Add("root://cmseos.fnal.gov//store/user/hats/PyRoot/2017/qcd_samples/shuffled_sig/sig_shuffled_2.root/tree");
    tchain->Add("root://cmseos.fnal.gov//store/user/hats/PyRoot/2017/qcd_samples/shuffled_sig/sig_shuffled_3.root/tree");
    tchain->Add("root://cmseos.fnal.gov//store/user/hats/PyRoot/2017/qcd_samples/shuffled_sig/sig_shuffled_4.root/tree");

    tchain->SetBranchStatus("*", 0);
    tchain->SetBranchStatus("jetAK4_N", 1);
    tchain->SetBranchStatus("jetAK4_pt", 1);
    tchain->SetBranchStatus("jetAK4_eta", 1);
    tchain->SetBranchStatus("jetAK4_phi", 1);
    tchain->SetBranchStatus("jetAK4_e", 1);

    Int_t N;
    vector<float> pt;
    vector<float> eta;
    vector<float> phi;
    vector<float> e;
    
    tchain->SetBranchAddress("jetAK4_N", &N);
    tchain->SetBranchAddress("jetAK4_pt", &pt);
    tchain->SetBranchAddress("jetAK4_eta", &eta);
    tchain->SetBranchAddress("jetAK4_phi", &phi);
    tchain->SetBranchAddress("jetAK4_e", &e);
    
    auto dijetMass_hist = new TH1D("dijetMass_hist", "dijet mass [GeV]", 100, 0, 1000);
    auto dijetEtBalance_hist = new TH1D("dijetEtBalance_hist", "dijet ET balance", 100, 0, 1);
    auto cosThetaStar_hist = new TH1D("cosThetaStar_hist", "cos(theta*)", 100, -1, 1);

    TLorentzVector leadingJet;
    TLorentzVector subleadingJet;
    TLorentzVector dijet;
    TLorentzVector boostedLeadingJet;
    
    int numEvents = tchain->GetEntries();
    gettimeofday(&startTime, 0);
    for (int event = 0;  event < numEvents;  event++) {
        tchain->GetEntry(event);
        
        if (N < 2)
            continue;
        
        leadingJet.SetPtEtaPhiE(pt.at(0), eta.at(0), phi.at(0), e.at(0));
        subleadingJet.SetPtEtaPhiE(pt.at(1), eta.at(1), phi.at(1), e.at(1));
        dijet = leadingJet + subleadingJet;
        boostedLeadingJet.SetPtEtaPhiE(pt.at(0), eta.at(0), phi.at(0), e.at(0));
        boostedLeadingJet.Boost(-dijet.BoostVector());
        
        dijetMass_hist->Fill(dijet.M());
        dijetEtBalance_hist->Fill(subleadingJet.Et() / leadingJet.Et());
        cosThetaStar_hist->Fill(boostedLeadingJet.Pz() / boostedLeadingJet.P());
    }
    gettimeofday(&endTime, 0);

    std::cout << "This took " << diff(endTime, startTime) << " seconds." << std::endl;
}
