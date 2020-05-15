#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SettingFontSizeOfIndividualLegend()
{
	//ExStart:SettingFontSizeOfIndividualLegend

	// The path to the documents directory.
	const String outPath = u"../out/SettingFontSizeOfIndividualLegend_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	//Setting legend properties

	SharedPtr<IChartTextFormat> tf = chart->get_Legend()->get_Entries()->idx_get(1)->get_TextFormat();

	tf->get_PortionFormat()->set_FontBold (NullableBool::True);

	tf->get_PortionFormat()->set_FontHeight(20);

	tf->get_PortionFormat()->set_FontItalic(NullableBool::True);

	tf->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid) ;

	tf->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Blue());

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SettingFontSizeOfIndividualLegend
}
