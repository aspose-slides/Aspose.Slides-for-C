#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ConvertToPDF()
{

	//ExStart:ConvertToPDF

	// The path to the documents directory.
	const String outPath = u"../out/ConvertToPDF_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";
	
	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
	
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf);

	//ExEnd:ConvertToPDF


}