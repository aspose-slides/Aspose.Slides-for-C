#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ReplaceFontsExplicitly()
{
	// ExStart:ReplaceFontsExplicitly
	// The path to the documents directory.
	const String outPath = u"../out/ReplaceFontsExplicitly_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Define new fonts
	SharedPtr<FontData> sourceFont = MakeObject<FontData>(u"Arial");
	SharedPtr<FontData> destFont = MakeObject<FontData>(u"Times New Roman");
	
	// Replace the fonts
	pres->get_FontsManager()->ReplaceFont(sourceFont, destFont);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ReplaceFontsExplicitly
}
