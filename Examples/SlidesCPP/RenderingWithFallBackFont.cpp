#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RenderingWithFallBackFont()
{
	//ExStart:RenderingWithFallBackFont

	// The path to the documents directory.
	const String outPNG = u"../out/Slide_0.png";
	const String templatePath = u"../templates/input.pptx";

	// Create new instance of a rules collection
	SharedPtr<IFontFallBackRulesCollection> rulesList = System::MakeObject<FontFallBackRulesCollection>();

	// create a number of rules
	rulesList->Add(System::MakeObject<FontFallBackRule>(static_cast<uint32_t>(0x400), static_cast<uint32_t>(0x4FF), u"Times New Roman"));

	auto fallBackRule_enumerator = rulesList->GetEnumerator();
	while (fallBackRule_enumerator->MoveNext())
	{
		auto fallBackRule = fallBackRule_enumerator->get_Current();

		//Trying to remove FallBack font "Tahoma" from loaded rules
		fallBackRule->Remove(u"Tahoma");

		//And to update of rules for specified range
		if ((fallBackRule->get_RangeEndIndex() >= static_cast<uint32_t>(0x4000)) && (fallBackRule->get_RangeStartIndex() < static_cast<uint32_t>(0x5000)))
		{
			fallBackRule->AddFallBackFonts(u"Verdana");
		}
	}

	//Also we can remove any existing rules from list
	if (rulesList->get_Count() > 0)
	{
		rulesList->Remove(rulesList->idx_get(0));
	}

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	//Assigning a prepared rules list for using
	pres->get_FontsManager()->set_FontFallBackRulesCollection(rulesList);

	// Rendering of thumbnail with using of initialized rules collection and saving to PNG
	pres->get_Slides()->idx_get(0)->GetThumbnail(1.f, 1.f)->Save(outPNG, System::Drawing::Imaging::ImageFormat::get_Png());
	//ExEnd:RenderingWithFallBackFont
}
