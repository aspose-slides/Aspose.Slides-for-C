#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void UseCustomFonts()
{
	// ExStart:UseCustomFonts
	// The path to the documents directory.

	const String fontPath = u"../templates/";
	const String outPath = u"../out/UseCustomFonts_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";
	
	//Setting fonts path
	ArrayPtr<String> loadFonts = System::MakeObject<Array<String>>(1, fontPath + u"CustomFonts.ttf");

	// Load the custom font directory fonts
	FontsLoader::LoadExternalFonts(loadFonts);

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// save the presentation without embedded "Calibri" font
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// Clear Font Cache
	FontsLoader::ClearCache();
	// ExEnd:UseCustomFonts
}
