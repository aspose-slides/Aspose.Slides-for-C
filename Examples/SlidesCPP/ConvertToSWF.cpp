#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;

void ConvertToSWF()
{
    //ExStart:ConvertToSWF
    // The path to the documents directory.
    const String outPath = u"../out/ConvertToSWF_out.swf";
    const String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    SharedPtr<SwfOptions> swfOptions = MakeObject<SwfOptions>();
    swfOptions->set_ViewerIncluded(true);

    pres->Save(outPath, SaveFormat::Swf, swfOptions);

    //ExEnd:ConvertToSWF
}
