#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ChangePosition()
{
	//ExStart:ChangePosition

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/ChangeSlidePosition.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Set the new position for the slide
	slide->set_SlideNumber(2);

	// Writing the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ChangePosition
}
