#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CloneToAnotherPresentationWithSetSizeAndType()
{
	//ExStart:CloneToAnotherPresentationWithSetSizeAndType

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/CloneToAnotherPresentationWithSetSizeAndType.pptx";
	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();
	
	// Set the slide size of generated presentations to that of source
	destPres->get_SlideSize()->SetSize(pres->get_SlideSize()->get_Type(), SlideSizeScaleType::DoNotScale);
    
	// Clone the desired slide at desired position of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CloneToAnotherPresentationWithSetSizeAndType
}
