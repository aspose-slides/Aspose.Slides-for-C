#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void ConvertToPdfUnsupportedFontStyles()
{
    //ExStart:ConvertToPdfUnsupportedFontStyles
    const System::String outFilePath = Path::Combine(GetOutPath(), u"UnsupportedFontStyles.pdf");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    System::SharedPtr<PdfOptions> pdfOptions = System::MakeObject<PdfOptions>();
    pdfOptions->set_RasterizeUnsupportedFontStyles(true);

    pres->Save(outFilePath, SaveFormat::Pdf, pdfOptions);
    //ExEnd:ConvertToPdfUnsupportedFontStyles
}
