#include "stdafx.h"
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

	presentation->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetChildFooter
}
