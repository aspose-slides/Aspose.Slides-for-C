#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::IO;

void ImportFromPdf()
{
    //ExStart:PdfImport

    String pdfFileName = Path::Combine(GetDataPath(), u"welcome-to-powerpoint.pdf");
    String resultPath = Path::Combine(GetOutPath(), u"fromPdfDocument.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    pres->get_Slides()->AddFromPdf(pdfFileName);
    pres->Save(resultPath, SaveFormat::Pptx);

    //ExEnd:PdfImport
}
