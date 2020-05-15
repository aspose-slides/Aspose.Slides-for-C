#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddVideoFrame()
{
    // ExStart:AddVideoFrame
    // The path to the documents directory.
    const String outPath = u"../out/AddVideoFrame_out.pptx";
    const String filePath = u"../templates/Wildlife.mp4";

    // Load the desired the presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Access first slide
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    // Load the wav sound file to stream
    SharedPtr<IO::FileStream> stream = System::MakeObject<IO::FileStream>(
        filePath, IO::FileMode::Open, IO::FileAccess::Read);

    // Add Video Frame
    SharedPtr<IVideoFrame> vf = slide->get_Shapes()->AddVideoFrame(50, 150, 300, 150, filePath);

    // Set Play Mode and Volume of the Video
    vf->set_PlayMode(VideoPlayModePreset::Auto);
    vf->set_Volume(AudioVolumeMode::Loud);

    //Write the PPTX file to disk
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:AddVideoFrame
}
