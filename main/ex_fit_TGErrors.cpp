#include "ReadData.h"

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
    TCanvas c("canvas", "grafico", 200, 10, 600, 400);

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

    // Criar objeto - gráfico com barras de erro
    TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);
    /* criar o objeto!
    Também pode ser feito sem ser um ponteiro: "TGraphErrors gr(n, x, y, ex, ey);"
    Se for criado assim, para aceder aos elemento do objeto utiliza-se um "." ao invés de "->" */
    gr->SetTitle("Ex1 Fit1D");          // Dar título ao gráfico
    gr->GetXaxis()->SetTitle("Eixo X"); // Título do eixo X
    gr->GetYaxis()->SetTitle("Eixo Y"); // Título do eixo Y

    gr->SetMarkerColor(60);
    gr->SetMarkerSize(1);
    gr->SetMarkerStyle(8);

    TF1 *f = new TF1("function_to_fit", "gaus", x[0], x[data.size()]);
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr->Fit(f);
    // std::cout << "ChiSquared: " << f->GetChisquare() << std::endl;

    c.Update();
    gr->Draw("AP");
    c.SaveAs("gaus_fit1D.pdf");

    delete gr;

    return 0;
}