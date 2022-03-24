#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ManageHandoutHeaderFooter()
{
	//ExStart:HandoutHeaderFooterManager
	// The path to the documents directory.
	const String outPath = u"../out/HandoutHeaderFooterManager_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>();

	System::SharedPtr<IMasterHandoutSlide> masterHandoutSlide = presentation->get_MasterHandoutSlideManager()->get_MasterHandoutSlide();
	if (masterHandoutSlide != nullptr)
	{
		System::SharedPtr<IBaseHandoutNotesSlideHeaderFooterManag> headerFooterManager = masterHandoutSlide->get_HeaderFooterManager();
		if (!headerFooterManager->get_IsHeaderVisible())
			headerFooterManager->SetHeaderVisibility(true); // make the master handout slide Header placeholder visible

		if (!headerFooterManager->get_IsFooterVisible())
			headerFooterManager->SetFooterVisibility(true); // make the master handout slide Footer placeholder visible

		if (!headerFooterManager->get_IsSlideNumberVisible())
			headerFooterManager->SetSlideNumberVisibility(true); // make the master handout slide SlideNumber placeholder visible

		if (!headerFooterManager->get_IsDateTimeVisible())
			headerFooterManager->SetDateTimeVisibility(true); // make the master handout slide Date-time placeholder visible

		headerFooterManager->SetHeaderText(u"New header text"); // set text to master handout slide Header placeholder
		headerFooterManager->SetFooterText(u"New footer text"); // set text to master handout slide Footer placeholder
		headerFooterManager->SetDateTimeText(u"New date and time text"); // set master handout to notes slide Date-time placeholder
	}

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	
	//ExEnd:HandoutHeaderFooterManager
}
