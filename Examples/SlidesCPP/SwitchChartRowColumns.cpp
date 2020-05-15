#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace System;

void SwitchChartRowColumns()
{
	//ExStart:SwitchChartRowColumns

	// The path to the documents directory.
	const String outPath = u"../out/SwitchChartRowColumns_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 100, 100, 400, 300);
	//Switching rows and columns
	chart->get_ChartData()->SwitchRowColumn();

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SwitchChartRowColumns
}
