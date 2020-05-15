#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void Apply3DRotationEffectOnShape()
{
	// ExStart:Apply3DRotationEffectOnShape

	// The path to the documents directory.
	const String outPath = u"../out/Apply3DRotationEffectOnShape_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 30, 30, 200, 200);

	autoShape->get_ThreeDFormat()->set_Depth (6);
	autoShape->get_ThreeDFormat()->get_Camera()->SetRotation(40, 35, 20);
	autoShape->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::IsometricLeftUp);
	autoShape->get_ThreeDFormat()->get_LightRig()->set_LightType ( LightRigPresetType::Balanced);

    autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Line, 30, 300, 200, 200);

    autoShape->get_ThreeDFormat()->set_Depth(6);
    autoShape->get_ThreeDFormat()->get_Camera()->SetRotation(0, 35, 20);
    autoShape->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::IsometricLeftUp);
    autoShape->get_ThreeDFormat()->get_LightRig()->set_LightType(LightRigPresetType::Balanced);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:Apply3DRotationEffectOnShape
}
