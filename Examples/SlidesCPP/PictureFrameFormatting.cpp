#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void PictureFrameFormatting()
{
	// ExStart:PictureFrameFormatting
	// The path to the documents directory.
	const String outPath = u"../out/PictureFrameFormatting_out.pptx";
	const String filePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Load Image to be added in presentaiton image collection
	// Get the picture
	auto bitmap = MakeObject<Bitmap>(filePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	// Add picture frame to slide
	SharedPtr<IPictureFrame> pf = slide->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 50, 50, 100, 100, imgx);

	// Setting relative scale width and height
	pf->set_RelativeScaleHeight(0.8f);
	pf->set_RelativeScaleWidth(1.35f);
	// Apply some formatting to PictureFrame
	pf->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	pf->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());
	pf->get_LineFormat()->set_Width(20);
	pf->set_Rotation( 45);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:PictureFrameFormatting
}
