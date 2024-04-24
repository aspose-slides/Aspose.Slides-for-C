#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;
using namespace System::Drawing;

void CreateScalingFactorThumbnail()
{
    // ExStart:CreateScalingFactorThumbnail

    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"CreateScalingFactorThumbnail_out.png");
    const System::String templatePath = Path::Combine(GetDataPath(), u"HelloWorld.pptx");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    auto image = pres->get_Slide(0)->get_Shape(0)->GetImage(ShapeThumbnailBounds::Shape, 2, 2);

    // Save the image to disk in PNG format
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:CreateScalingFactorThumbnail
}
