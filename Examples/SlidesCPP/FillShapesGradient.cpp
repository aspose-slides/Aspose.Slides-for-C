#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FillShapesGradient()
{
	// ExStart:FillShapesGradient

	// The path to the documents directory.
	const String outPath = u"../out/FillShapesGradient_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 50, 150, 75, 150);
	
	// Apply some gradiant formatting to ellipse shape
	autoShape->get_FillFormat()->set_FillType(FillType::Gradient);
	autoShape->get_FillFormat()->get_GradientFormat()->set_GradientShape(GradientShape::Linear);

	// Set the Gradient Direction
	autoShape->get_FillFormat()->get_GradientFormat()->set_GradientDirection ( GradientDirection::FromCorner2);

	// Add two Gradiant Stops
	autoShape->get_FillFormat()->get_GradientFormat()->get_GradientStops()->Add(1.0f, PresetColor::Purple);
	autoShape->get_FillFormat()->get_GradientFormat()->get_GradientStops()->Add(0.0f, PresetColor::Red);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FillShapesGradient
}
