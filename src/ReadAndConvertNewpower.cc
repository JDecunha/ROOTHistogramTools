#include "ReadAndConvertNewpower.hh"
//ROOT
#include "TH1D.h"
#include "TFile.h"
//CSVreader
#include <rapidcsv.h>

//
// This is just a script for one time use
//

void ReadAndConvertNewpower()
{
 std::string filePath = "/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/Newpower/newpower.csv";
 std::string outputDirectory = "/home/joseph/Dropbox/Documents/Work/Projects/MDA_Microdosimetry/software/Newpower/converted";

 //Let's create the rapidcsv handle
 rapidcsv::Document newpowerData(filePath, rapidcsv::LabelParams(-1, -1)); //No label headings

 //1.) Grab the bins from the CSV file:
 std::vector<double> bins = newpowerData.GetColumn<double>(0);
 double* binsPointer = &bins[0]; //get a pointer to the bins information

 //2.) Grab the primary proton energies from the CSV file
 std::vector<double> primaryProtonEnergy = newpowerData.GetRow<double>(0);

 //3.) Loop over each of the rows, create the TH1D, export and save
 for (int i = 1; i < primaryProtonEnergy.size();i++) //loop starts at 1, because the 0th element is actually a bin edge, not an energy
 {
    std::vector<double> values = newpowerData.GetColumn<double>(i);

    TH1D hist = TH1D("Lineal energy histogram", "y*f(y)",bins.size()-1,binsPointer);

    //Okay so the histogram should be filled
    for (int i = 1; i < values.size();i++) //again loop starts at 1 because the top value is an energy value
    {
        hist.SetBinContent(i,values[i]);
    }
    
    //Save
    std::stringstream concatstream;
    concatstream << outputDirectory << +"/proton_" << primaryProtonEnergy[i] << "MeV_" << ".root";
    TString filename = concatstream.str();
    TFile outfile(filename,"RECREATE");
    hist.Write();
 }

}
