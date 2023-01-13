#ifdef __CLING__
#pragma cling optimize(0)
#endif
void canvas()
{
//=========Macro generated from canvas: canvas/grafico
//=========  (Thu Jan 12 19:04:25 2023) by ROOT version 6.26/06
   TCanvas *canvas = new TCanvas("canvas", "grafico",74,71,1671,1009);
   canvas->SetHighLightColor(2);
   canvas->Range(-1.949319,-2.946417,15.96003,3.169388);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[30] = {
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   10,
   11,
   12,
   13,
   14,
   15,
   16,
   17,
   18,
   19,
   20,
   21,
   22,
   23,
   24,
   25,
   26,
   27,
   28,
   29};
   Double_t Graph0_fy1001[30] = {
   -1.776695,
   -1.879816,
   -1.107985,
   0.2455668,
   1.520412,
   2.00789,
   1.643093,
   0.5394987,
   -0.8645409,
   -1.774632,
   -1.898449,
   -1.040871,
   0.2594984,
   1.474038,
   2.073587,
   1.612574,
   0.4559798,
   -0.8461718,
   -1.830651,
   -1.888239,
   -0.9848458,
   0.2765641,
   1.546052,
   2.050019,
   1.639404,
   0.463435,
   -0.907044,
   -1.801248,
   -1.833389,
   -0.9656172};
   Double_t Graph0_fex1001[30] = {
   0.0419,
   0.0473,
   0.0213,
   0.0459,
   0.0857,
   0.0129,
   0.0261,
   0.061,
   0.0205,
   0.0577,
   0.0194,
   0.0605,
   0.0264,
   0.0161,
   0.0765,
   0.0156,
   0.0102,
   0.0689,
   0.0149,
   0.0198,
   0.0883,
   0.0101,
   0.0653,
   0.0514,
   0.0629,
   0.0505,
   0.0378,
   0.057,
   0.0643,
   0.079};
   Double_t Graph0_fey1001[30] = {
   0.0419,
   0.0473,
   0.0213,
   0.0459,
   0.0857,
   0.0129,
   0.0261,
   0.061,
   0.0205,
   0.0577,
   0.0194,
   0.0605,
   0.0264,
   0.0161,
   0.0765,
   0.0156,
   0.0102,
   0.0689,
   0.0149,
   0.0198,
   0.0883,
   0.0101,
   0.0653,
   0.0514,
   0.0629,
   0.0505,
   0.0378,
   0.057,
   0.0643,
   0.079};
   TGraphErrors *gre = new TGraphErrors(30,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("3ex TGRAPH FIT PANEL");
   gre->SetFillStyle(1000);
   gre->SetMarkerColor(9);
   gre->SetMarkerStyle(3);
   gre->SetMarkerSize(1.8);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","3ex TGRAPH FIT PANEL",100,-2.95399,31.99109);
   Graph_Graph01001->SetMinimum(-2.334837);
   Graph_Graph01001->SetMaximum(2.557807);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->GetXaxis()->SetTitle("Eixo xx");
   Graph_Graph01001->GetXaxis()->SetRange(9,49);
   Graph_Graph01001->GetXaxis()->SetLabelFont(42);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetXaxis()->SetTitleFont(42);
   Graph_Graph01001->GetYaxis()->SetTitle("Eixo yy");
   Graph_Graph01001->GetYaxis()->SetLabelFont(42);
   Graph_Graph01001->GetYaxis()->SetTitleFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   
   TF1 *PrevFitTMP1002 = new TF1("PrevFitTMP","[0]*sin([1]*x-[2])",-2.95399,31.99109, TF1::EAddToList::kNo);
   PrevFitTMP1002->SetFillColor(19);
   PrevFitTMP1002->SetFillStyle(0);
   PrevFitTMP1002->SetLineColor(6);
   PrevFitTMP1002->SetChisquare(17.64745);
   PrevFitTMP1002->SetNDF(27);
   PrevFitTMP1002->GetXaxis()->SetLabelFont(42);
   PrevFitTMP1002->GetXaxis()->SetTitleOffset(1);
   PrevFitTMP1002->GetXaxis()->SetTitleFont(42);
   PrevFitTMP1002->GetYaxis()->SetLabelFont(42);
   PrevFitTMP1002->GetYaxis()->SetTitleFont(42);
   PrevFitTMP1002->SetParameter(0,-1.999019);
   PrevFitTMP1002->SetParError(0,0.007259527);
   PrevFitTMP1002->SetParLimits(0,0,0);
   PrevFitTMP1002->SetParameter(1,0.6998205);
   PrevFitTMP1002->SetParError(1,0.0007566615);
   PrevFitTMP1002->SetParLimits(1,0,0);
   PrevFitTMP1002->SetParameter(2,-1.144408);
   PrevFitTMP1002->SetParError(2,0.01249815);
   PrevFitTMP1002->SetParLimits(2,0,0);
   PrevFitTMP1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(PrevFitTMP1002);
   gre->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.3268092,0.94,0.6673081,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("3ex TGRAPH FIT PANEL");
   TLine *pt_Line = pt->AddLine(0,0.297185,0,0.297185);
   pt_LaTex = pt->AddText("text");
   pt->Draw();
   TLatex *   tex = new TLatex(7.255773,1.675548,"#gamma ");
   tex->SetLineWidth(2);
   tex->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);
   canvas->ToggleToolBar();
}
