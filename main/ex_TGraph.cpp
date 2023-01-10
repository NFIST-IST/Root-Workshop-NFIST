#include "ReadData.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"

int main()
{
    double step = 0.005;
    int nstep = int(7 / step);
    double_t x[nstep];
    double_t y[nstep];

    for (int i = 1; i < nstep; i++)
    {
        x[i] = i * step;
        y[i] = 2 * sin(x[i]) * tanh(x[i]) * log(x[i]);
    }

    TCanvas c("canvas", "grafico", 200, 10, 1920, 1080);
    TGraph *gr = new TGraph(nstep, x, y);
    gStyle->SetOptFit(kTRUE);

    gr->SetTitle("ex TGraph; Eixo X; Eixo Y");
    gr->SetMarkerColor(60);
    gr->SetMarkerSize(0.7);
    gr->SetMarkerStyle(8);

    c.Update();
    gr->Draw("APL");
    c.SaveAs("ex_TGraph.png");
    return 0;
}