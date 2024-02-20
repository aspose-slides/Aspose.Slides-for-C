#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace MathText;

using namespace System::IO;

void ExportMathParagraphToLatex()
{
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Add a math shape.
    auto autoShape = pres->get_Slide(0)->get_Shapes()->AddMathShape(0.0f, 0.0f, 500.0f, 50.0f);

    // Get a math paragraph.
    auto mathParagraph = (System::ExplicitCast<MathPortion>(
        autoShape->get_TextFrame()->get_Paragraph(0)->get_Portion(0)))->get_MathParagraph();

    // Add a formula.
    mathParagraph->Add(
        System::MakeObject<MathematicalText>(u"a")->SetSuperscript(u"2")->Join(u"+")->Join(
            System::MakeObject<MathematicalText>(u"b")->SetSuperscript(u"2"))->Join(u"=")->Join(
            System::MakeObject<MathematicalText>(u"c")->SetSuperscript(u"2")));

    // Get formula string in Latex format.
    System::String latexString = mathParagraph->ToLatex();

    // Output the resulting Latex string to the console.
    System::Console::WriteLine(System::String::Format(u"Latex representation of a math paragraph: \"{0}\"", latexString));
}
