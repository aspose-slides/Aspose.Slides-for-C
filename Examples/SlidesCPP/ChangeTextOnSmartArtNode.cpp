#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void ChangeTextOnSmartArtNode()
{
	// ExStart:ChangeTextOnSmartArtNode
	// The path to the documents directory.
	const String outPath = u"../out/ChangeTextOnSmartArtNode.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::BasicCycle);

	// Accessing SmartArt node at index 0
	SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(0);

	// Setting the text of the TextFrame 
	node->get_TextFrame()->set_Text(u"Second root node");

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ChangeTextOnSmartArtNode
}
