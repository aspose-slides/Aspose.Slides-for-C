
#include <iostream>
#include <system/console.h>
#include <Export/SaveFormat.h>
#include <DOM/SmartArt/SmartArtQuickStyleType.h>
#include <DOM/SmartArt/SmartArtNode.h>
#include <DOM/SmartArt/SmartArtLayoutType.h>
#include <DOM/SmartArt/SmartArtColorType.h>
#include <DOM/SmartArt/SmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtNode.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/SmartArt/OrganizationChartLayoutType.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SmartArt;

using namespace System;

const int NodesCount = 5;

void AccessChildNodeSpecificPosition()
{

	// ExStart:AccessChildNodeSpecificPosition
	// The path to the documents directory.
	const String outPath = L"../out/AccessChildNodeSpecificPosition_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	System::SharedPtr<Aspose::Slides::SmartArt::ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::StackedList);

	if (smart->get_AllNodes()->get_Count() > 0)
	{
		// Accessing SmartArt node at index 0
		SharedPtr<Aspose::Slides::SmartArt::ISmartArtNode> node0 = smart->get_AllNodes()->idx_get(0);

		//Accessing child node collection
		auto nodeCollection =node0->get_ChildNodes();
		SharedPtr<SmartArtNode> foundChild;

		int position = 1;
		System::SharedPtr<Aspose::Slides::SmartArt::ISmartArtNode> node = node0->get_ChildNodes()->idx_get(position);

		// Printing the SmartArt child node parameters
		System::Console::WriteLine(L"j = " + node->get_TextFrame()->get_Text() + L", Text = " + node->get_Level() + L", Position = " + node->get_Position());

	}

	// ExEnd:AccessChildNodeSpecificPosition
}
