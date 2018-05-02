#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>
#include <DOM/SlideSizeScaleType.h>

#include <Export/Pdfoptions.h>
#include <Export/SaveOptions.h>


#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>

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
	pres->get_SlideSize()->SetSize(Aspose::Slides::SlideSizeType::A4Paper,Aspose::Slides::SlideSizeScaleType::EnsureFit);

	// Set different properties of PDF Options
	SharedPtr<Aspose::Slides::Export::PdfOptions> opts = MakeObject<Aspose::Slides::Export::PdfOptions>();
	opts->set_SufficientResolution(600);

	// Save presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, opts);
	//ExEnd:SetPDFPageSize
}
