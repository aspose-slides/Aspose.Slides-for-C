#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void MultiCategoryChart()
{
	//ExStart:MultiCategoryChart

	// The path to the documents directory.
	const String outPath = u"../out/MultiCategoryChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	//Clear workbook
	fact->Clear(defaultWorksheetIndex);

	chart->get_ChartData()->get_Series()->Clear();
	chart->get_ChartData()->get_Categories()->Clear();

	// Add Catrgories
	SharedPtr<IChartCategory> category = chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c2", ObjectExt::Box<String>(u"A")));
	category->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Group1"));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c3", ObjectExt::Box<String>(u"B")));
	
	category = chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c4", ObjectExt::Box<String>(u"C")));
	category->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Group2"));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c5", ObjectExt::Box<String>(u"D")));

	category = chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c6", ObjectExt::Box<String>(u"E")));
	category->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Group3"));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c7", ObjectExt::Box<String>(u"F")));

	category = chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c8", ObjectExt::Box<String>(u"G")));
	category->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Group4"));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, u"c9", ObjectExt::Box<String>(u"H")));

	// Now, Adding a new series
	SharedPtr<IChartSeries>  series = chart->get_ChartData()->get_Series()->Add(fact->GetCell(0, u"D1", ObjectExt::Box<String>(u"Series 1")),
		ChartType::ClusteredColumn);

	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D2", ObjectExt::Box<double>(10)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D3", ObjectExt::Box<double>(20)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D4", ObjectExt::Box<double>(30)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D5", ObjectExt::Box<double>(40)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D6", ObjectExt::Box<double>(50)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D7", ObjectExt::Box<double>(60)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D8", ObjectExt::Box<double>(70)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, u"D9", ObjectExt::Box<double>(80)));

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:MultiCategoryChart
}
