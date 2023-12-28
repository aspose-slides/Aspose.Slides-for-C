#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void ExportInkExample()
{
    //ExStart:ExportInkExample

    // The path to the documents directory.
    const System::String templateFilePath = Path::Combine(GetDataPath(), u"InkOptions.pptx");
    const System::String outFilePath1 = Path::Combine(GetOutPath(), u"HideInkDemo.pdf");
    const System::String outFilePath2 = Path::Combine(GetOutPath(), u"ROPInkDemo.pdf");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templateFilePath);

    System::SharedPtr<PdfOptions> options = System::MakeObject<PdfOptions>();
    // Hide ink objects
    options->get_InkOptions()->set_HideInk(true);
    // Save result
    pres->Save(outFilePath1, SaveFormat::Pdf, options);

    // Show Ink objects
    options->get_InkOptions()->set_HideInk(false);
    // Set using ROP operation for rendering brush
    options->get_InkOptions()->set_InterpretMaskOpAsOpacity(false);
    // Save result
    pres->Save(outFilePath2, SaveFormat::Pdf, options);

    //ExEnd:ExportInkExample
}
