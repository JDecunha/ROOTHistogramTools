#include <filesystem>
#include <iostream>
#include <math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGraph.h"
#include "TLine.h"
#include "TLegend.h"
#include "TMultiGraph.h"
#include "TLatex.h"
#include "TMath.h"
#include "TSystem.h"
#include "TGraphErrors.h"

#include "./include/ReadAndConvertNewpower.hh"

void PMF_to_PDF(TH1* h)
{
	//This converts a probability mass function to a probability density function
	int length = h->GetNbinsX();

	double_t normalization = 0;

	for (int i = 1; i <= length; i++) //bins per bin width
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		auto per_width = value/(width);
		//std::cout << "bin: " << i << " value: " << value << " after normalization: " << per_width << std::endl; 
		h->SetBinContent(i,per_width);

		normalization += value;
	}
	
	for (int i = 1; i <= length; i++) //normalize
	{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		//std::cout << "bin: " << i << " value: " << value << " normalization: " << normalization << " after normalization: " << normalized << std::endl; 
		h->SetBinContent(i,normalized);
	}
}

void PMF_to_DoseFunction(TH1* h)
{
	/*//This converts a probability mass function to a dose function n(y) --> d(y)
	int length = h->GetNbinsX();

	double_t normalization = 0;
	double_t yf = 0;

	for (int i = 1; i <= length; i++) //create unnormalized f(y)
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		double bin_middle = (high_edge+low_edge)/double(2);

		auto per_width = value/(width);
		//std::cout << "bin: " << i << " value: " << value << " after normalization: " << per_width << std::endl; 
		h->SetBinContent(i,per_width);

		normalization += value;
	}
	
	for (int i = 1; i <= length; i++) //normalize f(y)
	{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		//std::cout << "bin: " << i << " value: " << value << " normalization: " << normalization << " after normalization: " << normalized << std::endl; 
		h->SetBinContent(i,normalized);
	}

	//Calculate y_f
	for (int i = 1; i <= length; i++) //create unnormalized f(y)
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		double bin_middle = (high_edge+low_edge)/double(2);

		yf += bin_middle*value*width;
	}

	for (int i = 1; i <= length; i++) //convert to d(y)
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		double bin_middle = (high_edge+low_edge)/double(2);

		auto new_value = (value*bin_middle)/(yf);
		//std::cout << "bin: " << i << " value: " << value << " after normalization: " << per_width << std::endl; 
		h->SetBinContent(i,new_value);
	}*/


	
	//This converts a probability mass function to a probability density function
	int length = h->GetNbinsX();

	double_t normalization = 0;

	for (int i = 1; i <= length; i++) //bins per bin width
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		double bin_middle = (high_edge+low_edge)/double(2);
		auto per_width = bin_middle*value/(width);
		//std::cout << "bin: " << i << " value: " << value << " after normalization: " << per_width << std::endl; 
		h->SetBinContent(i,per_width);

		normalization += bin_middle*value;
	}
	
	for (int i = 1; i <= length; i++) //normalize
	{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		//std::cout << "bin: " << i << " value: " << value << " normalization: " << normalization << " after normalization: " << normalized << std::endl; 
		h->SetBinContent(i,normalized);
	}
}

void Prepare_for_Semilog(TH1* h)
{
	//This takes a PDF and normalizes it by an extra factor of y (i.e. to give y*f(y))to preserve the graphical properties
	//of a PDF on a semilog axis
	int length = h->GetNbinsX();
	for (int i = 1; i <= length; i++) //bins per bin width
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		double mid_value = (high_edge+low_edge)/double(2);
		h->SetBinContent(i,value*mid_value);
	}
}

void Print_TH1(TH1* h)
{
	int length = h->GetNbinsX();

	for (int i = 1; i <= length; i++) //bins per bin width
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto per_width = value/(high_edge-low_edge);
		std::cout << "bin: " << i << " value: " << value << std::endl;
	}

}

void Num_Entries(TH1* h)
{
	int length = h->GetNbinsX();
	int total = 0;

	for (int i = 1; i <= length; i++) //bins per bin width
	{
		total += h->GetBinContent(i);
		//std::cout << h->GetBinContent(i) << std::endl;
	}
	//std::cout << "Total: " << total << std::endl;

}

