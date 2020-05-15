#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void CreateNewPresentation()
{
	//ExStart:CreateNewPresentation

	// The path to the documents directory.
	const String outPath = u"../out/SampleChartresult.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	slide->get_Shapes()->AddAutoShape(ShapeType::Line, 50.0, 150.0, 300.0, 0.0);
	
	//Saving presentation
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:CreateNewPresentation
}
