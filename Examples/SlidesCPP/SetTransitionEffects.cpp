#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SlideShow;
using namespace System;

void SetTransitionEffects()
{
	//ExStart:SetTransitionEffects

	// The path to the documents directory.
	const String templatePath = u"../templates/SimpleSlideTransitions.pptx";
	const String outPath = u"../out/TransitionEffects.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Apply circle type transition on slide 1
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(TransitionType::Cut);

	auto transition = ExplicitCast<OptionalBlackTransition>(pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->get_Value());
	transition->set_FromBlack(true);

	// Write the presentation to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:SetTransitionEffects
}
