#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ReplacingText()
{
	// ExStart:ReplacingText
	// The path to the documents directory.
	const String outPath = u"../out/ReplacingText_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing the first and second placeholder in the slide and typecasting it as AutoShape
	SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(0);
	SharedPtr<AutoShape> ashp = DynamicCast<AutoShape>(shape);

	SharedPtr<ITextFrame> textframe = ashp->get_TextFrame();

	textframe->set_Text(u"This is Placeholder");
	
	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ReplacingText
}
