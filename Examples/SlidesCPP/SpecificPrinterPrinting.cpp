#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/PdfOptions.h>
#include "SlidesExamples.h"

using namespace Aspose;
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