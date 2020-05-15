#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using System::Drawing::Color;

void SetSlideBackgroundNormal()
{
	//ExStart:SetSlideBackgroundNormal

	// The path to the documents directory.
	const String OutPath = u"../out/SetSlideBackgroundNormal_out.pptx";

	// Instantiate the Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Set the background color of the Master ISlide to Forest Green
	pres->get_Slides()->idx_get(0)->get_Background()->set_Type(BackgroundType::OwnBackground);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
	pres->get_Slides()->idx_get(0)->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	//Write the presentation to disk
	pres->Save(OutPath, Export::SaveFormat::Pptx);

	//ExEnd:SetSlideBackgroundNormal
}
