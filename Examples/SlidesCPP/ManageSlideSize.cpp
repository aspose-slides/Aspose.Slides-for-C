#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>
#include <Export/Pdfoptions.h>
#include <DOM/SlideSizeScaleType.h>

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
	const String outPath = u"../out/SetPDFPageSize_out.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>();


	// Set SlideSize.Type Property 
	pres->get_SlideSize()->SetSize(SlideSizeType::A4Paper, SlideSizeScaleType::EnsureFit);


	// Set different properties of PDF Options
	Aspose::Slides::Export::PdfOptions opts = Aspose::Slides::Export::PdfOptions();
	opts.set_SufficientResolution (600);

	// Save presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, &opts);
	//ExEnd:SetPDFPageSize
}
