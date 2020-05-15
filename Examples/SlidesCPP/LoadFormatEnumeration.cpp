#include "stdafx.h"

using namespace System;
using namespace Aspose::Slides;

void LoadFormatEnumeration()
{
	//ExStart:LoadFormatEnumeration

	const String templatePath = u"../templates/AccessSlides.pptx";

	bool isOldFormat = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath)->get_LoadFormat() == LoadFormat::Ppt95;

	//ExEnd:LoadFormatEnumeration
}
