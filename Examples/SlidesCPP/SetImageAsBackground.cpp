
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>


#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>


#include <system/string.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void SetImageAsBackground()
{

	//ExStart:SetImageAsBackground

	// The path to the documents directory.

	const String templatePath = u"../templates/SetImageAsBackground.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";
	const String OutPath = u"../out/ContentBG_Img_out.pptx";

	// Instantiate the Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Apply Image as Background
	pres->get_Slides()->idx_get(0)->get_Background()->set_Type(BackgroundType::OwnBackground);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->set_FillType(FillType::Picture);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Stretch);

	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

	//Write the presentation to disk
	pres->Save(OutPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetImageAsBackground
}
