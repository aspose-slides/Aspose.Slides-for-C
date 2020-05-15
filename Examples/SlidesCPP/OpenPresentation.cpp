#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void OpenPresentation()
{
	//ExStart:OpenPresentation
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();

    //Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	printf("Total slides inside presentation are : %d\n", pres->get_Slides()->get_Count());

	//ExEnd:OpenPresentation
}
