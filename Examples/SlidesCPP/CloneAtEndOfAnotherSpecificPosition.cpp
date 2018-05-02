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

void CloneAtEndOfAnotherSpecificPosition()
{
	//ExStart:CloneAtEndOfAnotherSpecificPosition

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/CloneAtEndOfAnotherSpecificPosition.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Clone the desired slide at end of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneAtEndOfAnotherSpecificPosition
}
