#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/Fonts/FontFallBackRule.h>
#include <DOM/IFontFallBackRule.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;


void SetFontFallBack() {

  //ExStart:SetFontFallBack

	uint32_t startUnicodeIndex = 0x0B80;
	uint32_t endUnicodeIndex = 0x0BFF;

	System::SharedPtr<IFontFallBackRule> firstRule = System::MakeObject<FontFallBackRule>(startUnicodeIndex, endUnicodeIndex, u"Vijaya");
	System::SharedPtr<IFontFallBackRule> secondRule = System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x3040), static_cast<uint32_t>(0x309F), u"MS Mincho, MS Gothic");

	//Also the fonts list can be added in several ways:
	System::ArrayPtr<System::String> fontNames = System::MakeArray<System::String>({ u"Segoe UI Emoji, Segoe UI Symbol", u"Arial" });

	System::SharedPtr<IFontFallBackRule> thirdRule = System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x1F300), static_cast<uint32_t>(0x1F64F), fontNames);

  //ExEnd:SetFontFallBack

}