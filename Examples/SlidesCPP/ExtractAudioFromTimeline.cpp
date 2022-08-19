#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Animation;
using namespace System;
using namespace System::IO;

// The example shows how to extracting an audio file from a slide timeline.
void ExtractAudioFromTimeline()
{
    const String templatePath = Path::Combine(GetDataPath(), u"AnimationAudio.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"MediaTimeline.mpg");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Gets first slide of the presentation
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    // Gets the effects sequence for the slide
    SharedPtr<ISequence> effectsSequence = slide->get_Timeline()->get_MainSequence();

    // Extracts the effect sound in byte array
    System::ArrayPtr<uint8_t> audio = effectsSequence->idx_get(0)->get_Sound()->get_BinaryData();

    // Saves effect sound to media file
    File::WriteAllBytes(outPath, audio);
}
