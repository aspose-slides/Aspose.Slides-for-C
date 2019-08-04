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


using namespace Aspose::Slides;

using namespace System;

void SetBackground()
{
	//ExStart:SetBackground

	// The path to the documents directory.
	
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String OutPath = u"../out/ContentBG_Grad_out.pptx";


	// Instantiate the Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	
	// Apply Gradiant effect to the Background
	pres->get_Slides()->idx_get(0)->get_Background()->set_Type(BackgroundType::OwnBackground);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->set_FillType(FillType::Gradient);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->get_GradientFormat()->set_TileFlip(TileFlip::FlipBoth);

	//Write the presentation to disk
	pres->Save(OutPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetBackground
}



