#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void MutableHyperlink()
{
	//ExStart:MutableHyperlink
    SharedPtr <Presentation> presentation = System::MakeObject <Presentation>();
    SharedPtr <IAutoShape> shape1 = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 600, 50, false);
    shape1->AddTextFrame(u"Aspose: File Format APIs");
    shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_HyperlinkClick(System::MakeObject < Hyperlink >(u"https://www.aspose.com/"));
    shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_HyperlinkClick()->set_Tooltip(u"More than 70% Fortune 100 companies trust Aspose APIs");

    shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_FontHeight(32);
    presentation->Save(u"../out/presentation-out.pptx", Export::SaveFormat::Pptx);
    //ExEnd:MutableHyperlink
}
