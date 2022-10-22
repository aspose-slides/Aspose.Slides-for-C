#include "stdafx.h"
#include "SlidesExamples.h"
#include <LowCode/Compress.h>

using namespace Aspose::Slides;

void EmbeddedFontCompression()
{
    // ExStart:EmbeddedFontCompression

    const System::String presentationName = System::IO::Path::Combine(GetDataPath(), u"presWithEmbeddedFonts.pptx");
    const System::String outPath = System::IO::Path::Combine(GetOutPath(), u"presWithEmbeddedFonts-out.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationName);

    // Compress embedded fonts
    LowCode::Compress::CompressEmbeddedFonts(pres);
    // Save result
    pres->Save(outPath, Export::SaveFormat::Pptx);

    // Get source file info
    System::SharedPtr<System::IO::FileInfo> fi = System::MakeObject<System::IO::FileInfo>(presentationName);
    System::Console::WriteLine(u"Source file size = {0} bytes", fi->get_Length());
    // Get result file info
    fi = System::MakeObject<System::IO::FileInfo>(outPath);
    System::Console::WriteLine(u"Result file size = {0} bytes", fi->get_Length());

    // ExEnd:EmbeddedFontCompression
}
