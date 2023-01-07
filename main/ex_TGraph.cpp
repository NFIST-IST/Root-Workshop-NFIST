#include "ReadData.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"

int main()
{
    double step = 0.01;
    int nstep = int(6 / step);
    double_t x[nstep];
    double_t y[nstep];

    for (int i = 0; i < nstep; i++)
    {
        x[i] = i * step;
        y[i] = 2 * sin(x[i]) + 0.5;
    }

    TCanvas c("canvas", "grafico", 200, 10, 600, 400);
    TGraph *gr = new TGraph(nstep, x, y);

    gr->SetTitle("ex TGraph; Eixo X; Eixo Y");
    gr->SetMarkerColor(60);
    gr->SetMarkerSize(0.7);
    gr->SetMarkerStyle(8);

    c.Update();
    gr->Draw("APL");
    c.SaveAs("ex_TGraph.pdf");
    return 0;
}