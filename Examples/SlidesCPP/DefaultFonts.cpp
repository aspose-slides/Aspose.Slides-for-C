#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void DefaultFonts()
{
	// ExStart:DefaultFonts
	// The path to the documents directory.
	const String outPath = u"../out/DefaultFonts_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Use load options to define the default regualr and asian fonts
	SharedPtr<LoadOptions> loadOptions = MakeObject< LoadOptions>(LoadFormat::Auto);
	loadOptions->set_DefaultRegularFont(u"Wingdings");
	loadOptions->set_DefaultAsianFont(u"Wingdings");

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);

	// Generate slide thumbnail
	pres->get_Slides()->idx_get(0)->GetThumbnail(1, 1)->Save(u"../out/DefaultFonts_out.png", Imaging::ImageFormat::get_Png());

	// Generate PDF
	pres->Save(u"../out/DefaultFonts_out.pdf", Export::SaveFormat::Pdf);

	// Generate XPS
	pres->Save(u"../out/DefaultFonts_out.xps", Export::SaveFormat::Xps);

	// ExEnd:DefaultFonts
}
