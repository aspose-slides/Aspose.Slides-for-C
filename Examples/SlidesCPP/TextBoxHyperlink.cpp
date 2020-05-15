#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void TextBoxHyperlink()
{
	// ExStart:TextBoxHyperlink
	// The path to the documents directory.
	const String outPath = u"../out/TextBoxHyperlink_out.pptx";
	const String templatePath = u"../templates/DefaultFonts_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u" ");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(u"Aspose TextBox");
	// Set Hyperlink for the portion text
	SharedPtr<IHyperlinkManager> HypMan = portion->get_PortionFormat()->get_HyperlinkManager();
	HypMan->SetExternalHyperlinkClick(u"http://www.aspose.com");

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:TextBoxHyperlink
}
