#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void CheckSmartArtHiddenProperty()
{
	// ExStart:CheckSmartArtHiddenProperty
	// The path to the documents directory.
	const String outPath = u"../out/CheckSmartArtHiddenProperty_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::RadialCycle);

	// Adding SmartArt node
	SharedPtr<ISmartArtNode> NewNode = smart->get_AllNodes()->AddNode();

	// Check isHidden property
	bool hidden = NewNode->get_IsHidden(); // Returns true
	if (hidden)
	{
		// Do some actions or notifications
	}

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:CheckSmartArtHiddenProperty
}
