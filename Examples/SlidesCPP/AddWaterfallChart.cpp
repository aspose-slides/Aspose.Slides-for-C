#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void AddWaterfallChart()
{
	//ExStart:AddWaterfallChart

	// The path to the documents directory.
	const String outPath = u"../out/WaterfallChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Waterfall, 50, 50, 500, 400);
	chart->get_ChartData()->get_Categories()->Clear();
	chart->get_ChartData()->get_Series()->Clear();

	SharedPtr<IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();

	wb->Clear(0);

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A1", ObjectExt::Box<String>(u"Category 1")));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A2", ObjectExt::Box<String>(u"Category 2")));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A3", ObjectExt::Box<String>(u"Category 3")));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A4", ObjectExt::Box<String>(u"Category 4")));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A5", ObjectExt::Box<String>(u"Category 5")));
	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"A6", ObjectExt::Box<String>(u"Category 6")));

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(ChartType::Waterfall);
	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);

	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B1", ObjectExt::Box<int32_t>(15)));
	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B2", ObjectExt::Box<int32_t>(-41)));
	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B3", ObjectExt::Box<int32_t>(16)));
	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B4", ObjectExt::Box<int32_t>(10)));
	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B5", ObjectExt::Box<int32_t>(-23)));
	series->get_DataPoints()->AddDataPointForWaterfallSeries(wb->GetCell(0, u"B6", ObjectExt::Box<int32_t>(16)));

	series->get_DataPoints()->idx_get(5)->set_SetAsTotal(true);

	series->set_ShowConnectorLines(false);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddWaterfallChart
}
