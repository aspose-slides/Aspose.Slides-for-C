#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void GridProperties()
{
    //ExStart:GridProperties

    const System::String outFilePath = Path::Combine(GetOutPath(), u"GridProperties-out.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Set grid spacing
    pres->get_ViewProperties()->set_GridSpacing(72.0f);

    // Save presentation
    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:GridProperties
}
