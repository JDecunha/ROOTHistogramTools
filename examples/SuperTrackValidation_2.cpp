	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(4000, 5200);
	c->Divide(2,5,0.,0.);



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

	std::vector<std::string> STV1um3mm;
	std::vector<std::string> ST1um3mm;
	std::vector<std::string> STV1um;
	std::vector<std::string> ST1um;
	std::vector<std::string> STV100nm;
	std::vector<std::string> ST100nm;
	std::vector<std::string> STV10nm;
	std::vector<std::string> ST10nm;
	std::vector<std::string> STV1nm;
	std::vector<std::string> ST1nm;
	std::vector<std::string> titles;

	std::vector<std::string> STVFinalPlot;
	std::vector<std::string> STFinalPlot;
	std::vector<std::string> titles2;
	
	// titles.push_back("50 MeV");
	//STV100nm.push_back("/home/joseph/Downloads/STV/proton_50MeV_100nm_1755187072.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_50.0MeV_100nm_diameter_x10_oversamples_1654126884.root");
	
	// titles.push_back("0.1 MeV");
	// titles.push_back("1 MeV");
	// titles.push_back("10 MeV");
	// titles.push_back("100 MeV");
	
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_01MeV_100nm_39146530.root");
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_1MeV_100nm_1745853394.root");
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_10MeV_100nm_195192631.root");
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_100MeV_100nm_1158647087.root");

	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_0.1MeV_100nm_diameter_x10_oversamples_1654127252.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_1.0MeV_100nm_diameter_x10_oversamples_1654125919.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_10.0MeV_100nm_diameter_x10_oversamples_1654130466.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_100.0MeV_100nm_diameter_x10_oversamples_1654125681.root");

	
	titles.push_back("0.1 MeV");
	titles.push_back("1 MeV");
	titles.push_back("10 MeV");
	titles.push_back("100 MeV");
	


	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_0_1MeV_1um_400357550.root");
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_1MeV_1um_45529838.root");
	STV100nm.push_back("/home/joseph/Downloads/proton_10MeV_1um_1194250602.root");
	// STV100nm.push_back("/home/joseph/Downloads/STV/proton_100MeV_test_1084327416.root");
	
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_0.1MeV_1e3nm_diameter_x10_oversamples_1654235898.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_1.0MeV_1e3nm_diameter_x10_oversamples_1654234577.root");
	ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_10.0MeV_1e3nm_diameter_x10_oversamples_1654239035.root");
	// ST100nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_100.0MeV_1e3nm_diameter_x10_oversamples_1654234339.root");

	STV1nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_01MeV_1nm_794375214.root");
	STV1nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_1MeV_1nm_372351315.root");
	STV1nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_10MeV_1nm_1520554755.root");
	STV1nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_100MeV_1nm_1238447645.root");

	ST1nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_0.1MeV_1nm_diameter_x10_oversamples_1655522754.root");
	ST1nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_1.0MeV_1nm_diameter_x10_oversamples_1655521000.root");
	ST1nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_10.0MeV_1nm_diameter_x10_oversamples_1655527997.root");
	ST1nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_100.0MeV_1nm_diameter_x10_oversamples_1655520670.root");

	STV10nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_01MeV_10nm_1083773597.root");
	STV10nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_1MeV_10nm_1403813904.root");
	STV10nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_10MeV_10nm_1423529785.root");
	STV10nm.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_100MeV_10nm_1650077190.root");

	ST10nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_0.1MeV_10nm_diameter_x10_oversamples_1654051255.root");
	ST10nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_1.0MeV_10nm_diameter_x10_oversamples_1654049869.root");
	ST10nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_10.0MeV_10nm_diameter_x10_oversamples_1654054619.root");
	ST10nm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_100.0MeV_10nm_diameter_x10_oversamples_1654049639.root");

	STV1um.push_back("/home/joseph/Downloads/STV/proton_0_1MeV_1um_400357550.root");
	STV1um.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_1MeV_1um_1mil_324971933.root");
	STV1um.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1um/proton_10MeV_1um_1289741765.root");
	STV1um.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1um/proton_100MeV_test_104462586.root");

	ST1um.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_0.1MeV_1e3nm_diameter_x10_oversamples_1654235898.root");
	ST1um.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_1.0MeV_1e3nm_diameter_x10_oversamples_1654234577.root");
	ST1um.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_10.0MeV_1e3nm_diameter_x10_oversamples_1654239035.root");
	ST1um.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_100.0MeV_1e3nm_diameter_x10_oversamples_1654234339.root");


	STV1um3mm.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_01MeV_1um_3mm_339623719.root");
	STV1um3mm.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_1MeV_1um_3mm_1013576977.root");
	STV1um3mm.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_10MeV_1um_3mm_279583886.root");
	STV1um3mm.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_100MeV_1um_3mm_1288182744.root");

	ST1um3mm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_0.1MeV_1e3nm_diameter_x10_oversamples_1655781470.root");
	ST1um3mm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_1.0MeV_1e3nm_diameter_x10_oversamples_1655779984.root");
	ST1um3mm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_10.0MeV_1e3nm_diameter_x10_oversamples_1655785509.root");
	ST1um3mm.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_100.0MeV_1e3nm_diameter_x10_oversamples_1655779620.root");

	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_1MeV_1nm_372351315.root");
	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/1nm/proton_100MeV_1nm_1238447645.root");
	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_1MeV_10nm_1403813904.root");
	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/SuperTrackValidation_May23/10nm/proton_100MeV_10nm_1650077190.root");
	STVFinalPlot.push_back("/home/joseph/Downloads/STV/proton_1MeV_100nm_1745853394.root");
	STVFinalPlot.push_back("/home/joseph/Downloads/STV/proton_100MeV_100nm_1158647087.root");
	STVFinalPlot.push_back("/home/joseph/Downloads/STV/proton_1MeV_1um_45529838.root");
	STVFinalPlot.push_back("/home/joseph/Downloads/STV/proton_100MeV_test_1084327416.root");
	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_1MeV_1um_3mm_500k_543441654.root");
	STVFinalPlot.push_back("/home/joseph/Documents/PHD_local/STV_May23New/proton_100MeV_1um_3mm_1288182744.root");

	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_1.0MeV_1nm_diameter_x10_oversamples_1655521000.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1nm/proton_5um_DNA2_10k_100.0MeV_1nm_diameter_x10_oversamples_1655520670.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_1.0MeV_10nm_diameter_x10_oversamples_1654049869.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/10nm/proton_5um_DNA2_10k_100.0MeV_10nm_diameter_x10_oversamples_1654049639.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_1.0MeV_100nm_diameter_x10_oversamples_1654125919.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_100.0MeV_100nm_diameter_x10_oversamples_1654125681.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_1.0MeV_1e3nm_diameter_x10_oversamples_1654234577.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm/proton_5um_DNA2_10k_100.0MeV_1e3nm_diameter_x10_oversamples_1654234339.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_1.0MeV_1e3nm_diameter_x10_oversamples_1655779984.root");
	STFinalPlot.push_back("/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm/proton_3mm_DNA2_1k_100.0MeV_1e3nm_diameter_x10_oversamples_1655779620.root");

	TH1D* h;
	TH1D* h2;

	titles2.push_back("1 MeV, 1 nm Target Diameter");
	titles2.push_back("100 MeV, 1 nm Target Diameter");
	titles2.push_back("1 MeV, 10 nm Target Diameter");
	titles2.push_back("100 MeV, 10 nm Target Diameter");
	titles2.push_back("1 MeV, 100 nm Target Diameter");
	titles2.push_back("100 MeV, 100 nm Target Diameter");
	titles2.push_back("1 MeV, 1 #mum Target Diameter");
	titles2.push_back("100 MeV, 1 #mum Target Diameter");
	titles2.push_back("1 MeV, 1 #mum Target Diameter, 3 mm Voxel");
	titles2.push_back("100 MeV, 1 #mum Target Diameter, 3 mm Voxel");

	for (int i = 0; i < STFinalPlot.size(); ++i)
	{
		//std::string path = "/home/joseph/Downloads/STV/proton_50MeV_100nm_1755187072.root";
		//std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/100nm/proton_5um_DNA2_10k_50.0MeV_100nm_diameter_x10_oversamples_1654126884.root";
		
		c->cd(i+1);
		c->SetFillStyle(4000);
		c->SetFrameFillStyle(4000);

		TFile* f = new TFile((TString)STVFinalPlot[i]);
		TFile* f2 = new TFile((TString)STFinalPlot[i]);
		
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
		// h2->GetXaxis()->SetRangeUser(10,150);
		// h->GetXaxis()->SetRangeUser(10,150);

		//Set titles
		//std::string title = std::to_string(int(energy));
		//title += " MeV";
		h->SetTitle("");
		h2->SetFillColorAlpha(kAzure+3, 0.5);

		h2->SetTitle("");
		h->SetTitleSize(0.09,"t"); //this doesn't do anything
		h2->GetYaxis()->SetTitle("y #upoint d(y)");
		h2->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

		h2->GetXaxis()->CenterTitle(true);
		h2->GetYaxis()->CenterTitle(true);
		h2->GetXaxis()->SetTitleFont(42);
		h2->GetYaxis()->SetTitleFont(42);
		h2->GetXaxis()->SetTitleSize(0.075);
		h2->GetYaxis()->SetTitleSize(0.075);
		h2->GetXaxis()->SetLabelSize(0.05);
		h2->GetYaxis()->SetLabelSize(0.05);
		//h2->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap

		//Center
		h2->GetXaxis()->CenterTitle(true);
		h2->GetYaxis()->CenterTitle(true);

		//Offset x axis so no overlap
		h2->GetXaxis()->SetTitleOffset(0.9);
		h2->GetYaxis()->SetTitleOffset(0.8);


		//h->SetFillColorAlpha(kRed, 0.4);
		//h->SetFillStyle(3001);
		h2->SetLineColor(kBlue);
		h2->SetLineWidth(0);

		//h2->SetFillColorAlpha(kAzure+3, 0.5);
		//h->SetFillStyle(3001);
		h->SetLineColor(kBlack);
		h->SetLineWidth(5);
		// h->SetLineWidth(5);
		// h->SetLineStyle(9);

		gPad->SetLogx();
		gPad->SetFrameBorderMode(0);
		gPad->SetBorderMode(0);
		gPad->SetBorderSize(0);
		gPad->SetLeftMargin(0.15);
		gPad->SetRightMargin(0.005);
		gPad->SetBottomMargin(0.19);
		gPad->SetTopMargin(0.08);

		auto legend = new TLegend(0.18,0.75,0.18+0.24,0.75+0.15);//x start, y start, x end, yend
		// auto legend = new TLegend(0.70,0.85,0.70+0.25,0.85+0.13);
		//legend->SetHeader("","C"); // option "C" allows to center the header
		legend->AddEntry(h,"Geant4","L");
		legend->AddEntry(h2,"SuperTrack","f");
		legend->SetTextSize(0.06);
		legend->Draw();

		//Draw the inline title
		TLatex *t = new TLatex(0.015, 0.95, (TString)titles2[i]);
		t->SetNDC(); //set position in coordinate system relative to canvas
		t->SetTextSize(0.07);
		t->Draw();

		c->Update();
		
		
	}
	c->Print("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrackValidation/finalmultiplotwiderrbigfont_June9th23.jpg");