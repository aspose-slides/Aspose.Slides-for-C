#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

void SetVideoTrimFromEnd()
{
    //ExStart:SetVideoTrimFromEnd

    // The path to the documents directory.
    const System::String videoFileName = u"../templates/Wildlife.mp4";
    const System::String outPath = u"../out/VideoTrimming-out.pptx";

    auto pres = System::MakeObject<Presentation>();

    System::SharedPtr<ISlide> slide = pres->get_Slide(0);
    System::SharedPtr<IVideo> video = pres->get_Videos()->AddVideo(System::IO::File::ReadAllBytes(videoFileName));
    auto videoFrame = slide->get_Shapes()->AddVideoFrame(0.0f, 0.0f, 200.0f, 200.0f, video);

    // sets the trimming start time to 12sec
    videoFrame->set_TrimFromStart(12000.0f);

    // sets the triming end time to 16sec
    videoFrame->set_TrimFromEnd(14000.0f);

    // Save presentation
    pres->Save(outPath, Export::SaveFormat::Pptx);

    // ExEnd:SetVideoTrimFromEnd
}
