#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void RotatingText()
{
	// ExStart:RotatingText
	// The path to the documents directory.
	const String outPath = u"../out/RotatingText.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"");

	ashp->get_FillFormat()->set_FillType(FillType::NoFill);

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	txtFrame->get_TextFrameFormat()->set_TextVerticalType(TextVerticalType::Vertical270);

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion>portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text (u"A quick brown fox jumps over the lazy dog. A quick brown fox jumps over the lazy dog.");
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:RotatingText
}
