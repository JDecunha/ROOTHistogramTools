	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040/2, 1640/2);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	std::string path = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks";

	std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks";

	gSystem->Unlink("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/testgif_Julyoldmethod.gif");

	std::vector<std::string> target_sizes = {"1","2","3","4","5","6","7","8","9","10","20","30","40","50","60","70","80","90","100","200","300","400","500","600","700","800","900","1e3","2e3","3e3","4e3","5e3","6e3","7e3","8e3","9e3","10e3"};

	std::vector<std::string> target_sizes_title = {"1","2","3","4","5","6","7","8","9","10","20","30","40","50","60","70","80","90","100","200","300","400","500","600","700","800","900","1x10^{3}","2x10^{3}","3x10^{3}","4x10^{3}","5x10^{3}","6x10^{3}","7x10^{3}","8x10^{3}","9x10^{3}","10x10^{3}"};

	TH1D* h;
	TH1D* h2;

	for (int i = 1; i <= 100; i++)
	{
		h = GetDy(path, i, "1e3");
		h2 = GetDy(path2, i, "1e3");

		gStyle->SetTitleFont(42,"t");

		h->Draw();
		h2->Draw("same");
		
		//Set range
		h->GetYaxis()->SetRangeUser(0,1);
		//h->GetXaxis()->SetRange(0,1);

		//Set titles
		//std::string title = std::to_string(int(energy));
		//title += " MeV";
		h->SetTitle("");
		//h2->SetTitle("");
		h->SetTitleSize(0.03,"t"); //this doesn't do anything
		h->GetYaxis()->SetTitle("y #upoint d(y)");
		h->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

		h->GetXaxis()->CenterTitle(true);
		h->GetYaxis()->CenterTitle(true);
		h->GetXaxis()->SetTitleFont(42);
		h->GetYaxis()->SetTitleFont(42);
		h->GetXaxis()->SetTitleSize(0.042);
		h->GetYaxis()->SetTitleSize(0.048);
		h->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
		std::string titlestring = std::to_string(i) + " MeV";
		TLatex *t = new TLatex(0.015, 0.935, (TString)titlestring);
		t->SetNDC(); //set position in coordinate system relative to canvas
		t->Draw();
		//h->SetFillColor(kAzure+5);
		h->SetFillColorAlpha(kAzure+3, 0.5);
		//h->SetFillStyle(3001);
		h->SetLineColor(kBlack);
		h->SetLineWidth(2);

		//Center
		h->GetXaxis()->CenterTitle(true);
		h->GetYaxis()->CenterTitle(true);

		//Offset x axis so no overlap
		h->GetXaxis()->SetTitleOffset(1.2);

		h->GetXaxis()->SetTitleFont(42);
		h->GetYaxis()->SetTitleFont(42);

		//h2->Draw();
		h2->SetFillColorAlpha(kRed, 0.4);
		//h->SetFillStyle(3001);
		h2->SetLineColor(kBlack);
		h2->SetLineWidth(2);

		gPad->SetLogx();

		//bottom corner
		//auto legend = new TLegend(0.62,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
		//top corner
		auto legend = new TLegend(0.18,0.73,0.18+0.14,0.73+0.15);//x start, y start, x end, yend
		//legend->SetHeader("","C"); // option "C" allows to center the header
		legend->AddEntry(h2,"3 mm","f");
		legend->AddEntry(h,"5 #mum","f");	
		//legend->AddEntry(g5,"10 #mum","L");
		//legend->AddEntry(g6,"1","L");
		//legend->AddEntry(g5,"1 Million Tracks","P");
		legend->SetTextSize(0.035);
		legend->Draw();
		
		c->Update();
		c->Print("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/testgif_Julyoldmethod.gif+");
	}




	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040/2, 1640/2);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	std::string path = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks";

	std::string path2 = "/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks";

	gSystem->Unlink("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/testgif_Julyoldmethod.gif");

	std::vector<std::string> target_sizes = {"1","2","3","4","5","6","7","8","9","10","20","30","40","50","60","70","80","90","100","200","300","400","500","600","700","800","900","1e3","2e3","3e3","4e3","5e3","6e3","7e3","8e3","9e3","10e3"};

	std::vector<std::string> target_sizes_title = {"1","2","3","4","5","6","7","8","9","10","20","30","40","50","60","70","80","90","100","200","300","400","500","600","700","800","900","1x10^{3}","2x10^{3}","3x10^{3}","4x10^{3}","5x10^{3}","6x10^{3}","7x10^{3}","8x10^{3}","9x10^{3}","10x10^{3}"};

	TH1D* h;
	TH1D* h2;

	for (int i = 0; i < target_sizes.size(); i++)
	{
		h = GetDy(path, 50, target_sizes[i]);
		h2 = GetDy(path2, 50, target_sizes[i]);

		gStyle->SetTitleFont(42,"t");

		h->Draw();
		//h2->Draw();
		
		//Set range
		h->GetYaxis()->SetRangeUser(0,1);
		//h->GetXaxis()->SetRange(0,1);

		//Set titles
		//std::string title = std::to_string(int(energy));
		//title += " MeV";
		h->SetTitle("");
		h2->SetTitle("");
		h->SetTitleSize(0.03,"t"); //this doesn't do anything
		h->GetYaxis()->SetTitle("y #upoint d(y)");
		h->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

		h->GetXaxis()->CenterTitle(true);
		h->GetYaxis()->CenterTitle(true);
		h->GetXaxis()->SetTitleFont(42);
		h->GetYaxis()->SetTitleFont(42);
		h->GetXaxis()->SetTitleSize(0.042);
		h->GetYaxis()->SetTitleSize(0.048);
		h->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
		std::string titlestring = target_sizes_title[i]+" nm";
		TLatex *t = new TLatex(0.015, 0.935, (TString)titlestring);
		t->SetNDC(); //set position in coordinate system relative to canvas
		t->Draw();
		//h->SetFillColor(kAzure+5);
		h->SetFillColorAlpha(kAzure+5, 0.4);
		//h->SetFillStyle(3001);
		h->SetLineColor(kBlack);
		h->SetLineWidth(2);

		//Center
		h->GetXaxis()->CenterTitle(true);
		h->GetYaxis()->CenterTitle(true);

		//Offset x axis so no overlap
		h->GetXaxis()->SetTitleOffset(1.2);

		h->GetXaxis()->SetTitleFont(42);
		h->GetYaxis()->SetTitleFont(42);

		//h2->Draw();
		h2->SetFillColorAlpha(kRed, 0.4);
		//h->SetFillStyle(3001);
		h2->SetLineColor(kBlack);
		h2->SetLineWidth(2);

		gPad->SetLogx();

		//bottom corner
		//auto legend = new TLegend(0.62,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
		//top corner
		auto legend = new TLegend(0.18,0.73,0.18+0.14,0.73+0.15);//x start, y start, x end, yend
		//legend->SetHeader("","C"); // option "C" allows to center the header
		legend->AddEntry(h,"5 #mum","f");
		//legend->AddEntry(h2,"3 mm","f");
		//legend->AddEntry(g5,"10 #mum","L");
		//legend->AddEntry(g6,"1","L");
		//legend->AddEntry(g5,"1 Million Tracks","P");
		legend->SetTextSize(0.035);
		//legend->Draw();
		
		c->Update();
		c->Print("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/testgif_Julyoldmethod.gif+");
	}