#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;
using namespace Collections::Generic;

void ManageScriptFontsExample()
{
    //ExStart:ManageScriptFontsExample

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Get all script mapping
    SharedPtr<IDictionary<String, String>> scriptFontMap = pres->get_MasterTheme()->get_FontScheme()->get_Major()->GetScriptFontMap();
    for (auto&& kvp : scriptFontMap)
    {
        Console::WriteLine(u"{0} = {1}", kvp.get_Key(), kvp.get_Value());
    }

    // Get script font
    Console::WriteLine(u"Font for \"Thaa\" tag is " + pres->get_MasterTheme()->get_FontScheme()->get_Major()->GetScriptFont(u"Thaa"));

    // Set script font
    pres->get_MasterTheme()->get_FontScheme()->get_Major()->SetScriptFont(u"Thaa", u"Super Thaa");
    pres->get_MasterTheme()->get_FontScheme()->get_Minor()->RemoveScriptFont(u"Geor");

    // Check script font
    Console::WriteLine(u"Font for \"Thaa\" tag is " + pres->get_MasterTheme()->get_FontScheme()->get_Major()->GetScriptFont(u"Thaa"));

    //ExEnd:ManageScriptFontsExample
}
