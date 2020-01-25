#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <Export/PdfOptions.h>
#include <Export/HtmlOptions.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace Aspose::Slides::Export;


void SetDefaultFont() {

	//ExStart:SetDefaultFont
	
	const String tempplatePath = u"../templates/DemoFile.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(tempplatePath);

	System::SharedPtr<HtmlOptions> htmlOpts = System::MakeObject<HtmlOptions>();
	htmlOpts->set_DefaultRegularFont(u"Arial Black");
	pres->Save(u"../out/SomePresentation-out-ArialBlack.html", Aspose::Slides::Export::SaveFormat::Html, htmlOpts);
	htmlOpts->set_DefaultRegularFont(u"Lucida Console");
	pres->Save(u"../out/Somepresentation-out-LucidaConsole.html", Aspose::Slides::Export::SaveFormat::Html, htmlOpts);

	System::SharedPtr<PdfOptions> pdfOpts = System::MakeObject<PdfOptions>();
	pdfOpts->set_DefaultRegularFont(u"Arial Black");
	pres->Save(u"../out/SomePresentation-out-ArialBlack.pdf", Aspose::Slides::Export::SaveFormat::Pdf, pdfOpts);



	//ExEnd:SetDefaultFont

}