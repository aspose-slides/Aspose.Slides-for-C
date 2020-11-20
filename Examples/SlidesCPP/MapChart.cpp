#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void MapChart()
{
    //ExStart:MapChart
    String resultPath = Path::Combine(GetOutPath(), u"MapChart_out.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();

    //create empty chart
    SharedPtr<IChart> chart = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::Map, 50.0f, 50.0f, 500.0f, 400.0f, false);

    SharedPtr<IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();

    //Add series and few data points
    SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(ChartType::Map);
    series->get_DataPoints()->AddDataPointForMapSeries(wb->GetCell(0, u"B2", ObjectExt::Box<int32_t>(5)));
    series->get_DataPoints()->AddDataPointForMapSeries(wb->GetCell(0, u"B3", ObjectExt::Box<int32_t>(1)));
    series->get_DataPoints()->AddDataPointForMapSeries(wb->GetCell(0, u"B4", ObjectExt::Box<int32_t>(10)));

    //add categories
    chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A2", ObjectExt::Box<String>(u"United States")));
    chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A3", ObjectExt::Box<String>(u"Mexico")));
    chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A4", ObjectExt::Box<String>(u"Brazil")));

    //change data point value    
    SharedPtr<IChartDataPoint> dataPoint = series->get_DataPoints()->idx_get(1);
    dataPoint->get_ColorValue()->get_AsCell()->set_Value(ObjectExt::Box<String>(u"15"));

    //set data point appearance    
    dataPoint->get_Format()->get_Fill()->set_FillType(FillType::Solid);
    dataPoint->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Green());

    presentation->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:MapChart
}
