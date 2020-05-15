#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace Animation;
using namespace System;

void AnimatingCategoriesElements()
{
	//ExStart:AnimatingCategoriesElements

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/AnimatingCategoriesElements_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	auto chart = DynamicCast<Chart>(slide->get_Shapes()->idx_get(0));

	// Animate categories' elements
	slide->get_Timeline()->get_MainSequence()->AddEffect(chart, EffectType::Fade, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	auto sequence = DynamicCast<Sequence>(slide->get_Timeline()->get_MainSequence());
	
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 0, 0, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 0, 1, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 0, 2, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 0, 3, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 1, 0, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 1, 1, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 1, 2, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 1, 3, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 2, 0, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 2, 1, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType:: ByElementInCategory, 2, 2, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);
	sequence->AddEffect(chart, EffectChartMinorGroupingType::ByElementInCategory, 2, 3, EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:AnimatingCategoriesElements
}
