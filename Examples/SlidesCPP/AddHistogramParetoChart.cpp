#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;

using namespace System;

void AddHistogramParetoChart()
{
	//ExStart:AddHistogramParetoChart

	// The path to the documents directory.
	const String outPath = u"../out/HistogramParetoChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Histogram, 50, 50, 500, 400);

	chart->get_ChartData()->get_Series()->Add(ChartType::ParetoLine);

	chart->get_Axes()->get_SecondaryVerticalAxis()->set_NumberFormat(u"0%");
	chart->get_Axes()->get_SecondaryVerticalAxis()->set_MaxValue(1);
	chart->get_Axes()->get_SecondaryVerticalAxis()->set_IsAutomaticMaxValue(false);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddHistogramParetoChart
}
