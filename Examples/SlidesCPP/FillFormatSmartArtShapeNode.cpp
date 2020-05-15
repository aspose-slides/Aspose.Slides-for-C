#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void FillFormatSmartArtShapeNode()
{
	// ExStart:FillFormatSmartArtShapeNode
	// The path to the documents directory.
	const String outPath = u"../out/FillFormat_SmartArt_ShapeNode_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Add SmartArt BasicProcess 
	SharedPtr<ISmartArt> smart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSmartArt(10, 10, 400, 300, SmartArtLayoutType::ClosedChevronProcess);

	// Adding SmartArt node
	SharedPtr<ISmartArtNode> NewNode = smart->get_AllNodes()->AddNode();

	//Adding text to added node
	NewNode->get_TextFrame()->set_Text( u"Some text");

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:FillFormatSmartArtShapeNode
}
