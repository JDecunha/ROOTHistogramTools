/50 MeV 5 um Oversamples plot

		double energy = 50;

	//5um, DNA2, 100 tracks through 1 million tracks
	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	TGraph* g1 = PlotOversamplesFolder("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_100/",energy,1e2);
	g1->SetMarkerSize(4);
	g1->SetMarkerStyle(22);
	g1->SetMarkerColor(kRed+2);

	TGraph* g2 = PlotOversamplesFolder("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_1k/",energy,1e3);
	g2->SetMarkerSize(4);
	g2->SetMarkerStyle(23);
	g2->SetMarkerColor(kOrange);

	TGraph* g3 = PlotOversamplesFolder("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_10k/",energy,1e4);
	g3->SetMarkerSize(6);
	g3->SetMarkerStyle(89);
	g3->SetMarkerColor(kGreen+4);

	TGraph* g4 = PlotOversamplesFolder("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_100k/",energy,1e5);
	g4->SetMarkerSize(6);
	g4->SetMarkerStyle(86);
	g4->SetMarkerColor(kAzure+3);

	TGraph* g5 = PlotOversamplesFolder("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_1mil/",energy,1e6);
	g5->SetMarkerSize(6);
	g5->SetMarkerStyle(90);
	g5->SetMarkerColor(kViolet-6);

	//Axis / General Plot Settings
	TMultiGraph* multiGraph = new TMultiGraph();
	multiGraph->Add(g1,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g2,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g3,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g4,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	//multiGraph->Add(g5,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->GetXaxis()->SetTitle("Tracks x Number of Samples");
	multiGraph->Draw("a");
	multiGraph->GetYaxis()->SetTitle("#bar{y_{d}} [#frac{keV}{#mum}]");
	multiGraph->GetXaxis()->CenterTitle(true);
	multiGraph->GetYaxis()->CenterTitle(true);
	multiGraph->GetXaxis()->SetTitleFont(42);
	multiGraph->GetYaxis()->SetTitleFont(42);
	multiGraph->GetXaxis()->SetTitleSize(0.042);
	multiGraph->GetYaxis()->SetTitleSize(0.048);
	multiGraph->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
	gPad->SetLogx();
	multiGraph->GetXaxis()->SetLimits(10,1e7);
	//Y limits set differently than X for some reason
	multiGraph->SetMinimum(74);
	multiGraph->SetMaximum(78);

	//Draw text
   //TLatex *t = new TLatex(0.8, 2.313, "50 MeV"); //old relative coordinates system
   TLatex *t = new TLatex(0.015, 0.935, "0.1 MeV"); 
   t->SetNDC(); //set position in coordinate system relative to canvas
   t->Draw();

	auto legend = new TLegend(0.62,0.19,0.89,0.40);//x start, y start, x end, yend
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"100 Tracks","P");
	legend->AddEntry(g2,"1000 Tracks","P");
	legend->AddEntry(g3,"10000 Tracks","P");
	legend->AddEntry(g4,"100000 Tracks","P");
	//legend->AddEntry(g5,"1 Million Tracks","P");
	legend->SetTextSize(0.035);
	legend->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/01MeVOversample.jpg");