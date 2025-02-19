#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void FadeInOutDurationAudioExample()
{
    const String mediaFile = Path::Combine(GetDataPath(), u"audio.m4a");
    const String outPath = Path::Combine(GetOutPath(), u"AudioFrameFade_out.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Add Audio Frame
    SharedPtr<IAudio> audio = pres->get_Audios()->AddAudio(File::ReadAllBytes(mediaFile));
    SharedPtr<IAudioFrame> audioFrame = pres->get_Slide(0)->get_Shapes()->AddAudioFrameEmbedded(50.0f, 50.0f, 100.0f, 100.0f, audio);

    // Set the duration of the starting fade for 200ms
    audioFrame->set_FadeInDuration(200.0f);
    // Set the duration of the ending fade for 500ms
    audioFrame->set_FadeOutDuration(500.0f);

    pres->Save(outPath, SaveFormat::Pptx);
}
