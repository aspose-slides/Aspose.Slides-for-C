#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::Drawing::Imaging;

void ThumbnailWithUserDefinedDimensions()
{
	//ExStart:ThumbnailWithUserDefinedDimensions

	// The path to the documents directory.
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String outPath = u"../out/Aspose_UserDefinedDimension_Slide_out.png";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// User defined dimension
	int desiredX = 1200;
	int desiredY = 800;

	// Getting scaled value  of X and Y
	float ScaleX = (float)(1.0 / pres->get_SlideSize()->get_Size().get_Width()) * desiredX;
	float ScaleY = (float)(1.0 / pres->get_SlideSize()->get_Size().get_Height()) * desiredY;

	// Create a custom scale image
	auto bitmap = slide->GetThumbnail(ScaleX, ScaleY);

	bitmap->Save(outPath, ImageFormat::get_Png());

	//ExEnd:ThumbnailWithUserDefinedDimensions
}
