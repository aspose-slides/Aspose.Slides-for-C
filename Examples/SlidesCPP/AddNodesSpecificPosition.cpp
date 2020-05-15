#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AddNodesSpecificPosition()
{
	// ExStart:AddNodesSpecificPosition
	// The path to the documents directory.
	const String outPath = u"../out/AddNodesSpecificPosition_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::StackedList);

	if (smart->get_AllNodes()->get_Count() > 0)
	{
		// Accessing SmartArt node at index 0
		SharedPtr<SmartArtNode> node0 = System::DynamicCast_noexcept<SmartArtNode>(smart->get_AllNodes()->idx_get(0));

//		SharedPtr<ISmartArtNodeCollection> node0Collection = System::DynamicCast_noexcept<ISmartArtNodeCollection>(node0->get_ChildNodes()); ;
		SharedPtr<ISmartArtNodeCollection> node0Collection = node0->get_ChildNodes() ;

		// Adding new child node at position 2 in parent node
		SharedPtr<ISmartArtNode> chNode = node0Collection->AddNodeByPosition(2);

		// Add Text
		chNode->get_TextFrame()->set_Text(u"Sample Text Added");

	}
		// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:AddNodesSpecificPosition
}
