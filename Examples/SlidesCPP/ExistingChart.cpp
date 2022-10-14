#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void ExistingChart()
{
	//ExStart:ExistingChart

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/ExistingChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<Chart> chart = ExplicitCast<Chart>(slide->get_Shapes()->idx_get(0));

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	// Changing chart Category Name
	fact->GetCell(defaultWorksheetIndex, 1, 0, ObjectExt::Box<String>(u"Modified Category 1"));
	fact->GetCell(defaultWorksheetIndex, 2, 0, ObjectExt::Box<String>(u"Modified Category 2"));

	// Take first chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	
	// Now updating series data
	fact->GetCell(defaultWorksheetIndex, 0, 1, ObjectExt::Box<String>(u"New_Series1"));// Modifying series name

	series->get_DataPoints()->idx_get(0)->get_Value()->set_Data(ObjectExt::Box<double>(90));
	series->get_DataPoints()->idx_get(1)->get_Value()->set_Data(ObjectExt::Box<double>(123));
	series->get_DataPoints()->idx_get(2)->get_Value()->set_Data(ObjectExt::Box<double>(44));

	// Take Second chart series
	series = chart->get_ChartData()->get_Series()->idx_get(1);

	// Now updating series data
	fact->GetCell(defaultWorksheetIndex, 0, 2, ObjectExt::Box<String>(u"New_Series2"));// Modifying series name
	
	series->get_DataPoints()->idx_get(0)->get_Value()->set_Data(ObjectExt::Box<double>(20));
	series->get_DataPoints()->idx_get(1)->get_Value()->set_Data(ObjectExt::Box<double>(67));
	series->get_DataPoints()->idx_get(2)->get_Value()->set_Data(ObjectExt::Box<double>(99));

	// Now, Adding a new serie
	chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 3, ObjectExt::Box<String>(u"Series 3")), chart->get_Type());

	// Take 3rd chart series
	series = chart->get_ChartData()->get_Series()->idx_get(2);

	// Now populating series data
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 1, 3, ObjectExt::Box<double>(20)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 2, 3, ObjectExt::Box<double>(50)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 3, 3, ObjectExt::Box<double>(30)));
	
	chart->set_Type(ChartType::ClusteredCylinder);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ExistingChart
}