void Compare_To_Newpower()
{
	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	TFile* f = new TFile("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/SuperTrack/output/Proton50.0MeV5umTarget3mmVoxel_1638836719.root");

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2000, 1600);
    c->SetWindowSize(1020, 820);


	gStyle->SetTitleFont(42,"t");

	TH1D* h = (TH1D*)f->Get("Lineal energy histogram");
	PMF_to_PDF(h);
	//Prepare_for_Semilog(h);
	//Print_TH1(h);

	h->Draw();
	
	//Set range
	h->GetYaxis()->SetRangeUser(0,1);
	//h->GetXaxis()->SetRange(0,1);

	//Set titles
	h->SetTitle("50 MeV proton, 500 nm diameter target");
	h->SetTitleSize(0.03,"t"); //this doesn't do anything
	h->GetYaxis()->SetTitle("y*f(y)");
	h->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

	//Center
	h->GetXaxis()->CenterTitle(true);
	h->GetYaxis()->CenterTitle(true);

	//Offset x axis so no overlap
	h->GetXaxis()->SetTitleOffset(1.2);

	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);

	//gPad->SetLogx();
	
	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/proton_50MeV_500nm_10samples.jpg");
}

void Plot()
{
	gStyle->SetOptStat(0); //Don't print the stats window in the top right

	//TFile* f = new TFile("/home/joseph/Documents/PHD_local/proton_1um_5umrestrictedtracks_100x/proton/proton_73.0MeV_1e3nm_diameter_x100_oversamples_1644434154.root");
	TFile* f = new TFile("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/SuperTrack/output/test/test_1ev1645576079.root");

	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2000, 1600);
    c->SetWindowSize(1020, 820);

	gStyle->SetTitleFont(42,"t");

	TH1D* h = (TH1D*)f->Get("Lineal energy histogram");
	Num_Entries(h);
	PMF_to_PDF(h);
	Prepare_for_Semilog(h);

	h->Draw();
	
	//Set range
	h->GetYaxis()->SetRangeUser(0,1);
	h->GetXaxis()->SetRangeUser(0.01,300);
	

	//Set titles
	h->SetTitle("test, 1 um diameter target");
	h->SetTitleSize(0.03,"t"); //this doesn't do anything
	h->GetYaxis()->SetTitle("y*f(y)");
	h->GetXaxis()->SetTitle("y [#frac{keV}{#mum}]");

	//Center
	h->GetXaxis()->CenterTitle(true);
	h->GetYaxis()->CenterTitle(true);

	//Offset x axis so no overlap
	h->GetXaxis()->SetTitleOffset(1.2);

	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);

	gPad->SetLogx();

	
	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/temp.jpg");
}

std::string GetFileEnergy(std::string filename)
{
	std::stringstream pathsplitter(filename);
	std::string output;

	while (std::getline(pathsplitter,output,'_'))
	{
		//Find and erase MeV
		auto n = output.find("MeV");
		if (n != -1)
		{
			output.erase(n,3);
			return output;
		}
	}

	return "failure :(";
}

std::string GetFileTargetSize(std::string filename)
{
	std::stringstream pathsplitter(filename);
	std::string output;

	while (std::getline(pathsplitter,output,'_'))
	{
		//Find and erase nm
		auto n = output.find("nm");
		if (n != -1)
		{
			output.erase(n,2);
			return output;
		}
	}

	return "failure :(";
}

std::map<double,std::string> SortFolderByEnergy(const std::string& path)
{
	std::map<double,std::string> energyPathMap;

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		std::stringstream pathsplitter(entry.path().filename());
		std::string output;

		bool MeVFound = false;

		while (MeVFound == false)
		{
			std::getline(pathsplitter,output,'_');

			//Find and erase MeV
			auto n = output.find("MeV");
			if (n != -1)
			{
				output.erase(n,3);

				//cast to a double
				double energy = std::stod(output);

				//match the energy to a filepath
				energyPathMap.insert(std::pair<double,std::string>(energy,entry.path()));
				MeVFound = true;
			}
		}
		
	}

	return energyPathMap;
}

