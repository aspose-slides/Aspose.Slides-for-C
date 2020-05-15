#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CloneWithInSamePresentation()
{
	//ExStart:CloneWithInSamePresentation

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/CloneWithInSamePresentation.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slides = pres->get_Slides();

	// Clone the desired slide to the specified index in the same presentation
	slides->InsertClone(2, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CloneWithInSamePresentation
}
