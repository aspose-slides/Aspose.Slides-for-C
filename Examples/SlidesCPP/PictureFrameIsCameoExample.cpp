#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void PictureFrameIsCameoExample()
{
    // Path to source presentation
    const String presentationName = Path::Combine(GetDataPath(), u"PresCameo.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(presentationName);
    // Check if first picture frame is Cameo
    SharedPtr<PictureFrame> shape = AsCast<PictureFrame>(pres->get_Slide(0)->get_Shape(0));
    if (shape != nullptr)
    {
        Console::WriteLine(u"First picture is Cameo: {0}", shape->get_IsCameo());
    }

    // Check if third picture frame is Cameo
    shape = AsCast<PictureFrame>(pres->get_Slide(0)->get_Shape(2));
    if (shape != nullptr)
    {
        Console::WriteLine(u"Third picture is Cameo: {0}", shape->get_IsCameo());
    }
}
