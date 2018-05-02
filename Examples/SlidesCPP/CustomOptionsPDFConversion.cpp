#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/PdfOptions.h>
#include <Export/PdfTextCompression.h>
#include <Export/PdfCompliance.h>


#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void CustomOptionsPDFConversion()
{

	//ExStart:CustomOptionsPDFConversion

	// The path to the documents directory.
	const String outPath = u"../out/CustomOptionsPDFConversion_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<Aspose::Slides::Export::PdfOptions> pdfOptions = MakeObject <Aspose::Slides::Export::PdfOptions>();
	pdfOptions->set_ShowHiddenSlides(true);
	pdfOptions->set_JpegQuality(90);
	pdfOptions->set_SaveMetafilesAsPng(true);
	pdfOptions->set_TextCompression(PdfTextCompression::Flate);
	pdfOptions->set_Compliance(PdfCompliance::Pdf15);


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, pdfOptions);

	//ExEnd:CustomOptionsPDFConversion


}