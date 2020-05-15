#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SettingInvertIfNegativePropertyForIndividualSeries()
{
	//ExStart:SettingInvertIfNegativePropertyForIndividualSeries

	// The path to the documents directory.
	const String outPath = u"../out/SettingInvertIfNegativePropertyForIndividualSeries_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);
	
	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	//Clearing exisiting chart data
	chart->get_ChartData()->get_Series()->Clear();

	//Adding new series and its data
	SharedPtr<IChartSeries> series= chart->get_ChartData()->get_Series()->Add(fact->GetCell(0, u"B1"), chart->get_Type());
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(0, u"B2", ObjectExt::Box<int32_t>(-5)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(0, u"B3", ObjectExt::Box<int32_t>(3)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(0, u"B4", ObjectExt::Box<int32_t>(-2)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(0, u"B5", ObjectExt::Box<int32_t>(1)));

	//Setting invert if negative for data point
	series->set_InvertIfNegative (false);

	series->get_DataPoints()->idx_get(2)->set_InvertIfNegative(true);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SettingInvertIfNegativePropertyForIndividualSeries
}
