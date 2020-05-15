#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void CreateSmartArtShape()
{
	// ExStart:CreateSmartArtShape
	// The path to the documents directory.
	const String outPath = u"../out/SimpleSmartArt_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::BasicBlockList);

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:CreateSmartArtShape
}
