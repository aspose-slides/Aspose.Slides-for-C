#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ConvertToGif()
{
    // The path to the documents directory
    String dataDir = GetDataPath();

    // The path to output file
    String outPath = Path::Combine(GetOutPath(), u"ConvertToGif.gif");

    // Instantiate a Presentation object that represents a presentation file
    auto presentation = System::MakeObject<Presentation>(dataDir + u"ConvertToGif.pptx");

    auto gifOptions = System::MakeObject<GifOptions>();
    // the size of the resulted GIF
    gifOptions->set_FrameSize(System::Drawing::Size(540, 480));
    // how long each slide will be showed until it will be changed to the next one
    gifOptions->set_DefaultDelay(1500);
    // increase FPS to better transition animation quality
    gifOptions->set_TransitionFps(60);

    // Save the presentation to Gif
    presentation->Save(outPath, SaveFormat::Gif, gifOptions);
}
