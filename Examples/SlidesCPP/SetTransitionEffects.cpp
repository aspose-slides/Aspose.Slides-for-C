#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/SlideShowTransition/TransitionType.h>
#include <DOM/SlideShowTransition/OptionalBlackTransition.h>
#include <DOM/SlideShowTransition/ITransitionValueBase.h>
#include <DOM/ISlideShowTransition.h>


#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SlideShow;

using namespace System;

void SetTransitionEffects()
{
	//ExStart:SetTransitionEffects

	// The path to the documents directory.
	const String templatePath = L"../templates/SimpleSlideTransitions.pptx";
	const String outPath = L"../out/TransitionEffects.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Apply circle type transition on slide 1
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(Aspose::Slides::SlideShow::TransitionType::Cut);

	auto transition = DynamicCast<Aspose::Slides::SlideShow::OptionalBlackTransition>(pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->get_Value());
	transition->set_FromBlack(true);

	// Write the presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:SetTransitionEffects
}
