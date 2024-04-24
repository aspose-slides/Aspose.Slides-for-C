#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System::IO;

void RenderingWithFallBackFont()
{
    //ExStart:RenderingWithFallBackFont

    // The path to the documents directory.
    const System::String outPng = Path::Combine(GetOutPath(), u"Slide_0.png");
    const System::String templatePath = Path::Combine(GetDataPath(), u"input.pptx");

    // Create new instance of a rules collection
    System::SharedPtr<IFontFallBackRulesCollection> rulesList = System::MakeObject<FontFallBackRulesCollection>();

    // create a number of rules
    rulesList->Add(System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x400), static_cast<uint32_t>(0x4FF), u"Times New Roman"));

    auto fallBackRuleEnumerator = rulesList->GetEnumerator();
    while (fallBackRuleEnumerator->MoveNext())
    {
        auto fallBackRule = fallBackRuleEnumerator->get_Current();

        //Trying to remove FallBack font "Tahoma" from loaded rules
        fallBackRule->Remove(u"Tahoma");

        //And to update of rules for specified range
        if ((fallBackRule->get_RangeEndIndex() >= static_cast<uint32_t>(0x4000)) && (fallBackRule->get_RangeStartIndex()
            < static_cast<uint32_t>(0x5000)))
        {
            fallBackRule->AddFallBackFonts(u"Verdana");
        }
    }

    //Also we can remove any existing rules from list
    if (rulesList->get_Count() > 0)
    {
        rulesList->Remove(rulesList->idx_get(0));
    }

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    //Assigning a prepared rules list for using
    pres->get_FontsManager()->set_FontFallBackRulesCollection(rulesList);

    // Rendering of thumbnail with using of initialized rules collection and saving to PNG
    System::SharedPtr<IImage> image = pres->get_Slide(0)->GetImage(1.0f, 1.0f);
    image->Save(outPng, ImageFormat::Png);
    //ExEnd:RenderingWithFallBackFont
}
