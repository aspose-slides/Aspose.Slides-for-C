#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ImageQualityExample()
{
    //ExStart:ImageQualityExample

    // Path for source presentation
    const String pptxPath = Path::Combine(GetDataPath(), u"ImageQuality.pptx");
    // Out path
    const String imagePath = Path::Combine(GetOutPath(), u"ImageQuality-out.jpg");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxPath);
    SharedPtr<IImage> image = pres->get_Image(0)->get_Image();

    // Saves the first image to the memory stream in JPEG format with quality 80.
    SharedPtr<MemoryStream> ms = MakeObject<MemoryStream>();
    image->Save(ms, ImageFormat::Jpeg, 80);

    // Saves the first image to the file in JPEG format with high quality.
    image->Save(imagePath, ImageFormat::Jpeg, 100);

    //ExEnd:ImageQualityExample
}
