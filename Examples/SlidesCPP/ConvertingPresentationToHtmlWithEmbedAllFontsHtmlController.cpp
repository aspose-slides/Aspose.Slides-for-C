#include "stdafx.h"
#include "LinkAllFontsHtmlController.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;
using namespace Examples::CSharp::Conversion;

void ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController()
{
    //ExStart:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
    const System::String templatePath = Path::Combine(GetDataPath(), u"AccessSlides.pptx");
    const System::String outPath = Path::Combine(GetOutPath(), u"PresentationToHtmlWithEmbedAllFontsHtmlController_out.html");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // exclude default presentation fonts
    System::ArrayPtr<System::String> fontNameExcludeList = System::MakeArray<System::String>();

    System::SharedPtr<Paragraph> para = System::MakeObject<Paragraph>();

    System::SharedPtr<EmbedAllFontsHtmlController> embedFontsController = System::MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);

    System::SharedPtr<LinkAllFontsHtmlController> linkcont = System::MakeObject<LinkAllFontsHtmlController>(fontNameExcludeList, u"C:\\Windows\\Fonts\\");

    System::SharedPtr<HtmlOptions> htmlOptionsEmbed = System::MakeObject<HtmlOptions>();
    htmlOptionsEmbed->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(linkcont));

    pres->Save(outPath, SaveFormat::Html, htmlOptionsEmbed);
    //ExEnd:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
}
