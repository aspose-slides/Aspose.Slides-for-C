#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::IO;

void EmbedFontsInHtml()
{
	//ExStart:EmbedFontsInHtml

	// The path to the documents directory.
	const String outPath = u"../out/EmbedFontsInHtml_out.html";
	const String templatePath = Path::Combine(GetDataPath(), u"input.pptx");

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//	Add EmbedAllFontsHtmlController 
	ArrayPtr<String> fontNameExcludeList = MakeArray<String>({ u"Arial" });
	SharedPtr<EmbedAllFontsHtmlController> EmbedFontController = MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);

	SharedPtr<HtmlOptions> htmlOptions = MakeObject<HtmlOptions>();
	htmlOptions->set_HtmlFormatter((HtmlFormatter::CreateCustomFormatter(EmbedFontController)));

	pres->Save(outPath, SaveFormat::Html, htmlOptions);

	//ExEnd:EmbedFontsInHtml
}
