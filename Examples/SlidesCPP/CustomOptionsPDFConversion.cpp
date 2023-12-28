#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void CustomOptionsPDFConversion()
{
    //ExStart:CustomOptionsPDFConversion

    // The path to the documents directory.
    const System::String outPath = u"../out/CustomOptionsPDFConversion_out.pdf";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<PdfOptions> pdfOptions = System::MakeObject<PdfOptions>();
    pdfOptions->set_ShowHiddenSlides(true);
    pdfOptions->set_JpegQuality(90);
    pdfOptions->set_SaveMetafilesAsPng(true);
    pdfOptions->set_TextCompression(PdfTextCompression::Flate);
    pdfOptions->set_Compliance(PdfCompliance::Pdf15);

    System::SharedPtr<INotesCommentsLayoutingOptions> opts = System::MakeObject<NotesCommentsLayoutingOptions>();
    opts->set_NotesPosition(NotesPositions::BottomFull);

    pres->Save(outPath, SaveFormat::Pdf, pdfOptions);

    //ExEnd:CustomOptionsPDFConversion
}
