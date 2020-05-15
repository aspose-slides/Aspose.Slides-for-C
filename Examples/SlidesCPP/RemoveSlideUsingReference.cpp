#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveSlideUsingReference()
{
	//ExStart:RemoveSlideUsingReference

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/RemoveSlidesByReference.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Removing a slide using its reference
	pres->get_Slides()->Remove(slide);

	// Writing the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:RemoveSlideUsingReference
}
