#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetBackgroundToGradient()
{
	//ExStart:SetBackgroundToGradient

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
	pres->Save(OutPath, Export::SaveFormat::Pptx);

	//ExEnd:SetBackgroundToGradient
}
