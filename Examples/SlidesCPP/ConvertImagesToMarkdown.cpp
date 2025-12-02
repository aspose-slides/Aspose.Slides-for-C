#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ConvertImagesToMarkdown()
{
    //ExStart:ConvertImagesToMarkdown

    const String presentationName = Path::Combine(GetDataPath(), u"demo_2.pptx");
    const String outFilePath = Path::Combine(GetOutPath(), u"output_markdown.md");
    const String imagesDir = Path::Combine(GetOutPath(), u"ExportedImages");

    if (!Directory::Exists(imagesDir))
    {
        Directory::CreateDirectory_(imagesDir);
    }

    auto options = MakeObject<MarkdownSaveOptions>();
    options->set_ImagesSaveFolderName(u"Images");
    options->set_ExportType(MarkdownExportType::Visual);

    options->ImageSaving.connect(static_cast<std::function<bool(SharedPtr<IImage>, ImageFormat, String&)>>([&](SharedPtr<IImage> image, ImageFormat format, String& link) -> bool
    {
        format = ImageFormat::Jpeg;
        const String fileName = String(u"Image_") + Guid::NewGuid().ToString(u"N") + u".jpg";
        link = Path::Combine(imagesDir, fileName);
        image->Save(link, format);

        return true;
    }));

    options->SvgImageSaving.connect(static_cast<std::function<bool(SharedPtr<ISvgImage>, String&)>>([&](SharedPtr<ISvgImage> svgImage, String& link) -> bool
    {
        const String fileName = String(u"Svg_") + Guid::NewGuid().ToString(u"N") + u".svg";
        link = Path::Combine(imagesDir, fileName);
        File::WriteAllBytes(link, svgImage->get_SvgData());

        return true;
    }));

    auto presentation = MakeObject<Presentation>(presentationName);
    presentation->Save(outFilePath, SaveFormat::Md, options);

    //ExEnd:ConvertImagesToMarkdown
}
