#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void FindShapeInSlide()
{
	// ExStart:FindShapeInSlide

	// The path to the documents directory.
	const String outPath = u"../out/FindShapeInSlide_out.pptx";
	const String templatePath = u"../templates/FindingShapeInSlide.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IShape> shape = Util::SlideUtil::FindShape(slide, u"Shape1");
	if (shape != nullptr)
	{
		Console::WriteLine(u"Shape Name: " + shape->get_Name());
		Console::WriteLine(u"Shape Alternative Tex: " + shape->get_AlternativeText());
	}

	//ExEnd:FindShapeInSlide
}
