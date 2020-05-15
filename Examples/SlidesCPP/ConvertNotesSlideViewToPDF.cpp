#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

void ConvertNotesSlideViewToPDF()
{
    //ExStart:ConvertNotesSlideViewToPDF

    // The path to the documents directory.
    const String outPath = u"../out/ConvertNotesSlideViewToPDF_out.pdf";
    const String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    SharedPtr<PdfOptions> opts = System::MakeObject<PdfOptions>();

    SharedPtr<INotesCommentsLayoutingOptions> options = opts->get_NotesCommentsLayouting();
    options->set_NotesPosition(NotesPositions::BottomFull);

    pres->Save(outPath, SaveFormat::Pdf, opts);

    //ExEnd:ConvertNotesSlideViewToPDF
}
