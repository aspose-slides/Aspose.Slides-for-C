#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void ConversionToTIFFNotes()
{
    //ExStart:ConversionToTIFFNotes
    // The path to the documents directory.
    const System::String outPath = u"../out/ConversionToTIFFNotes_out.tiff";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<TiffOptions> opts = System::MakeObject<TiffOptions>();

    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_NotesPosition(NotesPositions::BottomFull);
    opts->set_SlidesLayoutOptions(options);
    // Saving to TiffNotes
    pres->Save(outPath, SaveFormat::Tiff, opts);
    //ExEnd:ConversionToTIFFNotes
}
