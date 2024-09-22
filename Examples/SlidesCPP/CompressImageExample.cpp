#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void CompressImageExample()
{
    // ExStart:CompressImageExample

    // Path to source presentation
    const String presentationName = Path::Combine(GetDataPath(), u"CroppedImage.pptx");
    // Path to output document
    const String outFilePath = Path::Combine(GetOutPath(), u"CroppedImage-Compress-out.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(presentationName);
    SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Get the PictureFrame from the slide
    SharedPtr<IPictureFrame> picFrame = System::AsCast<IPictureFrame>(slide->get_Shape(0));

    // Compress the image with a target resolution of 150 DPI (Web resolution) and remove cropped areas
    bool result = picFrame->get_PictureFormat()->CompressImage(true, 150.0f);

    // Check the result of the compression
    if (result)
    {
        Console::WriteLine(u"Image successfully compressed.");
    }
    else
    {
        Console::WriteLine(u"Image compression failed or no changes were necessary.");
    }

    // Save result
    pres->Save(outFilePath, SaveFormat::Pptx);

    // Check size
    Console::WriteLine(u"Source presentation length\t = {0}", System::MakeObject<FileInfo>(presentationName)->get_Length());
    Console::WriteLine(u"Resulting presentation length\t = {0}", System::MakeObject<FileInfo>(outFilePath)->get_Length());

    // ExEnd:CompressImageExample
}
