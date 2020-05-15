#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SetAutomaticSeriesFillColor()
{
	//ExStart:SetAutomaticSeriesFillColor

	// The path to the documents directory.
	const String outPath = u"../out/AutomaticSeriesFillColor_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Accessing the chart series collection
	SharedPtr<IChartSeriesCollection> seriesCollection = chart->get_ChartData()->get_Series();

	// Setting the preset number format
	// Traverse through every chart series
	for (int i = 0; i < seriesCollection->get_Count(); i++)
	{
		auto series = seriesCollection->idx_get(i);
		series->GetAutomaticSeriesColor();
	}

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetAutomaticSeriesFillColor
}
