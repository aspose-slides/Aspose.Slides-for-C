#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void DisableFontLigaturesExample()
{
    const String inputPath = Path::Combine(GetDataPath(), u"TextLigatures.pptx");
    const String outPathEnabled = Path::Combine(GetOutPath(), u"EnableLigatures-out.html");
    const String outPathDisabled = Path::Combine(GetOutPath(), u"DisableLigatures-out.html");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(inputPath);

    // Save with enabled ligatures
    pres->Save(outPathEnabled, SaveFormat::Html);

    // Configure export options
    SharedPtr<HtmlOptions> options = MakeObject<HtmlOptions>();
    // Disable ligatures in rendered text
    options->set_DisableFontLigatures(true);

    // Export presentation to HTML with disabled ligatures
    pres->Save(outPathDisabled, SaveFormat::Html, options);
}
