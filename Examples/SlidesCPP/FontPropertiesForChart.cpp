#include "stdafx.h"
#include <Export/SaveFormat.h>

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void FontPropertiesForChart()
{
	//ExStart:FontPropertiesForChart
	// The path to the documents directory.
	const String outPath = u"../out/FontPropertiesForChart.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::ClusteredColumn, 100, 100, 500, 400);
	chart->get_TextFormat()->get_PortionFormat()->set_FontHeight(20);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FontPropertiesForChart
}
