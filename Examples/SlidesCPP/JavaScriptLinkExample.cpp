#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void JavaScriptLinkExample()
{
    //ExStart:JavaScriptLinkExample

    // Path for source presentation
    const String pptxPath = Path::Combine(GetDataPath(), u"JavaScriptLink.pptx");
    // Out path
    const String outPath = Path::Combine(GetOutPath(), u"JavaScriptLink-out.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxPath);

    SharedPtr<PptxOptions> options = MakeObject<PptxOptions>();
    options->set_SkipJavaScriptLinks(true);

    pres->Save(outPath, SaveFormat::Pptx, options);

    //ExEnd:JavaScriptLinkExample
}
