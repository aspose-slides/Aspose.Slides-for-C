#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void SubstitutePictureTitleOfOLEObjectFrame()
{
    //ExStart:SubstitutePictureTitleOfOLEObjectFrame
    const System::String oleSourceFile = Path::Combine(GetDataPath(), u"book1.xlsx");
    const System::String oleIconFile = Path::Combine(GetDataPath(), u"img.png");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Add Ole objects
    System::SharedPtr<IOleObjectFrame> oof = slide->get_Shapes()->AddOleObjectFrame(
        20.0f, 20.0f, 50.0f, 50.0f, u"Excel.Sheet.12", oleSourceFile);
    oof->set_IsObjectIcon(true);

    // Add image object
    System::ArrayPtr<uint8_t> imgBuf = File::ReadAllBytes(oleIconFile);
    System::SharedPtr<MemoryStream> ms = System::MakeObject<MemoryStream>(imgBuf);

    System::SharedPtr<IPPImage> image = pres->get_Images()->AddImage(Images::FromStream(ms));

    oof->get_SubstitutePictureFormat()->get_Picture()->set_Image(image);

    // Set caption to OLE icon
    oof->set_SubstitutePictureTitle(u"Caption example");
    //ExEnd:SubstitutePictureTitleOfOLEObjectFrame
}
