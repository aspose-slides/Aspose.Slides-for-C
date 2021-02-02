#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::IO;

void ConvertToPdfConformancePdf1A_PdfUa()
{
    //ExStart:ConvertToPdfConformancePdf1A_PdfUa
    String pptxFile = Path::Combine(GetDataPath(), u"tagged-pdf-demo.pptx");
    String outPdf1aFile = Path::Combine(GetOutPath(), u"tagged-pdf-demo_1a.pdf");
    String outPdf1bFile = Path::Combine(GetOutPath(), u"tagged-pdf-demo_1b.pdf");
    String outPdfUaFile = Path::Combine(GetOutPath(), u"tagged-pdf-demo_1ua.pdf");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(pptxFile);

    SharedPtr<PdfOptions> PdfA1aOptions = System::MakeObject<PdfOptions>();
    PdfA1aOptions->set_Compliance(PdfCompliance::PdfA1a);
    presentation->Save(outPdf1aFile, SaveFormat::Pdf, PdfA1aOptions);

    SharedPtr<PdfOptions> PdfA1bOptions = System::MakeObject<PdfOptions>();
    PdfA1aOptions->set_Compliance(PdfCompliance::PdfA1b);
    presentation->Save(outPdf1bFile, SaveFormat::Pdf, PdfA1bOptions);

    SharedPtr<PdfOptions> PdfUaOptions = System::MakeObject<PdfOptions>();
    PdfA1aOptions->set_Compliance(PdfCompliance::PdfA1b);
    presentation->Save(outPdfUaFile, SaveFormat::Pdf, PdfUaOptions);
    //ExEnd:ConvertToPdfConformancePdf1A_PdfUa
}
