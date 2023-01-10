#include "TAxis.h"
#include "TF2.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TStyle.h"


double function2(double *x, double *par)
{
    double result = 4 + par[0] * (par[1] * x[0] * x[0] + par[2] * x[1] * x[1]) * (par[1] * x[0] * x[0] + par[2] * x[1] * x[1]) - (2 * x[0] * x[0] - x[1] * x[1]);
    return result;
}

int main()
{
    TCanvas *c = new TCanvas("canvas", "grafico", 200, 10, 1920, 1080);

    gStyle->SetPalette(57);
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(kTRUE);

    const int npar = 3;
    double f2params[npar] = {10, 3, 3}; //, 3, 160, 0, 0.8, 0, 0.9, 40, 4, 0.7, 4, 0.7};

    TF2 *f2 = new TF2("f2", function2, -10, 10, -10, 10, npar);
    f2->SetParameters(f2params);

    // Create an histogram and fill it randomly with f2
    TH2F *h2 = new TH2F("h2", "exemplo fit 3D - Histograma", 40, -10, 10, 40, -10, 10);
    int nentries = 100000;
    h2->FillRandom("f2", nentries);

    f2->SetParameters(f2params);
    h2->Fit("f2", "N");

    h2->Draw("lego2");
    h2->SetFillColor(38);

    f2->SetNpx(80);
    f2->SetNpy(80);
    f2->Draw("surf1 same bb");

    c->Update();
    c->SaveAs("ex2.png");

    return 0;
}