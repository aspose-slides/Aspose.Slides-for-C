#include "SlidesExamples.h"


#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IPPImage.h>
#include <DOM/IOleObjectFrame.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IImageCollection.h>
#include <DOM/IPictureFillFormat.h>
#include <DOM/ISlidesPicture.h>
#include <system/io/path.h>
#include <system/io/file.h>

using namespace Aspose::Slides;

using namespace System;

void SubstitutePictureTitleOfOLEObjectFrame()
{
	//ExStart:SubstitutePictureTitleOfOLEObjectFrame
	System::String oleSourceFile = u"ExcelObject.xlsx";
	System::String oleIconFile = u"Image.png";
	System::String path = u"../templates/";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	System::SharedPtr<IPPImage> image;
	System::SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add Ole objects
	System::ArrayPtr<uint8_t> allbytes = System::IO::File::ReadAllBytes(System::IO::Path::Combine(path, oleSourceFile));
	System::SharedPtr<IOleObjectFrame> oof = slide->get_Shapes()->AddOleObjectFrame(20.0f, 20.0f, 50.0f, 50.0f, u"Excel.Sheet.12", allbytes);
	oof->set_IsObjectIcon(true);

	// Add image object
	System::ArrayPtr<uint8_t> imgBuf = System::IO::File::ReadAllBytes(oleIconFile);
	System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>(imgBuf);

	image = pres->get_Images()->AddImage(System::MakeObject<System::Drawing::Bitmap>(ms));

	oof->get_SubstitutePictureFormat()->get_Picture()->set_Image(image);

	// Set caption to OLE icon
	oof->set_SubstitutePictureTitle(u"Caption example");
	//ExEnd:SubstitutePictureTitleOfOLEObjectFrame

}