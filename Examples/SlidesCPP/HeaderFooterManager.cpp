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
#include <DOM/IBaseSlideHeaderFooterManager.h>
#include <DOM/ISlideHeaderFooterManager.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;


void HeaderFooterManager()
{
	//ExStart:HeaderFooterManager
	// The path to the documents directory.
	const String outPath = u"../out/HeaderFooterManager_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = presentation->get_Slides();

	SharedPtr<IBaseSlideHeaderFooterManager> headerFooterManager = presentation->get_Slides()->idx_get(0)->get_HeaderFooterManager();
	if (!headerFooterManager->get_IsFooterVisible()) // Property IsFooterVisible is used for indicating that a slide footer placeholder is not present.
	{
		headerFooterManager->SetFooterVisibility(true); // Method SetFooterVisibility is used for making a slide footer placeholder visible.
	}
	if (!headerFooterManager->get_IsSlideNumberVisible()) // Property IsSlideNumberVisible is used for indicating that a slide page number placeholder is not present.
	{
		headerFooterManager->SetSlideNumberVisibility(true); // Method SetSlideNumberVisibility is used for making a slide page number placeholder visible.
	}
	if (!headerFooterManager->get_IsDateTimeVisible()) // Property IsDateTimeVisible is used for indicating that a slide date-time placeholder is not present.
	{
		headerFooterManager->SetDateTimeVisibility(true); // Method SetFooterVisibility is used for making a slide date-time placeholder visible.
	}
	headerFooterManager->SetFooterText(u"Footer text"); // Method SetFooterText is used for setting text to slide footer placeholder.
	headerFooterManager->SetDateTimeText(u"Date and time text"); // Method SetDateTimeText is used for setting text to slide date-time placeholder.

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:HeaderFooterManager

}
