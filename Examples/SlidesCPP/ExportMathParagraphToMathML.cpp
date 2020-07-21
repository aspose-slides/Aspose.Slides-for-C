#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace MathText;

using namespace System;

void ExportMathParagraphToMathML()
{
    //ExStart:ExportMathParagraphToMathML
    String outFileName = Path::Combine(GetOutPath(), u"mathml.xml");
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<IAutoShape> autoShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddMathShape(0, 0, 500, 50);
    SharedPtr<IMathParagraph> mathParagraph = (System::DynamicCast<MathPortion>(autoShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)))->get_MathParagraph();

    SharedPtr<IMathBlock> mathBlock = System::MakeObject<MathematicalText>(u"a")
            ->SetSuperscript(u"2")
        ->Join(u"+")
        ->Join(System::MakeObject<MathematicalText>(u"b")
            ->SetSuperscript(u"2"))
        ->Join(u"=")
        ->Join(System::MakeObject<MathematicalText>(u"c")
            ->SetSuperscript(u"2"));

    mathParagraph->Add(mathBlock);

    SharedPtr<Stream> stream = System::MakeObject<FileStream>(outFileName, FileMode::Create);        
    mathParagraph->WriteAsMathMl(stream);
    //ExEnd:ExportMathParagraphToMathML
}
