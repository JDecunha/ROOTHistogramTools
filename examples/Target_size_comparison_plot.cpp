	Target size comparison for 5 um:

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);


	std::string fullLibrary3mm = "/home/joseph/Documents/PHD_local/July_2022/proton_5umVoxel_DNA2_10kTracks";

	//Individual graphs
	auto fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/1nm");
	auto ydList = GetFolderYD(fileEnergyList);
	TGraph* g1 = PlotFolderYD(c,ydList);
	g1->SetLineColor(kPink-1);
	g1->SetLineStyle(1);
	g1->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/2nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g2 = PlotFolderYD(c,ydList);
	g2->SetLineColor(kMagenta+3);
	g2->SetLineStyle(1);
	g2->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/10nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g3 = PlotFolderYD(c,ydList);
	g3->SetLineColor(kOrange+7);
	g3->SetLineStyle(1);
	g3->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/50nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g4 = PlotFolderYD(c,ydList);
	g4->SetLineColor(kOrange);
	g4->SetLineStyle(1);
	g4->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/100nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g5 = PlotFolderYD(c,ydList);
	g5->SetLineColor(kSpring-7);
	g5->SetLineStyle(1);
	g5->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/1e3nm");
	ydList = GetFolderYD(fileEnergyList);
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
	multiGraph->GetYaxis()->SetTitle(" #bar{y_{d}} [#frac{keV}{#mum}]");
	multiGraph->GetXaxis()->CenterTitle(true);
	multiGraph->GetYaxis()->CenterTitle(true);
	multiGraph->GetXaxis()->SetTitleFont(42);
	multiGraph->GetYaxis()->SetTitleFont(42);
	multiGraph->GetXaxis()->SetTitleSize(0.042);
	multiGraph->GetYaxis()->SetTitleSize(0.048);
	multiGraph->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
	gPad->SetLogx();
	//multiGraph->GetXaxis()->SetLimits(0.5,5e4);
	//Y limits set differently than X for some reason
	//multiGraph->SetMinimum(96);
	//multiGraph->SetMaximum(106);

	//bottom corner
	//auto legend = new TLegend(0.62,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
	//top corner
	auto legend = new TLegend(0.75,0.68,0.89,0.68+0.21);//x start, y start, x end, yend
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"1 nm","L");
	legend->AddEntry(g2,"10 nm","L");
	legend->AddEntry(g3,"100 nm","L");
	legend->AddEntry(g4,"1 #mum","L");
	//legend->AddEntry(g5,"10 #mum","L");
	//legend->AddEntry(g6,"1","L");
	//legend->AddEntry(g5,"1 Million Tracks","P");
	legend->SetTextSize(0.035);
	//legend->Draw();

	TLatex *t = new TLatex(0.91, 0.400, "1 nm");
	t->SetTextSize(0.025);
	t->SetNDC(); //set position in coordinate system relative to canvas
	t->Draw();

	TLatex *t5 = new TLatex(0.91, 0.32, "2 nm");
	t5->SetTextSize(0.025);
	t5->SetNDC(); //set position in coordinate system relative to canvas
	t5->Draw();

	TLatex *t1 = new TLatex(0.91, 0.27, "10 nm");
	t1->SetTextSize(0.025);
	t1->SetNDC(); //set position in coordinate system relative to canvas
	t1->Draw();

	TLatex *t6 = new TLatex(0.91, 0.23, "50 nm");
	t6->SetTextSize(0.025);
	t6->SetNDC(); //set position in coordinate system relative to canvas
	t6->Draw();

	TLatex *t2 = new TLatex(0.909, 0.203, "100 nm");
	t2->SetTextSize(0.025);
	t2->SetNDC(); //set position in coordinate system relative to canvas
	t2->Draw();

	TLatex *t3 = new TLatex(0.91, 0.177, "1 #mum");
	t3->SetTextSize(0.025);
	t3->SetNDC(); //set position in coordinate system relative to canvas
	t3->Draw();

	TLatex *t4 = new TLatex(0.91, 0.167, "10 #mum");
	t4->SetTextSize(0.025);
	t4->SetNDC(); //set position in coordinate system relative to canvas
	//t4->Draw();

	TLatex *t7 = new TLatex(0.015, 0.935, "5 #mum voxel");
	//t7->SetTextSize(0.045);
	t7->SetTextFont(42);
	t7->SetNDC(); //set position in coordinate system relative to canvas
	t7->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/test.jpg"); 


	//3 mm comparison

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);


	std::string fullLibrary3mm = "/home/joseph/Documents/PHD_local/July_2022/proton_3mmVoxel_DNA2_1kTracks";

	//Individual graphs
	auto fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/1nm");
	auto ydList = GetFolderYD(fileEnergyList);
	TGraph* g1 = PlotFolderYD(c,ydList);
	g1->SetLineColor(kPink-1);
	g1->SetLineStyle(1);
	g1->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/2nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g2 = PlotFolderYD(c,ydList);
	g2->SetLineColor(kMagenta+3);
	g2->SetLineStyle(1);
	g2->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/10nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g3 = PlotFolderYD(c,ydList);
	g3->SetLineColor(kOrange+7);
	g3->SetLineStyle(1);
	g3->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/50nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g4 = PlotFolderYD(c,ydList);
	g4->SetLineColor(kOrange);
	g4->SetLineStyle(1);
	g4->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/100nm");
	ydList = GetFolderYD(fileEnergyList);
	TGraph* g5 = PlotFolderYD(c,ydList);
	g5->SetLineColor(kSpring-7);
	g5->SetLineStyle(1);
	g5->SetLineWidth(4);

	fileEnergyList = SortFolderByEnergy(fullLibrary3mm+"/1e3nm");
	ydList = GetFolderYD(fileEnergyList);
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
	multiGraph->GetYaxis()->SetTitle(" #bar{y_{d}} [#frac{keV}{#mum}]");
	multiGraph->GetXaxis()->CenterTitle(true);
	multiGraph->GetYaxis()->CenterTitle(true);
	multiGraph->GetXaxis()->SetTitleFont(42);
	multiGraph->GetYaxis()->SetTitleFont(42);
	multiGraph->GetXaxis()->SetTitleSize(0.042);
	multiGraph->GetYaxis()->SetTitleSize(0.048);
	multiGraph->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
	gPad->SetLogx();
	//multiGraph->GetXaxis()->SetLimits(0.5,5e4);
	//Y limits set differently than X for some reason
	//multiGraph->SetMinimum(96);
	//multiGraph->SetMaximum(106);

	//bottom corner
	//auto legend = new TLegend(0.62,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
	//top corner
	auto legend = new TLegend(0.75,0.68,0.89,0.68+0.21);//x start, y start, x end, yend
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"1 nm","L");
	legend->AddEntry(g2,"10 nm","L");
	legend->AddEntry(g3,"100 nm","L");
	legend->AddEntry(g4,"1 #mum","L");
	//legend->AddEntry(g5,"10 #mum","L");
	//legend->AddEntry(g6,"1","L");
	//legend->AddEntry(g5,"1 Million Tracks","P");
	legend->SetTextSize(0.035);
	//legend->Draw();

	TLatex *t = new TLatex(0.91, 0.400, "1 nm");
	t->SetTextSize(0.025);
	t->SetNDC(); //set position in coordinate system relative to canvas
	t->Draw();

	TLatex *t5 = new TLatex(0.91, 0.32, "2 nm");
	t5->SetTextSize(0.025);
	t5->SetNDC(); //set position in coordinate system relative to canvas
	t5->Draw();

	TLatex *t1 = new TLatex(0.91, 0.27, "10 nm");
	t1->SetTextSize(0.025);
	t1->SetNDC(); //set position in coordinate system relative to canvas
	t1->Draw();

	TLatex *t6 = new TLatex(0.91, 0.23, "50 nm");
	t6->SetTextSize(0.025);
	t6->SetNDC(); //set position in coordinate system relative to canvas
	t6->Draw();

	TLatex *t2 = new TLatex(0.91, 0.203, "100 nm");
	t2->SetTextSize(0.025);
	t2->SetNDC(); //set position in coordinate system relative to canvas
	t2->Draw();

	TLatex *t3 = new TLatex(0.91, 0.177, "1 #mum");
	t3->SetTextSize(0.025);
	t3->SetNDC(); //set position in coordinate system relative to canvas
	t3->Draw();

	TLatex *t4 = new TLatex(0.91, 0.170, "10 #mum");
	t4->SetTextSize(0.025);
	t4->SetNDC(); //set position in coordinate system relative to canvas
	//t4->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/test.jpg"); 


