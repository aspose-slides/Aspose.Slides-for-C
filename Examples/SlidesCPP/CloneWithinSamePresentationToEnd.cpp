#include <iostream>
#include <system/console.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/SlideLayoutType.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IMasterLayoutSlideCollection.h>
#include <DOM/ICommentAuthorCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>

//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void CloneWithinSamePresentationToEnd()
{
	//ExStart:CloneWithinSamePresentationToEnd

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneWithinSamePresentationToEnd.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slides = pres->get_Slides();

	// Clone the desired slide at end of same presentation
	slides->AddClone(pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneWithinSamePresentationToEnd
}

