#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Import;
using namespace System;

void AddImageFromSVGObjectFromExternalResource()
{
	//ExStart:AddImageFromSVGObjectFromExternalResource

	String outPptxPath = u"../out/presentation.pptx";
	String baseDir = GetDataPath();

	auto p = System::MakeObject<Presentation>();
	String svgContent = IO::File::ReadAllText(System::MakeObject<Uri>(System::MakeObject<Uri>(baseDir), u"image1.svg")->get_AbsolutePath());
	SharedPtr<ISvgImage> svgImage = System::MakeObject<SvgImage>(svgContent, System::MakeObject<ExternalResourceResolver>(), baseDir);
	SharedPtr<IPPImage> ppImage = p->get_Images()->AddImage(svgImage);
	p->get_Slides()->idx_get(0)->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 0.0f, 0.0f, static_cast<float>(ppImage->get_Width()), static_cast<float>(ppImage->get_Height()), ppImage);
	p->Save(outPptxPath, Export::SaveFormat::Pptx);
	//ExEnd:AddImageFromSVGObjectFromExternalResource
}
