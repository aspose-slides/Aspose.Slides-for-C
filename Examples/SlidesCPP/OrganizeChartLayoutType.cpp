#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void OrganizeChartLayoutType()
{
	// ExStart:OrganizeChartLayoutType
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";
	const String outPath = u"../out/OrganizeChartLayoutType_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt>  smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::OrganizationChart);

	// Accessing SmartArt node at index 0
	SharedPtr<ISmartArtNode> node0 = smart->get_AllNodes()->idx_get(0);

	// Get or Set the organization chart type 
	node0->set_OrganizationChartLayout(OrganizationChartLayoutType::LeftHanging);
	
	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:OrganizeChartLayoutType
}
