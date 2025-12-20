#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ConvertToImage()
{
    //ExStart:ConvertToImage

    const String pptxFileName = Path::Combine(GetDataPath(), u"ConvertExample.pptx");
    const String outPathJpeg = Path::Combine(GetOutPath(), u"ConvertedToJpeg.jpg");
    const String outPathPng = Path::Combine(GetOutPath(), u"ConvertedToPng.png");
    const String outPathTiff = Path::Combine(GetOutPath(), u"ConvertedToTiff.tiff");

    auto pres = System::MakeObject<Presentation>(pptxFileName);
    LowCode::Convert::ToJpeg(pres, outPathJpeg);
    LowCode::Convert::ToPng(pres, outPathPng);
    LowCode::Convert::ToTiff(pres, outPathTiff);

    //ExEnd:ConvertToImage
}
