#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void VerifyingPresentationWithoutloading()
{
	//ExStart:VerifyingPresentationWithoutloading
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";

	LoadFormat format = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath)->get_LoadFormat();

	//ExEnd:VerifyingPresentationWithoutloading
}
