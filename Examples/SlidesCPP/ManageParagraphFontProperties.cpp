#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ManageParagraphFontProperties()
{
	// ExStart:ManageParagraphFontProperties
	// The path to the documents directory.
	const String outPath = u"../out/ManageParagraphFontProperties_out.pptx";
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

	// Accessing the first Paragraph
	SharedPtr<IParagraph> para1 = tf1->get_Paragraphs()->idx_get(0);
	SharedPtr<IParagraph> para2 = tf2->get_Paragraphs()->idx_get(0);

	// Justify the paragraph
	para2->get_ParagraphFormat()->set_Alignment (TextAlignment::JustifyLow);

	// Accessing the first portion
	SharedPtr<IPortion> port1 = para1->get_Portions()->idx_get(0);
	SharedPtr<IPortion> port2 = para2->get_Portions()->idx_get(0);

	// Define new fonts
	SharedPtr<IFontData> fd1 = MakeObject<FontData>(u"Elephant");
	SharedPtr<IFontData> fd2 = MakeObject<FontData>(u"Castellar");

	// Assign new fonts to portion
	port1->get_PortionFormat()->set_LatinFont(fd1);
	port2->get_PortionFormat()->set_LatinFont(fd2);

	// Set font to Bold
	port1->get_PortionFormat()->set_FontBold(NullableBool::True);
	port2->get_PortionFormat()->set_FontBold(NullableBool::True);

	// Set font to Italic
	port1->get_PortionFormat()->set_FontItalic(NullableBool::True);
	port2->get_PortionFormat()->set_FontItalic(NullableBool::True);

	// Set font color
	port1->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	port1->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Purple());
	port2->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	port2->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Peru());

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ManageParagraphFontProperties
}
