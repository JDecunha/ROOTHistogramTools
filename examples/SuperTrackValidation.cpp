//std::string path = "/home/joseph/Documents/PHD_local/July_2022/proton_10um_DNA2_10k";
	//OrganizeLibraryFolder(path);
	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(9000, 5500);
	c->Divide(3,2);



	//50 MeV
	//std::string path = "/home/joseph/Downloads/proton_50MeV_test_593448127.root";
	//std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_50.0MeV_1e3nm_diameter_x10_oversamples_1654235541.root";

	//100 MeV
	// std::string path = "/home/joseph/Downloads/STV/proton_100MeV_test_1084327416.root";
	// std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_100.0MeV_1e3nm_diameter_x10_oversamples_1654234339.root";

	//10 MeV
	// std::string path = "/home/joseph/Downloads/STV/proton_10MeV_1um_876158395.root";
	// std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_10.0MeV_1e3nm_diameter_x10_oversamples_1654239035.root";

	//0.1 MeV
	// std::string path = "/home/joseph/Downloads/STV/proton_0_1MeV_1um_400357550.root";
	// std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_0.1MeV_1e3nm_diameter_x10_oversamples_1654235898.root";

	std::vector<std::string> STV100nm;
	std::vector<std::string> ST100nm;
	std::vector<std::string> titles;
	
	titles.push_back("100 nm, 100 MeV");
	titles.push_back("100 nm, 50 MeV");
	titles.push_back("100 nm, 10 MeV");
	titles.push_back("100 nm, 1 MeV");
	titles.push_back("100 nm, 0.1 MeV");

	STV100nm.push_back("/home/joseph/Downloads/STV/proton_100MeV_100nm_1158647087.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_50MeV_100nm_1755187072.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_10MeV_100nm_195192631.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_1MeV_100nm_1745853394.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_01MeV_100nm_39146530.root");

	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_100.0MeV_100nm_diameter_x10_oversamples_1654125681.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_50.0MeV_100nm_diameter_x10_oversamples_1654126884.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_10.0MeV_100nm_diameter_x10_oversamples_1654130466.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_1.0MeV_100nm_diameter_x10_oversamples_1654125919.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_0.1MeV_100nm_diameter_x10_oversamples_1654127252.root");
	

	/*titles.push_back("1 um, 100 MeV");
	titles.push_back("1 um, 50 MeV");
	titles.push_back("1 um, 10 MeV");
	titles.push_back("1 um, 1 MeV");
	titles.push_back("1 um, 0.1 MeV");

	STV100nm.push_back("/home/joseph/Downloads/STV/proton_100MeV_100nm_1158647087.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_50MeV_100nm_1755187072.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_10MeV_100nm_195192631.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_1MeV_100nm_1745853394.root");
	STV100nm.push_back("/home/joseph/Downloads/STV/proton_01MeV_100nm_39146530.root");

	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_100.0MeV_100nm_diameter_x10_oversamples_1654125681.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_50.0MeV_100nm_diameter_x10_oversamples_1654126884.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_10.0MeV_100nm_diameter_x10_oversamples_1654130466.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_1.0MeV_100nm_diameter_x10_oversamples_1654125919.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_0.1MeV_100nm_diameter_x10_oversamples_1654127252.root");*/

	TH1D* h;
	TH1D* h2;

	for (int i = 0; i < STV100nm.size(); ++i)
	{
		//std::string path = "/home/joseph/Downloads/STV/proton_50MeV_100nm_1755187072.root";
		//std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_50.0MeV_100nm_diameter_x10_oversamples_1654126884.root";
		
		c->cd(i+1);
		c->SetFillStyle(4000);
		c->SetFrameFillStyle(4000);

		TFile* f = new TFile((TString)STV100nm[i]);
		TFile* f2 = new TFile((TString)ST100nm[i]);
		
		h = new TH1D(*((TH1D*)f->Get("f(y)")));
		h2 = new TH1D(*((TH1D*)f2->Get("Lineal energy histogram")));
		//Print_TH1(h); //To manually print the bin values
		PMF_to_DoseFunction(h);
		Prepare_for_Semilog(h);
		PMF_to_DoseFunction(h2);
		Prepare_for_Semilog(h2);

		gStyle->SetTitleFont(42,"t");

		h2->Draw("hist");
		h->Draw("same hist");
		
		//Set range
		//h2->GetYaxis()->SetRangeUser(0,1);
		//h->GetYaxis()->SetRangeUser(0,1);

		//Set titles
		//std::string title = std::to_string(int(energy));
		//title += " MeV";
		h->SetTitle("");
		h2->SetTitle("");
		h->SetTitleSize(0.03,"t"); //this doesn't do anything
		h2->GetYaxis()->SetTitle("y #upoint d(y)");
		h2->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

		h2->GetXaxis()->CenterTitle(true);
		h2->GetYaxis()->CenterTitle(true);
		h2->GetXaxis()->SetTitleFont(42);
		h2->GetYaxis()->SetTitleFont(42);
		h2->GetXaxis()->SetTitleSize(0.042);
		h2->GetYaxis()->SetTitleSize(0.048);
		//h2->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap

		//Center
		h2->GetXaxis()->CenterTitle(true);
		h2->GetYaxis()->CenterTitle(true);

		//Offset x axis so no overlap
		h2->GetXaxis()->SetTitleOffset(1.2);
		h2->GetYaxis()->SetTitleOffset(1.2);

		h2->GetXaxis()->SetTitleFont(42);
		h2->GetYaxis()->SetTitleFont(42);


		//h->SetFillColorAlpha(kRed, 0.4);
		//h->SetFillStyle(3001);
		h->SetLineColor(kBlue);
		h->SetLineWidth(4);

		//h2->SetFillColorAlpha(kAzure+3, 0.5);
		//h->SetFillStyle(3001);
		h2->SetLineColor(kBlack);
		h2->SetLineWidth(2);

		gPad->SetLogx();
		gPad->SetFrameBorderMode(0);
		gPad->SetBorderMode(0);
		gPad->SetBorderSize(0);
		gPad->SetLeftMargin(0.15);
		gPad->SetRightMargin(0.);
		gPad->SetBottomMargin(0.12);
		//gPad->SetTopMargin(0.);

		auto legend = new TLegend(0.18,0.73,0.18+0.25,0.73+0.13);//x start, y start, x end, yend
		//legend->SetHeader("","C"); // option "C" allows to center the header
		legend->AddEntry(h,"Geant4","L");
		legend->AddEntry(h2,"SuperTrack","L");
		legend->SetTextSize(0.04);
		legend->Draw();

		//Draw the inline title
		TLatex *t = new TLatex(0.015, 0.935, (TString)titles[i]);
		t->SetNDC(); //set position in coordinate system relative to canvas
		t->Draw();

		//c->Update();
		//c->Print("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrackValidation/100nm_multigraph.jpg");
		
	}

	c->Print("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrackValidation/100nm_multigraph.jpg");