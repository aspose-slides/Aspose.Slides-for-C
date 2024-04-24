#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void AddRelativeScaleHeightPictureFrame()
{
    // ExStart:AddRelativeScaleHeightPictureFrame
    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"AddRelativeScaleHeightPictureFrame_out.pptx");
    const System::String filePath = Path::Combine(GetDataPath(), u"Tulips.jpg");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Load Image to be added in presentaiton image collection
    // Get the picture
    auto image = Images::FromFile(filePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(image);

    // Add picture frame to slide
    System::SharedPtr<IPictureFrame> pf = slide->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 50, 50, 100, 100, imgx);

    // Setting relative scale width and height
    pf->set_RelativeScaleHeight(0.8f);
    pf->set_RelativeScaleWidth(1.35f);

    //Write the PPTX file to disk
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:AddRelativeScaleHeightPictureFrame
}
