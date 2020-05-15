#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetPDFPageSize()
{
	//ExStart:SetPDFPageSize

	// The path to the documents directory.
	const String templatePath = u"../templates/Hyperlinks.pptx";
	const String outPath = u"../out/SetPDFPageSize_out.pdf";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Set SlideSize.Type Property 
	pres->get_SlideSize()->SetSize(SlideSizeType::A4Paper, SlideSizeScaleType::EnsureFit);

	// Set different properties of PDF Options
	SharedPtr<Export::PdfOptions> opts = MakeObject<Export::PdfOptions>();
	opts->set_SufficientResolution(600);

	// Save presentation to disk
	pres->Save(outPath, Export::SaveFormat::Pdf, opts);
	//ExEnd:SetPDFPageSize
}
