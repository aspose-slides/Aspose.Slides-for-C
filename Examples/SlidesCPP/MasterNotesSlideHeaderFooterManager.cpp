

#include <iostream>
#include <system/console.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterNotesSlide.h>
#include <DOM/IMasterNotesSlideManager.h>
#include <DOM/ISlide.h>
#include <DOM/INotesSlide.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/IMasterNotesSlideHeaderFooterManager.h>
#include <DOM/INotesSlideHeaderFooterManager.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IMasterLayoutSlideCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>
#include <DOM/IBaseSlideHeaderFooterManager.h>
#include <DOM/ISlideHeaderFooterManager.h>
#include <DOM/IPresentationHeaderFooterManager.h>
#include <DOM/IMasterHandoutSlideHeaderFooterManager.h>



//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;


void MasterNotesSlideHeaderFooterManager()
{
	//ExStart:MasterNotesSlideHeaderFooterManager
	// The path to the documents directory.
	const String outPath = u"../out/MasterNotesSlideHeaderFooterManager_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>();

	// Change Header and Footer settings for notes master and all notes slides
	System::SharedPtr<IMasterNotesSlide> masterNotesSlide = presentation->get_MasterNotesSlideManager()->get_MasterNotesSlide();
	if (masterNotesSlide != nullptr)
	{
		System::SharedPtr<IMasterNotesSlideHeaderFooterManager> headerFooterManager = masterNotesSlide->get_HeaderFooterManager();
	
		headerFooterManager->SetHeaderAndChildHeadersVisibility(true); // make the master notes slide and all child Footer placeholders visible
		headerFooterManager->SetFooterAndChildFootersVisibility(true); // make the master notes slide and all child Header placeholders visible
		headerFooterManager->SetSlideNumberAndChildSlideNumbersVisibility(true); // make the master notes slide and all child SlideNumber placeholders visible
		headerFooterManager->SetDateTimeAndChildDateTimesVisibility(true); // make the master notes slide and all child Date and time placeholders visible

		headerFooterManager->SetHeaderAndChildHeadersText(u"Header text"); // set text to master notes slide and all child Header placeholders
		headerFooterManager->SetFooterAndChildFootersText(u"Footer text"); // set text to master notes slide and all child Footer placeholders
		headerFooterManager->SetDateTimeAndChildDateTimesText(u"Date and time text"); // set text to master notes slide and all child Date and time placeholders
	}

	// Change Header and Footer settings for first notes slide only
	System::SharedPtr<INotesSlide> notesSlide = presentation->get_Slides()->idx_get(0)->get_NotesSlideManager()->get_NotesSlide();
	if (notesSlide != nullptr)
	{
		System::SharedPtr<INotesSlideHeaderFooterManager> headerFooterManager = notesSlide->get_HeaderFooterManager();
		if (!headerFooterManager->get_IsHeaderVisible())
			headerFooterManager->SetHeaderVisibility(true); // make this notes slide Header placeholder visible

		if (!headerFooterManager->get_IsFooterVisible())
			headerFooterManager->SetFooterVisibility(true); // make this notes slide Footer placeholder visible

		if (!headerFooterManager->get_IsSlideNumberVisible())
			headerFooterManager->SetSlideNumberVisibility(true); // make this notes slide SlideNumber placeholder visible

		if (!headerFooterManager->get_IsDateTimeVisible())
			headerFooterManager->SetDateTimeVisibility(true); // make this notes slide Date-time placeholder visible

		headerFooterManager->SetHeaderText(u"New header text"); // set text to notes slide Header placeholder
		headerFooterManager->SetFooterText(u"New footer text"); // set text to notes slide Footer placeholder
		headerFooterManager->SetDateTimeText(u"New date and time text"); // set text to notes slide Date-time placeholder
	}


		presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

		//ExEnd:MasterNotesSlideHeaderFooterManager

	}
