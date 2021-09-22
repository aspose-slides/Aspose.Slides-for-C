#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void ConvertToHtml5()
{
    // The path to output file
    String outFilePath = IO::Path::Combine(GetOutPath(), u"Demo.html");
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(GetDataPath() + u"demo.pptx");

    // Export a presentation containing slides transitions, animations, and shapes animations to HTML5
    SharedPtr<Html5Options> options = System::MakeObject<Html5Options>();
    options->set_AnimateShapes(true);
    options->set_AnimateTransitions(true);

    // Save presentation
    pres->Save(outFilePath, SaveFormat::Html5, options);
}
