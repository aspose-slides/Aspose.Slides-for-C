#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void TableTransparency()
{
    // ExStart:TableTransparency
    // The path to the presentation
    const System::String templatePath = Path::Combine(GetDataPath(), u"TableTransparency.pptx");

    // The path to output file
    const System::String outPath = Path::Combine(GetOutPath(), u"TableTransparency_out.pptx");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Get a table
    System::SharedPtr<ITable> table = System::ExplicitCast<ITable>(pres->get_Slide(0)->get_Shape(1));

    // Set transparency of the table to 62%
    table->get_TableFormat()->set_Transparency(0.62f);

    // Save presentation
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:TableTransparency
}
