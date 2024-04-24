#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void FillShapesPicture()
{
    // ExStart:FillShapesPicture

    // The path tos the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"FillShapesPicture_out.pptx");
    const System::String templatePath = Path::Combine(GetDataPath(), u"ConnectorLineAngle.pptx");
    const System::String imagePath = u"../templates/Tulips.jpg";

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Accessing shapes collection for selected slide
    System::SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

    // Now create effect "PathFootball" for existing shape from scratch.
    System::SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 75, 150);

    // Apply some picture formatting to rectangle shape
    autoShape->get_FillFormat()->set_FillType(FillType::Picture);
    // Set the picture fill mode
    autoShape->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Tile);

    // Get the picture
    auto image = Images::FromFile(imagePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(image);

    //Set picture to shape
    autoShape->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

    //Write the PPTX to Disk
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:FillShapesPicture
}
