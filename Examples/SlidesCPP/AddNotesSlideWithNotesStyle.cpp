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
#include <DOM/IMasterNotesSlide.h>
#include <DOM/IMasterNotesSlideManager.h>
#include <DOM/ITextStyle.h>
#include <DOM/BulletType.h>
#include <DOM/IParagraphFormat.h>
#include <DOM/IBulletFormat.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;


void AddNotesSlideWithNotesStyle()
{
	//ExStart:AddNotesSlideWithNotesStyle
	// The path to the documents directory.
	const String outPath = u"../out/AddNotesSlideWithNotesStyle_out.pptx";
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Accessing Master note slide
	SharedPtr<IMasterNotesSlide> notesMaster = pres->get_MasterNotesSlideManager()->get_MasterNotesSlide();

	if (notesMaster != NULL)
	{
		// Get MasterNotesSlide text style
		SharedPtr<ITextStyle> notesStyle = notesMaster->get_NotesStyle();

		//Set symbol bullet for the first level paragraphs
		SharedPtr<IParagraphFormat> paragraphFormat = notesStyle->GetLevel(0);
		paragraphFormat->get_Bullet()->set_Type(BulletType::Symbol);
	}


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:AddNotesSlideWithNotesStyle

}
