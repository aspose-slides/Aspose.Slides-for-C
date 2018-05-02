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
#include <DOM/IMasterSlideHeaderFooterManager.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;


void SetChildFooter()
{
	//ExStart:SetChildFooter
	// The path to the documents directory.
	const String outPath = u"../out/SetChildFooter_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = presentation->get_Slides();

	SharedPtr<IMasterSlideHeaderFooterManager> headerFooterManager = presentation->get_Masters()->idx_get(0)->get_HeaderFooterManager();
	headerFooterManager->SetFooterAndChildFootersVisibility(true); // Method SetFooterAndChildFootersVisibility is used for making a master slide and all child footer placeholders visible.
	headerFooterManager->SetSlideNumberAndChildSlideNumbersVisibility(true); // Method SetSlideNumberAndChildSlideNumbersVisibility is used for making a master slide and all child page number placeholders visible.
	headerFooterManager->SetDateTimeAndChildDateTimesVisibility(true); // Method SetDateTimeAndChildDateTimesVisibility is used for making a master slide and all child date-time placeholders visible.

	headerFooterManager->SetFooterAndChildFootersText(u"Footer text"); // Method SetFooterAndChildFootersText is used for setting text to master slide and all child footer placeholders.
	headerFooterManager->SetDateTimeAndChildDateTimesText(u"Date and time text"); // Method SetDateTimeAndChildDateTimesText is used for setting text to master slide and all child date-time placeholders.

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:SetChildFooter

}
