#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void AddRadarChart()
{
    //ExStart:AddRadarChart

    String outPath = GetOutPath() + u"RadarChart_Out.pptx";

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

    // Add Radar chart
    SharedPtr<IChart> ichart = sld->get_Shapes()->AddChart(ChartType::Radar, 0.0f, 0.0f, 400.0f, 400.0f);

    // Setting the index of chart data sheet
    int32_t defaultWorksheetIndex = 0;

    // Getting the chart data WorkSheet
    SharedPtr<IChartDataWorkbook> fact = ichart->get_ChartData()->get_ChartDataWorkbook();

    // Set chart title
    ichart->get_ChartTitle()->AddTextFrameForOverriding(u"Radar Chart");

    // Delete default generated series and categories
    ichart->get_ChartData()->get_Categories()->Clear();
    ichart->get_ChartData()->get_Series()->Clear();

    // Adding new categories
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 1, 0, ObjectExt::Box<String>(u"Caetegoty 1")));
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 2, 0, ObjectExt::Box<String>(u"Caetegoty 3")));
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 3, 0, ObjectExt::Box<String>(u"Caetegoty 5")));
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 4, 0, ObjectExt::Box<String>(u"Caetegoty 7")));
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 5, 0, ObjectExt::Box<String>(u"Caetegoty 9")));
    ichart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 6, 0, ObjectExt::Box<String>(u"Caetegoty 11")));

    // Adding new series
    ichart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 1, ObjectExt::Box<String>(u"Series 1")), ichart->get_Type());
    ichart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 2, ObjectExt::Box<String>(u"Series 2")), ichart->get_Type());

    // Now populating series data
    SharedPtr<IChartSeries> series = ichart->get_ChartData()->get_Series()->idx_get(0);
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<double>(2.7)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 2, 1, ObjectExt::Box<double>(2.4)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 3, 1, ObjectExt::Box<double>(1.5)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 4, 1, ObjectExt::Box<double>(3.5)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 5, 1, ObjectExt::Box<int32_t>(5)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 6, 1, ObjectExt::Box<double>(3.5)));

    // Set series color
    series->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
    series->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DarkRed());

    // Now populating another series data
    series = ichart->get_ChartData()->get_Series()->idx_get(1);
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 1, 2, ObjectExt::Box<double>(2.5)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 2, 2, ObjectExt::Box<double>(2.4)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 3, 2, ObjectExt::Box<double>(1.6)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 4, 2, ObjectExt::Box<double>(3.5)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 5, 2, ObjectExt::Box<int32_t>(4)));
    series->get_DataPoints()->AddDataPointForRadarSeries(fact->GetCell(defaultWorksheetIndex, 6, 2, ObjectExt::Box<double>(3.6)));

    // Set series color
    series->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
    series->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Orange());

    // Set legend position
    ichart->get_Legend()->set_Position(LegendPositionType::Bottom);

    // Setting Category Axis Text Properties
    SharedPtr<IChartPortionFormat> txtCat = ichart->get_Axes()->get_HorizontalAxis()->get_TextFormat()->get_PortionFormat();
    txtCat->set_FontBold(NullableBool::True);
    txtCat->set_FontHeight(10.0f);
    txtCat->get_FillFormat()->set_FillType(FillType::Solid);
    ;
    txtCat->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DimGray());
    txtCat->set_LatinFont(System::MakeObject<FontData>(u"Calibri"));

    // Setting Legends Text Properties
    SharedPtr<IChartPortionFormat> txtleg = ichart->get_Legend()->get_TextFormat()->get_PortionFormat();
    txtleg->set_FontBold(NullableBool::True);
    txtleg->set_FontHeight(10.0f);
    txtleg->get_FillFormat()->set_FillType(FillType::Solid);
    ;
    txtleg->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DimGray());
    txtCat->set_LatinFont(System::MakeObject<FontData>(u"Calibri"));

    // Setting Value Axis Text Properties
    SharedPtr<IChartPortionFormat> txtVal = ichart->get_Axes()->get_VerticalAxis()->get_TextFormat()->get_PortionFormat();
    txtVal->set_FontBold(NullableBool::True);
    txtVal->set_FontHeight(10.0f);
    txtVal->get_FillFormat()->set_FillType(FillType::Solid);
    txtVal->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DimGray());
    txtVal->set_LatinFont(System::MakeObject<FontData>(u"Calibri"));

    // Setting value axis number format
    ichart->get_Axes()->get_VerticalAxis()->set_IsNumberFormatLinkedToSource(false);
    ichart->get_Axes()->get_VerticalAxis()->set_NumberFormat(u"\"$\"#,##0.00");

    // Setting chart major unit value
    ichart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMajorUnit(false);
    ichart->get_Axes()->get_VerticalAxis()->set_MajorUnit(1.25f);

    // Save generated presentation
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:AddRadarChart
}
