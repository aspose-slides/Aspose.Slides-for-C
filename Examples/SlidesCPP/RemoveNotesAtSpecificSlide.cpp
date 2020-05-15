#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveNotesAtSpecificSlide()
{
	//ExStart:RemoveNotesAtSpecificSlide

	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/RemoveNotesAtSpecificSlide.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Removing notes of all slides
	SharedPtr<INotesSlideManager> mgr;
	
	//Removing notes from first slide
	mgr = pres->get_Slides()->idx_get(0)->get_NotesSlideManager();
	mgr->RemoveNotesSlide();
	
	// Save presentation to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
	// ExEnd:RemoveNotesAtSpecificSlide
}
