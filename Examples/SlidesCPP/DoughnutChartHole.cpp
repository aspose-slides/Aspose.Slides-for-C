#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void DoughnutChartHole()
{
	//ExStart:DoughnutChartHole

	// The path to the documents directory.
	const String outPath = u"../out/DoughnutChartHole_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Doughnut, 0, 0, 500, 500);


	chart->get_ChartData()->get_SeriesGroups()->idx_get(0)->set_DoughnutHoleSize(90);
	
	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:DoughnutChartHole
}
