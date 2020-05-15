#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void CustomRotationAngleTextframe()
{
	// ExStart:CustomRotationAngleTextframe
	// The path to the documents directory.
	const String outPath = u"../out/CustomRotationAngleTextframe_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IChart>  chart = sld->get_Shapes()->AddChart(ChartType::ClusteredColumn, 50, 50, 500, 300);

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	series->get_Labels()->get_DefaultDataLabelFormat()->get_TextFormat()->get_TextBlockFormat()->set_RotationAngle(65);

	chart->set_HasTitle (true);
	chart->get_ChartTitle()->AddTextFrameForOverriding(u"Custom title")->get_TextFrameFormat()->set_RotationAngle ( -30);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:CustomRotationAngleTextframe
}
