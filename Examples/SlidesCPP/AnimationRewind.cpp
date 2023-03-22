#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Animation;

void AnimationRewind()
{
    //ExStart:AnimationRewind

    // The path to the documents directory.
    const System::String templatePath = u"../templates/AnimationRewind.pptx";
    const System::String outPath = u"../out/AnimationRewind-out.pptx";

    // Instantiate Presentation class that represents a presentation file
    auto presentation = System::MakeObject<Presentation>(templatePath);

    // Gets the effects sequence for the first slide
    System::SharedPtr<ISequence> effectsSequence = presentation->get_Slide(0)->get_Timeline()->get_MainSequence();

    // Gets the first effect of the main sequence.
    System::SharedPtr<IEffect> effect = effectsSequence->idx_get(0);
    System::Console::WriteLine(u"\nEffect Timing/Rewind in source presentation is {0}", effect->get_Timing()->get_Rewind());
    // Turns the effect Timing/Rewind on.
    effect->get_Timing()->set_Rewind(true);

    // Save presentation
    presentation->Save(outPath, Export::SaveFormat::Pptx);

    auto pres = System::MakeObject<Presentation>(outPath);

    // Gets the effects sequence for the first slide
    effectsSequence = pres->get_Slide(0)->get_Timeline()->get_MainSequence();

    // Gets the first effect of the main sequence.
    effect = effectsSequence->idx_get(0);
    System::Console::WriteLine(u"Effect Timing/Rewind in destination presentation is {0}\n", effect->get_Timing()->get_Rewind());

    // ExEnd:AnimationRewind
}
