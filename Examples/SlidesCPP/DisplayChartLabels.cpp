#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void DisplayChartLabels()
{
	//ExStart:DisplayChartLabels

	// The path to the documents directory.
	const String outPath = u"../out/DisplayChartLabels_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Pie, 0, 0, 500, 500);

	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue ( true);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowLabelAsDataCallout( true);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->idx_get(2)->get_DataLabelFormat()->set_ShowLabelAsDataCallout ( false);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:DisplayChartLabels
}
