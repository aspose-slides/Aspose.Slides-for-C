#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RotatingShapes()
{
	// ExStart:RotatingShapes

	// The path to the documents directory.
	const String outPath = u"../out/RotatingShapes_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	SharedPtr<IAutoShape> autoShape1 = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 50, 40, 150, 50);

	// Rotate the shape to 90 degree
	autoShape1->set_Rotation(90);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:RotatingShapes
}
