	 //5um percent difference oversamples plot plot

	double energy = 10;
	double errorLineWidth = 7;
	double errorLineStyle = 9;

	//3mm, DNA2, 1 tracj through 10k tracks
	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040*2, 1640*2);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	//Get the YD and uncertainty of the reference measurement
	auto YDandUncertainty = GetYDandUncertainty("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_1mil/proton_5um_DNA2_1mil_10.0MeV_1e3nm_diameter_x1_oversamples_1652574094.root");
	//proton_3mm_DNA2_10k_100.0MeV_1e3nm_diameter_x1_oversamples_1655501599
	//proton_3mm_DNA2_10k_50.0MeV_1e3nm_diameter_x1_oversamples_1655502494
	//proton_3mm_DNA2_10k_10.0MeV_1e3nm_diameter_x1_oversamples_1655503446
	//proton_3mm_DNA2_10k_1.0MeV_1e3nm_diameter_x1_oversamples_1655502111
	//home/joseph/Documents/PHD_local/June_2022/proton_3mm_oversamples_test/proton_3mm_DNA2_10k/proton_3mm_DNA2_10k_0.1MeV_1e3nm_diameter_x1_oversamples_1655503267.root

	double normalization_value = std::get<0>(YDandUncertainty);

	TGraphErrors* g2 = PlotOversamplesFolderPercentDifferenceWithError("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_1k",energy,1e3,normalization_value);
	g2->SetMarkerSize(6);
	g2->SetMarkerStyle(23);
	g2->SetLineWidth(errorLineWidth);
	g2->SetLineColor(kOrange);
	g2->SetLineStyle(errorLineStyle);
	g2->SetMarkerColor(kOrange);

	TGraphErrors* g3 = PlotOversamplesFolderPercentDifferenceWithError("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_10k",energy,1e4,normalization_value);
	g3->SetMarkerSize(6);
	g3->SetMarkerStyle(89);//89
	g3->SetLineWidth(errorLineWidth);
	g3->SetLineColor(kGreen+4);
	g3->SetLineStyle(errorLineStyle);
	g3->SetMarkerColor(kGreen+4);

	TGraphErrors* g4 = PlotOversamplesFolderPercentDifferenceWithError("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_100k",energy,1e5,normalization_value);
	g4->SetMarkerSize(5);
	g4->SetMarkerStyle(34);//86
	g4->SetLineWidth(errorLineWidth);
	g4->SetLineColor(kAzure+3);
	g4->SetLineStyle(errorLineStyle);
	g4->SetMarkerColor(kAzure+3);

	TGraphErrors* g5 = PlotOversamplesFolderPercentDifferenceWithError("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_1mil",energy,1e6,normalization_value);
	g5->SetMarkerSize(8);
	g5->SetMarkerStyle(90);
	g5->SetMarkerColor(kViolet-6);

	TGraphErrors* g1 = PlotOversamplesFolderPercentDifferenceWithError("/home/joseph/Documents/PHD_local/May_2022/proton_5um_DNA2_100",energy,1e2,normalization_value);
	g1->SetMarkerSize(6);
	g1->SetMarkerStyle(22);
	g1->SetLineWidth(errorLineWidth);
	g1->SetLineColor(kRed+2);
	g1->SetLineStyle(errorLineStyle);
	g1->SetMarkerColor(kRed+2);

	//Axis / General Plot Settings
	TMultiGraph* multiGraph = new TMultiGraph();
	multiGraph->Add(g1,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g2,"PE0"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g3,"PE0"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g4,"PE0"); //A is to draw the axis arond the line, P to draw marker instead of line
	multiGraph->Add(g5,"P"); //A is to draw the axis arond the line, P to draw marker instead of line	
	multiGraph->GetXaxis()->SetTitle("Tracks x Number of Samples");
	multiGraph->Draw("a");
	multiGraph->GetYaxis()->SetTitle(" #Delta #bar{y_{d}} [%]");
	multiGraph->GetXaxis()->CenterTitle(true);
	multiGraph->GetYaxis()->CenterTitle(true);
	multiGraph->GetXaxis()->SetTitleFont(42);
	multiGraph->GetYaxis()->SetTitleFont(42);
	multiGraph->GetXaxis()->SetTitleSize(0.042);
	multiGraph->GetYaxis()->SetTitleSize(0.048);
	multiGraph->GetXaxis()->SetTitleOffset(1.50); //Offset x axis so no overlap
	gPad->SetLogx();
	multiGraph->GetXaxis()->SetLimits(50,5e6); //0.5 5e5
	//Y limits set differently than X for some reason
	multiGraph->SetMinimum(80);
	multiGraph->SetMaximum(105);

	//Draw text
   //TLatex *t = new TLatex(0.8, 2.313, "50 MeV"); //old relative coordinates system
   TLatex *t = new TLatex(0.015, 0.935, "10 MeV"); 
   t->SetNDC(); //set position in coordinate system relative to canvas
   t->Draw();

   //bottom corner
	auto legend = new TLegend(0.63,0.19,0.89,0.19+0.21);//x start, y start, x end, yend
	//top corner
	// auto legend = new TLegend(0.63,0.68,0.89,0.68+0.21);//x start, y start, x end, yend
	//legend->SetHeader("","C"); // option "C" allows to center the header
	legend->AddEntry(g1,"100 Tracks","P");
	legend->AddEntry(g2,"1k Tracks","P");
	legend->AddEntry(g3,"10k Tracks","P");
	legend->AddEntry(g4,"100k Tracks","P");
	// legend->AddEntry(g5,"1 Million Tracks","P");
	//legend->AddEntry(g5,"1 Million Tracks","P");
	legend->SetTextSize(0.035);
	legend->Draw();

	TLine* l = new TLine(50,101,5e6,101);
	l->SetLineStyle(9);
	l->SetLineWidth(4);
	l->Draw();
	TLine* l2 = new TLine(50,99,5e6,99);
	l2->SetLineStyle(9);
	l2->SetLineWidth(4);
	l2->Draw();

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/Revision1/10MeV_percentdiff_5umOversample.jpg"); 