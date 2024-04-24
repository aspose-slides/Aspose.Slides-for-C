#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void StretchOffsetLeftForPictureFrame()
{
    // ExStart:StretchOffsetLeftForPictureFrame

    // The path tos the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"StretchOffsetLeftForPictureFrame_out.pptx");
    const System::String imagePath = Path::Combine(GetDataPath(), u"Tulips.jpg");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Accessing shapes collection for selected slide
    System::SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

    // Now create effect "PathFootball" for existing shape from scratch.
    System::SharedPtr<IAutoShape> autoShape = shapes->AddAutoShape(
        ShapeType::Rectangle, 100, 100, 300, 300);

    // Apply some picture formatting to rectangle shape
    autoShape->get_FillFormat()->set_FillType(FillType::Picture);

    // Set the picture fill mode
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Stretch);

    // Get the picture
    auto image = Images::FromFile(imagePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(image);

    //Set picture to shape
    autoShape->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

    // Specify image offsets from the corresponding edge of the shape's bounding box
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetLeft(25);
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetRight(25);
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetTop(-20);
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetBottom(-10);

    //Write the PPTX to Disk
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:StretchOffsetLeftForPictureFrame
}
