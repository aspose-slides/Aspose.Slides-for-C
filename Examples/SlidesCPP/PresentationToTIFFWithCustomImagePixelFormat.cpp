#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void PresentationToTIFFWithCustomImagePixelFormat()
{
    //ExStart:PresentationToTIFFWithCustomImagePixelFormat
    // The path to the documents directory.
    const System::String outPath = u"../out/PresentationToTIFFWithCustomImagePixelFormat_out.tiff";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<TiffOptions> tiffOptions = System::MakeObject<TiffOptions>();
    tiffOptions->set_PixelFormat(ImagePixelFormat::Format8bppIndexed);

    System::SharedPtr<INotesCommentsLayoutingOptions> opts = System::MakeObject<NotesCommentsLayoutingOptions>();
    opts->set_NotesPosition(NotesPositions::BottomFull);
    tiffOptions->set_SlidesLayoutOptions(opts);

    //Saving to Tiff
    pres->Save(outPath, SaveFormat::Tiff, tiffOptions);
    
    //ExEnd:PresentationToTIFFWithCustomImagePixelFormat
}
