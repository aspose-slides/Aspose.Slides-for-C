#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void HighlightText()
{
	//ExStart:HighlightText
	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(u"../templates/HighlightText.pptx");
	// highlighting all words 'important'
	(System::ExplicitCast<AutoShape> (presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightText(u"important", System::Drawing::Color::get_LightBlue());
	auto options = System::MakeObject<TextHighlightingOptions>();
	options->set_WholeWordsOnly(true);
	// highlighting all separate 'the' occurrences
	(System::ExplicitCast <AutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightText(u"the", System::Drawing::Color::get_Violet(), options);
	presentation->Save(u"../out/HighlightText-out.pptx", Export::SaveFormat::Pptx);
	//ExEnd:HighlightText
}