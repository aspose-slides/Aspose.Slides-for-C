#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddSimplePictureFrames()
{
	// ExStart:AddSimplePictureFrames
	// The path to the documents directory.
	const String outPath = u"../out/AddSimplePictureFrames_out.pptx";
	const String filePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Load Image to be added in presentaiton image collection
	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(filePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	// Add picture frame to slide
	SharedPtr<IPictureFrame> pf = slide->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 50, 50, 100, 100, imgx);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddSimplePictureFrames
}
