#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace Animation;

using namespace System;

void AnimatingSeries()
{
	//ExStart:AnimatingSeries

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/AnimatingSeries.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	auto chart = ExplicitCast<Chart>(slide->get_Shapes()->idx_get(0));

	// Animate series
	slide->get_Timeline()->get_MainSequence()->AddEffect(chart, EffectType::Fade, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	auto sequence = ExplicitCast<Sequence>(slide->get_Timeline()->get_MainSequence());

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 0,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 1,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 2,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 3,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:AnimatingSeries
}
