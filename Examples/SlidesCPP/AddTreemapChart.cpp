#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Charts;

using namespace System;

void AddTreemapChart()
{
	//ExStart:AddTreemapChart

	// The path to the documents directory.
	const String outPath = u"../out/TreemapChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Treemap, 50, 50, 500, 400);
	chart->get_ChartData()->get_Categories()->Clear();
	chart->get_ChartData()->get_Series()->Clear();

	SharedPtr<IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();

	wb->Clear(0);

	//branch 1
	SharedPtr<IChartCategory> leaf = chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C1", ObjectExt::Box<String>(u"Leaf1")));
	leaf->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Stem1"));
	leaf->get_GroupingLevels()->SetGroupingItem(2, ObjectExt::Box<String>(u"Branch1"));

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C2", ObjectExt::Box<String>(u"Leaf2")));

	leaf = chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C3", ObjectExt::Box<String>(u"Leaf3")));
	leaf->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Stem2"));

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C4", ObjectExt::Box<String>(u"Leaf4")));


	//branch 2
	leaf = chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C5", ObjectExt::Box<String>(u"Leaf5")));
	leaf->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Stem3"));
	leaf->get_GroupingLevels()->SetGroupingItem(2, ObjectExt::Box<String>(u"Branch2"));

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C6", ObjectExt::Box<String>(u"Leaf6")));

	leaf = chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C7", ObjectExt::Box<String>(u"Leaf7")));
	leaf->get_GroupingLevels()->SetGroupingItem(1, ObjectExt::Box<String>(u"Stem4"));

	chart->get_ChartData()->get_Categories()->Add(wb->GetCell(0, u"C8", ObjectExt::Box<String>(u"Leaf8")));

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(ChartType::Treemap);
	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowCategoryName(true);
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D1", ObjectExt::Box<int32_t>(4)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D2", ObjectExt::Box<int32_t>(5)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D3", ObjectExt::Box<int32_t>(3)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D4", ObjectExt::Box<int32_t>(6)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D5", ObjectExt::Box<int32_t>(9)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D6", ObjectExt::Box<int32_t>(9)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D7", ObjectExt::Box<int32_t>(4)));
	series->get_DataPoints()->AddDataPointForTreemapSeries(wb->GetCell(0, u"D8", ObjectExt::Box<int32_t>(3)));

	series->set_ParentLabelLayout(ParentLabelLayoutType::Overlapping);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddTreemapChart
}
