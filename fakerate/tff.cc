Double_t lowp[7]  = {25, 30, 40, 50, 70, 100, 135};
Double_t highp[7] = {30, 40, 50, 70, 100, 135, 400};

void fit(int k) {
    TFile* fdata = TFile::Open(Form("data_%0.f_%0.f.root", lowp[k], highp[k]));
    TFile* ftrue = TFile::Open(Form("true_%0.f_%0.f.root", lowp[k], highp[k]));
    TFile* ffake = TFile::Open(Form("fake_%0.f_%0.f.root", lowp[k], highp[k]));

    TH1F* hdata = (TH1F*)fdata->Get("histo");
    TH1F* htrue = (TH1F*)ftrue->Get("histo");
    TH1F* hfake = (TH1F*)ffake->Get("histo");
    for (Int_t i = 0; i < 160; i++) {
        if (hdata->GetBinContent(i + 1) <= 0)
            hdata->SetBinContent(i + 1, 0.000000);
        if (htrue->GetBinContent(i + 1) <= 0)
            htrue->SetBinContent(i + 1, 0.000000);
        if (hfake->GetBinContent(i + 1) <= 0)
            hfake->SetBinContent(i + 1, 0.000000);
    }

    TObjArray* mc = new TObjArray(2);
    mc->Add(htrue);
    mc->Add(hfake);
    TFractionFitter* fit = new TFractionFitter(hdata, mc);  // initialise
    fit->Constrain(1, 0.0, 1.0);                            // constrain fraction 1 to be between 0 and 1
    //fit->SetRangeX(1,15);                    // use only the first 15 bins in the fit
    Int_t status = fit->Fit();  // perform the fit
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ fit status in pt" << lowp[k] << "_" << highp[k] << ": " << status << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$" << htrue->GetBinContent(56) << '\n';

    TCanvas* c1 = new TCanvas("c1", "c1", 700, 700);
    Double_t val0, err0;
    Double_t val1, err1;
    Double_t n_data_total = hdata->Integral();
    fit->GetResult(0, val0, err0);  // fit fraction of true
    fit->GetResult(1, val1, err1);  // fit fraction of fake

    //-- get fake rate
    Double_t fake_err_in_window, fake_err_total, data_err_in_window, data_err_total;

    Double_t n_hfake_in_window = hfake->IntegralAndError(1, 40, fake_err_in_window);  // value in n_hfake_in_window
    Double_t n_hfake_total     = hfake->IntegralAndError(1, 160, fake_err_total);     // value in n_hfake_in_total
    Double_t sector1           = n_hfake_in_window / n_hfake_total;                   // value in n_hfake_in_window/n_hfake_total

    Double_t n_hdata_in_window = hdata->IntegralAndError(1, 40, data_err_in_window);  // n_hdata_in_window
    Double_t n_hdata_total     = hdata->IntegralAndError(1, 160, data_err_total);     // n_hdata_total
    Double_t sector2           = n_hdata_in_window / n_hdata_total;                   // value in n_hdata_in_window/n_hdata_total

    Double_t fakerate = val1 * sector1 / sector2;

    //-- get fake rate error

    Double_t err_sector1  = TMath::Sqrt(TMath::Power(sector1, 2) * (TMath::Power(fake_err_in_window / n_hfake_in_window, 2) + TMath::Power(fake_err_total / n_hfake_total, 2)));  // error in n_hfake_in_window/n_hfake_total
    Double_t err_sector2  = TMath::Sqrt(TMath::Power(sector2, 2) * (TMath::Power(data_err_in_window / n_hdata_in_window, 2) + TMath::Power(data_err_total / n_hdata_total, 2)));  // error in n_hdata_in_window/n_hdata_total
    Double_t tmp          = val1 * sector1;
    Double_t tmp_err      = TMath::Sqrt(TMath::Power(val1 * sector1, 2) * (TMath::Power(err_sector1 / sector1, 2) + TMath::Power(err1 / val1, 2)));   // error in n_hfake_in_window/n_hfake_total
    Double_t fakerate_err = TMath::Sqrt(TMath::Power(tmp / sector2, 2) * (TMath::Power(tmp_err / tmp, 2) + TMath::Power(err_sector2 / sector2, 2)));  // error in n_hfake_in_window/n_hfake_total

    if (true) {  // check on fit status
        TH1F* result = (TH1F*)fit->GetPlot();
        hdata->Draw("Ep");
        hdata->GetYaxis()->SetTitle("Events/bin");
        hdata->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
        hdata->SetStats(kFALSE);
        hdata->SetLineColor(kMagenta);
        hdata->SetMarkerColor(kMagenta);
        result->Draw("same");
        result->SetLineColor(kBlack);
        result->SetStats(kFALSE);

        // draw template nomalized to the frac*n_data_total
        htrue->SetLineColor(kGreen + 3);
        htrue->SetMarkerColor(kGreen + 3);
        htrue->SetStats(kFALSE);
        htrue->DrawNormalized("Ep same", val0 * n_data_total);
        hfake->SetLineColor(kBlue);
        hfake->SetMarkerColor(kBlue);
        hfake->SetStats(kFALSE);
        hfake->DrawNormalized("Ep same", val1 * n_data_total);

        //output info
        TLegend* leg = new TLegend(0.53, 0.50, 0.88, 0.90, NULL, "brNDC");
        leg->SetFillStyle(0);
        leg->SetLineColor(0);
        leg->SetFillColor(10);
        leg->SetBorderSize(0);
        leg->SetHeader(Form("%0.fGeV<p_{T}^{#gamma}<%0.fGeV", lowp[k], highp[k]), "c");
        leg->AddEntry(hdata, "Data", "LPE");
        leg->AddEntry(result, "Template prediction", "LPE");
        leg->AddEntry(htrue, "True template from W#gamma", "LPE");
        leg->AddEntry(hfake, "Fake template from Data", "LPE");
        leg->Draw("same");

        TString statusStr = "fit status: ";
        statusStr += status;
        TLatex latex0;
        latex0.SetNDC();
        latex0.SetTextSize(0.03);
        latex0.SetLineWidth(1);
        latex0.DrawLatex(0.55, 0.46, statusStr);

        TString  strChi    = "#chi^{2}/ndf=";
        Double_t chi2      = fit->GetChisquare();
        Int_t    ndf       = fit->GetNDF();
        Double_t chi2ToNDF = chi2 / ndf;
        float    chiFloat  = (100 * chi2ToNDF);
        int      chiInt    = chiFloat;
        strChi += (chiInt / 100);
        strChi += ".";
        strChi += (chiInt % 100);
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.03);
        latex.SetLineWidth(1);
        latex.DrawLatex(0.55, 0.42, strChi);

        TString strFR   = "fake rate = (";
        float   FRFloat = (10000 * fakerate);
        int     FRInt   = FRFloat;
        strFR += (FRInt / 100);
        strFR += ".";
        strFR += (FRInt % 100);
        strFR += "#pm";
        float FRErrFloat = (10000 * fakerate_err);
        int   FRErrInt   = FRErrFloat;
        strFR += (FRErrInt / 100);
        strFR += ".";
        strFR += (FRErrInt % 100);
        strFR += ")%";
        TLatex* textFR = new TLatex(0.55, 0.38, strFR);
        textFR->SetNDC();
        textFR->SetTextSize(0.03);
        textFR->SetLineWidth(1);
        textFR->Draw();
        //gStyle->SetOptStat(0);
    }

    c1->SaveAs(Form("tff_%0.f_%0.f.pdf", lowp[k], highp[k]));
}
int tff() {
    for (int i = 0; i < 7; i++) {
        fit(i);
    }
    return 0;
}
