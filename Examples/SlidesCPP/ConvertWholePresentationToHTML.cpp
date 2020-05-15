#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

void ConvertWholePresentationToHTML()
{
	//ExStart:ConvertWholePresentationToHTML

	// The path to the documents directory.
	const String outPath = u"../out/ConvertWholePresentationToHTML_out.html";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<ResponsiveHtmlController> controller = MakeObject<ResponsiveHtmlController>();
	
	SharedPtr<HtmlOptions> htmlOptions = MakeObject <HtmlOptions>();
	htmlOptions->set_HtmlFormatter((HtmlFormatter::CreateSlideShowFormatter(u"", false)));
    
	pres->Save(outPath, SaveFormat::Html, htmlOptions);

	//ExEnd:ConvertWholePresentationToHTML
}
