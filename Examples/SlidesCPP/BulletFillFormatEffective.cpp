#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;
using namespace System::IO;

void BulletFillFormatEffective()
{
    // ExStart:BulletFillFormatEffective
    String pptxFile = Path::Combine(GetDataPath(), u"BulletData.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFile);

    SharedPtr<AutoShape> autoShape = System::ExplicitCast<AutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    for (auto para : autoShape->get_TextFrame()->get_Paragraphs())
    {
        SharedPtr<IBulletFormatEffectiveData> bulletFormatEffective = para->get_ParagraphFormat()->get_Bullet()->GetEffective();
        Console::WriteLine(String(u"Bullet type: ") + ObjectExt::ToString(bulletFormatEffective->get_Type()));
        if (bulletFormatEffective->get_Type() != BulletType::None)
        {
            Console::WriteLine(String(u"Bullet fill type: ") + ObjectExt::ToString(bulletFormatEffective->get_FillFormat()->get_FillType()));
            switch (bulletFormatEffective->get_FillFormat()->get_FillType())
            {
                case FillType::Solid:
                    Console::WriteLine(String(u"Solid fill color: ") + bulletFormatEffective->get_FillFormat()->get_SolidFillColor());
                    break;

                case FillType::Gradient:
                {
                    Console::WriteLine(String(u"Gradient stops count: ") + bulletFormatEffective->get_FillFormat()->get_GradientFormat()->get_GradientStops()->get_Count());
                    for (auto gradStop : bulletFormatEffective->get_FillFormat()->get_GradientFormat()->get_GradientStops())
                    {
                        Console::WriteLine(Convert::ToString(gradStop->get_Position()) + u": " + gradStop->get_Color());
                    }
                    break;
                }

                case FillType::Pattern:
                    Console::WriteLine(String(u"Pattern style: ") + ObjectExt::ToString(bulletFormatEffective->get_FillFormat()->get_PatternFormat()->get_PatternStyle()));
                    Console::WriteLine(String(u"Fore color: ") + bulletFormatEffective->get_FillFormat()->get_PatternFormat()->get_ForeColor());
                    Console::WriteLine(String(u"Back color: ") + bulletFormatEffective->get_FillFormat()->get_PatternFormat()->get_BackColor());
                    break;

                default:
                    break;
            }
        }

        Console::WriteLine();
    }
    // ExEnd:BulletFillFormatEffective
}
