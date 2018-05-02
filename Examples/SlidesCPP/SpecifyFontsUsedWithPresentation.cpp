
#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <DOM/LoadOptions.h>
#include <IBlobManagementOptions.h>
#include <IFontSources.h>
#include <system\io\file.h>


#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::IO;

void SpecifyFontsUsedWithPresentation()
{

	//ExStart:SpecifyFontsUsedWithPresentation
	// The path to the documents directory.
	const String outPath = u"../out/SpecifyFontsUsedWithPresentation.pptx";
	const String templatePath = u"../templates/AccessSlides.pptx";

	ArrayPtr<String> fontsLocation =  MakeArray<System::String>({ u"assets\\fonts", u"global\\fonts" });// ;
	ArrayPtr<ArrayPtr<uint8_t>> memoryfontsLocation = MakeArray < ArrayPtr<uint8_t>>({ File::ReadAllBytes(u"../templates/CustomFont1.ttf"), File::ReadAllBytes(u"../templates/CustomFont2.ttf") });

	SharedPtr < Aspose::Slides::LoadOptions > loadOptions = MakeObject <Aspose::Slides::LoadOptions>();

	loadOptions->get_DocumentLevelFontSources()->set_FontFolders(fontsLocation);
	loadOptions->get_DocumentLevelFontSources()->set_MemoryFonts(memoryfontsLocation);
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);
	
	//work with the presentation
	//CustomFont1, CustomFont2 as well as fonts from assets\fonts & global\fonts folders and their subfolders are available to the presentation
	
	//ExEnd:SpecifyFontsUsedWithPresentation
}