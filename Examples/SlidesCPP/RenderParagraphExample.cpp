#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void RenderParagraphExample()
{
    //ExStart:RenderParagraphExample

    const String presentationName = Path::Combine(GetDataPath(), u"ModifyBuiltinProperties.pptx");

    auto pres = MakeObject<Presentation>(presentationName);
    auto slide = pres->get_Slide(0);

    int shapeIndex = 0;
    for (auto&& shape : slide->get_Shapes())
    {
        shapeIndex++;
        
        auto autoShape = System::AsCast<IAutoShape>(shape);
        if (autoShape == nullptr || autoShape->get_TextFrame() == nullptr)
            continue;

        int paragraphIndex = 0;
        for (auto&& paragraph : autoShape->get_TextFrame()->get_Paragraphs())
        {
            paragraphIndex++;
            String outFileName = Path::Combine(
                GetOutPath(),
                String::Format(u"shape{0}_paragraph{1}.png", shapeIndex, paragraphIndex));

            auto image = paragraph->GetImage(2.0f, 2.0f);
            image->Save(outFileName);
        }
    }

    //ExEnd:RenderParagraphExample
}
