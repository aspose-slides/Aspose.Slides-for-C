#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::Drawing::Imaging;

void ThumbnailFromSlideInNotes()
{
	//ExStart:ThumbnailFromSlideInNotes

	// The path to the documents directory.
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String outPath = u"../out/Aspose_NotesSlide_out.png";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// User defined dimension
	int desiredX = 1200;
	int desiredY = 800;

	// Create a full scale image
	auto bitmap = slide->GetThumbnail(2, 2);

	bitmap->Save(outPath, ImageFormat::get_Png());

	//ExEnd:ThumbnailFromSlideInNotes
}
