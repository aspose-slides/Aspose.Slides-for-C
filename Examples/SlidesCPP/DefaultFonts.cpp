#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void DefaultFonts()
{
    // ExStart:DefaultFonts
    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"DefaultFonts.pptx");
    const System::String outPathPng = Path::Combine(GetOutPath(), u"DefaultFonts_out.png");
    const System::String outPathPdf = Path::Combine(GetOutPath(), u"DefaultFonts_out.pdf");
    const System::String outPathXps = Path::Combine(GetOutPath(), u"DefaultFonts_out.xps");

    // Use load options to define the default regular and asian fonts
    System::SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>(LoadFormat::Auto);
    loadOptions->set_DefaultRegularFont(u"Wingdings");
    loadOptions->set_DefaultAsianFont(u"Wingdings");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);

    // Generate slide thumbnail
    System::SharedPtr<IImage> image = pres->get_Slide(0)->GetImage(1, 1);
    image->Save(outPathPng, ImageFormat::Png);

    // Generate PDF
    pres->Save(outPathPdf, SaveFormat::Pdf);

    // Generate XPS
    pres->Save(outPathXps, SaveFormat::Xps);

    // ExEnd:DefaultFonts
}
