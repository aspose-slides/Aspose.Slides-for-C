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
#include <DOM/SlideSizeScaleType.h>
#include <DOM/IMasterSlideHeaderFooterManager.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;


void SetSizeAndType()
{
	//ExStart:SetSizeAndType
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/SetSizeAndType_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>(templatePath);
	SharedPtr<Presentation> auxPresentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);

	// Set the slide size of generated presentations to that of source
	auxPresentation->get_SlideSize()->SetSize(presentation->get_SlideSize()->get_Type(), SlideSizeScaleType::EnsureFit);

	auxPresentation->get_Slides()->InsertClone(0, slide);
	auxPresentation->get_Slides()->RemoveAt(0);

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:SetSizeAndType

}
