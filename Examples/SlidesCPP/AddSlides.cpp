#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddSlides()
{
	//ExStart:AddSlides

	// The path to the documents directory.
	const String outPath = u"../out/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Instantiate SlideCollection class
	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	for (int i = 0; i < pres->get_LayoutSlides()->get_Count(); i++)
	{
		// Add an empty slide to the Slides collection
		slds->AddEmptySlide(pres->get_LayoutSlides()->idx_get(i));
	}

	// Save the PPTX file to the Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddSlides
}
