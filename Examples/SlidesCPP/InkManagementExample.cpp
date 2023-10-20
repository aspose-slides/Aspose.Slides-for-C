#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Ink;
using namespace System;
using namespace IO;

void InkManagementExample()
{
    //ExStart:InkManagementExample

    // Path to source presentation
    const String presentationName = Path::Combine(GetDataPath(), u"SimpleInk.pptx");
    // Path to output document
    const String outFilePath = Path::Combine(GetOutPath(), u"SimpleInk_out.pptx");

    SharedPtr<Presentation> presentation = MakeObject<Presentation>(presentationName);

    // Get Ink shape
    auto inkShape = AsCast<IInk>(presentation->get_Slide(0)->get_Shape(0));

    if (inkShape != nullptr)
    {
        SharedPtr<IInkBrush> brush = inkShape->get_Traces()[0]->get_Brush();
        Console::WriteLine(u"Width of the Ink shape = {0}", inkShape->get_Width());
        Console::WriteLine(u"Height of the Ink shape = {0}", inkShape->get_Height());
        Console::WriteLine(u"Brush height of the trace = {0}", brush->get_Size().get_Width());
        Console::WriteLine(u"Brush color of the trace = {0}", brush->get_Color());

        // Change color and size of the brush
        brush->set_Color(System::Drawing::Color::get_Red());
        brush->set_Size(System::Drawing::SizeF(10.0f, 5.0f));
    }

    // Save presentation
    presentation->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:InkManagementExample
}
