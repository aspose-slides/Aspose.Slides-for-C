#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FillShapesPattern()
{
	// ExStart:FillShapesPattern

	// The path tos the documents directory.
	const String outPath = u"../out/FillShapesPattern_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 75, 150);
	/*
	// Apply some pattern formatting to rectangle shape
	autoShape->get_FillFormat()->set_FillType(FillType::Pattern);
	autoShape->get_FillFormat()->get_PatternFormat()->set_PatternStyle(PatternStyle::Trellis);

	// Set the pattern back and fore colors
	autoShape->get_FillFormat()->get_PatternFormat()->get_BackColor()->set_Color ( Color::get_LightGray());
	autoShape->get_FillFormat()->get_PatternFormat()->get_ForeColor()->set_Color(Color::get_Yellow());
	*/
	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FillShapesPattern
}
