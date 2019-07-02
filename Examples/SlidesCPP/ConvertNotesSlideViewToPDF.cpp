#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"
#include <Export/PdfOptions.h>
#include <Export/NotesPositions.h>
#include <Export/INotesCommentsLayoutingOptions.h>

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ConvertNotesSlideViewToPDF ()
{

	//ExStart:ConvertNotesSlideViewToPDF

	// The path to the documents directory.
	const String outPath = u"../out/ConvertNotesSlideViewToPDF_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";
	
	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);


	System::SharedPtr<PdfOptions> opts = System::MakeObject<PdfOptions>();

	System::SharedPtr<INotesCommentsLayoutingOptions> options = opts->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, opts);

	//ExEnd:ConvertNotesSlideViewToPDF


}