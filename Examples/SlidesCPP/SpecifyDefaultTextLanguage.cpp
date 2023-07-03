#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SpecifyDefaultTextLanguage()
{
    //ExStart:SpecifyDefaultTextLanguage

    SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
    loadOptions->set_DefaultTextLanguage(u"en-US");
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(loadOptions);

    SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Add new rectangle shape with text
    SharedPtr<IAutoShape> shp = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50.0f, 50.0f, 150.0f, 50.0f);
    shp->get_TextFrame()->set_Text(u"New Text");

    SharedPtr<IPortion> portion = shp->get_TextFrame()->get_Paragraph(0)->get_Portion(0);
    // Check the first portion language
    Console::WriteLine(portion->get_PortionFormat()->get_LanguageId());

    //ExEnd:SpecifyDefaultTextLanguage
}
