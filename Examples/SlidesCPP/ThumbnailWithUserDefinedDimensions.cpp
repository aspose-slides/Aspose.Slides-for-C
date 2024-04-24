#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void ThumbnailWithUserDefinedDimensions()
{
    //ExStart:ThumbnailWithUserDefinedDimensions

    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"TestDeck_050.pptx");
    const System::String outPath = Path::Combine(GetOutPath(), u"Aspose_UserDefinedDimension_Slide_out.png");

    // Instantiate Presentation class
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Access the first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // User defined dimension
    int desiredX = 1200;
    int desiredY = 800;

    // Getting scaled value  of X and Y
    float scaleX = (float)(1.0 / pres->get_SlideSize()->get_Size().get_Width()) * desiredX;
    float scaleY = (float)(1.0 / pres->get_SlideSize()->get_Size().get_Height()) * desiredY;

    // Create a custom scale image
    auto image = slide->GetImage(scaleX, scaleY);
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:ThumbnailWithUserDefinedDimensions
}
