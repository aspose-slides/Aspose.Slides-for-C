#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveNotesFromAllSlides()
{
	//ExStart:RemoveNotesFromAllSlides

	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/RemovedAllNotes.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Removing notes of all slides
	SharedPtr<INotesSlideManager> mgr ;
	for (int i = 0; i < pres->get_Slides()->get_Count(); i++)
	{
		mgr = pres->get_Slides()->idx_get(i)->get_NotesSlideManager();
		mgr->RemoveNotesSlide();
	}
	// Save presentation to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
	// ExEnd:RemoveNotesFromAllSlides
}
