#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IAutoShape.h>
#include <DOM/TextHighlightingOptions.h>
#include <DOM/AutoShape.h>
#include <DOM/ITextFrame.h>

#include "SlidesExamples.h"
using namespace Aspose::Slides;
using namespace System;

void HighlightText() {
	//ExStart:HighlightText
	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(u"SomePresentation.pptx");
	// highlighting all words 'important'
	(System::DynamicCast<Aspose::Slides::AutoShape> (presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightText(u"important", System::Drawing::Color::get_LightBlue());
	auto options = System::MakeObject<TextHighlightingOptions>();
	options->set_WholeWordsOnly(true);
	// highlighting all separate 'the' occurrences
	(System::DynamicCast <Aspose::Slides::AutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightText(u"the", System::Drawing::Color::get_Violet(), options);
	presentation->Save(u"../out/SomePresentation-out.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:HighlightText
}