#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void ManageParagraphPictureBulletsInPPT()
{
    // ExStart:ManageParagraphPictureBulletsInPPT
    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"ManageParagraphPictureBulletsInPPT_out.pptx");
    const System::String templatePath = Path::Combine(GetDataPath(), u"DefaultFonts.pptx");
    const System::String imagePath = Path::Combine(GetDataPath(), u"Tulips.jpg");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    System::SharedPtr<ISlide> sld = pres->get_Slide(0);

    // Add an AutoShape of Rectangle type
    System::SharedPtr<IAutoShape> ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

    // Add TextFrame to the Rectangle
    ashp->AddTextFrame(u"");

    // Accessing the text frame
    System::SharedPtr<ITextFrame> txtFrame = ashp->get_TextFrame();

    // Create the Paragraph object for text frame
    System::SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraph(0);

    // Create Portion object for paragraph
    System::SharedPtr<IPortion> portion = paragraph->get_Portion(0);
    portion->set_Text(u"Welcome to Aspose.Slides");

    // Get the picture
    auto image = Images::FromFile(imagePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> ippxImage = pres->get_Images()->AddImage(image);

    // Setting paragraph bullet style and image
    paragraph->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Picture);
    paragraph->get_ParagraphFormat()->get_Bullet()->get_Picture()->set_Image(ippxImage);

    // Setting Bullet Height
    paragraph->get_ParagraphFormat()->get_Bullet()->set_Height(100);

    // Save PPTX to Disk
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:ManageParagraphPictureBulletsInPPT
}
