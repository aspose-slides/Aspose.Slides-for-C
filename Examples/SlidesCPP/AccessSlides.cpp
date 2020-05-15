#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AccessSlides()
{
	//ExStart:AccessSlides
	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	// Accessing a slide using its slide index
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//Prinitng slide number
	printf("Accessed Slide Number : %d\n", slide->get_SlideNumber());
	//ExEnd:AccessSlides
}
