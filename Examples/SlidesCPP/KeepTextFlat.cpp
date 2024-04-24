#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void KeepTextFlat()
{
    // ExStart:KeepTextFlat
    const System::String pptxFileName = Path::Combine(GetDataPath(), u"KeepTextFlat.pptx");
    const System::String resultPath = Path::Combine(GetOutPath(), u"KeepTextFlat_out.png");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);

    auto shape1 = System::AsCast<AutoShape>(pres->get_Slide(0)->get_Shape(0));
    auto shape2 = System::AsCast<AutoShape>(pres->get_Slide(0)->get_Shape(1));

    shape1->get_TextFrame()->get_TextFrameFormat()->set_KeepTextFlat(false);
    shape2->get_TextFrame()->get_TextFrameFormat()->set_KeepTextFlat(true);

    const float scale = 4 / 3.f;
    System::SharedPtr<IImage> image = pres->get_Slides()->idx_get(0)->GetImage(scale, scale);
    image->Save(resultPath, ImageFormat::Png);
    // ExEnd:KeepTextFlat
}
