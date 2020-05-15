#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetHyperlinkColor()
{
	//ExStart:SetHyperlinkColor
	const String outPath = u"../out/Hyperlink-color-out.pptx";   
	SharedPtr<Presentation> presentation = System::MakeObject <Presentation>();

	SharedPtr<IAutoShape> shape1 = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 450, 50, false);
	shape1->AddTextFrame(u"This is a sample of colored hyperlink.");
	shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_HyperlinkClick(System::MakeObject <Hyperlink>(u"https://www.aspose.com/"));
	shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_HyperlinkClick()->set_ColorSource(HyperlinkColorSource::PortionFormat);
	shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());

	SharedPtr<IAutoShape> shape2 = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 200, 450, 50, false);
	shape2->AddTextFrame(u"This is a sample of usual hyperlink.");
	shape2->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_HyperlinkClick(System::MakeObject <Hyperlink>(u"https://www.aspose.com/"));

	presentation->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetHyperlinkColor
}
