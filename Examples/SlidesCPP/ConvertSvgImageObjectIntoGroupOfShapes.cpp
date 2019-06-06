
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/ISvgImage.h>
#include <DOM/SvgImage.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/PictureFrame.h>
#include <DOM/IPictureFillFormat.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IShapeFrame.h>
#include <system/io/path.h>
#include <system/io/file.h>

#include "SlidesExamples.h"
using namespace Aspose::Slides;

using namespace System;

void ConvertSvgImageObjectIntoGroupOfShapes()
{
	//ExStart:ConvertSvgImageObjectIntoGroupOfShapes

	System::String pptxFileName = u"../templates/image.pptx";
	System::String outPptxPath = u"../out/image_group.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);
	System::SharedPtr<PictureFrame> pFrame = System::DynamicCast_noexcept<Aspose::Slides::PictureFrame>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	System::SharedPtr<ISvgImage> svgImage = pFrame->get_PictureFormat()->get_Picture()->get_Image()->get_SvgImage();
	if (svgImage != nullptr)
	{
		// Convert svg image into group of shapes
		System::SharedPtr<IShapeFrame> shapeFrame = pFrame->get_Frame();
		System::SharedPtr<IGroupShape> groupShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddGroupShape(svgImage, shapeFrame->get_X(), shapeFrame->get_Y(), shapeFrame->get_Width(), shapeFrame->get_Height());
		// remove source svg image from presentation
		pres->get_Slides()->idx_get(0)->get_Shapes()->Remove(pFrame);

		pres->Save(outPptxPath, Aspose::Slides::Export::SaveFormat::Pptx);
	}
	//ExEnd:ConvertSvgImageObjectIntoGroupOfShapes
}