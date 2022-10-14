#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void MutilevelBullets()
{
	// ExStart:MutilevelBullets
	// The path to the documents directory.
	const String outPath = u"../out/MutilevelBullets_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape> ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 200, 300);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();
	
	//Clearing exisiting default paragraph
	txtFrame->get_Paragraphs()->Clear();

	// Create the first level bullet paragraph
	SharedPtr<Paragraph> Para1 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para1 = ExplicitCast<IParagraph>(Para1);
	para1->set_Text(u"Content");
	// Setting paragraph bullet style 
	para1->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para1->get_ParagraphFormat()->get_Bullet()->set_Char(Convert::ToChar(8226));
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para1->get_ParagraphFormat()->set_Depth(0);

	// Create the second level bullet paragraph
	SharedPtr<Paragraph> Para2 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para2 = ExplicitCast<IParagraph>(Para2);
	para2->set_Text(u"Second level");
	// Setting paragraph bullet style 
	para2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para2->get_ParagraphFormat()->get_Bullet()->set_Char('-');
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para2->get_ParagraphFormat()->set_Depth(1);

	// Create the third level bullet paragraph
	SharedPtr<Paragraph> Para3 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para3 = ExplicitCast<IParagraph>(Para3);
	para3->set_Text(u"Content");
	// Setting paragraph bullet style 
	para3->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para3->get_ParagraphFormat()->get_Bullet()->set_Char(Convert::ToChar(8226));
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para3->get_ParagraphFormat()->set_Depth(0);

	// Create the fourth level bullet paragraph
	SharedPtr<Paragraph> Para4 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para4 = ExplicitCast<IParagraph>(Para4);
	para4->set_Text(u"Fourth level");
	// Setting paragraph bullet style 
	para4->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para4->get_ParagraphFormat()->get_Bullet()->set_Char('-');
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para4->get_ParagraphFormat()->set_Depth(3);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:MutilevelBullets
}
