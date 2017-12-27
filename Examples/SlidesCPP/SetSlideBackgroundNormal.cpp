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

void SetSlideBackgroundNormal()
{

	//ExStart:SetSlideBackgroundNormal

	// The path to the documents directory.

	const String OutPath = L"../out/SetSlideBackgroundNormal_out.pptx";

	// Instantiate the Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Set the background color of the Master ISlide to Forest Green
	pres->get_Slides()->idx_get(0)->get_Background()->set_Type(BackgroundType::OwnBackground);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Blue());

	//Write the presentation to disk
	pres->Save(OutPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetSlideBackgroundNormal
}
