#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace MathText;
using namespace System;
using namespace System::IO;

void AddMathematicalShape()
{
    //ExStart:AddMathematicalShape
    //Path for output presentation
    const String outpptxFile = Path::Combine(GetOutPath(), u"MathematicalShape_out.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create a new AutoShape of the type Rectangle to host mathematical content inside and adds it to the end of the collection.
    SharedPtr<IAutoShape> mathShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddMathShape(10.0f, 10.0f, 100.0f, 25.0f);

    // Cteate mathematical paragraph that is a container for mathematical blocks.
    SharedPtr<IMathParagraph> mathParagraph = (System::DynamicCast<MathPortion>(mathShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)))->get_MathParagraph();

    // Create mathematical expression as an instance of mathematical text that contained within a MathParagraph.
    SharedPtr<IMathBlock> mathBlock = System::MakeObject<MathematicalText>(u"c")
    ->SetSuperscript(u"2")
    ->Join(u"=")
    ->Join(System::MakeObject<MathematicalText>(u"a")
        ->SetSuperscript(u"2"))
    ->Join(u"+")
    ->Join(System::MakeObject<MathematicalText>(u"b")
        ->SetSuperscript(u"2"));

    // Add mathematical expression to the mathematical paragraph.
    mathParagraph->Add(mathBlock);

    pres->Save(outpptxFile, Export::SaveFormat::Pptx);
    // ExEnd:AddMathematicalShape
}
