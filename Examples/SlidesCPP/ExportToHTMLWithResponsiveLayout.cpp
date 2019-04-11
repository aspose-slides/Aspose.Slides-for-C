#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <Export/HtmlOptions.h>
#include<Export/ResponsiveHtmlController.h>
#include <Export/HtmlFormatter.h>

#include "SlidesExamples.h"
using namespace Aspose::Slides;
using namespace System;

void ExportToHTMLWithResponsiveLayout() {
	//ExStart:ExportToHTMLWithResponsiveLayout
	SharedPtr<Presentation> presentation = MakeObject<Presentation>(u"SomePresentation.pptx");
	SharedPtr<Aspose::Slides::Export::HtmlOptions> saveOptions = MakeObject <Aspose::Slides::Export::HtmlOptions>();
	saveOptions->set_SvgResponsiveLayout(true);
	presentation->Save(u"../out/SomePresentation-out.html", Export::SaveFormat::Html, saveOptions);
	//ExEnd:ExportToHTMLWithResponsiveLayout
}