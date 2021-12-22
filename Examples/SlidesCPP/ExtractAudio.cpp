#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ExtractAudio()
{
    String dataDir = GetDataPath();
    String presName = dataDir + u"AudioSlide.ppt";

    // Instantiate Presentation class that represents the presentation file
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presName);

    // Access the desired slide
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    // Get the slideshow transition effects for slide
    SharedPtr<ISlideShowTransition> transition = slide->get_SlideShowTransition();

    //Extract sound in byte array
    ArrayPtr<uint8_t> audio = transition->get_Sound()->get_BinaryData();

    Console::WriteLine(String(u"Length: ") + audio->get_Length());
}
