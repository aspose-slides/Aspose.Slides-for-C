
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

void AddNodesSpecificPosition()
{

	// ExStart:AddNodesSpecificPosition
	// The path to the documents directory.
	const String outPath = u"../out/AddNodesSpecificPosition_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	System::SharedPtr<Aspose::Slides::SmartArt::ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::StackedList);

	if (smart->get_AllNodes()->get_Count() > 0)
	{
		// Accessing SmartArt node at index 0
		System::SharedPtr<Aspose::Slides::SmartArt::SmartArtNode> node0 = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArtNode>(smart->get_AllNodes()->idx_get(0));

//		SharedPtr<ISmartArtNodeCollection> node0Collection = System::DynamicCast_noexcept<ISmartArtNodeCollection>(node0->get_ChildNodes()); ;
		SharedPtr<ISmartArtNodeCollection> node0Collection = node0->get_ChildNodes() ;


		// Adding new child node at position 2 in parent node
		SharedPtr<ISmartArtNode> chNode = node0Collection->AddNodeByPosition(2);

		// Add Text
		chNode->get_TextFrame()->set_Text(u"Sample Text Added");

	}
		// Save Presentation
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:AddNodesSpecificPosition
}
