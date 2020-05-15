#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddImageFromSVGObject()
{
	//ExStart:AddImageFromSVGObject

	String svgPath = u"../templates/sample.svg";
	String outPptxPath = u"../out/presentation.pptx";

	auto p = System::MakeObject<Presentation>();
	String svgContent = IO::File::ReadAllText(svgPath);
	SharedPtr<ISvgImage> svgImage = System::MakeObject<SvgImage>(svgContent);
	SharedPtr<IPPImage> ppImage = p->get_Images()->AddImage(svgImage);
	p->get_Slides()->idx_get(0)->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 0.0f, 0.0f, static_cast<float>(ppImage->get_Width()), static_cast<float>(ppImage->get_Height()), ppImage);
	p->Save(outPptxPath, Export::SaveFormat::Pptx);
	//ExEnd:AddImageFromSVGObject
}
