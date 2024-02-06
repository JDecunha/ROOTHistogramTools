	//Variance plot
	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);


	std::string fullLibrary5um = "/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks";

	//Individual graphs
	auto fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/1nm");
	auto ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g1 = PlotFolderYD(c,ydList);
	g1->SetLineColor(kPink-1);
	g1->SetLineStyle(1);
	g1->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/2nm");
	ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g2 = PlotFolderYD(c,ydList);
	g2->SetLineColor(kMagenta+4);
	g2->SetLineStyle(1);
	g2->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/10nm");
	ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g3 = PlotFolderYD(c,ydList);
	g3->SetLineColor(kOrange+7);
	g3->SetLineStyle(1);
	g3->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/50nm");
	ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g4 = PlotFolderYD(c,ydList);
	g4->SetLineColor(kOrange);
	g4->SetLineStyle(1);
	g4->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/100nm");
	ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g5 = PlotFolderYD(c,ydList);
	g5->SetLineColor(kSpring-7);
	g5->SetLineStyle(1);
	g5->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary5um+"/1e3nm");
	ydList = GetFolderRelativePercentVariancefy(fileEnergyList);
	TGraph* g6 = PlotFolderYD(c,ydList);
	g6->SetLineColor(kAzure+3);
	g6->SetLineStyle(1);
	g6->SetLineWidth(4);


	//Axis / General Plot Settings
	TMultiGraph* multiGraph = new TMultiGraph();
	multiGraph->Add(g1,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g2,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g3,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g4,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g5,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g6,"AL"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->GetXaxis()->SetTitle("Primary Proton Energy [MeV]");
	multiGraph->Draw("a");
	multiGraph->GetYaxis()->SetTitle(" #frac{V(f(y))}{f(y)} x 100 [%] ");
	multiGraph->GetXaxis()->CenterTitle(true);
	multiGraph->GetYaxis()->CenterTitle(true);
	multiGraph->GetXaxis()->SetTitleFont(42);
	multiGraph->GetYaxis()->SetTitleFont(42);
	multiGraph->GetXaxis()->SetTitleSize(0.042);
	multiGraph->GetYaxis()->SetTitleSize(0.048);
	multiGraph->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
	multiGraph->GetYaxis()->SetTitleOffset(1.3); //Offset y axis so we can see it
	gPad->SetLogx();
	multiGraph->GetXaxis()->SetLimits(0.1,100);
	multiGraph->SetMinimum(9.9);
	multiGraph->SetMaximum(1000);
	gPad->SetLogy();
	//Y limits set differently than X for some reason
	
	//multiGraph->SetMaximum(106);

	//bottom corner
	auto legend = new TLegend(0.76,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
	//top corner
	//auto legend = new TLegend(0.62,0.68,0.89,0.68+0.21);//x start, y start, x end, yend
	//bottom left corner
	//auto legend = new TLegend(0.19,0.19,0.19+0.27,0.19+0.21);//x start, y start, x end, yend
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"1 nm","L");
	legend->AddEntry(g2,"2 nm","L");
	legend->AddEntry(g3,"10 nm","L");
	legend->AddEntry(g4,"50 nm","L");
	legend->AddEntry(g5,"100 nm","L");
	legend->AddEntry(g6,"1 #mum","L");
	//multiGraph->GetYaxis()->SetNdivisions(513);
	multiGraph->GetYaxis()->ChangeLabel(1,-1,-1,-1,-1,-1,"10%");
	multiGraph->GetYaxis()->ChangeLabel(2,-1,-1,-1,-1,-1,"100%");
	multiGraph->GetYaxis()->ChangeLabel(3,-1,-1,-1,-1,-1,"1000%");
	//legend->AddEntry(g5,"1 Million Tracks","P");
	legend->SetTextSize(0.035);
	legend->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/variancetest.jpg"); 