std::map<double,std::string> SortFolderByEnergyNew(const std::string& path)
{
	std::map<double,std::string> energyPathMap;

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		std::stringstream pathsplitter(entry.path().filename());
		std::string output;

		bool MeVFound = false;

		while (MeVFound == false)
		{
			std::getline(pathsplitter,output,'_');
			std::getline(pathsplitter,output,'_');
			std::getline(pathsplitter,output,'_');
			std::getline(pathsplitter,output,'_');

			//Find and erase MeV
			auto n = output.find("MeV");
			if (n != -1)
			{
				output.erase(n,3);

				//cast to a double
				double energy = std::stod(output);

				//match the energy to a filepath
				energyPathMap.insert(std::pair<double,std::string>(energy,entry.path()));
				MeVFound = true;
			}
		}
		
	}

	return energyPathMap;
}

std::map<double,std::string> SortFolderByEnergyAndFilter(const std::string& path, double TargetSize)
{
	std::map<double,std::string> energyPathMap;

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		std::stringstream pathsplitter(entry.path().filename());
		
		double fileTargetSize = std::stod(GetFileTargetSize(entry.path().filename()));
		if (fileTargetSize == TargetSize)
		{
			double energy = std::stod(GetFileEnergy(entry.path().filename()));
			energyPathMap.insert(std::pair<double,std::string>(energy,entry.path()));
		}
	}
	return energyPathMap;
}

double GetYD(std::string path)
{

	double normalization = 0;
	double topUncertainty = 0;
	double bottomUncertainty = 0;
	double top = 0;
	double bottom = 0;

	TFile f = TFile((TString)path); //get file
	TH1D* h = (TH1D*)f.Get("Lineal energy histogram"); //get histogram
	int length = h->GetNbinsX(); //get length

	//Step 1.) Convert to f(y) PDF
	for (int i = 1; i <= length; i++) //bins per bin width
	{
	auto value = h->GetBinContent(i);
	auto low_edge = h->GetBinLowEdge(i);
	auto high_edge = h->GetBinLowEdge(i+1);
	auto width = high_edge-low_edge;
	auto per_width = value/(width);
	h->SetBinContent(i,per_width);

	normalization += value;
	}
	
	for (int i = 1; i <= length; i++) //normalize
	{
	auto value = h->GetBinContent(i);
	auto normalized = value/normalization;
	h->SetBinContent(i,normalized);
	}

	//Step 2.) Calculate y_d
	for (int i = 1; i <= length; i++) 
	{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		double y = (high_edge+low_edge)/2;
		auto width = high_edge-low_edge;

		top += value*width*pow(y,2);
		bottom += value*width*y; 
	}	
	std::cout << "y_d: " << top/bottom << " nentries:" << normalization << std::endl;

	return top/bottom;
}

std::tuple<double,double> GetYDandUncertainty(const std::string& path)
{

	double normalization = 0;

	double uncertainty_top = 0;
	double uncertainty_bottom = 0;
	double top_absolute_N = 0;
	double bottom_absolute_N = 0;
	double uncertainty = 0;

	
	double top = 0;
	double bottom = 0;

	TFile f = TFile((const TString&)path); //get file
	TH1D* h = (TH1D*)f.Get("Lineal energy histogram"); //get histogram
	TH1D* h_unnormalized = new TH1D(*h);
	int length = h->GetNbinsX(); //get length

	//Step 1.) Convert to f(y) PDF
	for (int i = 1; i <= length; i++) //bins per bin width
	{
		auto value = h->GetBinContent(i);
		double low_edge = h->GetBinLowEdge(i);
		double high_edge = h->GetBinLowEdge(i+1);
		double width = high_edge-low_edge;
		double per_width = value/(width);

		//Normalize per bin width
		h->SetBinContent(i,per_width);
	}

	//Step 2.) Normalize so integration yields 1
	for (int i = 1; i <= length; i++) 
	{
		auto value = h->GetBinContent(i);
		double low_edge = h->GetBinLowEdge(i);
		double high_edge = h->GetBinLowEdge(i+1);
		double width = high_edge-low_edge;
		normalization += value*width;
	}
	for (int i = 1; i <= length; i++) 
	{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		h->SetBinContent(i,normalized);
	}


	//Step 3.) Calculate y_d
	for (int i = 1; i <= length; i++) 
	{
		auto value = h->GetBinContent(i);
		double low_edge = h->GetBinLowEdge(i);
		double high_edge = h->GetBinLowEdge(i+1);
		double y = (high_edge+low_edge)/2;
		double width = high_edge-low_edge;

		top += value*width*pow(y,2);
		bottom += value*width*y; 
	}	

	//Step 4.) Calculate uncertainty
	for (int i = 1; i <= length; i++) 
	{
		auto value = h->GetBinContent(i);
		auto value_unnormalized = h_unnormalized->GetBinContent(i);
		//std::cout << value_unnormalized << std::endl;
		double low_edge = h->GetBinLowEdge(i);
		double high_edge = h->GetBinLowEdge(i+1);
		double width = high_edge-low_edge;
		double per_width = value/(width);
		double y = double(high_edge+low_edge)/double(2);

		double uncertainty_per_bin;
		if (value_unnormalized == 0) { uncertainty_per_bin = 0; }
		else
		{
			uncertainty_per_bin = TMath::Sqrt(value_unnormalized);
		}

		//Need to calculate uncertainty before we start normalizing
		uncertainty_top += TMath::Power(uncertainty_per_bin*width*y*y,2);
	    uncertainty_bottom += TMath::Power(uncertainty_per_bin*width*y,2);

	    top_absolute_N += value_unnormalized*width*y*y;
	    bottom_absolute_N += value_unnormalized*width*y;

	}	

	uncertainty_top = TMath::Sqrt(uncertainty_top);
    uncertainty_bottom = TMath::Sqrt(uncertainty_bottom);

	//std::cout << file.first << "MeV, y_d: " << top/bottom << " nentries:" << normalization << std::endl;
	//These are fractional uncertainties!
	uncertainty = TMath::Sqrt(TMath::Power(uncertainty_top/top_absolute_N,2)+TMath::Power(uncertainty_bottom/bottom_absolute_N,2));

	std::tuple<double,double> output = std::make_pair(top/bottom,uncertainty);//pass the energy and uncertainty

	return output;
}

