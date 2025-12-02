#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void FindTextOptions()
{
    // ExStart:FindTextOptions

    const String presentationName = Path::Combine(GetDataPath(), u"TextOptionsExample.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"TextOptionsExample-out.pptx");

    auto pres = MakeObject<Presentation>(presentationName);

    // Set text search options
    auto options = MakeObject<TextSearchOptions>();
    options->set_IncludeNotes(true);
    options->set_CaseSensitive(true);

    // Replace text
    pres->ReplaceText(u"old", u"new", options, nullptr);

    // Save result
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:FindTextOptions
}
