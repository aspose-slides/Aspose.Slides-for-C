#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void ThumbnailFromSlide()
{
    //ExStart:ThumbnailFromSlide

    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"TestDeck_050.pptx");
    const System::String outPath = Path::Combine(GetOutPath(), u"Aspose_out.png");

    // Instantiate Presentation class
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Access the first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    System::SharedPtr<IImage> image = slide->GetImage(1, 1);
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:ThumbnailFromSlide
}
