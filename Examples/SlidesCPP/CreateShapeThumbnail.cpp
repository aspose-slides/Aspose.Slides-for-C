#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CreateShapeThumbnail()
{
	// ExStart:CreateShapeThumbnail

	// The path to the documents directory.
	const String outPath = u"../out/CreateShapeThumbnail_out.png";
	const String templatePath = u"../templates/HelloWorld.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	auto bitmap = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->GetThumbnail();

	// Save the image to disk in PNG format
	bitmap->Save(outPath, System::Drawing::Imaging::ImageFormat::get_Png());

	//ExEnd:CreateShapeThumbnail
}
