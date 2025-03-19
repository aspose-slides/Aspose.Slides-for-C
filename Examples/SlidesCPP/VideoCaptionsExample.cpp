#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void VideoCaptionsExample()
{
    //ExStart:VideoCaptionsExample

    const String mediaFile = Path::Combine(GetDataPath(), u"NewVideo.mp4");
    const String trackFile = Path::Combine(GetDataPath(), u"bunny.vtt");
    const String outCaptionsFile = Path::Combine(GetOutPath(), u"Caption_out.vtt");
    const String outAddCaptionsPath = Path::Combine(GetOutPath(), u"VideoCaptionAdd_out.pptx");
    const String outRemoveCaptionsPath = Path::Combine(GetOutPath(), u"VideoCaptionRemove_out.pptx");

    // Add captions to a VideoFrame
    SharedPtr<Presentation> pres = MakeObject<Presentation>();
    SharedPtr<IVideo> video = pres->get_Videos()->AddVideo(File::ReadAllBytes(mediaFile));
    SharedPtr<IVideoFrame> videoFrame = pres->get_Slide(0)->get_Shapes()->AddVideoFrame(0, 0, 100, 100, video);

    // Adds the new captions track from file
    videoFrame->get_CaptionTracks()->Add(u"New track", trackFile);

    pres->Save(outAddCaptionsPath, SaveFormat::Pptx);

    // Extract captions from a VideoFrame
    pres = MakeObject<Presentation>(outAddCaptionsPath);
    videoFrame = AsCast<VideoFrame>(pres->get_Slide(0)->get_Shape(0));
    if (videoFrame != nullptr)
    {
        for (auto&& captionTrack : videoFrame->get_CaptionTracks())
        {
            // Extracts the captions binary data and saves theme to the file
            File::WriteAllBytes(outCaptionsFile, captionTrack->get_BinaryData());
        }

        // Removes all captions from the VideoFrame
        videoFrame->get_CaptionTracks()->Clear();

        pres->Save(outRemoveCaptionsPath, SaveFormat::Pptx);
    }

    //ExEnd:VideoCaptionsExample
}
