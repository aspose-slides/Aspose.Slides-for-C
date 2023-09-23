#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

void SlideShowMediaControls()
{
    //ExStart:SlideShowMediaControls

    // Path to output document
    const String outFileName = u"../out/SlideShowMediaControl.pptx";

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Enable media control display in slideshow mode
    pres->get_SlideShowSettings()->set_ShowMediaControls(true);

    // Save presentation
    pres->Save(outFileName, SaveFormat::Pptx);

    //ExEnd:SlideShowMediaControls
}