std::vector<std::tuple<double,double>> GetFolderYD(const std::map<double,std::string>& PathMap)
{

	std::vector<std::tuple<double,double>> output;


	//So let's go through every file first
	for (const auto &file : PathMap)
	{
		double normalization = 0;
		double topUncertainty = 0;
		double bottomUncertainty = 0;
		double top = 0;
		double bottom = 0;

		TFile f = TFile((TString)file.second); //get file
		TH1D* h = (TH1D*)f.Get("Lineal energy histogram"); //get histogram
		int length = h->GetNbinsX(); //get length

		//Step 1.) Convert to f(y) PDF
		for (int i = 1; i <= length; i++) //bins per bin width
		{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		auto per_width = value/(width);
		h->SetBinContent(i,per_width);

		normalization += value;
		}
		
		for (int i = 1; i <= length; i++) //normalize
		{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		h->SetBinContent(i,normalized);
		}

		//Step 2.) Calculate y_d
		for (int i = 1; i <= length; i++) 
		{
			auto value = h->GetBinContent(i);
			auto low_edge = h->GetBinLowEdge(i);
			auto high_edge = h->GetBinLowEdge(i+1);
			double y = (high_edge+low_edge)/2;
			auto width = high_edge-low_edge;

			top += value*width*pow(y,2);
			bottom += value*width*y; 
		}	
		std::cout << file.first << "MeV, y_d: " << top/bottom << " nentries:" << normalization << std::endl;
		output.push_back(std::make_pair(file.first,top/bottom));//pass the energy and y_d
	}

	return output;
}

std::vector<std::tuple<double,double,double>> GetFolderYDandError(const std::map<double,std::string>& PathMap)
{

	std::vector<std::tuple<double,double,double>> output;


	//So let's go through every file first
	for (const auto &file : PathMap)
	{
		auto YDandUncert = GetYDandUncertainty(file.second);

		std::cout << file.first << "MeV, y_d: " << std::get<0>(YDandUncert) << " Fractional error:" << std::get<1>(YDandUncert) << std::endl;
		output.push_back(std::make_tuple(file.first,std::get<0>(YDandUncert),std::get<1>(YDandUncert)*std::get<0>(YDandUncert)));//pass the energy and y_d
	}

	return output;
}

