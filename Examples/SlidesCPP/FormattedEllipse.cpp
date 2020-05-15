#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FormattedEllipse()
{
	// ExStart:FormattedEllipse
	// The path to the documents directory.
	const String outPath = u"../out/FormattedEllipse_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	SharedPtr<IAutoShape> shape = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 50, 150, 150, 50);

	// Set the fill color of the rectangle shape
	shape->get_FillFormat()->set_FillType(FillType::Solid);
	shape->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Chocolate());

	// Apply some formatting on the line
	shape->get_LineFormat()->set_Style(LineStyle::ThickThin);
	shape->get_LineFormat()->set_Width(5);
	shape->get_LineFormat()->set_DashStyle(LineDashStyle::DashDot);

	shape->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FormattedEllipse
}
