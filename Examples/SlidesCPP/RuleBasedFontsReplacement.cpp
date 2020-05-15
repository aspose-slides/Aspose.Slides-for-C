#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RuleBasedFontsReplacement()
{
	// ExStart:RuleBasedFontsReplacement
	// The path to the documents directory.
	const String outPath = u"../out/RuleBasedFontsReplacement_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Define new fonts
	SharedPtr<IFontData> sourceFont = MakeObject<FontData>(u"SomeRareFont");
	SharedPtr<IFontData> destFont = MakeObject<FontData>(u"Arial");
	
	// Add font rule for font replacement
	SharedPtr<FontSubstRule> fontSubstRule = MakeObject<FontSubstRule>(sourceFont, destFont, FontSubstCondition::WhenInaccessible);

	// Add rule to font substitute rules collection
	SharedPtr<FontSubstRuleCollection> fontSubstRuleCollection = MakeObject<FontSubstRuleCollection>();
	fontSubstRuleCollection->Add(fontSubstRule);

	// Add font rule collection to rule list
	pres->get_FontsManager()->set_FontSubstRuleList ( fontSubstRuleCollection);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:RuleBasedFontsReplacement
}