std::vector<std::tuple<double,double>> GetFolderVariancefy(const std::map<double,std::string>& PathMap)
{

	std::vector<std::tuple<double,double>> output;


	//So let's go through every file first
	for (const auto &file : PathMap)
	{
		double normalization = 0;
		double topUncertainty = 0;
		double bottomUncertainty = 0;
		double top = 0;
		double bottom = 0;

		TFile f = TFile((TString)file.second); //get file
		TH1D* h = (TH1D*)f.Get("Lineal energy histogram"); //get histogram
		int length = h->GetNbinsX(); //get length

		//Step 1.) Convert to f(y) PDF
		for (int i = 1; i <= length; i++) //bins per bin width
		{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		auto per_width = value/(width);
		h->SetBinContent(i,per_width);

		normalization += value;
		}
		
		for (int i = 1; i <= length; i++) //normalize
		{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		h->SetBinContent(i,normalized);
		}

		//Step 2.) Calculate y_d
		for (int i = 1; i <= length; i++) 
		{
			auto value = h->GetBinContent(i);
			auto low_edge = h->GetBinLowEdge(i);
			auto high_edge = h->GetBinLowEdge(i+1);
			double y = (high_edge+low_edge)/2;
			auto width = high_edge-low_edge;

			top += value*width*pow(y,2);
			bottom += value*width*y; 

		}	

		double y_d = top/bottom;

		double variance = (top-(bottom*bottom));

		
		output.push_back(std::make_pair(file.first,variance));//pass the energy and y_d
	}

	return output;
}

std::vector<std::tuple<double,double>> GetFolderRelativePercentVariancefy(const std::map<double,std::string>& PathMap)
{

	std::vector<std::tuple<double,double>> output;


	//So let's go through every file first
	for (const auto &file : PathMap)
	{
		double normalization = 0;
		double topUncertainty = 0;
		double bottomUncertainty = 0;
		double top = 0;
		double bottom = 0;

		TFile f = TFile((TString)file.second); //get file
		TH1D* h = (TH1D*)f.Get("Lineal energy histogram"); //get histogram
		int length = h->GetNbinsX(); //get length

		//Step 1.) Convert to f(y) PDF
		for (int i = 1; i <= length; i++) //bins per bin width
		{
		auto value = h->GetBinContent(i);
		auto low_edge = h->GetBinLowEdge(i);
		auto high_edge = h->GetBinLowEdge(i+1);
		auto width = high_edge-low_edge;
		auto per_width = value/(width);
		h->SetBinContent(i,per_width);

		normalization += value;
		}
		
		for (int i = 1; i <= length; i++) //normalize
		{
		auto value = h->GetBinContent(i);
		auto normalized = value/normalization;
		h->SetBinContent(i,normalized);
		}

		//Step 2.) Calculate y_d
		for (int i = 1; i <= length; i++) 
		{
			auto value = h->GetBinContent(i);
			auto low_edge = h->GetBinLowEdge(i);
			auto high_edge = h->GetBinLowEdge(i+1);
			double y = (high_edge+low_edge)/2;
			auto width = high_edge-low_edge;

			top += value*width*pow(y,2);
			bottom += value*width*y; 

		}	

		double y_d = top/bottom;

		double variance = (top-(bottom*bottom));
		variance = variance/(bottom*bottom);
		variance = variance*100; //to make it a percent

		
		output.push_back(std::make_pair(file.first,variance));//pass the energy and y_d
	}

	return output;
}



void PlotAndSaveFolderYD(const std::vector<std::tuple<double,double>>& ydList)
{
   TCanvas* c = new TCanvas("c","c");
   c->SetCanvasSize(2000, 1600);
   c->SetWindowSize(1020, 820);
   auto gr = new TGraph();

   for (int i = 0; i < ydList.size(); i++)
   {
   	gr->AddPoint(std::get<0>(ydList[i]),std::get<1>(ydList[i]));
   }
   gr->GetHistogram()->SetMinimum(1);
   gr->GetHistogram()->SetMaximum(100);
   gr->GetXaxis()->SetLimits(0.1,100);
   gr->Draw();
   gPad->SetLogx();
   gPad->SetLogy();
   c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/yd.jpg");
}

TGraph* PlotFolderYD(TCanvas* c, const std::vector<std::tuple<double,double>>& ydList)
{
   auto gr = new TGraph();

   for (int i = 0; i < ydList.size(); i++)
   {
   	gr->AddPoint(std::get<0>(ydList[i]),std::get<1>(ydList[i]));
   }

   return gr;
}

