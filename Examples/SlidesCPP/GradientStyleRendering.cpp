#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void GradientStyleRendering()
{
    //ExStart:GradientStyleRendering
    const String dataPath = Path::Combine(GetDataPath(), u"GradientStyleExample.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"GradientStyleExample-out.png");

    SharedPtr<Presentation> presentation = MakeObject<Presentation>(dataPath);

    SharedPtr<RenderingOptions> options = MakeObject<RenderingOptions>();
    // Set rendering the two-color gradient according to its appearance in the PowerPoint user interface.
    options->set_GradientStyle(GradientStyle::PowerPointUI);

    // Get the image.
    SharedPtr<IImage> img = presentation->get_Slide(0)->GetImage(options, 2.0f, 2.0f);

    // Save image.
    img->Save(outPath, ImageFormat::Png);

    //ExEnd:GradientStyleRendering
}
