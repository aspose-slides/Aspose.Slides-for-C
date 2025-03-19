#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SplitTextByColumnsExample()
{
    //ExStart:SplitTextByColumnsExample

    const String presentationName = Path::Combine(GetDataPath(), u"MultiColumnText.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(presentationName);

    // Get the first shape on the slide
    SharedPtr<IAutoShape> shape = AsCast<IAutoShape>(pres->get_Slide(0)->get_Shape(0));
    // Get textFrame
    SharedPtr<ITextFrame> textFrame = shape->get_TextFrame();
    // Split the text frame content into columns
    ArrayPtr<String> columnsText = textFrame->SplitTextByColumns();

    // Print each column's text to the console
    for (auto&& column : columnsText)
        Console::WriteLine(column);

    //ExEnd:SplitTextByColumnsExample
}
