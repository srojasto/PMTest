// -*- C++ -*-
// $Id$
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"


void macro(const Char_t* fileRoot="data.root"){

	TString aFile = fileRoot;

	TFile *f = TFile::Open(aFile);
	TTree *TE = (TTree*)f->Get("RawDataTree");
	TE->Print();
	TE->Show(10);
	//TE->Scan("Amplitude");

		gStyle->SetOptStat("neRM");

  	TE->Draw("main_FDD.Amplitude>>h1(512,-0.5,599.5)", "", "GOFF");
	TH1 *h1 = TE->GetHistogram();
	h1->SetTitle("Amplitude;Volts;Entries");

  	TE->Draw("main_AD.Amplitude>>h2(512,-0.5,599.5)", "", "GOFF");
	TH1 *h2 = TE->GetHistogram();

  	TE->Draw("TRA.Amplitude>>hTRA(512,-0.5,599.5)", "", "GOFF");
	TH1 *hTRA = TE->GetHistogram();

  	TE->Draw("TRB.Amplitude>>hTRA(512,-0.5,599.5)", "", "GOFF");
	TH1 *hTRB = TE->GetHistogram();


  	Double_t w = 1400;
   	Double_t h = 1000;
 	TCanvas * c1 = new TCanvas("c1","Time", w, h);
	c1->Divide(2,2);
	c1->cd(1);
	h1->Draw();
	c1->cd(2);
	h2->Draw();
	c1->cd(3);
	hTRA->Draw();
	c1->cd(4);
	hTRB->Draw();

  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin) >> hdt(100,0,50)", "AD.Charge>10", "GOFF");
	TH1 *hdt = TE->GetHistogram();

  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin.Time) >> hQT(100,0,50)", "main_AD.Amplitude>30 && TRA.Amplitude>45 && TRB.Amplitude>45 && AD.Charge>10", "GOFF");
	TH1 *hQT = TE->GetHistogram();
	hQT -> SetTitle("Signal width at 10% of peak;time (ns);Entries");


  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin):main_FDD.Amplitude >> hQdT(200,0,400, 200,0,100)", "AD.Charge>10", "GOFF");
	TH1 *hQdT = TE->GetHistogram();

  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin):FDD.Charge >> hChargedT(200,0,400, 200,0,100)", "AD.Charge>10", "GOFF");
	TH1 *hChargedT = TE->GetHistogram();


  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin):main_FDD.Amplitude >> hQdT2(200,0,400, 200,0,50)", "main_AD.Amplitude>30 && TRA.Amplitude>45 && TRB.Amplitude>45", "GOFF");
	TH1 *hQdT2 = TE->GetHistogram();

  	TE->Draw("(main_FDD.time_end-main_FDD.time_begin):FDD.Charge >> hChargedT2(200,0,400, 200,0,50)", "main_AD.Amplitude>30 && TRA.Amplitude>45 && TRB.Amplitude>45 && AD.Charge>10", "GOFF");
	TH1 *hChargedT2 = TE->GetHistogram();


 	TCanvas * c2 = new TCanvas("c2","Time Difference", w, h);
	c2->Divide(2,3);
	c2->cd(1);
	hdt->Draw();
	c2->cd(2);
	hQT->Draw();
	c2->cd(3);
	c2->cd(3)->SetLogz();
	hQdT->SetTitle("Width (10%) and Amplitude;Amplitude (volts);#Deltat (ns)");
	hQdT->Draw("COLZ");
	c2->cd(4);
	hChargedT->SetTitle("Width (10%) and Charge;Charge;#Deltat (ns)");
	hChargedT->Draw("COLZ");

	c2->cd(5);
	c2->cd(5)->SetLogz();
	hQdT2->SetTitle("Width (10%) and Amplitude;Amplitude (volts);#Deltat (ns)");
	hQdT2->Draw("COLZ");
	c2->cd(6);
	hChargedT2->SetTitle("Width (10%) and Charge;Charge;#Deltat (ns)");
	hChargedT2->Draw("COLZ");




  	TE->Draw("(main_FDD.time_front_end-main_FDD.time_begin) >> hdtRise(100,0,50)", "main_AD.Amplitude>30 && TRA.Amplitude>45 && TRB.Amplitude>45 && AD.Charge>10", "GOFF");
	TH1 *hdtRise = TE->GetHistogram();
	hdtRise->SetTitle("FDD rise time: #Deltat=t(90%)-t(10%);#Deltat (ns);Entries");

  	TE->Draw("(main_FDD.time_end-main_FDD.time_back_begin.Time) >> hdtTile(100,0,50)", "main_AD.Amplitude>30 && TRA.Amplitude>45 && TRB.Amplitude>45 && AD.Charge>10", "GOFF");
	TH1 *hdtTile = TE->GetHistogram();
	hdtTile->SetTitle("FDD Tile time: #Deltat=t(90%)-t(10%);#Deltat (ns);Entries");


 	TCanvas * cRes = new TCanvas("cRes","Results", w, h);
	cRes-> Divide(2,2);

	cRes->cd(1);
	hQT->Draw();
	cRes->cd(2);
	hQdT2->Draw("COLZ");


	cRes->cd(3);
	hdtRise->Draw();
	cRes->cd(4);
	hdtTile->Draw();

	TE->StartViewer();

}
