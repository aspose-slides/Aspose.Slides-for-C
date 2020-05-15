#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FontFamilySetting()
{
	// ExStart:FontFamilySetting
	// The path to the documents directory.
	const String outPath = u"../out/FontFamilySetting_out.pptx";

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
	
	//Get portion format
	SharedPtr<IPortionFormat> pf = portion->get_PortionFormat();
	
	// Set the Font for the Portion
	pf->set_LatinFont(MakeObject<FontData>(u"Times New Roman"));

	// Set Bold property of the Font
	pf->set_FontBold (NullableBool::True);

	// Set Italic property of the Font
	pf->set_FontItalic(NullableBool::True);

	// Set Underline property of the Font
	pf->set_FontUnderline(TextUnderlineType::Single);

	// Set the Height of the Font
	pf->set_FontHeight (25);

	// Set the color of the Font
	pf->get_FillFormat()->set_FillType(FillType::Solid);
	pf->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:FontFamilySetting
}
