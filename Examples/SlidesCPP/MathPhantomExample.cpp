#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace MathText;
using namespace System;
using namespace IO;
using namespace Collections::Generic;

void MathPhantomExample()
{
    // ExStart:MathPhantomExample

    // Path for output presentation
    const String outPptxFile = Path::Combine(GetOutPath(), u"MathPhantom_out.pptx");

    auto pres = MakeObject<Presentation>();
    SharedPtr<IAutoShape> autoShape = pres->get_Slide(0)->get_Shapes()->AddMathShape(0, 0, 500, 50);
    SharedPtr<IMathParagraph> mathParagraph = ExplicitCast<MathPortion>(autoShape->get_TextFrame()->get_Paragraph(0)->get_Portion(0))->get_MathParagraph();

    auto eq1 = MakeObject<MathematicalText>(u"eq1");
    auto eq2 = MakeObject<MathematicalText>(u"eq2");
    // Create phantom math object
    auto phant = MakeObject<MathPhantom>(MakeObject<MathFraction>(MakeObject<MathematicalText>(u"1"), MakeObject<MathematicalText>(u"2")));
    phant->set_Show(false);
    phant->set_ZeroAsc(true);
    auto first = MakeObject<MathematicalText>(u"    (1)");
    auto sect = MakeObject<MathematicalText>(u"    (2)");
    auto second = MakeObject<MathematicalText>()->Join(phant)->Join(sect);
    auto nums = MakeObject<MathArray>(MakeArray<SharedPtr<IMathElement>>({ first, second }));
    auto subArr = MakeArray<SharedPtr<IMathElement>>({ eq1, eq2 });
    auto arr = MakeObject<MathArray>(subArr);
    auto eqs = MakeObject<MathDelimiter>(arr);
    eqs->set_BeginningCharacter('{');
    eqs->set_EndingCharacter('\0');
    auto wholeBlock = MakeObject<MathematicalText>()->Join(eqs)->Join(u" ")->Join(ExplicitCast<IMathElement>(nums));
    mathParagraph->Add(wholeBlock);

    pres->Save(outPptxFile, SaveFormat::Pptx);

    // ExEnd:MathPhantomExample
}
