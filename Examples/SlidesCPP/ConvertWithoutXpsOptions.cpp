#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/Xpsoptions.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace Aspose::Slides::Export;
using namespace System;

void ConvertWithoutXpsOptions()
{

	//ExStart:ConvertWithoutXpsOptions
	// The path to the documents directory.
	const String outPath = u"../out/ConvertWithoutXpsOptions_out.xps";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Xps);
	
	//ExEnd:ConvertWithoutXpsOptions

}