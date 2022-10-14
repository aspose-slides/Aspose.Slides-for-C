#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;
using namespace System::Drawing;

/*
The example shows how to set up the slide show paramentes of the presentation.
After running this example, you can open the slideshow settings of the saved presentation and see the settings set by this example there.
*/
void PresentationSlideShowSetup()
{
    // Path for out presentation
    const String outPath = Path::Combine(GetOutPath(), u"PresentationSlideShowSetup.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Gets SlideShow settings
    SharedPtr<SlideShowSettings> slideShowSettings = pres->get_SlideShowSettings();

    // Sets "Using Timing" parameter
    slideShowSettings->set_UseTimings(false);

    // Sets Pen color
    auto penColor = System::ExplicitCast<IColorFormat>(slideShowSettings->get_PenColor());
    penColor->set_Color(Color::get_Green());

    // Adds slides for
    {
        SharedPtr<ISlideCollection> slides = pres->get_Slides();

        slides->AddClone(slides->idx_get(0));
        slides->AddClone(slides->idx_get(0));
        slides->AddClone(slides->idx_get(0));
        slides->AddClone(slides->idx_get(0));
    }

    // Sets Show Slide parameter
    SharedPtr<SlidesRange> slidesRange = System::MakeObject<SlidesRange>();
    slidesRange->set_Start(2);
    slidesRange->set_End(5);
    slideShowSettings->set_Slides(slidesRange);

    // Save presentation
    pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
}
