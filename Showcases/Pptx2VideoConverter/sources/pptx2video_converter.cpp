#include <system/shared_ptr.h>
#include <system/string.h>
#include <system/io/path.h>
#include <system/io/directory.h>
#include <drawing/bitmap.h>
#include <system/diagnostics/process.h>
#include <system/diagnostics/process_start_info.h>
#include <system/diagnostics/process_window_style.h>

#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <Export/FramesStream/PresentationAnimationsGenerator.h>
#include <Export/FramesStream/PresentationPlayer.h>
#include <Export/FramesStream/FrameTickEventArgs.h>

#include "pptx2video_converter.h"

using namespace Aspose::Slides;
using namespace System::IO;
using namespace System::Diagnostics;

Pptx2VideoConverter::Pptx2VideoConverter(
    System::SharedPtr<Presentation> presentation,
    const System::String& outVideoPath,
    const System::String& tempFolderPath,
    int32_t fps
    )
    : m_presentation(presentation)
    , m_outVideoPath(outVideoPath)
    , m_tempFolderPath(tempFolderPath)
    , m_fps(fps)
{
    if (Directory::Exists(m_tempFolderPath))
        Directory::Delete(m_tempFolderPath, true);

    Directory::CreateDirectory_(m_tempFolderPath);
}

void Pptx2VideoConverter::GenerateFrames()
{
    auto animationsGenerator = System::MakeObject<PresentationAnimationsGenerator>(m_presentation);
    auto player = System::MakeObject<PresentationPlayer>(animationsGenerator, m_fps);

    player->FrameTick.connect(&Pptx2VideoConverter::OnFrameTick, this);
    animationsGenerator->Run(m_presentation->get_Slides());
}

void Pptx2VideoConverter::OnFrameTick(
    System::SharedPtr<PresentationPlayer> sender,
    System::SharedPtr<FrameTickEventArgs> args)
{
    auto fileName = System::String::Format(u"frame_{0}.png", sender->get_FrameIndex());
    args->GetFrame()->Save(Path::Combine(m_tempFolderPath, fileName));
}

void Pptx2VideoConverter::RunFFmpeg()
{
    const System::String fileMask = Path::Combine(m_tempFolderPath, u"frame_%d.png");

    auto ffmpegProcessStartInfo = System::MakeObject<ProcessStartInfo>();
    ffmpegProcessStartInfo->set_FileName(u"ffmpeg");
    ffmpegProcessStartInfo->set_Arguments(System::String::Format(
        u"-loglevel {0} -framerate {1} -i {2} -y -c:v {3} -pix_fmt {4} {5}",
        u"warning", m_fps, fileMask, u"libx264", u"yuv420p", m_outVideoPath
    ));
    ffmpegProcessStartInfo->set_WindowStyle(ProcessWindowStyle::Hidden);
    ffmpegProcessStartInfo->set_CreateNoWindow(true);

    auto ffmpegProcess = Process::Start(ffmpegProcessStartInfo);
    ffmpegProcess->WaitForExit();
    int exitCode = ffmpegProcess->get_ExitCode();
    if (exitCode != 0)
        throw System::Exception(System::String::Format(u"FFmpeg failed with exit code {0}", exitCode));
}
