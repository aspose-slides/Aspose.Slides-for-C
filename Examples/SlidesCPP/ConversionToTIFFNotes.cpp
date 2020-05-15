#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

void ConversionToTIFFNotes()
{
	//ExStart:ConversionToTIFFNotes
	// The path to the documents directory.
	const String outPath = u"../out/ConversionToTIFFNotes_out.tiff";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<TiffOptions> opts = System::MakeObject<TiffOptions>();

	SharedPtr<INotesCommentsLayoutingOptions> options = opts->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);
	// Saving to TiffNotes
	pres->Save(outPath, SaveFormat::Tiff, opts);
	//ExEnd:ConversionToTIFFNotes
}
