#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void ExportToHTMLWithResponsiveLayout()
{
	//ExStart:ExportToHTMLWithResponsiveLayout
	SharedPtr<Presentation> presentation = MakeObject<Presentation>(u"../templates/SomePresentation.pptx");
	SharedPtr<HtmlOptions> saveOptions = MakeObject<HtmlOptions>();
	saveOptions->set_SvgResponsiveLayout(true);
	presentation->Save(u"../out/SomePresentation-out.html", SaveFormat::Html, saveOptions);
	//ExEnd:ExportToHTMLWithResponsiveLayout
}
