#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Import;
using namespace Export;
using namespace System::IO;

void PdfImportTableExample()
{
    //ExStart:PdfImportTableExample

    const System::String pdfFileName = Path::Combine(GetDataPath(), u"SimpleTableExample.pdf");
    const System::String resultPath = Path::Combine(GetOutPath(), u"SimpleTableExample.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    System::SharedPtr<Stream> stream = System::MakeObject<FileStream>(pdfFileName, FileMode::Open, FileAccess::Read, FileShare::Read);

    System::SharedPtr<PdfImportOptions> pdfImportOptions = System::MakeObject<PdfImportOptions>();
    pdfImportOptions->set_DetectTables(true);
    pres->get_Slides()->AddFromPdf(stream, pdfImportOptions);

    pres->Save(resultPath, SaveFormat::Pptx);

    //ExEnd:PdfImportTableExample
}
