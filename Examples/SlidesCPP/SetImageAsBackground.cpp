#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void SetImageAsBackground()
{
    //ExStart:SetImageAsBackground

    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"SetImageAsBackground.pptx");
    const System::String imagePath = Path::Combine(GetDataPath(), u"Tulips.jpg");
    const System::String outPath = Path::Combine(GetOutPath(), u"ContentBG_Img_out.pptx");

    // Instantiate the Presentation class that represents the presentation file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Apply Image as Background
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);
    slide->get_Background()->set_Type(BackgroundType::OwnBackground);
    slide->get_Background()->get_FillFormat()->set_FillType(FillType::Picture);
    slide->get_Background()->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Stretch);

    // Get the picture
    auto image = Images::FromFile(imagePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(image);

    slide->get_Background()->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

    //Write the presentation to disk
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:SetImageAsBackground
}
