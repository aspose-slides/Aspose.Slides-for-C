#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Animation;

void AnimationRepeatOnSlide()
{
    //ExStart:AnimationRepeatOnSlide

    // The path to the documents directory.
    const System::String templatePath = u"../templates/AnimationOnSlide.pptx";
    const System::String outPath = u"../out/AnimationOnSlide.pptx";

    // Instantiate Presentation class that represents a presentation file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Gets the effects sequence for the first slide
    System::SharedPtr<ISequence> effectsSequence = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence();

    // Gets the first effect of the main sequence.
    System::SharedPtr<IEffect> effect = effectsSequence->idx_get(0);

    // Changes the effect Timing/Repeat to "Until End of Slide"
    effect->get_Timing()->set_RepeatUntilEndSlide(true);

    // Changes the effect Timing/Repeat to "Until End of Slide"
    effect->get_Timing()->set_RepeatUntilNextClick(true);

    // Save presentation
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:AnimationRepeatOnSlide
}
