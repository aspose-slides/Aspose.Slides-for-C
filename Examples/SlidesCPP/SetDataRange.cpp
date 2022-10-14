#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SetDataRange()
{
	//ExStart:SetDataRange

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/DataRange_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
//	SharedPtr<IChart> chart = ExplicitCast<Aspose::Slides::Charts::IChart>(slide->get_Shapes()->idx_get(0));
	auto chart = ExplicitCast<Chart>(slide->get_Shapes()->idx_get(0));

	//Not working

	//Set data range	
//	chart->get_ChartData()->SetRange("Sheet1!A1:B4");

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetDataRange
}
