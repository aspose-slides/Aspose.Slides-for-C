#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System::IO;

void CreateSmartArtChildNoteThumbnail()
{
    // ExStart:CreateSmartArtChildNoteThumbnail

    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"CreateSmartArtChildNoteThumbnail_out.png");
    const System::String templatePath = Path::Combine(GetDataPath(), u"HelloWorld.pptx");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Add SmartArt 
    System::SharedPtr<ISmartArt> smart = pres->get_Slide(0)->get_Shapes()->AddSmartArt(
        10, 10, 400, 300, SmartArtLayoutType::BasicCycle);

    // Obtain the reference of a node by using its Index  
    System::SharedPtr<ISmartArtNode> node = smart->get_Node(1);

    // Get thumbnail
    auto image = node->get_Shape(0)->GetImage();

    // Save the image to disk in PNG format
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:CreateSmartArtChildNoteThumbnail
}
