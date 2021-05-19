#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void MacroHyperlink()
{
    //ExStart:MacroHyperlink
    String macroName = u"TestMacro";
    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();
    
    SharedPtr<IAutoShape> shape = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::BlankButton, 20.0f, 20.0f, 80.0f, 30.0f);
    shape->get_HyperlinkManager()->SetMacroHyperlinkClick(macroName);

    Console::WriteLine(u"External URL is {0}", shape->get_HyperlinkClick()->get_ExternalUrl());
    Console::WriteLine(u"Shape action type is {0}", shape->get_HyperlinkClick()->get_ActionType());
    //ExEnd:MacroHyperlink
}
