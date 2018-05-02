#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/HtmlFormatter.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ConversionToTIFFNotes()
{

	//ExStart:ConversionToTIFFNotes
	// The path to the documents directory.
	const String outPath = u"../out/ConversionToTIFFNotes_out.tiff";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Saving to TiffNotes
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::TiffNotes);
	//ExEnd:ConversionToTIFFNotes

}
