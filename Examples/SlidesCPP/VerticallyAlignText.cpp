#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void VerticallyAlignText()
{

	// ExStart:VerticallyAlignText
	// The path to the documents directory.
	const String outPath = u"../out/VerticallyAlignText_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	ArrayPtr<double> dblCols = System::MakeObject<Array<double>>(4, 70);
	ArrayPtr<double> dblRows = System::MakeObject<Array<double>>(4, 70);

	// Add table shape to slide
	SharedPtr<ITable> table = islide->get_Shapes()->AddTable(100, 50, dblCols, dblRows);

	// Set the text of the first column of second row
	table->idx_get(1, 0)->get_TextFrame()->set_Text(u"10");
	table->idx_get(2, 0)->get_TextFrame()->set_Text(u"20");
	table->idx_get(3, 0)->get_TextFrame()->set_Text(u"30");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = table->idx_get(0, 0)->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(u"Text here");
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	// Aligning the text vertically
	SharedPtr<ICell> cell = table->idx_get(0, 0);
	cell->set_TextAnchorType(TextAnchorType::Center);
	cell->set_TextVerticalType ( TextVerticalType::Vertical270);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:VerticallyAlignText
}
