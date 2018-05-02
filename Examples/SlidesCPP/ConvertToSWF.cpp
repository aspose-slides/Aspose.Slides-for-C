#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/Swfoptions.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void ConvertToSWF()
{

	//ExStart:ConvertToSWF
	// The path to the documents directory.
	const String outPath = u"../out/ConvertToSWF_out.swf";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<Aspose::Slides::Export::SwfOptions> swfOptions = MakeObject <Aspose::Slides::Export::SwfOptions>();
	swfOptions->set_ViewerIncluded ( true);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Swf, swfOptions);

	//ExEnd:ConvertToSWF

}