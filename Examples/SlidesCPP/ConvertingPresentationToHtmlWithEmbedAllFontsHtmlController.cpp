#include "stdafx.h"
#include "LinkAllFontsHtmlController.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Examples::CSharp::Conversion;

void ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController()
{
    //ExStart:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
	const String outPath = u"../out/PresentationToHtmlWithEmbedAllFontsHtmlController_out.html";
	const String templatePath = u"../templates/AccessSlides.pptx";
	
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
   
    // exclude default presentation fonts
    ArrayPtr<String> fontNameExcludeList = System::MakeArray<String>({u"Calibri", u"Arial"});
        
    SharedPtr<Paragraph> para = System::MakeObject<Paragraph>();
    SharedPtr<ITextFrame> txt;
    
    SharedPtr<EmbedAllFontsHtmlController> embedFontsController = System::MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);
    
    SharedPtr<LinkAllFontsHtmlController> linkcont = System::MakeObject<LinkAllFontsHtmlController>(fontNameExcludeList, u"C:\\Windows\\Fonts\\");
    
    SharedPtr<HtmlOptions> htmlOptionsEmbed = System::MakeObject<HtmlOptions>();
    htmlOptionsEmbed->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(linkcont));
    
    pres->Save(outPath, SaveFormat::Html, htmlOptionsEmbed);
    //ExEnd:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
}
