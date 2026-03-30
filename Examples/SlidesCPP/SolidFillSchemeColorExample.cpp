#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SolidFillSchemeColorExample()
{
    //ExStart:SolidFillSchemeColorExample

    const String presentationPath = Path::Combine(GetDataPath(), u"FillColor.pptx");

    auto presentation = MakeObject<Presentation>(presentationPath);
    for (auto&& shape : presentation->get_Slide(0)->get_Shapes())
    {
        if (ObjectExt::Is<AutoShape>(shape))
        {
            auto fillFormat = ExplicitCast<AutoShape>(shape)->get_TextFrame()->get_Paragraph(0)->get_Portion(0)->get_PortionFormat()->get_FillFormat()->GetEffective();
            Console::WriteLine(u"Fill color: {0}", fillFormat->get_SolidFillColor());
            Console::WriteLine(u"Fill scheme color: {0}", fillFormat->get_SolidFillSchemeColor());
        }
    }

    //ExEnd:SolidFillSchemeColorExample
}
