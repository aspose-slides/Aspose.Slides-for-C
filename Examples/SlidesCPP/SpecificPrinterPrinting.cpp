#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void SpecificPrinterPrinting()
{
	//ExStart:SpecificPrinterPrinting
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
	
	//pres->Print(u"Please set your printer name here");

	//ExEnd:SpecificPrinterPrinting
}
