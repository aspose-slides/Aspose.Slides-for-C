#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void AddBlobImageToPresentation()
{
    //ExStart:AddBlobImageToPresentation

    // supposed we have the large image file we want to include into the presentation
    const System::String pathToLargeImage = Path::Combine(GetDataPath(), u"largeImage.jpg");
    const System::String outPath = Path::Combine(GetOutPath(), u"presentationWithLargeImage.pptx");

    // create a new presentation which will contain this image
    auto pres = System::MakeObject<Presentation>();

    auto fileStream = System::MakeObject<FileStream>(pathToLargeImage, FileMode::Open);

    // let's add the image to the presentation - we choose KeepLocked behavior, because we not
    // have an intent to access the "largeImage.png" file.
    auto img = pres->get_Images()->AddImage(fileStream, LoadingStreamBehavior::KeepLocked);

    pres->get_Slide(0)->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 0.0f, 0.0f, 300.0f, 200.0f, img);
    // save the presentation. Despite that the output presentation will be
    // large, the memory consumption will be low the whole lifetime of the pres object
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:AddBlobImageToPresentation
}
