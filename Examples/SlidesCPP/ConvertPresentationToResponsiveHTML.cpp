#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include<Export\ResponsiveHtmlController.h>
#include <Export/HtmlFormatter.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ConvertPresentationToResponsiveHTML()
{

	//ExStart:ConvertPresentationToResponsiveHTML
	
	// The path to the documents directory.
	const String outPath = u"../out/ConvertPresentationToResponsiveHTML_out.html";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//	ResponsiveHtmlController controller = new ResponsiveHtmlController();
	SharedPtr<Aspose::Slides::Export::ResponsiveHtmlController> controller = MakeObject <Aspose::Slides::Export::ResponsiveHtmlController>();
	
	System::SharedPtr<HtmlOptions> htmlOptions = System::MakeObject<HtmlOptions>();
	htmlOptions->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(controller));
	
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Html, htmlOptions);

	//ExEnd:ConvertPresentationToResponsiveHTML
}
