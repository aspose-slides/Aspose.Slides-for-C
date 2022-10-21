#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void HighlightTextUsingRegx()
{	
	//ExStart:HighlightTextUsingRegx
	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(u"../templates/HighlightTextRegx.pptx");
	SharedPtr<TextHighlightingOptions> options = System::MakeObject<TextHighlightingOptions>();
	// highlighting all words with 10 symbols or longer
	(System::ExplicitCast <AutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightRegex(u"\\b[^\\s]{10,}\\b", System::Drawing::Color::get_LightGoldenrodYellow(), options);
	presentation->Save(u"../out/HighlightTextRegx-out.pptx", Export::SaveFormat::Pptx);
	//ExEnd:HighlightTextUsingRegx
}