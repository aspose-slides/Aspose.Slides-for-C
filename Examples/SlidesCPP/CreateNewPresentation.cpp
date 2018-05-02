#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include<Export/IPptxOptions.h>
#include<DOM/ISlide.h>
#include<DOM/ISlideCollection.h>
#include<DOM/IShapeCollection.h>
#include<DOM/ShapeType.h>

#include<DOM/IShape.h>
#include<DOM/ISlideCollection.h>
#include<Export/ImagePixelFormat.h>
#include<Export/ISlideImageFormat.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

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
	slide->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Line, 50.0, 150.0, 300.0, 0.0);
	
	//Saving presentation
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CreateNewPresentation
}