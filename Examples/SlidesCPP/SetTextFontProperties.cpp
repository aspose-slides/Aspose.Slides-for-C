#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void SetTextFontProperties()
{
	// ExStart:SetTextFontProperties
	// The path to the documents directory.
	const String outPath = u"../out/SetTextFontProperties_out.pptx";
	const String templatePath = u"../templates/DefaultFonts_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"Aspose TextBox");

	ashp->get_FillFormat()->set_FillType(FillType::NoFill);

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	txtFrame->get_TextFrameFormat()->set_AutofitType(TextAutofitType::Shape);

	SharedPtr<FontData> destFont = MakeObject<FontData>(u"Times New Roman");

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion>portion = paragraph->get_Portions()->idx_get(0);

	portion->get_PortionFormat()->set_LatinFont(destFont);
	// Set font to Bold
	portion->get_PortionFormat()->set_FontBold(NullableBool::True);

	// Set font to Italic
	portion->get_PortionFormat()->set_FontItalic(NullableBool::True);

	// Set text to underline
	portion->get_PortionFormat()->set_FontUnderline ( TextUnderlineType::Single);

	// Set the Height of the Font
	portion->get_PortionFormat()->set_FontHeight ( 25);

	// Set font color
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:SetTextFontProperties
}
