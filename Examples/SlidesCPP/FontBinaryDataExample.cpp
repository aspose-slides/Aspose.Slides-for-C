#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void FontBinaryDataExample()
{
    // ExStart:FontBinaryDataExample

    // The path to the presentation
    const System::String dataPath = Path::Combine(GetDataPath(), u"Presentation.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(dataPath);
    System::SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

    // Retrieve all fonts used in the presentation
    System::ArrayPtr<System::SharedPtr<IFontData>> fonts = fontsManager->GetFonts();

    // Get the byte array representing the regular style of the first font in the presentation
    System::ArrayPtr<uint8_t> bytes = fontsManager->GetFontBytes(fonts[0], System::Drawing::FontStyle::Regular);

    // The path to output file
    const System::String outFilePath = Path::Combine(GetOutPath(), System::String::Concat(fonts[0]->get_FontName(), u".ttf"));

    // Save font
    File::WriteAllBytes(outFilePath, bytes);

    // Print message
    System::Console::WriteLine(u"Font \"{0}\" saved to file \"{1}\"", fonts[0]->get_FontName(), outFilePath);

    // ExEnd:FontBinaryDataExample
}
