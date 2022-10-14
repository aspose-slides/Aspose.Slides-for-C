#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void ChangeChartCategoryAxis()
{
	//ExStart:ChangeChartCategoryAxis

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/ChangeChartCategoryAxis_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<Chart> chart = ExplicitCast<Aspose::Slides::Charts::Chart>(slide->get_Shapes()->idx_get(0));

	chart->get_Axes()->get_HorizontalAxis()->set_CategoryAxisType(CategoryAxisType::Date);
	chart->get_Axes()->get_HorizontalAxis()->set_IsAutomaticMajorUnit( false);
	chart->get_Axes()->get_HorizontalAxis()->set_MajorUnit ( 1);
	chart->get_Axes()->get_HorizontalAxis()->set_MajorUnitScale (TimeUnitType::Months);

	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ChangeChartCategoryAxis
}
