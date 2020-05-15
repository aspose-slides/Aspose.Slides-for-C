#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace Export;

void SetDefaultFont()
{
	//ExStart:SetDefaultFont
	
	const String tempplatePath = u"../templates/DemoFile.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(tempplatePath);

	SharedPtr<HtmlOptions> htmlOpts = System::MakeObject<HtmlOptions>();
	htmlOpts->set_DefaultRegularFont(u"Arial Black");
	pres->Save(u"../out/SomePresentation-out-ArialBlack.html", SaveFormat::Html, htmlOpts);
	htmlOpts->set_DefaultRegularFont(u"Lucida Console");
	pres->Save(u"../out/Somepresentation-out-LucidaConsole.html", SaveFormat::Html, htmlOpts);

	SharedPtr<PdfOptions> pdfOpts = System::MakeObject<PdfOptions>();
	pdfOpts->set_DefaultRegularFont(u"Arial Black");
	pres->Save(u"../out/SomePresentation-out-ArialBlack.pdf", SaveFormat::Pdf, pdfOpts);

	//ExEnd:SetDefaultFont
}