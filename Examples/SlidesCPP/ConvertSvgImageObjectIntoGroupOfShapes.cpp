#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ConvertSvgImageObjectIntoGroupOfShapes()
{
	//ExStart:ConvertSvgImageObjectIntoGroupOfShapes

	String pptxFileName = u"../templates/image.pptx";
	String outPptxPath = u"../out/image_group.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);
	SharedPtr<PictureFrame> pFrame = System::DynamicCast_noexcept<PictureFrame>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	SharedPtr<ISvgImage> svgImage = pFrame->get_PictureFormat()->get_Picture()->get_Image()->get_SvgImage();
	if (svgImage != nullptr)
	{
		// Convert svg image into group of shapes
		SharedPtr<IShapeFrame> shapeFrame = pFrame->get_Frame();
		SharedPtr<IGroupShape> groupShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddGroupShape(svgImage, shapeFrame->get_X(), shapeFrame->get_Y(), shapeFrame->get_Width(), shapeFrame->get_Height());
		// remove source svg image from presentation
		pres->get_Slides()->idx_get(0)->get_Shapes()->Remove(pFrame);

		pres->Save(outPptxPath, Export::SaveFormat::Pptx);
	}
	//ExEnd:ConvertSvgImageObjectIntoGroupOfShapes
}
