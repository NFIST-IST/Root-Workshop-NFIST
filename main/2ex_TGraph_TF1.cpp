#include "ReadData.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"

int main()
{
    // Data Import
    ReadData DataImport("y.txt");
    auto data = DataImport.GetData();

    int n = data.size();
    Double_t x[n];
    Double_t y[n];

    for (int i = 0; i < data.size(); i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
    }

    TCanvas c("canvas", "grafico", 200, 10, 1920, 1080);
    TGraph *gr = new TGraph(n, x, y);
    gStyle->SetOptFit(kTRUE);

    gr->SetTitle("3ex TGraph TF1");
    gr->GetXaxis()->SetTitle("Eixo xx");
    gr->GetYaxis()->SetTitle("Eixo yy");
    gr->SetMarkerColor(60);
    gr->SetMarkerSize(0.7);
    gr->SetMarkerStyle(8);

    /*
    Para fazer um fit escrevendo código, é necessário criar um objeto TF#X - uma função a #X dimensões.
    Em cadeiras de FeX, geralmente é necessário apenas fazer fits de funções a 1 dimensão - usando um TF1!

    A função no TF1 pode ser inserida de várias formas diferentes:
    a) Como expressão - string (quando colocamos como texto entre " ")
    b) Como um lambda function
    c) Como uma função que recebe dois double* e retorna um double

    Ao longo dos programas vamos usando diferentes formas de as definir!

    Na verdade, fazer fits a programar pode ser bastante complicado, uma vez que muitas vezes o ROOT nem sempre
    força os parâmetros a se alterarem de modo a diminuir o valor do Chi² - mas não temam, sempre que não funcionar
    podemos usar o ROOT como o Fitteia, e forçarmos nós a correr o fit até os parâmetros estarem otimizados!
    (E também o faremos) :)
    Os fits costumam ser mais faceis de fazer quando temos um erro associado a cada ponto!
    */

    TF1 *f = new TF1("function_to_fit", "[0] * sin([1] * x - [2])", x[0], x[data.size()]);

    f->SetParameters(2, 1, 1); // (2, 0.7, 2)
    f->SetParLimits(0, 1, 3);
    f->SetParLimits(1, 0, 1);
    f->SetParLimits(2, 1, 2.5);

    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr->Fit(f);

    c.Update();
    gr->Draw("AP");
    c.SaveAs("ex2.png");
    return 0;
}