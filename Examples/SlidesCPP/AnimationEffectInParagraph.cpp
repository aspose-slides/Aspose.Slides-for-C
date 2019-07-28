#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Paragraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/ITextFrame.h>
#include <DOM/TextFrame.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IAutoShape.h>
#include <DOM/IAnimationTimeLine.h>
#include <DOM/Animation/ISequence.h>
#include <DOM/Animation/EffectType.h>
#include <DOM/Animation/EffectSubtype.h>
#include <DOM/Animation/EffectTriggerType.h>
#include <Export/SaveFormat.h>


#include "SlidesExamples.h"


using namespace Aspose::Slides;
using namespace System;

void AnimationEffectinParagraph() {

	//ExStart:AnimationEffectinParagraph 
	const String templatePath = u"../templates/Presentation1.pptx";
	const String outPath = u"../out/animationEffectinParagraph.pptx";

	auto presentation = System::MakeObject<Presentation>(templatePath);
	// select paragraph to add effect
	auto autoShape = System::DynamicCast<Aspose::Slides::IAutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	auto paragraph = autoShape->get_TextFrame()->get_Paragraphs()->idx_get(0);
	// add Fly animation effect to selected paragraph
	auto effect = presentation->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(
		paragraph,
		Aspose::Slides::Animation::EffectType::Fly,
		Aspose::Slides::Animation::EffectSubtype::Left,
		Aspose::Slides::Animation::EffectTriggerType::OnClick);

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AnimationEffectinParagraph 
}