#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void LineSpacing()
{
	// ExStart:LineSpacing
	// The path to the documents directory.
	const String outPath = u"../out/LineSpacing_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing the first and second placeholder in the slide and typecasting it as AutoShape
	SharedPtr<ITextFrame> tf1 = (ExplicitCast<Aspose::Slides::AutoShape>(slide->get_Shapes()->idx_get(0)))->get_TextFrame();

	// Accessing the first Paragraph
	SharedPtr<IParagraph> para1 = tf1->get_Paragraphs()->idx_get(0);

	// Set properties of Paragraph
	para1->get_ParagraphFormat()->set_SpaceWithin ( 80);
	para1->get_ParagraphFormat()->set_SpaceBefore ( 40);
	para1->get_ParagraphFormat()->set_SpaceAfter ( 40);

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:LineSpacing
}
