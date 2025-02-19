#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void TrimmingTimeAudioExample()
{
    const String mediaFile = Path::Combine(GetDataPath(), u"audio.m4a");
    const String outPath = Path::Combine(GetOutPath(), u"AudioFrameTrim_out.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Add Audio Frame
    SharedPtr<IAudio> audio = pres->get_Audios()->AddAudio(File::ReadAllBytes(mediaFile));
    SharedPtr<IAudioFrame> audioFrame = pres->get_Slide(0)->get_Shapes()->AddAudioFrameEmbedded(50.0f, 50.0f, 100.0f, 100.0f, audio);

    // Set the start trimming time 0.5 seconds
    audioFrame->set_TrimFromStart(500.0f);
    // Set the end trimming time 1 seconds
    audioFrame->set_TrimFromEnd(1000.0f);

    pres->Save(outPath, SaveFormat::Pptx);
}
