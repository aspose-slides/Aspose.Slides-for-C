#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SlideShow;
using namespace System;

void SimpleSlideTransitions()
{
	//ExStart:SimpleSlideTransitions

	// The path to the documents directory.
	const String templatePath = u"../templates/SimpleSlideTransitions.pptx";
	const String outPath = u"../out/SampleTransition_out.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Apply circle type transition on slide 1
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(TransitionType::Circle);

	// Apply comb type transition on slide 2
	pres->get_Slides()->idx_get(1)->get_SlideShowTransition()->set_Type(TransitionType::Comb);

	// Write the presentation to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:SimpleSlideTransitions
}
