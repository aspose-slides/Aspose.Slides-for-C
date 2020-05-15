#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ParagraphIndent()
{
	// ExStart:ParagraphBullets
	// The path to the documents directory.
	const String outPath = u"../out/ParagraphIndent.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"This is first line \rThis is second line \rThis is third line");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Set the text to fit the shape
	txtFrame->get_TextFrameFormat()->set_AutofitType ( TextAutofitType::Shape);

	// Hide the lines of the Rectangle
	ashp->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);

	// Setting paragraph bullet style and symbol
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');
	
	paragraph->get_ParagraphFormat()->set_Alignment( TextAlignment::Left);

	// Setting bullet indent
	paragraph->get_ParagraphFormat()->set_Depth(2);
	paragraph->get_ParagraphFormat()->set_Indent(30);


	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph2 = txtFrame->get_Paragraphs()->idx_get(1);

	// Setting paragraph bullet style and symbol
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');

	paragraph2->get_ParagraphFormat()->set_Alignment(TextAlignment::Left);

	// Setting bullet indent
	paragraph2->get_ParagraphFormat()->set_Depth(2);
	paragraph2->get_ParagraphFormat()->set_Indent(40);

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph3 = txtFrame->get_Paragraphs()->idx_get(2);

	// Setting paragraph bullet style and symbol
	paragraph3->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph3->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');

	paragraph3->get_ParagraphFormat()->set_Alignment(TextAlignment::Left);

	// Setting bullet indent
	paragraph3->get_ParagraphFormat()->set_Depth(2);
	paragraph3->get_ParagraphFormat()->set_Indent(50);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ParagraphIndent
}
