#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void ConvertToHtml5()
{
    const System::String templatePath = Path::Combine(GetDataPath(), u"demo.pptx");

    // The path to output file
    const System::String outFilePath = Path::Combine(GetOutPath(), u"Demo.html");
    
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Export a presentation containing slides transitions, animations, and shapes animations to HTML5
    System::SharedPtr<Html5Options> options = System::MakeObject<Html5Options>();
    options->set_AnimateShapes(true);
    options->set_AnimateTransitions(true);

    // Save presentation
    pres->Save(outFilePath, SaveFormat::Html5, options);
}
