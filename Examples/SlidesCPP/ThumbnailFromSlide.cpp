#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::Drawing::Imaging;

void ThumbnailFromSlide()
{
	//ExStart:ThumbnailFromSlide

	// The path to the documents directory.
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String outPath = u"../out/Aspose_out.png";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	auto bitmap = slide->GetThumbnail(1, 1);

	bitmap->Save(outPath, ImageFormat::get_Png());

	//ExEnd:ThumbnailFromSlide
}
