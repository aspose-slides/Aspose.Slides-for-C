#include "stdafx.h"
#include "SlidesExamples.h"
#include "LinkController.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;
using namespace System::IO;

void ExportToHtmlWithImageLinks()
{
    //ExStart:ExportToHtmlWithImageLinks
    const String templatePath = u"../templates/image1.pptx";
    auto pres = System::MakeObject<Presentation>(templatePath);

    auto htmlOptions = System::MakeObject<HtmlOptions>(System::MakeObject<Examples::LinkController>(GetOutPath()));
    htmlOptions->set_SlideImageFormat(SlideImageFormat::Svg(System::MakeObject<SVGOptions>()));
    // This line is needed to remove the slide title display in HTML.
    // Comment it out if your prefer slide title displayed.
    htmlOptions->set_HtmlFormatter(HtmlFormatter::CreateDocumentFormatter(String::Empty, false));

    pres->Save(GetOutPath() + u"/output.html", SaveFormat::Html, htmlOptions);
    //ExEnd:ExportToHtmlWithImageLinks
}
