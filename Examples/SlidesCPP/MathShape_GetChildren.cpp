#include "stdafx.h"
#include "SlidesExamples.h"


using namespace Aspose::Slides;
using namespace MathText;
using namespace System;
using namespace System::IO;

void ForEachMathElement(System::SharedPtr<IMathElement> root)
{
    for (SharedPtr<IMathElement> child : root->GetChildren())
    {
        auto mathText = ObjectExt::Is<MathematicalText>(child) ? String(u" : ") + DynamicCast<MathematicalText>(child)->get_Value() : u"";
        Console::WriteLine(ObjectExt::GetType(child).ToString() + mathText);

        //recursive
        ForEachMathElement(child);
    }
}

void MathShape_GetChildren()
{
    // Path for output presentation
    String outPptxFile = Path::Combine(GetOutPath(), u"MathShape_GetChildren_out.pptx");

    auto presentation = System::MakeObject<Presentation>();

    // Get first slide
    auto slide = presentation->get_Slides()->idx_get(0);

    // Create MathShape in the first slide
    auto mathShape = slide->get_Shapes()->AddMathShape(10.0f, 10.0f, 500.0f, 500.0f);
    // Create MathParagraph
    auto portion = mathShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0);
    auto mathParagraph = (System::DynamicCast_noexcept<MathPortion>(portion))->get_MathParagraph();

    // Create MathBlock
    auto mathText = System::MakeObject<MathematicalText>(u"F")
        ->Join(u"+")
        ->Join(System::MakeObject<MathematicalText>(u"1")->Divide(u"y"))
        ->Underbar();
    auto mathBlock = System::MakeObject<MathBlock>(mathText);

    // Add MathBlock to the MathParagraph
    mathParagraph->Add(mathBlock);

    // Print all elements of the mathBlock
    ForEachMathElement(mathBlock);

    presentation->Save(outPptxFile, Export::SaveFormat::Pptx);
}
