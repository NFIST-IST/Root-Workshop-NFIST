#include "ReadData.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TRootCanvas.h"
#include "TApplication.h"
#include "TGraphErrors.h"

int main()
{
    // Data Import
    ReadData DataImport("data_w_errors.txt");
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
        ex[i] = data[i][2];
        ey[i] = data[i][3];
    }

    // Criar uma janela da aplicação
    TApplication app("app", NULL, NULL);
    // Criar o canvas onde será desenhado o gráfico
    TCanvas *c = new TCanvas("canvas", "grafico", 200, 10, 1920, 1080);

    TRootCanvas *r = (TRootCanvas *)c->GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);
    gr->SetTitle("3ex TGRAPH FIT PANEL");
    gr->GetXaxis()->SetTitle("Eixo xx");
    gr->GetYaxis()->SetTitle("Eixo yy");

    gr->SetMarkerColor(60);
    gr->SetMarkerColor(60);
    gr->SetMarkerSize(0.7);
    gr->SetMarkerStyle(8);

    /*
    Agora descartamos toda esta parte, e tornamos tudo muito mais simples!

    TF1 *f = new TF1("function_to_fit", "[0] * sin([1] * x - [2])", x[0], x[data.size()]);
    f->SetParameters(2, 1, 1, 0.1); // (2, 0.7, 2, 0.2)
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr->Fit(f);
    */

    c->Update();
    gr->Draw("AP");
    app.Run("true");

    return 0;
}