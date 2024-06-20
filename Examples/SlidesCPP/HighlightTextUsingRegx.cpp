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

    SharedPtr<TextHighlightingOptions> options = System::MakeObject<TextHighlightingOptions>();
    // highlighting all words with 10 symbols or longer
    SharedPtr<ITextFrame> textFrame = System::ExplicitCast<AutoShape>(presentation->get_Slide(0)->get_Shape(0))->get_TextFrame();
    textFrame->HighlightRegex(u"\\b[^\\s]{10,}\\b", System::Drawing::Color::get_LightGoldenrodYellow(), options);

    presentation->Save(u"../out/HighlightTextRegx-out.pptx", Export::SaveFormat::Pptx);
    //ExEnd:HighlightTextUsingRegx
}