#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetFontFallBack()
{
    //ExStart:SetFontFallBack

	uint32_t startUnicodeIndex = 0x0B80;
	uint32_t endUnicodeIndex = 0x0BFF;

	SharedPtr<IFontFallBackRule> firstRule = System::MakeObject<FontFallBackRule>(startUnicodeIndex, endUnicodeIndex, u"Vijaya");
	SharedPtr<IFontFallBackRule> secondRule = System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x3040), static_cast<uint32_t>(0x309F), u"MS Mincho, MS Gothic");

	//Also the fonts list can be added in several ways:
	ArrayPtr<String> fontNames = System::MakeArray<String>({ u"Segoe UI Emoji, Segoe UI Symbol", u"Arial" });

	SharedPtr<IFontFallBackRule> thirdRule = System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x1F300), static_cast<uint32_t>(0x1F64F), fontNames);

    //ExEnd:SetFontFallBack
}