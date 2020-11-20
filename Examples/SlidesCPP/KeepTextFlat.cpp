#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

using System::Drawing::Imaging::ImageFormat;

void KeepTextFlat()
{
    // ExStart:KeepTextFlat
    String pptxFileName = Path::Combine(GetDataPath(), u"KeepTextFlat.pptx");
    String resultPath = Path::Combine(GetOutPath(), u"KeepTextFlat_out.png");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);

    auto shape1 = System::DynamicCast_noexcept<AutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    auto shape2 = System::DynamicCast_noexcept<AutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(1));

    shape1->get_TextFrame()->get_TextFrameFormat()->set_KeepTextFlat(false);
    shape2->get_TextFrame()->get_TextFrameFormat()->set_KeepTextFlat(true);

    pres->get_Slides()->idx_get(0)->GetThumbnail(4 / 3.f, 4 / 3.f)->Save(resultPath, ImageFormat::get_Png());
    // ExEnd:KeepTextFlat
}
