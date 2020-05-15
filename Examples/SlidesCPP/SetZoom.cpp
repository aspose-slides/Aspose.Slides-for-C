#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;

void SetZoom()
{
	//ExStart:SetZoom

	// The path to the documents directory.
	const String outPath = u"../out/SetZoom_out.pptx";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->get_ViewProperties()->get_SlideViewProperties()->set_Scale(100);

	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SetZoom
}