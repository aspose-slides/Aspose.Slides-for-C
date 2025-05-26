#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ConvertToHtml5Handout()
{
    // Path to files
    const String presFilePath = Path::Combine(GetDataPath(), u"HandoutExample.pptx");
    const String outFilePath = Path::Combine(GetOutPath(), u"HandoutExample.html");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(presFilePath);
    SharedPtr<HandoutLayoutingOptions> slidesLayoutOptions = MakeObject<HandoutLayoutingOptions>();
    slidesLayoutOptions->set_Handout(HandoutType::Handouts4Horizontal);
    SharedPtr<Html5Options> options = MakeObject<Html5Options>();
    options->set_SlidesLayoutOptions(slidesLayoutOptions);

    // Save result
    pres->Save(outFilePath, SaveFormat::Html5, options);
}
