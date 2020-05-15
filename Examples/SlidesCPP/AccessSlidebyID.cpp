#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AccessSlidebyID()
{
	//ExStart:AccessSlidebyID

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Getting Slide ID
	int id = pres->get_Slides()->idx_get(0)->get_SlideId();

	// Accessing Slide by ID
	SharedPtr<IBaseSlide> slide = pres->GetSlideById(id);

	//ExEnd:AccessSlidebyID
}
