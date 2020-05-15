#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveSlideUsingIndex()
{
	//ExStart:RemoveSlideUsingIndex

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/RemoveSlidesByID.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Removing a slide using its slide index
	pres->get_Slides()->RemoveAt(0);

	// Writing the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:RemoveSlideUsingIndex
}
