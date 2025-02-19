#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void VolumeAudioExample()
{
    const String mediaFile = Path::Combine(GetDataPath(), u"audio.m4a");
    const String outPath = Path::Combine(GetOutPath(), u"AudioFrameValue_out.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Add Audio Frame
    SharedPtr<IAudio> audio = pres->get_Audios()->AddAudio(File::ReadAllBytes(mediaFile));
    SharedPtr<IAudioFrame> audioFrame = pres->get_Slide(0)->get_Shapes()->AddAudioFrameEmbedded(50.0f, 50.0f, 100.0f, 100.0f, audio);

    // Set the audio volume for 85%
    audioFrame->set_VolumeValue(85.0f);

    pres->Save(outPath, SaveFormat::Pptx);
}