TGraphErrors* PlotFolderYDandError(TCanvas* c, const std::vector<std::tuple<double,double,double>>& ydList)
{
	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> yError;

	for (int i = 0; i < ydList.size(); i++)
	{
		x.push_back(std::get<0>(ydList[i]));
		y.push_back(std::get<1>(ydList[i]));
		yError.push_back(std::get<2>(ydList[i]));
	}

	auto gr = new TGraphErrors(ydList.size(),&x[0],&y[0],nullptr,&yError[0]);
	return gr;
}



TGraph* PlotOversamplesFolder(const std::string& folderPath, double energy, int nTracks)
{
	TGraph* returnGraph = new TGraph(); //Create the graph to return

	//Iterate over every file
	for (const auto &entry : std::filesystem::directory_iterator(folderPath))
	{
		//Create a stringstream to split the name
		std::stringstream filenameStream(entry.path().filename());
		std::string textBetweenDelimeters;

		//For my while loop
		bool oversamplesFound = false;
		int fileOversamples{};

		//Look for nOversamples
		while (oversamplesFound == false)
		{
			//Read the text between delimters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find n Oversamples in file: " << entry.path().filename() << std::endl; break; }

			//Find x (which typicall preceedes noversamples i.e. x1000)
			auto oversampleLocation = textBetweenDelimeters.find("x");

			if (oversampleLocation != -1) //if x is found
			{
				textBetweenDelimeters.erase(0,1); //erase the first character, should be an x

				//try to cast to an int
				try
				{
					fileOversamples = std::stoi(textBetweenDelimeters);
					oversamplesFound = true;
				}
				catch(...)
				{
					std::cout << "Unable to parse entry beginning with x as an int. This can occur if you have an x in your filename." << std::endl;
				}
			}
		}

		//Re-create the stringstream, because calling std::getline on it deletes its entries each time
		filenameStream = std::stringstream(entry.path().filename());
		bool energyFound = false;
		double fileEnergy{};

		//Look for amount of energy
		while (energyFound == false)
		{
			//Read the text between delimeters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find energy amount Oversamples in file: " << entry.path().filename() << std::endl; break; }
			
			//Find MeV
			auto energyLocation = textBetweenDelimeters.find("MeV");

			if (energyLocation != -1)
			{
				textBetweenDelimeters.erase(energyLocation,3); //erase MeV
				fileEnergy = std::stod(textBetweenDelimeters); //Cast to double
				energyFound = true;
			}
		}

		//Add to graph if it matches the oversamples and energy
		if (oversamplesFound && energyFound)
		{
			if (fileEnergy == energy)
			{
				auto YDandError= GetYDandUncertainty(entry.path());
				double yd = std::get<0>(YDandError);
				std::cout << "Filename: " << entry.path() << " Yd: " << std::get<0>(YDandError) << " Error: " << std::get<1>(YDandError) << std::endl;
				returnGraph->AddPoint(nTracks*fileOversamples,yd);
			}
		}
	}

	return returnGraph;
}

TGraph* PlotOversamplesFolderPercentDifference(const std::string& folderPath, double energy, int nTracks, double normalization_value)
{
	TGraph* returnGraph = new TGraph(); //Create the graph to return

	//Iterate over every file
	for (const auto &entry : std::filesystem::directory_iterator(folderPath))
	{
		//Create a stringstream to split the name
		std::stringstream filenameStream(entry.path().filename());
		std::string textBetweenDelimeters;

		//For my while loop
		bool oversamplesFound = false;
		int fileOversamples{};

		//Look for nOversamples
		while (oversamplesFound == false)
		{
			//Read the text between delimters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find n Oversamples in file: " << entry.path().filename() << std::endl; break; }

			//Find x (which typicall preceedes noversamples i.e. x1000)
			auto oversampleLocation = textBetweenDelimeters.find("x");

			if (oversampleLocation != -1) //if x is found
			{
				textBetweenDelimeters.erase(0,1); //erase the first character, should be an x

				//try to cast to an int
				try
				{
					fileOversamples = std::stoi(textBetweenDelimeters);
					oversamplesFound = true;
				}
				catch(...)
				{
					std::cout << "Unable to parse entry beginning with x as an int. This can occur if you have an x in your filename." << std::endl;
				}
			}
		}

		//Re-create the stringstream, because calling std::getline on it deletes its entries each time
		filenameStream = std::stringstream(entry.path().filename());
		bool energyFound = false;
		double fileEnergy{};

		//Look for amount of energy
		while (energyFound == false)
		{
			//Read the text between delimeters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find energy amount Oversamples in file: " << entry.path().filename() << std::endl; break; }
			
			//Find MeV
			auto energyLocation = textBetweenDelimeters.find("MeV");

			if (energyLocation != -1)
			{
				textBetweenDelimeters.erase(energyLocation,3); //erase MeV
				fileEnergy = std::stod(textBetweenDelimeters); //Cast to double
				energyFound = true;
			}
		}

		//Add to graph if it matches the oversamples and energy
		if (oversamplesFound && energyFound)
		{
			if (fileEnergy == energy)
			{
				auto YDandError= GetYDandUncertainty(entry.path());
				double yd = std::get<0>(YDandError);
				std::cout << "Filename: " << entry.path() << " Yd: " << std::get<0>(YDandError) << " Error: " << std::get<1>(YDandError) << std::endl;
				returnGraph->AddPoint(nTracks*fileOversamples,(yd*100/normalization_value));
			}
		}
	}

	return returnGraph;
}

