//Plot 2: Verification plot
TCanvas* c = new TCanvas("c","c");
c->SetCanvasSize(2040, 1640);
c->SetWindowSize(2040, 1640);
c->SetLeftMargin(0.15);
c->SetBottomMargin(0.15);

std::string Newpower = "/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/Newpower/converted";
std::string MyNewpower = "/home/joseph/Documents/PHD_local/June_2022/proton_5um_DNA2_10k/1um";

auto fileEnergyList = SortFolderByEnergy(Newpower);
auto ydList = GetFolderYD(fileEnergyList);
TGraph* g1 = PlotFolderYD(c,ydList);
g1->SetMarkerSize(2);
g1->SetMarkerStyle(21);
g1->SetLineColor(2);
g1->SetLineStyle(2);
g1->SetLineWidth(0);

fileEnergyList = SortFolderByEnergy(MyNewpower);
ydList = GetFolderYD(fileEnergyList);
TGraph* g2 = PlotFolderYD(c,ydList);
g2->SetLineWidth(7);
g2->SetLineColor(2);
g2->SetLineStyle(2);

TGraph* g3 = GetVassiliev1umYD();
g3->SetMarkerSize(4);
g3->SetMarkerStyle(22);
int G3Color = TColor::GetColor(10, 191, 58);
g3->SetMarkerColor(G3Color);

TGraph* g4 = GetNikjooYD();
g4->SetMarkerSize(4);
g4->SetMarkerStyle(23);
int G4Color = TColor::GetColor(24,80,201);
g4->SetMarkerColor(G4Color);



//Axis / General Plot Settings
TMultiGraph* multiGraph = new TMultiGraph();
multiGraph->Add(g1,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
multiGraph->Add(g2,"APL"); //A is to draw the axis arond the line, P to draw marker instead of line
multiGraph->Add(g3,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
multiGraph->Add(g4,"AP"); //A is to draw the axis arond the line, P to draw marker instead of line
multiGraph->GetXaxis()->SetTitle("Primary Proton Energy [MeV]");
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
gPad->SetLogy();
multiGraph->GetXaxis()->SetLimits(0.1,100);
//Y limits set differently than X for some reason
multiGraph->SetMinimum(1);
multiGraph->SetMaximum(100);

auto legend = new TLegend(0.63,0.70,0.89,0.89);//x start, y start, x end, yend
//legend->SetHeader("","C"); // option "C" allows to center the header
legend->AddEntry(g3,"Vassiliev et al.","P");
legend->AddEntry(g4,"Nikjoo et al.","P");
legend->AddEntry(g1,"Newpower et al.","P");
legend->AddEntry(g2,"SuperTrack","L");
//legend->AddEntry(g5,"1 Million Tracks","P");
legend->SetTextSize(0.035);
legend->Draw();

c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/temp_yd.jpg"); 