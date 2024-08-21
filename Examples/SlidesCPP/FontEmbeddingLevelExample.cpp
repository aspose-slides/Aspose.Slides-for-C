#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void FontEmbeddingLevelExample()
{
    // ExStart:FontEmbeddingLevelExample

    // The path to the presentation
    const System::String dataPath = Path::Combine(GetDataPath(), u"Presentation.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(dataPath);
    System::SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

    // Retrieve all fonts used in the presentation
    System::ArrayPtr<System::SharedPtr<IFontData>> fonts = fontsManager->GetFonts();

    // Get the byte array representing the regular style of the first font in the presentation
    System::ArrayPtr<uint8_t> bytes = fontsManager->GetFontBytes(fonts[0], System::Drawing::FontStyle::Regular);

    // Determine the embedding level of the font
    EmbeddingLevel embeddingLevel = fontsManager->GetFontEmbeddingLevel(bytes, fonts[0]->get_FontName());

    // Print embedding level to console
    System::Console::WriteLine(u"Font \"{0}\" has \"{1}\" embedding level", fonts[0]->get_FontName(), embeddingLevel);

    // ExEnd:FontEmbeddingLevelExample
}
