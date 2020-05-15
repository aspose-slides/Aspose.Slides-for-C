#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;

void ConvertPresentationToPasswordProtectedPDF()
{
    //ExStart:ConvertPresentationToPasswordProtectedPDF
    // The path to the documents directory.
    const String outPath = u"../out/ConvertPresentationToPasswordProtectedPDF_out.pdf";
    const String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    SharedPtr<PdfOptions> pdfoptions = MakeObject<PdfOptions>();
    pdfoptions->set_Password(u"password");

    pres->Save(outPath, SaveFormat::Pdf, pdfoptions);
    //ExEnd:ConvertPresentationToPasswordProtectedPDF
}
