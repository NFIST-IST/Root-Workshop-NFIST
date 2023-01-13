#include "ReadData.h"

#include "TStyle.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"

int main()
{
    int n = 20;
    double_t x1[n];
    double_t y1[n];
    double_t x2[n];
    double_t y2[n];

    // Colocar valores nos vetores:
    for (int i = 0; i < 20; i++)
    {
        x1[i] = i;
        y1[i] = i * i * 2;
        x2[i] = i;
        y2[i] = exp(0.5 * i);
    }

    //std::vector<double> vec;

    TGraph *gr1 = new TGraph(n, x1, y1);
    TGraph *gr2 = new TGraph(n, x2, y2);

    TCanvas c("canvas", "grafico", 200, 10, 1920, 1080);
    gStyle->SetOptFit(kTRUE);

    gr1->SetTitle("ex TGraph FIT; Eixo X; Eixo Y");

    gr1->SetLineColor(kBlue);
    gr1->SetMarkerSize(0.7);
    gr1->SetMarkerStyle(8);
    gr1->SetLineWidth(2);

    gr2->SetLineColor(kRed);
    gr2->SetMarkerSize(0.7);
    gr2->SetMarkerStyle(21);
    gr2->SetLineWidth(2);
    
    c.Update();
    gr1->Draw("APC");
    gr2->Draw("same PC");
    c.SaveAs("TwoGraphs.png");
    return 0;
}