#include "stdafx.h"
#include "SlidesExamples.h"
#include "CustomHeaderAndFontsController.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace Examples::CSharp::Presentations::Conversion;

void SavingHTMLAndCSSFileWhenExportingIntoHTML()
{
    //ExStart:SavingHTMLAndCSSFileWhenExportingIntoHTML
    // The path to the documents directory.
 	const String outPath = u"../out/pres.html";
	const String templatePath = u"../templates/AccessSlides.pptx";

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
    
    SharedPtr<CustomHeaderAndFontsController> htmlController = System::MakeObject<CustomHeaderAndFontsController>(u"styles.css");
    SharedPtr<HtmlOptions> options = System::MakeObject<HtmlOptions>();
    options->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(htmlController));

    pres->Save(outPath, SaveFormat::Html, options);
	
	//ExEnd:SavingHTMLAndCSSFileWhenExportingIntoHTML
}
