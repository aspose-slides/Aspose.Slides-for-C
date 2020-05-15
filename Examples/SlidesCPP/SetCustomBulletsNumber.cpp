#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void SetCustomBulletsNumber()
{
	//ExStart:SetCustomBulletsNumber
	// The path to the documents directory.
	const String outPath = u"../out/SetCustomBulletsNumber_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 200, 300);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	//Clearing exisiting default paragraph
	txtFrame->get_Paragraphs()->Clear();

	// First list
	SharedPtr<Paragraph> paragraph1 = MakeObject<Paragraph>();
	paragraph1->set_Text(u"bullet 2");
	paragraph1->get_ParagraphFormat()->set_Depth((short)4);
	paragraph1->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)2);
	paragraph1->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);
	txtFrame->get_Paragraphs()->Add(paragraph1);

	SharedPtr<Paragraph> paragraph2 = MakeObject<Paragraph>();
	paragraph2->set_Text(u"bullet 3");
	paragraph2->get_ParagraphFormat()->set_Depth((short)4);
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)3); 
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);  
	txtFrame->get_Paragraphs()->Add(paragraph2);

	// Second list
	SharedPtr<Paragraph> paragraph5 = MakeObject<Paragraph>();
	paragraph5->set_Text(u"bullet 5");
	paragraph5->get_ParagraphFormat()->set_Depth((short)4);
	paragraph5->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)5);
	paragraph5->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);
	txtFrame->get_Paragraphs()->Add(paragraph5);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetCustomBulletsNumber
}
