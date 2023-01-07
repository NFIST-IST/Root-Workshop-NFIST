#ifndef __multifit__
#define __multifit__

#include "TAxis.h"
#include "TROOT.h"
#include "TF1.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include <TROOT.h>
#include <TStyle.h>
#include "TH1F.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TDirectory.h"
#include "TFrame.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"

#include <vector>
#include <iostream>
#include <sstream> // std::stringstream
#include <fstream> // std::fstream
#include <iomanip>

std::vector<std::vector<float>> MFReadData(std::string filename);
std::vector<std::vector<std::vector<float>>> DataSet(std::vector<std::vector<float>> data1, std::vector<std::vector<float>> data2);
void DataSetDump(std::vector<std::vector<std::vector<float>>> set);
void MultiFit(std::vector<std::vector<std::vector<float>>> data, const char *title);

#endif