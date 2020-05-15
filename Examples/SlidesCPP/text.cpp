#include "stdafx.h"
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IAutoShape.h>
#include <DOM/Portion.h>
#include <DOM/Paragraph.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/ITextFrame.h>
#include <DOM/ShapeType.h>
#include <DOM/Fonts/FontData.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "text.h"

using namespace Aspose::Slides;

using namespace System;

void ::Text::SampleAddText()
{
    auto pres = MakeObject<Presentation>();

    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
    SharedPtr<IAutoShape> shape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 200, 200);

    SharedPtr<Paragraph> paragraph = MakeObject<Paragraph>();
    SharedPtr<Portion> portion1 = MakeObject<Portion>(L"Text 1.1");
    portion1->get_PortionFormat()->set_LatinFont(MakeObject<FontData>(L"Calibri"));

    SharedPtr<Portion> portion2 = MakeObject<Portion>(L"Text 1.2");
    portion2->get_PortionFormat()->set_LatinFont(MakeObject<FontData>(L"Arial"));

    SharedPtr<Portion> portion3 = MakeObject<Portion>(L"Text 1.3");
    portion3->get_PortionFormat()->set_LatinFont(MakeObject<FontData>(L"Adobe Garamond Pro"));

    paragraph->get_Portions()->Add(portion1);
    paragraph->get_Portions()->Add(portion2);
    paragraph->get_Portions()->Add(portion3);

    shape->get_TextFrame()->get_Paragraphs()->Add(paragraph);

    pres->Save(L"../out/SampleAddText.pptx", Export::SaveFormat::Pptx);
}
