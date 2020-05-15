#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;

using namespace System;

void SetChartSeriesOverlap()
{
	//ExStart:SetChartSeriesOverlap

	// The path to the documents directory.
	const String outPath = u"../out/ChartSeriesOverlap_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Accessing the chart series collection
	SharedPtr<IChartSeriesCollection> seriesCollection = chart->get_ChartData()->get_Series();
	auto series = seriesCollection->idx_get(0);
	if (series->get_Overlap() == 0)
	{
		// Setting series overlap
		series->get_ParentSeriesGroup()->set_Overlap ( -30);
	}

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetChartSeriesOverlap
}
