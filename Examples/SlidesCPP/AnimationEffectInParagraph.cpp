#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AnimationEffectinParagraph()
{
	//ExStart:AnimationEffectinParagraph 
	const String templatePath = u"../templates/Presentation1.pptx";
	const String outPath = u"../out/animationEffectinParagraph.pptx";

	auto presentation = System::MakeObject<Presentation>(templatePath);
	// select paragraph to add effect
	auto autoShape = System::DynamicCast<IAutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	auto paragraph = autoShape->get_TextFrame()->get_Paragraphs()->idx_get(0);
	// add Fly animation effect to selected paragraph
	auto effect = presentation->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(
		paragraph,
		Animation::EffectType::Fly,
		Animation::EffectSubtype::Left,
		Animation::EffectTriggerType::OnClick);

	presentation->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AnimationEffectinParagraph 
}
