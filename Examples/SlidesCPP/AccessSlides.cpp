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


void AccessSlides()
{
	//ExStart:AccessSlides
	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	// Accessing a slide using its slide index
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//Prinitng slide number
	printf("Accessed Slide Number : %d\n", slide->get_SlideNumber());
	//ExEnd:AccessSlides
}
