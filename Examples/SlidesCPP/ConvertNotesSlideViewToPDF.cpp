#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void ConvertNotesSlideViewToPDF()
{
    //ExStart:ConvertNotesSlideViewToPDF

    // The path to the documents directory.
    const System::String outPath = u"../out/ConvertNotesSlideViewToPDF_out.pdf";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<PdfOptions> opts = System::MakeObject<PdfOptions>();
    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_NotesPosition(NotesPositions::BottomFull);
    opts->set_SlidesLayoutOptions(options);

    pres->Save(outPath, SaveFormat::Pdf, opts);

    //ExEnd:ConvertNotesSlideViewToPDF
}
