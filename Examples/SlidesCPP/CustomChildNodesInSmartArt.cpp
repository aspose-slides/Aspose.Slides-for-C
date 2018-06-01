
#include <iostream>
#include <system/console.h>
#include <Export/SaveFormat.h>
#include <DOM/SmartArt/ISmartArtShape.h>

#include <DOM/SmartArt/SmartArtQuickStyleType.h>
#include <DOM/SmartArt/SmartArtNode.h>
#include <DOM/SmartArt/SmartArtLayoutType.h>
#include <DOM/SmartArt/SmartArtColorType.h>
#include <DOM/SmartArt/SmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtShapeCollection.h>
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

void CustomChildNodesInSmartArt()
{

	// The path to the documents directory.
	const String outPath = u"../out/CustomChildNodesInSmartArt_out.pptx";

	// ExStart:CustomChildNodesInSmartArt

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	System::SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(20, 20, 600, 500, Aspose::Slides::SmartArt::SmartArtLayoutType::OrganizationChart);

	// Move SmartArt shape to new position
	System::SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(1);
	System::SharedPtr<ISmartArtShape> shape = node->get_Shapes()->idx_get(1);
	shape->set_X((float)(shape->get_X() + (shape->get_Width() * 2)));
	shape->set_Y((float)(shape->get_Y() - (shape->get_Height() / 2)));

	// Change SmartArt shape's widths
	node = smart->get_AllNodes()->idx_get(2);
	shape = node->get_Shapes()->idx_get(1);
	shape->set_Width(shape->get_Width() + (shape->get_Width() / 2));

	// Change SmartArt shape's height
	node = smart->get_AllNodes()->idx_get(3);
	shape = node->get_Shapes()->idx_get(1);
	shape->set_Height(shape->get_Height() + (shape->get_Height() / 2));

	// Change SmartArt shape's rotation
	node = smart->get_AllNodes()->idx_get(4);
	shape = node->get_Shapes()->idx_get(1);
	shape->set_Rotation(90);

	
	// Save Presentation
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:CustomChildNodesInSmartArt
}
