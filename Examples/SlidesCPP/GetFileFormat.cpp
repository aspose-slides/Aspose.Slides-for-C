#include "stdafx.h"

using namespace System;
using namespace Aspose::Slides;

void GetFileFormat()
{
	//ExStart:GetFileFormat
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<IPresentationInfo> info = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath);
	switch (info->get_LoadFormat())
	{
	    case LoadFormat::Pptx:
	    {
		    break;
	    }
	    case LoadFormat::Unknown:
	    {
		    break;
	    }
	}

	//ExEnd:GetFileFormat
}
