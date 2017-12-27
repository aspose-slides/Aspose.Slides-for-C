#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/NullableBool.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/ITextFrame.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IAxis.h>
#include <DOM/Chart/IAxesManager.h>
#include <DOM/Chart/IChartCategoryCollection.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/DisplayUnitType.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <Export/SaveFormat.h>

#include "chart.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace Aspose::Slides::SmartArt;

using namespace System;

void ::Chart::SampleChart()
{
    //Instantiate Presentation class that represents PPTX file
    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    //Access first slide
    SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

    // Add chart with default data
    SharedPtr<IChart> chart = sld->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::ClusteredColumn, 0, 0, 500, 500);

    //Setting chart Title
    chart->get_ChartTitle()->AddTextFrameForOverriding(L"Sample Title");
    chart->get_ChartTitle()->get_TextFrameForOverriding()->get_TextFrameFormat()->set_CenterText(Aspose::Slides::NullableBool::True);
    chart->get_ChartTitle()->set_Height(30);
    chart->set_HasTitle(true);

    //Set first series to Show Values
    chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);

    //Setting the index of chart data sheet
    int defaultWorksheetIndex = 0;

    //Getting the chart data worksheet
    SharedPtr<IChartDataWorkbook> workbook = chart->get_ChartData()->get_ChartDataWorkbook();

    //Delete default generated series and categories
    chart->get_ChartData()->get_Series()->Clear();
    chart->get_ChartData()->get_Categories()->Clear();
    int s = chart->get_ChartData()->get_Series()->get_Count();
    s = chart->get_ChartData()->get_Categories()->get_Count();

    //Adding new series
    chart->get_ChartData()->get_Series()->Add(workbook->GetCell(defaultWorksheetIndex, 0, 1, ObjectExt::Box<String>(L"Series 1")), chart->get_Type());
    chart->get_ChartData()->get_Series()->Add(workbook->GetCell(defaultWorksheetIndex, 0, 2, ObjectExt::Box<String>(L"Series 2")), chart->get_Type());
    chart->get_ChartData()->get_Series()->Add(workbook->GetCell(defaultWorksheetIndex, 0, 3, ObjectExt::Box<String>(L"Series 3")), chart->get_Type());

    //Adding new categories
    chart->get_ChartData()->get_Categories()->Add(workbook->GetCell(defaultWorksheetIndex, 1, 0, ObjectExt::Box<String>(L"Category 1")));
    chart->get_ChartData()->get_Categories()->Add(workbook->GetCell(defaultWorksheetIndex, 2, 0, ObjectExt::Box<String>(L"Category 2")));
    chart->get_ChartData()->get_Categories()->Add(workbook->GetCell(defaultWorksheetIndex, 3, 0, ObjectExt::Box<String>(L"Category 3")));

    //Take first chart series
    SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

    //Now populating series data
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<double>(.20)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 2, 1, ObjectExt::Box<double>(.50)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 3, 1, ObjectExt::Box<double>(.30)));

    //Take second chart series
    series = chart->get_ChartData()->get_Series()->idx_get(1);

    //Now populating series data
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 1, 2, ObjectExt::Box<double>(.30)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 2, 2, ObjectExt::Box<double>(.10)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 3, 2, ObjectExt::Box<double>(.60)));

    //Take second chart series
    series = chart->get_ChartData()->get_Series()->idx_get(2);

    //Now populating series data
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 1, 2, ObjectExt::Box<double>(.3)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 2, 2, ObjectExt::Box<int>(1)));
    series->get_DataPoints()->AddDataPointForBarSeries(workbook->GetCell(defaultWorksheetIndex, 3, 2, ObjectExt::Box<double>(.6)));

    chart->get_Axes()->get_VerticalAxis()->set_DisplayUnit(Aspose::Slides::Charts::DisplayUnitType::None);
    chart->get_Axes()->get_VerticalAxis()->set_NumberFormat(L"0.0%");
    chart->get_Axes()->get_VerticalAxis()->set_IsNumberFormatLinkedToSource(false);

    pres->Save(L"../out/SampleChart.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
}
