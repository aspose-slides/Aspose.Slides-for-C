#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SpecifyFontsUsedWithPresentation()
{
	//ExStart:SpecifyFontsUsedWithPresentation
	// The path to the documents directory.
	const String outPath = u"../out/SpecifyFontsUsedWithPresentation.pptx";
	const String templatePath = u"../templates/AccessSlides.pptx";

	ArrayPtr<String> fontsLocation =  MakeArray<String>({ u"assets\\fonts", u"global\\fonts" });// ;
	ArrayPtr<ArrayPtr<uint8_t>> memoryfontsLocation = MakeArray<ArrayPtr<uint8_t>>({ File::ReadAllBytes(u"../templates/CustomFont1.ttf"), File::ReadAllBytes(u"../templates/CustomFont2.ttf") });

	SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();

	loadOptions->get_DocumentLevelFontSources()->set_FontFolders(fontsLocation);
	loadOptions->get_DocumentLevelFontSources()->set_MemoryFonts(memoryfontsLocation);
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);
	
	//work with the presentation
	//CustomFont1, CustomFont2 as well as fonts from assets\fonts & global\fonts folders and their subfolders are available to the presentation
	
	//ExEnd:SpecifyFontsUsedWithPresentation
}