TGraphErrors* PlotOversamplesFolderPercentDifferenceWithError(const std::string& folderPath, double energy, int nTracks, double normalization_value)
{
	std::vector<double> xVals;
	std::vector<double> yVals;
	std::vector<double> yErrors;

	//Iterate over every file
	for (const auto &entry : std::filesystem::directory_iterator(folderPath))
	{
		//Create a stringstream to split the name
		std::stringstream filenameStream(entry.path().filename());
		std::string textBetweenDelimeters;

		//For my while loop
		bool oversamplesFound = false;
		int fileOversamples{};

		//Look for nOversamples
		while (oversamplesFound == false)
		{
			//Read the text between delimters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find n Oversamples in file: " << entry.path().filename() << std::endl; break; }

			//Find x (which typicall preceedes noversamples i.e. x1000)
			auto oversampleLocation = textBetweenDelimeters.find("x");

			if (oversampleLocation != -1) //if x is found
			{
				textBetweenDelimeters.erase(0,1); //erase the first character, should be an x

				//try to cast to an int
				try
				{
					fileOversamples = std::stoi(textBetweenDelimeters);
					oversamplesFound = true;
				}
				catch(...)
				{
					std::cout << "Unable to parse entry beginning with x as an int. This can occur if you have an x in your filename." << std::endl;
				}
			}
		}

		//Re-create the stringstream, because calling std::getline on it deletes its entries each time
		filenameStream = std::stringstream(entry.path().filename());
		bool energyFound = false;
		double fileEnergy{};

		//Look for amount of energy
		while (energyFound == false)
		{
			//Read the text between delimeters
			bool moreText = bool(std::getline(filenameStream,textBetweenDelimeters,'_'));
			//Check if at end of file
			if (moreText == false) { std::cout << "Could not find energy amount Oversamples in file: " << entry.path().filename() << std::endl; break; }
			
			//Find MeV
			auto energyLocation = textBetweenDelimeters.find("MeV");

			if (energyLocation != -1)
			{
				textBetweenDelimeters.erase(energyLocation,3); //erase MeV
				fileEnergy = std::stod(textBetweenDelimeters); //Cast to double
				energyFound = true;
			}
		}

		//Add to graph if it matches the oversamples and energy
		if (oversamplesFound && energyFound)
		{
			if (fileEnergy == energy)
			{
				auto YDandError= GetYDandUncertainty(entry.path());
				double yd = std::get<0>(YDandError);
				double yVal = (yd*100)/normalization_value;
				xVals.push_back(nTracks*fileOversamples);
				yVals.push_back(yVal);
				yErrors.push_back(std::get<1>(YDandError)*yVal); //Since it's a fractional error we can just multiply like this
				std::cout << "Filename: " << entry.path() << " Yd: " << std::get<0>(YDandError) << " Percent Error: " <<  std::get<1>(YDandError)*100 << std::endl;
			}
		}
	}

	TGraphErrors* returnGraph = new TGraphErrors(xVals.size(), &xVals[0], &yVals[0], nullptr, &yErrors[0]); //Create the graph to return
	return returnGraph;
}

