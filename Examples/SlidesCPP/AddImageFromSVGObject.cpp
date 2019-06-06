
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

#include <system/io/path.h>
#include <system/io/file.h>

#include "SlidesExamples.h"
using namespace Aspose::Slides;

using namespace System;

void AddImageFromSVGObject()
{
	//ExStart:AddImageFromSVGObject

	System::String svgPath = u"../templates/sample.svg";
	System::String outPptxPath = u"../out/presentation.pptx";

	auto p = System::MakeObject<Presentation>();
	System::String svgContent = System::IO::File::ReadAllText(svgPath);
	System::SharedPtr<ISvgImage> svgImage = System::MakeObject<SvgImage>(svgContent);
	System::SharedPtr<IPPImage> ppImage = p->get_Images()->AddImage(svgImage);
	p->get_Slides()->idx_get(0)->get_Shapes()->AddPictureFrame(Aspose::Slides::ShapeType::Rectangle, 0.0f, 0.0f, static_cast<float>(ppImage->get_Width()), static_cast<float>(ppImage->get_Height()), ppImage);
	p->Save(outPptxPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:AddImageFromSVGObject
}