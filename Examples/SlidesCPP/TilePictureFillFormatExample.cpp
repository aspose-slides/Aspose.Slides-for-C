#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void TilePictureFillFormatExample()
{
    //ExStart:TilePictureFillFormatExample
    const System::String imagePath = Path::Combine(GetDataPath(), u"image.png");
    // The path to output file
    const System::String outFilePath = Path::Combine(GetOutPath(), u"ImageTileExample.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    System::SharedPtr<ISlide> firstSlide = pres->get_Slide(0);

    System::SharedPtr<IImage> newImage = Images::FromFile(imagePath);
    System::SharedPtr<IPPImage> ppImage = pres->get_Images()->AddImage(newImage);

    // Adds the new Rectangle shape
    System::SharedPtr<IAutoShape> newShape = firstSlide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 0, 0, 350, 350);
    System::SharedPtr<IFillFormat> fillFormat = newShape->get_FillFormat();

    // Sets the fill type of the new shape to Picture
    fillFormat->set_FillType(FillType::Picture);

    // Sets the shape's fill image
    System::SharedPtr<IPictureFillFormat> pictureFillFormat = fillFormat->get_PictureFillFormat();
    pictureFillFormat->get_Picture()->set_Image(ppImage);

    // Sets the picture fill mode to Tile and changes the properties
    pictureFillFormat->set_PictureFillMode(PictureFillMode::Tile);
    pictureFillFormat->set_TileOffsetX(-275);
    pictureFillFormat->set_TileOffsetY(-247);
    pictureFillFormat->set_TileScaleX(120);
    pictureFillFormat->set_TileScaleY(120);
    pictureFillFormat->set_TileAlignment(RectangleAlignment::BottomRight);
    pictureFillFormat->set_TileFlip(TileFlip::FlipBoth);

    pres->Save(outFilePath, SaveFormat::Pptx);
    //ExEnd:TilePictureFillFormatExample
}
