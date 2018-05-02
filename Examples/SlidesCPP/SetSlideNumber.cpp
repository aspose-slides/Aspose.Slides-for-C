#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void SetSlideNumber ()
{
	//ExStart:SetSlideNumber

	// The path to the documents directory.
	const String outPath = u"../out/SetSlideNumber_out.pptx";
	const String templatePath = u"../templates/AccessSlides.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	int firstSlideNumber = pres->get_FirstSlideNumber();
	pres->set_FirstSlideNumber(2);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetSlideNumber
}