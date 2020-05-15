#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SecondPlotOptionsforCharts()
{
	//ExStart:SecondPlotOptionsforCharts

	// The path to the documents directory.
	const String outPath = u"../out/SecondPlotOptionsforCharts_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Pie, 0, 0, 500, 500);
	
	// Take first chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	// Set different properties
	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	series->get_ParentSeriesGroup()->set_SecondPieSize ( 149);
	series->get_ParentSeriesGroup()->set_PieSplitBy ( PieSplitType::ByPercentage);
	series->get_ParentSeriesGroup()->set_PieSplitPosition ( 53);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SecondPlotOptionsforCharts
}
