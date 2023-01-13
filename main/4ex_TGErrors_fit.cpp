#include "ReadData.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TAxis.h"

int main()
{
    // OBTER DADOS
    ReadData DataImport("PET1.txt");
    auto data = DataImport.GetData();

    // Criar CANVAS
    TCanvas c("canvas", "grafico", 200, 10, 1920, 1080);
    gStyle->SetOptFit(kTRUE);

    // Colocar dados no TGraph
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

    /*
    Criar objeto - gráfico com barras de erro - provavelmente o que vão utilizar mais em qualquer tratamento
    de dados de qualquer laboratório
    */
    TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);

    /*
    Criar o objeto!
    Também pode ser feito sem ser um ponteiro: "TGraphErrors gr(n, x, y, ex, ey);"
    Se for criado assim, para aceder aos elemento do objeto utiliza-se um "." ao invés de "->"
    */

    gr->SetTitle("4ex Gaussiana");                            // Dar título ao gráfico
    gr->GetXaxis()->SetTitle("#theta (^{o})");                // Título do eixo X
    gr->GetYaxis()->SetTitle("N^{o} de Coincid#hat{e}ncias"); // Título do eixo Y

    gr->SetStats(1);

    gr->SetMarkerColor(kGreen + 1);
    gr->SetMarkerSize(1.2);
    gr->SetMarkerStyle(8);

    TF1 *f = new TF1("function_to_fit", "gaus(0)", -10, 10);
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr->Fit(f, "R");

    c.Update();
    gr->Draw("AP");
    c.SaveAs("ex4.png");

    delete gr;

    return 0;
}