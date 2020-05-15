#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void ChangeSmartArtLayout()
{
	// ExStart:ChangeSmartArtLayout
	// The path to the documents directory.
	const String outPath = u"../out/ChangeSmartArtLayout_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::BasicBlockList);

	// Change LayoutType to BasicProcess
	smart->set_Layout(SmartArtLayoutType::BasicProcess);

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ChangeSmartArtLayout
}
