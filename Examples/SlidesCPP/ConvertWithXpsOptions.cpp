#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void ConvertWithXpsOptions()
{
	//ExStart:ConvertWithXpsOptions
	// The path to the documents directory.
	const String outPath = u"../out/ConvertWithXpsOptions_out.xps";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<XpsOptions> xpsOptions = MakeObject<XpsOptions>();
	xpsOptions->set_SaveMetafilesAsPng(true);

	pres->Save(outPath, SaveFormat::Xps, xpsOptions);

	//ExEnd:ConvertWithXpsOptions
}
