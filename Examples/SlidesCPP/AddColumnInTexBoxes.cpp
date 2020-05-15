#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddColumnInTexBoxes()
{
	// ExStart:AddColumnInTexBoxes
	// The path to the documents directory.
	const String outPath = u"../out/AddColumnInTexBoxes_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 300, 300);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"All these columns are limited to be within a single text container -- you can add or delete text and the new or remaining text automatically adjusts itself to flow within the container. You cannot have text flow from one container to other though -- we told you PowerPoint's column options for text are limited!");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Get text format of TextFrame
	SharedPtr<ITextFrameFormat> format = txtFrame->get_TextFrameFormat();

	// Specify number of columns in TextFrame
	format->set_ColumnCount(3);

	// Specify spacing between columns
	format->set_ColumnSpacing ( 10);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:AddColumnInTexBoxes
}
