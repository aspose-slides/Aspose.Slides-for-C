#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void HighlightTextUsingRegx()
{
    //ExStart:HighlightTextUsingRegx
    const String dataPath = Path::Combine(GetDataPath(), u"HighlightTextRegx.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"HighlightTextRegx-out.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(dataPath);

    SharedPtr<ITextFrame> textFrame = System::ExplicitCast<AutoShape>(presentation->get_Slide(0)->get_Shape(0))->get_TextFrame();
    textFrame->HighlightRegex(u"\\b[^\\s]{5,}\\b", System::Drawing::Color::get_LightGoldenrodYellow(), nullptr);

    presentation->Save(outPath, Export::SaveFormat::Pptx);
    //ExEnd:HighlightTextUsingRegx
}