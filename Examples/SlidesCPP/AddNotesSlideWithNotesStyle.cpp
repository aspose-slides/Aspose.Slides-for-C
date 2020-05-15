#include "stdafx.h"
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

	if (notesMaster != nullptr)
	{
		// Get MasterNotesSlide text style
		SharedPtr<ITextStyle> notesStyle = notesMaster->get_NotesStyle();

		//Set symbol bullet for the first level paragraphs
		SharedPtr<IParagraphFormat> paragraphFormat = notesStyle->GetLevel(0);
		paragraphFormat->get_Bullet()->set_Type(BulletType::Symbol);
	}

	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:AddNotesSlideWithNotesStyle
}
