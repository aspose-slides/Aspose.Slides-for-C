#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include<Export\EmbedAllFontsHtmlController.h>
#include <Export/HtmlFormatter.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void EmbedFontsInHtml()
{

	//ExStart:EmbedFontsInHtml

	// The path to the documents directory.
	const String outPath = u"../out/EmbedFontsInHtml_out.html";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//	Add EmbedAllFontsHtmlController 
	ArrayPtr<String> fontNameExcludeList = MakeArray<String>({ u"Calibri", u"Arial" });
	SharedPtr<Aspose::Slides::Export::EmbedAllFontsHtmlController> EmbedFontController = MakeObject <Aspose::Slides::Export::EmbedAllFontsHtmlController>(fontNameExcludeList);

	SharedPtr<Aspose::Slides::Export::HtmlOptions> htmlOptions = MakeObject <Aspose::Slides::Export::HtmlOptions>();
	htmlOptions->set_HtmlFormatter((HtmlFormatter::CreateCustomFormatter(EmbedFontController)));


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Html, htmlOptions);

	//ExEnd:EmbedFontsInHtml
}
