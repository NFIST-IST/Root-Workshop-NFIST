#include "ReadData.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TRootCanvas.h"
#include "TApplication.h"

int main()
{
    ReadData DataImport("y.txt");
    auto data = DataImport.GetData();

    int n = data.size();
    Double_t x[n];
    Double_t y[n];
    Double_t ex[n];
    Double_t ey[n];

    for (int i = 0; i < data.size(); i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
    }

    TApplication app("app", NULL, NULL);
    TCanvas *c = new TCanvas("canvas", "grafico", 200, 10, 1920, 1080);
    TRootCanvas *r = (TRootCanvas *)c->GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TGraph *gr = new TGraph(n, x, y);
    gStyle->SetOptFit(kTRUE);

    gr->SetTitle("ex TGraph FIT PANEL; Eixo X; Eixo Y");
    gr->SetMarkerColor(60);
    gr->SetMarkerSize(0.7);
    gr->SetMarkerStyle(8);

    /*
    TF1 *f = new TF1("function_to_fit", "[0] * sin([1] * x - [2]) - [3] * x", x[0], x[data.size()]);
    f->SetParameters(2, 1, 1, 0.1); // (2, 0.7, 2, 0.2)
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr->Fit(f);
    // std::cout << "ChiSquared: " << f->GetChisquare() << std::endl;
    */

    c->Update();
    gr->Draw("AP");
    app.Run("true");
    return 0;
}