#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetExternalWorkbook()
{
    //ExStart:SetExternalWorkbook
    
    const String templateWbPath = GetDataPath() + u"externalWorkbook.xlsx";
    const String outWbPath = GetOutPath() + u"externalWorkbook.xlsx";
    const String outPath = u"../out/Presentation_with_externalWorkbook.pptx";

    Copy(templateWbPath, outWbPath);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    SharedPtr<Charts::IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f, false);
    SharedPtr<Charts::IChartData> chartData = chart->get_ChartData();

    chartData->SetExternalWorkbook(outWbPath);

    chartData->get_Series()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"B1"), Charts::ChartType::Pie);
    chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B2"));
    chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B3"));
    chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B4"));

    chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A2"));
    chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A3"));
    chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A4"));
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:SetExternalWorkbook
}
