#include <DOM/Presentation.h>
#include <DOM/IPresentationInfo.h>
#include <DOM/PresentationInfo.h>
#include <DOM/PresentationFactory.h>
#include <DOM/IPresentationFactory.h>
#include<Dom/LoadOptions.h>
#include<LoadFormat.h>

using namespace System;
using namespace Aspose;
using namespace Aspose::Slides;

void GetFileFormat() {

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