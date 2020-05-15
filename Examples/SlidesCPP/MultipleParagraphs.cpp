#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void MultipleParagraphs()
{
	// ExStart:MultipleParagraphs
	// The path to the documents directory.
	const String outPath = u"../out/MultipleParagraphs_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	SharedPtr<ITextFrame> tf=ashp->AddTextFrame(u" ");

	// Accessing the first Paragraph
	SharedPtr<IParagraph> para0 = tf->get_Paragraphs()->idx_get(0);
	
	SharedPtr<Portion> port01 = MakeObject<Portion>();
	SharedPtr<Portion> port02 = MakeObject<Portion>();
	para0->get_Portions()->Add(port01);
	para0->get_Portions()->Add(port02);

	// Adding second Paragraph
	SharedPtr<Paragraph> para1 = MakeObject<Paragraph>();
	tf->get_Paragraphs()->Add(para1);
	SharedPtr<Portion> port10 = MakeObject<Portion>();
	SharedPtr<Portion> port11 = MakeObject<Portion>();
	SharedPtr<Portion> port12 = MakeObject<Portion>();
	para1->get_Portions()->Add(port10);
	para1->get_Portions()->Add(port11);
	para1->get_Portions()->Add(port12);

	// Adding third Paragraph
	SharedPtr<Paragraph> para2 = MakeObject<Paragraph>();
	tf->get_Paragraphs()->Add(para2);
	SharedPtr<Portion> port20 = MakeObject<Portion>();
	SharedPtr<Portion> port21 = MakeObject<Portion>();
	SharedPtr<Portion> port22 = MakeObject<Portion>();
	para2->get_Portions()->Add(port20);
	para2->get_Portions()->Add(port21);
	para2->get_Portions()->Add(port22);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tf->get_Paragraphs()->idx_get(i)->get_Portions()->idx_get(j)->set_Text(u"Portion_"+j);
			SharedPtr<IPortionFormat>format = tf->get_Paragraphs()->idx_get(i)->get_Portions()->idx_get(j)->get_PortionFormat();

			if (j == 0)
			{
				format->get_FillFormat()->set_FillType(FillType::Solid);
				format->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());
				format->set_FontBold(NullableBool::True);
				format->set_FontHeight(15);
			}
			else if (j == 1)
			{
				format->get_FillFormat()->set_FillType(FillType::Solid);
				format->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());
				format->set_FontBold(NullableBool::True);
				format->set_FontHeight(18);
			}
		}
	}

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:MultipleParagraphs
}
