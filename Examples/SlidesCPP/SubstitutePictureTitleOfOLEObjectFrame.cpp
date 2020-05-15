#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void SubstitutePictureTitleOfOLEObjectFrame()
{
	//ExStart:SubstitutePictureTitleOfOLEObjectFrame
	String oleSourceFile = u"book1.xlsx";
	String oleIconFile = u"img.png";
	String path = u"../templates/";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	SharedPtr<IPPImage> image;
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add Ole objects
	ArrayPtr<uint8_t> allbytes = File::ReadAllBytes(Path::Combine(path, oleSourceFile));
	SharedPtr<IOleObjectFrame> oof = slide->get_Shapes()->AddOleObjectFrame(20.0f, 20.0f, 50.0f, 50.0f, u"Excel.Sheet.12", allbytes);
	oof->set_IsObjectIcon(true);

	// Add image object
	ArrayPtr<uint8_t> imgBuf = File::ReadAllBytes(Path::Combine(path, oleIconFile));
	SharedPtr<MemoryStream> ms = System::MakeObject<MemoryStream>(imgBuf);

	image = pres->get_Images()->AddImage(System::MakeObject<System::Drawing::Bitmap>(ms));

	oof->get_SubstitutePictureFormat()->get_Picture()->set_Image(image);

	// Set caption to OLE icon
	oof->set_SubstitutePictureTitle(u"Caption example");
	//ExEnd:SubstitutePictureTitleOfOLEObjectFrame

}
