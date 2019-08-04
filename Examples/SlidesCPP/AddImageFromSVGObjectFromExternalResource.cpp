
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
#include <Import/ExternalResourceResolver.h>
#include <Import/IExternalResourceResolver.h>
#include <system/io/path.h>
#include <system/io/file.h>

#include "SlidesExamples.h"
using namespace Aspose::Slides;
using namespace Aspose::Slides::Import;

using namespace System;

void AddImageFromSVGObjectFromExternalResource()
{
	//ExStart:AddImageFromSVGObjectFromExternalResource

	System::String svgPath = u"../templates/sample.svg";
	System::String outPptxPath = u"../out/presentation.pptx";
	System::String baseDir = u"../templates/";

	auto p = System::MakeObject<Presentation>();
	System::String svgContent = System::IO::File::ReadAllText(System::MakeObject<System::Uri>(System::MakeObject<System::Uri>(baseDir), u"image1.svg")->get_AbsolutePath());
	System::SharedPtr<ISvgImage> svgImage = System::MakeObject<SvgImage>(svgContent, System::MakeObject<ExternalResourceResolver>(), baseDir);
	System::SharedPtr<IPPImage> ppImage = p->get_Images()->AddImage(svgImage);
	p->get_Slides()->idx_get(0)->get_Shapes()->AddPictureFrame(Aspose::Slides::ShapeType::Rectangle, 0.0f, 0.0f, static_cast<float>(ppImage->get_Width()), static_cast<float>(ppImage->get_Height()), ppImage);
	p->Save(outPptxPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:AddImageFromSVGObjectFromExternalResource
}