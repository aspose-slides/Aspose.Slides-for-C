#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddingSuperscriptAndSubscriptTextInTextFrame()
{
	// ExStart:AddingSuperscriptAndSubscriptTextInTextFrame
	// The path to the documents directory.
	const String outPath = u"../out/AddingSuperscriptAndSubscriptTextInTextFrame_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 300, 300);

	// Add TextFrame to the Rectangle
	SharedPtr<ITextFrame> tf = ashp->AddTextFrame(String::Empty);

	tf->get_Paragraphs()->Clear();

	// Adding the first Paragraph
	SharedPtr<Paragraph> superPar = MakeObject<Paragraph>();
	SharedPtr<Portion> portion1 = MakeObject<Portion>(u"SlideTitle");
	superPar->get_Portions()->Add(portion1);

	SharedPtr<Portion> superPortion = MakeObject<Portion>();
	superPortion->get_PortionFormat()->set_Escapement(30);
	superPortion->set_Text(u"TM");
	superPar->get_Portions()->Add(superPortion);

	// Adding the first Paragraph
	SharedPtr<Paragraph> subPar = MakeObject<Paragraph>();
	SharedPtr<Portion> portion2 = MakeObject<Portion>(u"a");
	subPar->get_Portions()->Add(portion2);

	SharedPtr<Portion> subPortion = MakeObject<Portion>();
	subPortion->get_PortionFormat()->set_Escapement(-25);
	subPortion->set_Text(u"i");
	subPar->get_Portions()->Add(subPortion);

	//Adding to text frame
	ashp->get_TextFrame()->get_Paragraphs()->Add(superPar);
	ashp->get_TextFrame()->get_Paragraphs()->Add(subPar);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:AddingSuperscriptAndSubscriptTextInTextFrame
}
