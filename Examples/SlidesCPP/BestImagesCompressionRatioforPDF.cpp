#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

void BestImagesCompressionRatioforPDF()
{
	//ExStart:BestImagesCompressionRatioforPDF

	// The path to the documents directory.
	const String outPath = u"../out/BestImagesCompressionRatio_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";
	
	SharedPtr<PdfOptions> options = System::MakeObject<PdfOptions>();
	options->set_BestImagesCompressionRatio(true);

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->Save(outPath, SaveFormat::Pdf, options);

	//ExEnd:BestImagesCompressionRatioforPDF
}
