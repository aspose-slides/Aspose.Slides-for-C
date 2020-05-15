#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;
using namespace System::Drawing;

void CreateSmartArtChildNoteThumbnail()
{
	// ExStart:CreateSmartArtChildNoteThumbnail

	// The path to the documents directory.
	const String outPath = u"../out/CreateSmartArtChildNoteThumbnail_out.png";
	const String templatePath = u"../templates/HelloWorld.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt 
	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::BasicCycle);

	// Obtain the reference of a node by using its Index  
	SharedPtr<ISmartArtNode> node = smart->get_Nodes()->idx_get(1);

	// Get thumbnail
	auto bitmap = node->get_Shapes()->idx_get(0)->GetThumbnail();

	// Save the image to disk in PNG format
	bitmap->Save(outPath, Imaging::ImageFormat::get_Png());

	//ExEnd:CreateSmartArtChildNoteThumbnail
}
