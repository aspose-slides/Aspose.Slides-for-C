#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SettingFontSizeOfLegend()
{
	//ExStart:SettingFontSizeOfLegend

	// The path to the documents directory.
	const String outPath = u"../out/SettingFontSizeOfLegend_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	//Setting legend properties
	chart->get_Legend()->get_TextFormat()->get_PortionFormat()->set_FontHeight (20);

	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMinValue (false);

	chart->get_Axes()->get_VerticalAxis()->set_MinValue (-5);

	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMaxValue (false);

	chart->get_Axes()->get_VerticalAxis()->set_MaxValue ( 10);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SettingFontSizeOfLegend
}
