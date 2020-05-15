#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void CustomChildNodesInSmartArt()
{
	// The path to the documents directory.
	const String outPath = u"../out/CustomChildNodesInSmartArt_out.pptx";

	// ExStart:CustomChildNodesInSmartArt

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(20, 20, 600, 500, SmartArtLayoutType::OrganizationChart);

	// Move SmartArt shape to new position
	SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(1);
	SharedPtr<ISmartArtShape> shape = node->get_Shapes()->idx_get(1);
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
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:CustomChildNodesInSmartArt
}
