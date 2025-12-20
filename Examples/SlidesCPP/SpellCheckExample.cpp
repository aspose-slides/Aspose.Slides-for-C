#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SpellCheckExample()
{
    //ExStart:SpellCheckExample

    const String pptxPath = Path::Combine(GetDataPath(), u"SpellChecksExample.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"SpellChecksExample-out.pptx");

    auto pres = MakeObject<Presentation>(pptxPath);

    // Access the first portion of text inside the first shape on the first slide
    auto portion = ExplicitCast<AutoShape>(pres->get_Slide(0)->get_Shape(0))->get_TextFrame()->get_Paragraph(0)->get_Portion(0);

    // Read spell checking property
    Console::WriteLine(u"SpellCheck is {0}", portion->get_PortionFormat()->get_SpellCheck());

    // Disable spell checking for this text portion
    portion->get_PortionFormat()->set_SpellCheck(true);

    // Save the modified presentation
    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:SpellCheckExample
}
