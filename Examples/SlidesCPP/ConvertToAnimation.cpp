#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

static void OnFrameTick(SharedPtr<PresentationPlayer> sender, SharedPtr<FrameTickEventArgs> args)
{
    args->GetFrame()->Save(Path::Combine(GetOutPath(), String::Format(u"frame_{0}.png", sender->get_FrameIndex())));
}

void ConvertToAnimation()
{
    const String dataDir = GetDataPath();
    const String presentationName = Path::Combine(GetDataPath(), u"SimpleAnimations.pptx");

    const int32_t FPS = 30;

    auto presentation = System::MakeObject<Presentation>(presentationName);

    auto animationsGenerator = System::MakeObject<PresentationAnimationsGenerator>(presentation);
    auto player = System::MakeObject<PresentationPlayer>(animationsGenerator, FPS);

    player->FrameTick.connect(OnFrameTick);

    animationsGenerator->Run(presentation->get_Slides());
}
