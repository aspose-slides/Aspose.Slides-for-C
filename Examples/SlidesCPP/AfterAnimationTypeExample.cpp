#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Animation;
using namespace Export;

void AfterAnimationTypeExample()
{
    // The path to the documents directory.
    String inputPath = Path::Combine(GetDataPath(), u"AnimationAfterEffect.pptx");
    String outPath = Path::Combine(GetOutPath(), u"AnimationAfterEffect-out.pptx");

    // Instantiate Presentation class that represents a presentation file
    auto pres = System::MakeObject<Presentation>(inputPath);
    auto slide = pres->get_Slide(0);

    // Add new slide to the presentation
    SharedPtr<ISlide> slide1 = pres->get_Slides()->AddClone(slide);
    // Get the first effect of the first slide
    SharedPtr<ISequence> seq = slide1->get_Timeline()->get_MainSequence();
    // Change the After animation effect to "Hide on Next Mouse Click" 
    for (auto&& effect : seq)
    {
        effect->set_AfterAnimationType(AfterAnimationType::HideOnNextMouseClick);
    }

    // Add new slide to the presentation
    SharedPtr<ISlide> slide2 = pres->get_Slides()->AddClone(slide);
    // Get the first effect of the first slide
    seq = slide2->get_Timeline()->get_MainSequence();
    // Change the After animation effect type to "Color"
    for (auto&& effect : seq)
    {
        effect->set_AfterAnimationType(AfterAnimationType::Color);
        effect->get_AfterAnimationColor()->set_Color(System::Drawing::Color::get_Green());
    }

    // Add new slide to the presentation
    SharedPtr<ISlide> slide3 = pres->get_Slides()->AddClone(slide);
    // Get the first effect of the first slide
    seq = slide3->get_Timeline()->get_MainSequence();
    // Change the After animation effect to "Hide After Animation" 
    for (auto&& effect : seq)
    {
        effect->set_AfterAnimationType(AfterAnimationType::HideAfterAnimation);
    }

    pres->Save(outPath, SaveFormat::Pptx);

}
