#include "multifit.h"

std::vector<std::vector<float>> MFReadData(std::string filename)
{
    std::vector<std::vector<float>> data;
    std::fstream rFile(filename); // read mode
    if (rFile.fail())
    {
        std::cout << "Error: Unable to load data file" << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(rFile, line))
    {
        // loop on file lines

        std::stringstream ss(line); // build object stringstream
        float d;
        std::vector<float> temp;
        while (ss >> d)
        { // parse line words to numbers (empty space separated)
            temp.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        data.push_back(temp);
    }
    rFile.close();

    return data;
};
std::vector<std::vector<std::vector<float>>> DataSet(std::vector<std::vector<float>> data1, std::vector<std::vector<float>> data2)
{
    std::vector<std::vector<std::vector<float>>> set;
    set.push_back(data1);
    set.push_back(data2);
    return set;
};
void DataSetDump(std::vector<std::vector<std::vector<float>>> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        std::cout << "\n"
                  << "SET " << i << "\n"
                  << std::endl;
        for (int j = 0; j < set[i].size(); j++)
            std::cout << "(" << set[i][j][0] << ", " << set[i][j][1] << ", " << set[i][j][2] << ", " << set[i][j][3] << ")" << std::endl;
    }
};
void MultiFit(std::vector<std::vector<std::vector<float>>> data, const char *title)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TMultiGraph *mg = new TMultiGraph();

    int n = data[0].size();
    std::cout << n << std::endl;

    Double_t x[n];
    Double_t y[n];
    Double_t ex[n];
    Double_t ey[n];

    for (int i = 0; i < data[0].size(); i++)
    {
        x[i] = data[0][i][0];
        y[i] = data[0][i][1];
        ex[i] = data[0][i][2];
        ey[i] = data[0][i][3];
        std::cout << "(" << x[i] << "; " << y[i] << "; " << ex[i] << "; " << ey[i] << ")" << std::endl;
    }

    int m = data[1].size();
    std::cout << m << std::endl;
    Double_t xm[n];
    Double_t ym[n];
    Double_t exm[n];
    Double_t eym[n];

    for (int i = 0; i < data[1].size(); i++)
    {
        xm[i] = data[1][i][0];
        ym[i] = data[1][i][1];
        exm[i] = data[1][i][2];
        eym[i] = data[1][i][3];
        std::cout << "(" << xm[i] << "; " << ym[i] << "; " << exm[i] << "; " << eym[i] << ")" << std::endl;
    }

    auto g1 = new TGraphErrors(n, x, y, ex, ey);
    auto g2 = new TGraphErrors(m, xm, ym, exm, eym);

    TF1 *f = new TF1("f", "pol1", x[0], x[data[0].size()]);
    TF1 *f1 = new TF1("f1", "pol1", xm[0], xm[data[1].size()]);
    f->SetLineColor(kRed + 1);
    f1->SetLineColor(kBlue + 1);
    f->SetLineWidth(2);
    f1->SetLineWidth(2);

    //g1->Fit(f, "R");
    //g2->Fit(f1, "R+");

    g1->SetMarkerStyle(kFullCircle);
    g2->SetMarkerStyle(8);

    g1->SetMarkerColor(50);
    g2->SetMarkerColor(70);
    g1->SetMarkerSize(1);
    g2->SetMarkerSize(3);

    mg->Add(g1);
    mg->Add(g2);

    // c.SetGrid();
    //mg->SetMinimum(-1);
    //mg->SetMaximum(2.2);

    // gPad->SetLogx();
    // gPad->SetLogy();

    mg->GetYaxis()->SetRangeUser(0, 90000);
    // mg->GetXaxis()->SetLimits(-10, 5100);

    /* TLegend *legend = new TLegend(0.2, .90, .50, 1.);
    legend->SetFillColor(0);
    legend->AddEntry(f, "1 in", "l");
    legend->AddEntry(f1, "-1.5 in", "l");

    legend->Draw("SAME");
 */
    mg->SetTitle(title);
    mg->Draw("AP");
    c.Update();
    // c1->SaveAs(&name[0]);
    app.Run();
};