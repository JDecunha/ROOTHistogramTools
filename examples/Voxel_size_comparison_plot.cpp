Plot 3: Comparison of voxel sizes

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	std::string MyNewpower = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks/1e3nm";
	std::string threemm_1um = "/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks/1e3nm";

	auto fileEnergyList = SortFolderByEnergy(threemm_1um);
	auto ydList = GetFolderYD(fileEnergyList);
	TGraph* g1 = PlotFolderYD(c,ydList);

	g1->GetHistogram()->SetMinimum(1);
	g1->GetHistogram()->SetMaximum(100);
	g1->GetXaxis()->SetLimits(0.1,100);
		//g1->SetMarkerColor(4);
	g1->SetMarkerSize(0);
	g1->SetMarkerStyle(22);
	g1->SetLineColor(kPink-1);
	g1->SetLineStyle(1);
	g1->SetLineWidth(4);
	//g1->SetTitle("#bar{y_{d}} in 1 #mum diameter spheres");
	g1->GetXaxis()->SetTitle("Primary Proton Energy [MeV]");
	g1->GetYaxis()->SetTitle("#bar{y_{d}} [#frac{keV}{#mum}]");
	g1->GetXaxis()->CenterTitle(true);
	g1->GetYaxis()->CenterTitle(true);
	g1->GetXaxis()->SetTitleFont(42);
	g1->GetYaxis()->SetTitleFont(42);
	g1->GetXaxis()->SetTitleSize(0.048);
	g1->GetYaxis()->SetTitleSize(0.048);
	g1->GetXaxis()->SetTitleOffset(1.2); //Offset x axis so no overlap
	g1->Draw("ACP");

	fileEnergyList = SortFolderByEnergy(MyNewpower);
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g2 = PlotFolderYD(c,ydList);

	g2->SetLineWidth(4);
	g2->SetLineColor(kAzure+3);
	g2->SetLineStyle(1);
	g2->Draw("pl same");
	gPad->SetLogx();
	gPad->SetLogy();

	 auto legend = new TLegend(0.50,0.78,0.89,0.89);
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"1 #mum target, 3 mm voxel","l");
	legend->AddEntry(g2,"1 #mum target, 5 #mum voxel","l");
	legend->SetTextSize(0.035);
	legend->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/temp_yd.jpg"); 