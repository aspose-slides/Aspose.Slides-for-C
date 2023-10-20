#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void NumberLinesInParagraph()
{
    //ExStart:NumberLinesInParagraph

    SharedPtr<Presentation> presentation = MakeObject<Presentation>();

    SharedPtr<ISlide> sld = presentation->get_Slide(0);
    SharedPtr<IAutoShape> ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150.0f, 75.0f, 150.0f, 50.0f);
    SharedPtr<IParagraph> para = ashp->get_TextFrame()->get_Paragraph(0);
    SharedPtr<IPortion> portion = para->get_Portion(0);
    portion->set_Text(u"Aspose Paragraph GetLinesCount() Example");

    Console::WriteLine(u"Lines Count = {0}", para->GetLinesCount());

    // Change shape width
    ashp->set_Width(250.0f);
    Console::WriteLine(u"Lines Count after changing shape width = {0}", para->GetLinesCount());

    //ExEnd:NumberLinesInParagraph
}
