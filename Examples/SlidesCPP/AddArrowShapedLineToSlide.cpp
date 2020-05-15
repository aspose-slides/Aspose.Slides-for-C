#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void AddArrowShapedLineToSlide()
{
	// ExStart:AddArrowShapedLineToSlide
	// The path to the documents directory.
	const String outPath = u"../out/AddArrowShapedLineToSlide_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	SharedPtr<IAutoShape> shape = slide->get_Shapes()->AddAutoShape(ShapeType::Line, 50, 150, 300, 0);

	// Apply some formatting on the line
	shape->get_LineFormat()->set_Style(LineStyle::ThickBetweenThin);
	shape->get_LineFormat()->set_Width(10);

	shape->get_LineFormat()->set_DashStyle(LineDashStyle::DashDot);

	shape->get_LineFormat()->set_BeginArrowheadLength(LineArrowheadLength::Short);
	shape->get_LineFormat()->set_BeginArrowheadStyle(LineArrowheadStyle::Oval);

	shape->get_LineFormat()->set_EndArrowheadLength(LineArrowheadLength::Long);
	shape->get_LineFormat()->set_EndArrowheadStyle(LineArrowheadStyle::Triangle);

	shape->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Maroon());

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddArrowShapedLineToSlide
}
