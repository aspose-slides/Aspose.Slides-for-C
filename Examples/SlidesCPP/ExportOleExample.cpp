#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ExportOleExample()
{
    //ExStart:ExportOleExample

    // The path to the presentation.
    const String templatePath = Path::Combine(GetDataPath(), u"PresOleExample.pptx");
    // The path to output file.
    const String outFilePath = Path::Combine(GetOutPath(), u"PresOleExample.pdf");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
    SharedPtr<PdfOptions> options = MakeObject<PdfOptions>();
    // Include OLE data into exported PDF.
    options->set_IncludeOleData(true);
    // Save result
    pres->Save(outFilePath, SaveFormat::Pdf, options);

    //ExEnd:ExportOleExample
}
