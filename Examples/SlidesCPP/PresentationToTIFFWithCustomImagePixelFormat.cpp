#include "stdafx.h"
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

	SharedPtr<TiffOptions> tiffOptions = MakeObject<TiffOptions>();
	tiffOptions->set_PixelFormat(ImagePixelFormat::Format8bppIndexed);

	//Saving to Tiff
	pres->Save(outPath, SaveFormat::Tiff, tiffOptions);
	
	//ExEnd:PresentationToTIFFWithCustomImagePixelFormat
}
