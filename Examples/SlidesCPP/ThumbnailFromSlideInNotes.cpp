#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void ThumbnailFromSlideInNotes()
{
    //ExStart:ThumbnailFromSlideInNotes

    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"TestDeck_050.pptx");
    const System::String outPath = Path::Combine(GetOutPath(), u"Aspose_NotesSlide_out.png");

    // Instantiate Presentation class
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Access the first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Create a full scale image
    auto image = slide->GetImage(2, 2);
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:ThumbnailFromSlideInNotes
}
