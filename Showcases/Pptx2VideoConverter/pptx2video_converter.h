#ifndef PPTX2VIDEO_CONVERTER_H
#define PPTX2VIDEO_CONVERTER_H

#include <system/string.h>
#include <system/shared_ptr.h>

#include <DOM/Presentation.h>
#include <Export/FramesStream/PresentationPlayer.h>
#include <Export/FramesStream/FrameTickEventArgs.h>

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

class Pptx2VideoConverter : public System::Object
{
public:
    Pptx2VideoConverter(
        System::SharedPtr<Presentation> presentation,
        const System::String& outVideoPath,
        const System::String& tempFolderPath,
        int32_t fps);

    void GenerateFrames();
    void RunFFmpeg();

private:
    void OnFrameTick(
        System::SharedPtr<PresentationPlayer> sender,
        System::SharedPtr<FrameTickEventArgs> args);

private:
    System::SharedPtr<Presentation> m_presentation;
    const System::String m_outVideoPath;
    const System::String m_tempFolderPath;
    const int32_t m_fps;
};

#endif /* PPTX2VIDEO_CONVERTER_H */
