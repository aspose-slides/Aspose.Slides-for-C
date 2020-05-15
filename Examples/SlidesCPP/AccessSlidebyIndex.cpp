#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AccessSlidebyIndex()
{
	//ExStart:AccessSlidebyIndex

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//ExEnd:AccessSlidebyIndex
}
