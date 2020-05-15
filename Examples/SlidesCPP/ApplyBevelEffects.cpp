#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ApplyBevelEffects()
{
	// ExStart:ApplyBevelEffects

	// The path to the documents directory.
	const String outPath = u"../out/ApplyBevelEffects_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 30, 30, 100, 100);
	autoShape->get_FillFormat()->set_FillType ( FillType::Solid);
	autoShape->get_FillFormat()->get_SolidFillColor()->set_Color ( Color::get_Green());

	SharedPtr<ILineFillFormat> format = autoShape->get_LineFormat()->get_FillFormat();
	format->set_FillType ( FillType::Solid);
	format->get_SolidFillColor()->set_Color(Color::get_Orange());
	autoShape->get_LineFormat()->set_Width ( 2.0);

	// Set ThreeDFormat properties of shape

	autoShape->get_ThreeDFormat()->set_Depth(4);
	autoShape->get_ThreeDFormat()->get_BevelTop()->set_BevelType (BevelPresetType::Circle);
	autoShape->get_ThreeDFormat()->get_BevelTop()->set_Height ( 6);
	autoShape->get_ThreeDFormat()->get_BevelTop()->set_Width ( 6);
	autoShape->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::OrthographicFront);
	autoShape->get_ThreeDFormat()->get_LightRig()->set_LightType(LightRigPresetType::ThreePt);
	autoShape->get_ThreeDFormat()->get_LightRig()->set_Direction(LightingDirection::Top);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ApplyBevelEffects
}
