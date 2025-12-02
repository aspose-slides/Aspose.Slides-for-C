#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Animation;
using namespace System;
using namespace IO;

void AnimationDurationSlide()
{
    // ExStart:AnimationDurationSlide

    // The path to the documents directory
    const String pptxPath = Path::Combine(GetDataPath(), u"AnimationDurationSlides.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"AnimationDurationSlides-out.pptx");

    // Instantiate Presentation class that represents a presentation file
    auto pres = MakeObject<Presentation>(pptxPath);
    for (auto&& slide : pres->get_Slides())
    {
        // Sets the transition duration to 0.25s
        slide->get_SlideShowTransition()->set_Duration(250);
    }

    // Save the result
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:AnimationDurationSlide
}
