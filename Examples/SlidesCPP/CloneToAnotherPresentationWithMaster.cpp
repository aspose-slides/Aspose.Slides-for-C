#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CloneToAnotherPresentationWithMaster()
{
	//ExStart:CloneToAnotherPresentationWithMaster

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/CloneToAnotherPresentationWithMaster.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Instantiate ISlide from the collection of slides in source presentation along with
	// Master slide
	SharedPtr<ISlide> SourceSlide = pres->get_Slides()->idx_get(0);
	SharedPtr<IMasterSlide> SourceMaster = SourceSlide->get_LayoutSlide()->get_MasterSlide();

	// Clone the desired master slide from the source presentation to the collection of masters in the
	// Destination presentation
	SharedPtr<IMasterSlideCollection> masters = destPres->get_Masters();
	SharedPtr<IMasterSlide> DestMaster = SourceSlide->get_LayoutSlide()->get_MasterSlide();

	// Clone the desired master slide from the source presentation to the collection of masters in the
	// Destination presentation
	SharedPtr<IMasterSlide> iSlide = masters->AddClone(SourceMaster);

	// Clone the desired slide from the source presentation with the desired master to the end of the
	// Collection of slides in the destination presentation
	slideCollection->AddClone(SourceSlide, iSlide, true);

	// Clone the desired slide at end of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CloneToAnotherPresentationWithMaster
}
