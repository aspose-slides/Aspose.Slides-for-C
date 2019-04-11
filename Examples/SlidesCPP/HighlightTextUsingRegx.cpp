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

void HighlightTextUsingRegx() {
	
	//ExStart:HighlightTextUsingRegx
		System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(u"SomePresentation.pptx");
		System::SharedPtr <TextHighlightingOptions> options = System::MakeObject<TextHighlightingOptions>();
		// highlighting all words with 10 symbols or longer
		(System::DynamicCast <Aspose::Slides::AutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)))->get_TextFrame()->HighlightRegex(u"\\b[^\\s]{10,}\\b", System::Drawing::Color::get_LightGoldenrodYellow(), options);
		presentation->Save(u"../out/SomePresentation-out.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
		//ExEnd:HighlightTextUsingRegx
}