#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FormatJoinStyles()
{
	// ExStart:FormatJoinStyles
	// The path to the documents directory.
	const String outPath = u"../out/FormatJoinStyles_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	SharedPtr<IAutoShape> shape1 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 150, 75);
	SharedPtr<IAutoShape> shape2 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 300, 100, 150, 75);
	SharedPtr<IAutoShape> shape3 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 250, 150, 75);

	// Set the fill color of the rectangle shape
	shape1->get_FillFormat()->set_FillType(FillType::Solid);
	shape1->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape1->get_LineFormat()->set_Width(15);
	shape1->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape1->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Set the fill color of the rectangle shape
	shape2->get_FillFormat()->set_FillType(FillType::Solid);
	shape2->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape2->get_LineFormat()->set_Width(15);
	shape2->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape2->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());


	// Set the fill color of the rectangle shape
	shape3->get_FillFormat()->set_FillType(FillType::Solid);
	shape3->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape3->get_LineFormat()->set_Width(15);
	shape3->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape3->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Set the Join Style
	shape2->get_LineFormat()->set_JoinStyle(LineJoinStyle::Miter);
	shape2->get_LineFormat()->set_JoinStyle(LineJoinStyle::Bevel);
	shape3->get_LineFormat()->set_JoinStyle(LineJoinStyle::Round);

	// Add text to each rectangle
	shape1->get_TextFrame()->set_Text(u"This is Miter Join Style");
	shape2->get_TextFrame()->set_Text(u"This is Bevel Join Style");
	shape3->get_TextFrame()->set_Text(u"This is Round Join Style");

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FormatJoinStyles
}
