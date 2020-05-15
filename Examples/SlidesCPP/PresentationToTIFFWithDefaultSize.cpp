#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void PresentationToTIFFWithDefaultSize()
{
	//ExStart:PresentationToTIFFWithDefaultSize
	// The path to the documents directory.
	const String outPath = u"../out/PresentationToTIFFWithDefaultSize_out.tiff";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Saving to Tiff
	pres->Save(outPath, SaveFormat::Tiff);

	//ExEnd:PresentationToTIFFWithDefaultSize
}
