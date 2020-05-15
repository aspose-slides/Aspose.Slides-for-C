#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

void ConvertToPDFWithHiddenSlides()
{
	//ExStart:ConvertToPDFWithHiddenSlides

	// The path to the documents directory.
	const String outPath = u"../out/ConvertToPDFWithHiddenSlides_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<PdfOptions> pdfOptions = MakeObject <PdfOptions>();
	pdfOptions->set_ShowHiddenSlides(true);

	pres->Save(outPath, SaveFormat::Pdf, pdfOptions);

	//ExEnd:ConvertToPDFWithHiddenSlides
}
