#ifndef __analise__
#define __analise__

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

#include <vector>
#include <iostream>
#include <sstream> // std::stringstream
#include <fstream> // std::fstream
#include <iomanip>

#pragma once

std::vector<std::vector<float>> ReadData(std::string filename);
void HistMaker(std::vector<std::vector<float>> data, bool wapp, int n, double min, double max, const char *title, const char *savename, const char *draw);
void GraphMaker(std::vector<std::vector<float>> data, const char *title, const char *expr, const char *draw, int color);

void GraphPDF(std::vector<std::vector<float>> data, const char *title, const char *expr, const char *draw, const char *filename, int color);

#endif
