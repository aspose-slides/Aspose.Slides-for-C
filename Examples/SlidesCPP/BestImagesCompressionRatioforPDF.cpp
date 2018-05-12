#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/PdfOptions.h>
#include <DOM/LoadOptions.h>
#include <LoadFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void BestImagesCompressionRatioforPDF()
{

	//ExStart:BestImagesCompressionRatioforPDF

	// The path to the documents directory.
	const String outPath = u"../out/BestImagesCompressionRatio_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";
	
	System::SharedPtr<PdfOptions> options = System::MakeObject<PdfOptions>();
	options->set_BestImagesCompressionRatio(true);

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, options);

	//ExEnd:BestImagesCompressionRatioforPDF


}