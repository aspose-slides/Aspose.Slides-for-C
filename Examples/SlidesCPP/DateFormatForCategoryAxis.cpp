#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void DateFormatForCategoryAxis()
{
	//ExStart:DateFormatForCategoryAxis

	// The path to the documents directory.
	const String outPath = u"../out/DateFormatForCategoryAxis_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Area, 0, 0, 500, 500);

	//Accessing chart workbook
	SharedPtr<IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();
	wb->Clear(0);
	//System::DateTime::get_Now()
	chart->get_ChartData()->get_Categories()->Clear();
	chart->get_ChartData()->get_Series()->Clear();

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A2", ObjectExt::Box<double>(DateTime(2015, 1, 1).ToOADate())));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A3", ObjectExt::Box<double>(DateTime(2016, 1, 1).ToOADate())));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A4", ObjectExt::Box<double>(DateTime(2017, 1, 1).ToOADate())));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A5", ObjectExt::Box<double>(DateTime(2018, 1, 1).ToOADate())));

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(ChartType::Line);
	series->get_DataPoints()->AddDataPointForLineSeries(wb->GetCell(0, u"B2", ObjectExt::Box<double>(1)));
	series->get_DataPoints()->AddDataPointForLineSeries(wb->GetCell(0, u"B3", ObjectExt::Box<double>(2)));
	series->get_DataPoints()->AddDataPointForLineSeries(wb->GetCell(0, u"B4", ObjectExt::Box<double>(3)));
	series->get_DataPoints()->AddDataPointForLineSeries(wb->GetCell(0, u"B5", ObjectExt::Box<double>(4)));
	chart->get_Axes()->get_HorizontalAxis()->set_CategoryAxisType ( CategoryAxisType::Date);
	chart->get_Axes()->get_HorizontalAxis()->set_IsNumberFormatLinkedToSource ( false);
	chart->get_Axes()->get_HorizontalAxis()->set_NumberFormat (u"yyyy");

	// Accessing the chart series collection
	SharedPtr<IChartSeriesCollection> seriesCollection = chart->get_ChartData()->get_Series();

	// Setting the position of label from axis
	chart->get_Axes()->get_HorizontalAxis()->set_LabelOffset(500);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:DateFormatForCategoryAxis
}
