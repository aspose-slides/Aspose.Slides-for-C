#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void FindAndReplaceText()
{
    // ExStart:FindAndReplaceText

    // The path to the documents directory.
    const String templatePath = Path::Combine(GetDataPath(), u"TextReplaceExample.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"TextReplaceExample-out.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    auto format = System::MakeObject<PortionFormat>();
    format->set_FontHeight(24.0f);
    format->set_FontItalic(NullableBool::True);
    auto fillFormat = format->get_FillFormat();
    fillFormat->set_FillType(FillType::Solid);
    fillFormat->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());

    Util::SlideUtil::FindAndReplaceText(pres, true, u"[this block] ", u"my text ", format);
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:FindAndReplaceText
}
