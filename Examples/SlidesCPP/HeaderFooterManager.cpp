#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ManageHeaderFooter()
{
	//ExStart:HeaderFooterManager
	// The path to the documents directory.
	const String outPath = u"../out/HeaderFooterManager_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = presentation->get_Slides();

//	SharedPtr<IBaseSlideHeaderFooterManager> headerFooterManager = presentation->get_Slides()->idx_get(0)->get_HeaderFooterManager();
	SharedPtr<IMasterSlideHeaderFooterManager> headerFooterManager = presentation->get_Masters()->idx_get(0)->get_HeaderFooterManager();
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

	presentation->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:HeaderFooterManager
}
