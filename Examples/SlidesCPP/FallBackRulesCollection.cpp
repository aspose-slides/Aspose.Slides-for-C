
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/Fonts/FontFallBackRule.h>
#include <DOM/Fonts/FontFallBackRulesCollection.h>
#include <DOM/IFontFallBackRule.h>
#include <DOM/IFontFallBackRulesCollection.h>
#include <DOM/IFontsManager.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void FallBackRulesCollection() {

	 //ExStart:FallBackRulesCollection

	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();

	System::SharedPtr<IFontFallBackRulesCollection> userRulesList = System::MakeObject<FontFallBackRulesCollection>();

	userRulesList->Add(System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x0B80), static_cast<uint32_t>(0x0BFF), u"Vijaya"));
	userRulesList->Add(System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x3040), static_cast<uint32_t>(0x309F), u"MS Mincho, MS Gothic"));

	presentation->get_FontsManager()->set_FontFallBackRulesCollection(userRulesList);
	 //ExEnd:FallBackRulesCollection


}