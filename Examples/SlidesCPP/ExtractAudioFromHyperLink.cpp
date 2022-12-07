#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ExtractAudioFromHyperLink()
{
    const String pptxFile = Path::Combine(GetDataPath(), u"HyperlinkSound.pptx");
    const String outMediaPath = Path::Combine(GetOutPath(), u"HyperlinkSound.mpg");

    auto pres = System::MakeObject<Presentation>(pptxFile);

    // Gets the first shape hyperlink
    SharedPtr<IHyperlink> link = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_HyperlinkClick();

    if (link->get_Sound() != nullptr)
    {
        // Extracts the hyperlink sound in byte array
        ArrayPtr<uint8_t> audioData = link->get_Sound()->get_BinaryData();

        // Saves effect sound to media file
        File::WriteAllBytes(outMediaPath, audioData);
    }
}
