#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void CreateScalingFactorThumbnail()
{
	// ExStart:CreateScalingFactorThumbnail

	// The path to the documents directory.
	const String outPath = u"../out/CreateScalingFactorThumbnail_out.png";
	const String templatePath = u"../templates/HelloWorld.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	auto bitmap = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->GetThumbnail(ShapeThumbnailBounds::Shape, 2, 2);

	// Save the image to disk in PNG format
	bitmap->Save(outPath, Imaging::ImageFormat::get_Png());

	//ExEnd:CreateScalingFactorThumbnail
}
