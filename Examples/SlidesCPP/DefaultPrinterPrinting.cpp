#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void DefaultPrinterPrinting()
{
	//ExStart:DefaultPrinterPrinting
	// The path to the documents directory.

	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    //pres->Print();

	//ExEnd:DefaultPrinterPrinting
}
