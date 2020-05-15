#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AccessChildNodeSpecificPosition()
{
	// ExStart:AccessChildNodeSpecificPosition
	// The path to the documents directory.
	const String outPath = u"../out/AccessChildNodeSpecificPosition_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::StackedList);

	if (smart->get_AllNodes()->get_Count() > 0)
	{
		// Accessing SmartArt node at index 0
		SharedPtr<ISmartArtNode> node0 = smart->get_AllNodes()->idx_get(0);

		//Accessing child node collection
		auto nodeCollection =node0->get_ChildNodes();
		SharedPtr<SmartArtNode> foundChild;

		int position = 1;
		SharedPtr<ISmartArtNode> node = node0->get_ChildNodes()->idx_get(position);

		// Printing the SmartArt child node parameters
		Console::WriteLine(u"j = " + node->get_TextFrame()->get_Text() + u", Text = " + node->get_Level() + u", Position = " + node->get_Position());
	}

	// ExEnd:AccessChildNodeSpecificPosition
}
