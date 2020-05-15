#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void CreateGroupShape()
{
	// ExStart:CreateGroupShape

	// The path to the documents directory.
	const String outPath = u"../out/CreateGroupShape_out.pptx";
	const String templatePath = u"../templates/Source Frame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> slideShapes = slide->get_Shapes();

	// Adding a group shape to the slide 
	SharedPtr<IGroupShape> groupShape = slideShapes->AddGroupShape();

	// Adding shapes inside added group shape 
	groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 300, 100, 100, 100);
	groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 500, 100, 100, 100);
	groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 300, 300, 100, 100);
	groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 500, 300, 100, 100);

	// Adding group shape frame 
	groupShape->set_Frame( MakeObject<ShapeFrame>(100, 300, 500, 40, NullableBool::False, NullableBool::False, 0));

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CreateGroupShape
}
