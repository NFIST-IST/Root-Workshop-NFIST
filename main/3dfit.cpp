#include "ReadData.h"

#include "TGraph2D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TF2.h"
#include "TAxis.h"
#include "TRootCanvas.h"
#include "TApplication.h"

double function(double *x, double *par)
{
    double result = par[0] * exp(-0.5 * pow(((x[0] - par[1]) / par[2]), 2)) - 0.5 * pow(((x[1] - par[3]) / par[4]), 2) + par[5] * exp(-0.5 * pow(((x[0] - par[6]) / par[7]), 2)) - 0.5 * pow(((x[1] - par[8]) / par[9]), 2);
    return result;
}

int main()
{
    ReadData D("tomografiainchL.txt");
    auto data = D.GetData();

    double_t x[data.size()];
    double_t y[data.size()];
    double_t z[data.size()];

    for (int i = 0; i < data.size(); i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
        z[i] = data[i][2];
    }

    // Criar uma janela da aplicação
    // TApplication app("app", NULL, NULL);
    // Criar o canvas onde será desenhado o gráfico
    TCanvas *c = new TCanvas("canvas", "grafico", 200, 10, 1920, 1080);

    TGraph2D *gr = new TGraph2D(data.size(), x, y, z);
    TF2 *f = new TF2("func", "xygaus(0) + xygaus(5)", -2.5, 2, -2.5, 2);
    f->SetParameters(20, 1, 0.4, -0.8, 0.4, 10, 0.1, 0.3, 0.6, 0.2);
    auto param = f->GetParameters();

    gr->Fit(f);
 
    gr->SetMarkerStyle(20);
    c->Update();
    
    f->Draw("surf1");
    gr->Draw("same P");
    c->SaveAs("tomografia.png");
    return 0;
}