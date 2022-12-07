#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Animation;
using namespace System;
using namespace IO;

void StopPreviousSoundExample()
{
    const String pptxFile = Path::Combine(GetDataPath(), u"AnimationStopSound.pptx");
    const String outPath = Path::Combine(GetDataPath(), u"AnimationStopSound-out.pptx");

    auto pres = System::MakeObject<Presentation>(pptxFile);

    // Gets the first effect of the first slide.
    SharedPtr<IEffect> firstSlideEffect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->idx_get(0);

    // Gets the first effect of the second slide.
    SharedPtr<IEffect> secondSlideEffect = pres->get_Slides()->idx_get(1)->get_Timeline()->get_MainSequence()->idx_get(0);

    if (firstSlideEffect->get_Sound() != nullptr)
    {
        // Changes the second effect Enhancements/Sound to "Stop Previous Sound"
        secondSlideEffect->set_StopPreviousSound(true);
    }

    pres->Save(outPath, SaveFormat::Pptx);
}