#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void AudioCaptionsExample()
{
    //ExStart:AudioCaptionsExample

    const String mediaFile = Path::Combine(GetDataPath(), u"audio.mp3");
    const String trackFile = Path::Combine(GetDataPath(), u"track.vtt");
    const String outCaptionFile = Path::Combine(GetOutPath(), u"AudioCaption_out.vtt");
    const String outAddPath = Path::Combine(GetOutPath(), u"AudioCaptionAdd_out.pptx");
    const String outRemovePath = Path::Combine(GetOutPath(), u"AudioCaptionRemove_out.pptx");

    // Add captions to a VideoFrame
    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    SharedPtr<IAudio> audio = pres->get_Audios()->AddAudio(File::ReadAllBytes(mediaFile));
    auto audioFrame = pres->get_Slide(0)->get_Shapes()->AddAudioFrameEmbedded(10, 10, 50, 50, audio);

    // Adds the new captions track from file
    audioFrame->get_CaptionTracks()->Add(u"New track", trackFile);
    pres->Save(outAddPath, SaveFormat::Pptx);

    // Extract captions from a VideoFrame
    pres = MakeObject<Presentation>(outAddPath);

    audioFrame = AsCast<IAudioFrame>(pres->get_Slide(0)->get_Shape(0));
    if (audioFrame != nullptr)
    {
        for (auto&& captionTrack : audioFrame->get_CaptionTracks())
        {
            // Extracts the captions binary data and saves theme to the file
            File::WriteAllBytes(outCaptionFile, captionTrack->get_BinaryData());
        }

        // Removes all captions from the VideoFrame
        audioFrame->get_CaptionTracks()->Clear();

        pres->Save(outRemovePath, SaveFormat::Pptx);
    }

    //ExEnd:AudioCaptionsExample
}
