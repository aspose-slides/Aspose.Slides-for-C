#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::Drawing;

void AddEmbeddedFonts()
{
    // ExStart:AddEmbeddedFonts
    // The path to the documents directory.
    const String outPath = u"../out/AddEmbeddedFonts_out.pptx";
    const String templatePath = u"../templates/EmbeddedFonts.pptx";

    // Load the desired the presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    // Access first slide
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

    // get all embedded fonts
    ArrayPtr<SharedPtr<IFontData>> embeddedFonts = fontsManager->GetEmbeddedFonts();
    ArrayPtr<SharedPtr<IFontData>> allFonts = fontsManager->GetFonts();

    for(auto font : allFonts)
    {
        if (embeddedFonts->Contains(font))
        {
            fontsManager->AddEmbeddedFont(font, EmbedFontCharacters::All);
        }
    }

    // save the presentation without embedded "Calibri" font
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:AddEmbeddedFonts
}