TGraph* GetVassiliev1umYD()
{
   //So Vassiliev gives the first and second moments
	//Take the ratio of them to get Yd

   auto gr = new TGraph();

   gr->AddPoint(0.1,6670./78.1);
   gr->AddPoint(0.2,5470./68.2);
   gr->AddPoint(0.5,1920./40.4);
   gr->AddPoint(1.0,775./25.5);
   gr->AddPoint(2.0,281./15.2);
   gr->AddPoint(5.0,66.3/7.14);
   gr->AddPoint(10.0,21.2/3.88);
   gr->AddPoint(20.0,7.07/2.1);
   gr->AddPoint(50.0,1.89/0.949);
   gr->AddPoint(100.0,0.737/0.508);

   return gr;
}


TGraph* GetNikjooYD()
{
   auto gr = new TGraph();

   gr->AddPoint(0.1,22.8);
   gr->AddPoint(0.2,11.3);
   gr->AddPoint(0.3,67.3);
   gr->AddPoint(0.5,49.6);
   gr->AddPoint(0.7,40.0);
   gr->AddPoint(1.0,30.3);
   gr->AddPoint(2.0,18.8);
   gr->AddPoint(5.0,9.5);
   gr->AddPoint(10.0,5.8);
   gr->AddPoint(20.0,3.9);
   gr->AddPoint(50.0,2.5);
   gr->AddPoint(100.0,1.8);
   gr->AddPoint(200.0,0.5);

   return gr;
}

TH1D* GetDy(std::string path, double Energy, std::string TargetSize)
{
	TH1::AddDirectory(false);
	TH1D* h;

	path = path + "/" + TargetSize + "nm";

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		std::stringstream pathsplitter(entry.path().filename());

		double energy = std::stod(GetFileEnergy(entry.path().filename()));
		if (Energy == energy)
		{

			TFile f = TFile((TString)entry.path());

			h = (TH1D*)f.Get("Lineal energy histogram");
			PMF_to_DoseFunction(h);
			Prepare_for_Semilog(h);

			return h;
		}
	}

	return nullptr;
}

void OrganizeLibraryFolder(std::string path)
{
	//This function takes a bunch of SuperTrack output files all in one big file (under the input argument path)
	//And organizes into a bunch of subdirectories in terms of target sizes

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		//skip directories
		if (!std::filesystem::is_directory(entry.path()))
		{
			//Get the target size
			std::string TargetSize = GetFileTargetSize(entry.path().filename());

			//If it's a valid file proceed
			if (TargetSize != "failure :(")
			{
				//make the new directory
				std::string directory_name = path+"/";
				directory_name = directory_name+TargetSize+"nm";
				std::filesystem::create_directory(directory_name);

				//place the file in the new directory
				std::string oldfile = path+"/"+((std::string)entry.path().filename());
				std::string newfile = path+"/"+TargetSize+"nm/"+((std::string)entry.path().filename());
				std::filesystem::rename(oldfile, newfile);
			}
		}
	}	
}


int main()
{
	//Plot 2: Verification plot
	TCanvas* c = new TCanvas("c","c");
	c->SetCanvasSize(2040, 1640);
	c->SetWindowSize(2040, 1640);
	c->SetLeftMargin(0.15);
	c->SetBottomMargin(0.15);

	std::string Newpower = "/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/Newpower/converted";
	// std::string MyNewpower = "/home/joseph/Documents/PHD_local/June_2022/proton_5um_DNA2_10k/1um";
	std::string MyNewpower = "/home/joseph/Documents/PHD_local/STV_LogEnergies_June152023/1um";

	auto fileEnergyList = SortFolderByEnergy(Newpower);
	auto ydList = GetFolderYD(fileEnergyList);
	TGraph* g1 = PlotFolderYD(c,ydList);
	g1->SetMarkerSize(2);
	g1->SetMarkerStyle(21);
	g1->SetLineColor(2);
	g1->SetLineStyle(2);
	g1->SetLineWidth(0);

	fileEnergyList = SortFolderByEnergyNew(MyNewpower);
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
	multiGraph->GetXaxis()->SetLimits(0.1,230);
	//Y limits set differently than X for some reason
	multiGraph->SetMinimum(0.4);
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

	c->SaveAs("/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/Images/SuperTrack/temp_yd_Aug23.jpg"); 
}