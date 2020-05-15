#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AddNodes()
{
	// ExStart:AddNodes
	// The path to the documents directory.
	const String outPath = u"../out/AddNodes_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::StackedList);

	if (smart->get_AllNodes()->get_Count() > 0)
	{
		// Accessing SmartArt node at index 0
		SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->AddNode();

		// Add Text
		node->get_TextFrame()->set_Text(u"Test");

//		SharedPtr<ISmartArtNodeCollection> nodeCollection = System::DynamicCast_noexcept<ISmartArtNodeCollection>(node->get_ChildNodes()); ;
		auto nodeCollection = node->get_ChildNodes() ;

		// Adding new child node at end of parent node
		SharedPtr<ISmartArtNode> chNode = nodeCollection->AddNode();

		// Add Text
		chNode->get_TextFrame()->set_Text(u"Sample Text Added");

	}
	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:AddNodes
}
