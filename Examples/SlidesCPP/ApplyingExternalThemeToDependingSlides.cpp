#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void ApplyingExternalThemeToDependingSlides()
{
	try 
	{
		//ExStart:ApplyingExternalThemeToDependingSlides
	
		const String templatePath = u"../templates/HelloWorld.pptx";
		const String templateThemePath = u"../templates/Theme1Word.pptx";
		const String outPptxFileName = u"../out/ApplyingExternalThemeToDependingSlides_out.ppt";

		SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

		pres->get_Masters()->idx_get(0)->ApplyExternalThemeToDependingSlides(templateThemePath);

		pres->Save(outPptxFileName, SaveFormat::Pptx);

		//ExEnd:ApplyingExternalThemeToDependingSlides
	}
	catch (Exception ex)
	{

	}
}
