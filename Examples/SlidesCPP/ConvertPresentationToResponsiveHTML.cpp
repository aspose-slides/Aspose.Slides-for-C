#include "stdafx.h"
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
    SharedPtr<ResponsiveHtmlController> controller = MakeObject<ResponsiveHtmlController>();

    SharedPtr<HtmlOptions> htmlOptions = MakeObject<HtmlOptions>();
    htmlOptions->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(controller));

    pres->Save(outPath, SaveFormat::Html, htmlOptions);

    //ExEnd:ConvertPresentationToResponsiveHTML
}
