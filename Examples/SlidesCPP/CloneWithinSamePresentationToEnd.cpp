#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CloneWithinSamePresentationToEnd()
{
	//ExStart:CloneWithinSamePresentationToEnd

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/CloneWithinSamePresentationToEnd.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slides = pres->get_Slides();

	// Clone the desired slide at end of same presentation
	slides->AddClone(pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CloneWithinSamePresentationToEnd
}
