#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void EndParaGraphProperties()
{
	// ExStart:EndParaGraphProperties
	// The path to the documents directory.
	const String outPath = u"../out/EndParaGraphProperties_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 300, 300);

	// Add TextFrame to the Rectangle
	SharedPtr<ITextFrame> tf = ashp->AddTextFrame(String::Empty);

	// Adding the first Paragraph
	//SharedPtr<IParagraph> para1 = tf->get_Paragraphs()->idx_get(0);

	SharedPtr<Paragraph> para1 = MakeObject<Paragraph>();
	SharedPtr<Portion> port01 = MakeObject<Portion>(u"Sample text");

	para1->get_Portions()->Add(port01);

	// Adding the second Paragraph
	SharedPtr<Paragraph> para2 = MakeObject<Paragraph>();
	SharedPtr<Portion> port02 = MakeObject<Portion>(u"Sample text 2");

	para2->get_Portions()->Add(port02);

	SharedPtr<PortionFormat> endParagraphPortionFormat = MakeObject<PortionFormat>();
	endParagraphPortionFormat->set_FontHeight ( 48);
	endParagraphPortionFormat->set_LatinFont ( MakeObject< FontData>(u"Times New Roman"));
	para2->set_EndParagraphPortionFormat(endParagraphPortionFormat);

	ashp->get_TextFrame()->get_Paragraphs()->Add(para1);
	ashp->get_TextFrame()->get_Paragraphs()->Add(para2);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:EndParaGraphProperties
}
