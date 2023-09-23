#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;
using namespace Animation;

void AnimateTextTypeExample()
{
    //ExStart:AnimateTextTypeExample

    // Path to output document
    const String outFilePath = u"../out/AnimateTextEffect_out.pptx";

    SharedPtr<Presentation> presentation = MakeObject<Presentation>();
    SharedPtr<ISlide> slide = presentation->get_Slide(0);

    SharedPtr<IAutoShape> oval = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 100.0f, 100.f, 300.0f, 150.0f);
    oval->get_TextFrame()->set_Text(u"The new animated text");

    // Get animation timeline
    SharedPtr<IAnimationTimeLine> timeline = slide->get_Timeline();

    // Set the effect of the first slide
    SharedPtr<IEffect> effect = timeline->get_MainSequence()->AddEffect(oval, EffectType::Appear, EffectSubtype::None, EffectTriggerType::OnClick);

    // Set the effect Animate text type to "By letter"
    effect->set_AnimateTextType(AnimateTextType::ByLetter);

    // Set the delay between animated text parts
    effect->set_DelayBetweenTextParts(-1.5f);

    // Save presentation
    presentation->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:AnimateTextTypeExample
}
