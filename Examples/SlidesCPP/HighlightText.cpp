#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void HighlightText()
{
    //ExStart:HighlightText
    const String dataPath = Path::Combine(GetDataPath(), u"HighlightText.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"HighlightText-out.pptx");

    SharedPtr<Presentation> presentation = MakeObject<Presentation>(dataPath);
    SharedPtr<ITextFrame> textFrame = System::ExplicitCast<AutoShape>(presentation->get_Slide(0)->get_Shape(0))->get_TextFrame();

    // highlighting all words 'important'
    textFrame->HighlightText(u"important", System::Drawing::Color::get_LightBlue());

    auto options = MakeObject<TextHighlightingOptions>();
    options->set_WholeWordsOnly(true);

    // highlighting all separate 'the' occurrences
    textFrame->HighlightText(u"the", System::Drawing::Color::get_Violet(), options);

    presentation->Save(outPath, Export::SaveFormat::Pptx);
    //ExEnd:HighlightText
}