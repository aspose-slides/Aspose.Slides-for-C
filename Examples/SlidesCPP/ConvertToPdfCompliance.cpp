#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

void ConvertToPdfCompliance()
{
    const String presentationName = Path::Combine(GetDataPath(), u"ConvertToPDF.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"ConvertToPDF-comp.pdf");

    auto presentation = System::MakeObject<Presentation>(presentationName);
    auto pdfOptions = System::MakeObject<PdfOptions>();
    pdfOptions->set_Compliance(PdfCompliance::PdfA2a);
    presentation->Save(outPath, SaveFormat::Pdf, pdfOptions);
}
