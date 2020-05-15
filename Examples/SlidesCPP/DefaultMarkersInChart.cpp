#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;

void DefaultMarkersInChart()
{
	//ExStart:DefaultMarkersInChart

	// The path to the documents directory.
	const String outPath = u"../out/DefaultMarkersInChart.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Accessing the first slide in presentation
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::LineWithMarkers, 10, 10, 400, 400);

	chart->get_ChartData()->get_Series()->Clear();
	chart->get_ChartData()->get_Categories()->Clear();

	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	chart->get_ChartData()->get_Series()->Add(fact->GetCell(0,0,1, ObjectExt::Box<String>(u"Category 1")),chart->get_Type());

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(0, 1, 0, ObjectExt::Box<String>(u"C1")));
	series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 1, 1, ObjectExt::Box<int32_t>(24)));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(0, 2, 0, ObjectExt::Box<String>(u"C2")));
	series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 2, 1, ObjectExt::Box<int32_t>(23)));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(0, 3, 0, ObjectExt::Box<String>(u"C3")));
	series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 3, 1, ObjectExt::Box<int32_t>(-10)));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(0, 4, 0, ObjectExt::Box<String>(u"C4")));
	series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 4, 1, nullptr));

	chart->get_ChartData()->get_Series()->Add(fact->GetCell(0, 0, 2, ObjectExt::Box<String>(u"Series 2")), chart->get_Type());

	//Take second chart series
	SharedPtr<IChartSeries> series2 = chart->get_ChartData()->get_Series()->idx_get(1);

	//Now populating series data
	series2->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 1, 2, ObjectExt::Box<int32_t>(30)));
	series2->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 2, 2, ObjectExt::Box<int32_t>(10)));
	series2->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 3, 2, ObjectExt::Box<int32_t>(60)));
	series2->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(0, 4, 2, ObjectExt::Box<int32_t>(40)));

	chart->set_HasLegend(true);
	chart->get_Legend()->set_Overlay(false);

	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:DefaultMarkersInChart
}
