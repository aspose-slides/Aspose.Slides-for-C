#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

// ExStart:ConnectorLineAngle
double getDirection(float w, float h, NullableBool flipH, NullableBool flipV)
{
	float endLineX = w;

	if (flipH == NullableBool::True)
		endLineX = endLineX * -1;
	else
		endLineX = endLineX * 1;
	//float endLineX = w * (flipH ? -1 : 1);
	float endLineY = h;
	if (flipV == NullableBool::True)
		endLineY = endLineY * -1;
	else
		endLineY = endLineY * 1;
	//	float endLineY = h * (flipV ? -1 : 1);
	float endYAxisX = 0;
	float endYAxisY = h;
	double angle = (Math::Atan2(endYAxisY, endYAxisX) - Math::Atan2(endLineY, endLineX));
	if (angle < 0) angle += 2 * Math::PI;
	return angle * 180.0 / Math::PI;
}
void ConnectorLineAngle()
{
	// The path to the documents directory.
	const String outPath = u"../out/ConnectorLineAngle_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	for (int i = 0; i < slide->get_Shapes()->get_Count(); i++)
	{
		double dir = 0.0;
		// Accessing the shape collection of slides
		SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(i);

		if (ObjectExt::Is<AutoShape>(shape))
		{
			SharedPtr<AutoShape> aShape = ExplicitCast<AutoShape>(shape);
			if (aShape->get_ShapeType() == ShapeType::Line)
			{
				dir = getDirection(aShape->get_Width(), aShape->get_Height(), aShape->get_Frame()->get_FlipH(), aShape->get_Frame()->get_FlipV());
			}
		}

		else if (ObjectExt::Is<Connector>(shape))
		{
			SharedPtr<Connector> aShape = ExplicitCast<Connector>(shape);
			dir = getDirection(aShape->get_Width(), aShape->get_Height(), aShape->get_Frame()->get_FlipH(), aShape->get_Frame()->get_FlipV());
		}

		Console::WriteLine(dir);
	}
}
//ExEnd:ConnectorLineAngle
