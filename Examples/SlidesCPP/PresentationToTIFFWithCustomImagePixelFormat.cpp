#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/TiffOptions.h>
#include <Export/ImagePixelFormat.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void PresentationToTIFFWithCustomImagePixelFormat()
{

	//ExStart:PresentationToTIFFWithCustomImagePixelFormat
	// The path to the documents directory.
	const String outPath = u"../out/PresentationToTIFFWithCustomImagePixelFormat_out.tiff";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<Aspose::Slides::Export::TiffOptions> tiffOptions = MakeObject <Aspose::Slides::Export::TiffOptions>();
	tiffOptions->set_PixelFormat(ImagePixelFormat::Format8bppIndexed);

	//Saving to Tiff
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Tiff, tiffOptions);
	
	//ExEnd:PresentationToTIFFWithCustomImagePixelFormat

}
