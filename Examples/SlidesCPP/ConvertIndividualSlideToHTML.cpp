#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;

using namespace System;

//ExStart:ConvertIndividualSlideToHTML
class CustomFormattingController : public IHtmlFormattingController
{
    void WriteDocumentStart(SharedPtr<IHtmlGenerator> generator, SharedPtr<IPresentation> presentation) override
    {}

    void WriteDocumentEnd(SharedPtr<IHtmlGenerator> generator, SharedPtr<IPresentation> presentation) override
    {}

    void WriteSlideStart(SharedPtr<IHtmlGenerator> generator, SharedPtr<ISlide> slide) override
    {
        generator->AddHtml(String::Format(SlideHeader, generator->get_SlideIndex() + 1));
    }

    void WriteSlideEnd(SharedPtr<IHtmlGenerator> generator, SharedPtr<ISlide> slide) override
    {
        generator->AddHtml(SlideFooter);
    }

    void WriteShapeStart(SharedPtr<IHtmlGenerator> generator, SharedPtr<IShape> shape) override
    {}

    void WriteShapeEnd(SharedPtr<IHtmlGenerator> generator, SharedPtr<IShape> shape) override
    {}

    static const String SlideHeader;
    static const String SlideFooter;
};
const String CustomFormattingController::SlideHeader = String(u"<div class=\"slide\" name=\"slide\" id=\"slide{0}\">");
const String CustomFormattingController::SlideFooter = String(u"</div>");

void ConvertIndividualSlideToHTML()
{
	// The path to the documents directory.
	const String outPath = u"../out/";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<HtmlOptions> htmlOptions = MakeObject<HtmlOptions>();
    htmlOptions->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(System::MakeObject<CustomFormattingController>()));
    
	// Saving File              
	for (int i = 0; i < pres->get_Slides()->get_Count(); i++)
	{
		pres->Save(outPath + u"Individual Slide" + (i + 1) + u"_out.html", System::MakeArray<int32_t>({ i + 1 }), SaveFormat::Html, htmlOptions);
	}
}
//ExEnd:ConvertIndividualSlideToHTML