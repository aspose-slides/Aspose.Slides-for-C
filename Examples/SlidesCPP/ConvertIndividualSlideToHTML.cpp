#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include<Export/ResponsiveHtmlController.h>
#include <Export/HtmlFormatter.h>
#include <DOM/ISlideCollection.h>

#include "SlidesExamples.h"
//#include "ConvertIndividualSlide.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ConvertIndividualSlideToHTML()
{

	//ExStart:ConvertIndividualSlideToHTML

	// The path to the documents directory.
//	const String outPath = u"../out/ConvertWholePresentationToHTML_out.html";
	const String outPath = u"../out/";
	const String templatePath = u"../templates/AccessSlides.pptx";

//	ConvertIndividualSlide::Run();
	//Instantiate Presentation class that represents PPTX file
	//SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//	ResponsiveHtmlController controller = new ResponsiveHtmlController();
	//SharedPtr<Aspose::Slides::Export::ResponsiveHtmlController> controller = MakeObject <Aspose::Slides::Export::ResponsiveHtmlController>();

//	SharedPtr<Aspose::Slides::Export::HtmlOptions> htmlOptions = MakeObject <Aspose::Slides::Export::HtmlOptions>();
	//htmlOptions->set_HtmlFormatter((HtmlFormatter::CreateSlideShowFormatter(u"", false)));
//	htmlOptions->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(System::MakeObject<ConvertIndividualSlide::CustomFormattingController>()));
//	htmlOptions->set_IncludeComments( true);
	
	// Saving File              
	/*for (int i = 0; i < pres->get_Slides()->get_Count(); i++)
	{
		pres->Save(outPath + u"Individual Slide" + (i + 1) + u"_out.html", System::MakeArray<int32_t>({ i + 1 }), SaveFormat::Html, htmlOptions);

	}*/
	
	//ExEnd:ConvertIndividualSlideToHTML
}
