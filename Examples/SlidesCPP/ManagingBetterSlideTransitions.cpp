#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/SlideShowTransition/TransitionType.h>
#include <DOM/ISlideShowTransition.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SlideShow;

using namespace System;

void ManagingBetterSlideTransitions()
{
	//ExStart:ManagingBetterSlideTransitions

	// The path to the documents directory.
	const String templatePath = L"../templates/SimpleSlideTransitions.pptx";
	const String outPath = L"../out/BetterSlideTransitions.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Apply circle type transition on slide 1
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(Aspose::Slides::SlideShow::TransitionType::Circle);

	// Set the transition time of 3 seconds
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_AdvanceOnClick(true);
	pres->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_AdvanceAfterTime(3000);

	// Apply comb type transition on slide 2
	pres->get_Slides()->idx_get(1)->get_SlideShowTransition()->set_Type(Aspose::Slides::SlideShow::TransitionType::Comb);


	// Set the transition time of 5 seconds
	pres->get_Slides()->idx_get(1)->get_SlideShowTransition()->set_AdvanceOnClick(true);
	pres->get_Slides()->idx_get(1)->get_SlideShowTransition()->set_AdvanceAfterTime(5000);

	// Write the presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ManagingBetterSlideTransitions
}
