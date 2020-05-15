#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void ShowPictureOrganizationChart()
{
	// ExStart:ShowPictureOrganizationChart

	// The path to the documents directory.
	const String outPath = u"../out/PictureOrganizationChart_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	
	//Adding Picture Organization Chart
	SharedPtr<ISmartArt> smartArt = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(0, 0, 400, 400, SmartArtLayoutType::PictureOrganizationChart);

	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ShowPictureOrganizationChart
}
