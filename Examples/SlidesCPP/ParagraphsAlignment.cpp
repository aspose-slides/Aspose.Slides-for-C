#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ParagraphsAlignment()
{
	// ExStart:ParagraphsAlignment
	// The path to the documents directory.
	const String outPath = u"../out/ParagraphsAlignment_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing the first and second placeholder in the slide and typecasting it as AutoShape
	SharedPtr<IShape> shape1 = slide->get_Shapes()->idx_get(0);
	SharedPtr<IShape> shape2 = slide->get_Shapes()->idx_get(1);

	SharedPtr<AutoShape> ashp1 = ExplicitCast<AutoShape>(shape1);
	SharedPtr<AutoShape> ashp2 = ExplicitCast<AutoShape>(shape2);

	SharedPtr<ITextFrame> tf1 = ashp1->get_TextFrame();
	SharedPtr<ITextFrame> tf2 = ashp2->get_TextFrame();

	// Change the text in both placeholders
	tf1->set_Text (u"Center Align by Aspose");
	tf2->set_Text(u"Center Align by Aspose");

	// Accessing the first Paragraph
	SharedPtr<IParagraph> para1 = tf1->get_Paragraphs()->idx_get(0);
	SharedPtr<IParagraph> para2 = tf2->get_Paragraphs()->idx_get(0);

	// Aligning the text paragraph to center
	para1->get_ParagraphFormat()->set_Alignment (TextAlignment::Center);
	para2->get_ParagraphFormat()->set_Alignment(TextAlignment::Center);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ParagraphsAlignment
}
