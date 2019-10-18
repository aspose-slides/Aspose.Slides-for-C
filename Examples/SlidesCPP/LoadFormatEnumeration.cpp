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


void LoadFormatEnumeration() {

	//ExStart:LoadFormatEnumeration

	const String templatePath = u"../templates/AccessSlides.pptx";

	bool isOldFormat = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath)->get_LoadFormat() == LoadFormat::Ppt95;

	//ExEnd:LoadFormatEnumeration
}