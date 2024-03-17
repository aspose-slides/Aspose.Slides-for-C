#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void ExternalUrlOriginal()
{
    const System::String presentationName = Path::Combine(GetDataPath(), u"ExternalUrlOriginal.pptx");

    auto presentation = System::MakeObject<Presentation>(presentationName);
    auto shape = System::ExplicitCast<AutoShape>(presentation->get_Slide(0)->get_Shape(1));
    auto portion = shape->get_TextFrame()->get_Paragraph(0)->get_Portion(0);

    auto hyperlinkClick = portion->get_PortionFormat()->get_HyperlinkClick();

    // Show fake hyperlink
    System::Console::WriteLine(u"Fake External Hyperlink : {0}", hyperlinkClick->get_ExternalUrl());

    // Show real hyperlink
    System::Console::WriteLine(u"Real External Hyperlink : {0}", hyperlinkClick->get_ExternalUrlOriginal());
}
