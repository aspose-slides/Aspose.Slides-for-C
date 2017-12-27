#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/SlideSizeType.h>
#include <Export/Pdfoptions.h>
#include <DOM/ShapeType.h>
#include <DOM/INotesSlideManager.h>



#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>
#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;
void RemoveNotesAtSpecificSlide()
{
	//ExStart:RemoveNotesAtSpecificSlide

	// The path to the documents directory.
	const String templatePath = L"../templates/AccessSlides.pptx";
	const String outPath = L"../out/RemoveNotesAtSpecificSlide.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Removing notes of all slides
	SharedPtr<INotesSlideManager> mgr;
	
	//Removing notes from first slide
	mgr = pres->get_Slides()->idx_get(0)->get_NotesSlideManager();
	mgr->RemoveNotesSlide();
	
	// Save presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	// ExEnd:RemoveNotesAtSpecificSlide
}