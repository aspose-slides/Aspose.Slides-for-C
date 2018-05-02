#include <system/object_ext.h>
#include<Dom/LoadOptions.h>
#include<LoadFormat.h>
#include <DOM/Presentation.h>
#include <DOM/PresentationInfo.h>
#include<ILoadOptions.h>
#include<DOM/PresentationFactory.h>
#include <Export/SaveFormat.h>
#include<System/console.h>
#include <iostream>
#include<System/convert.h>
#include <system/console.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void VerifyingPresentationWithoutloading()
{

	//ExStart:VerifyingPresentationWithoutloading
	// The path to the documents directory.

	const String templatePath = u"../templates/AccessSlides.pptx";
	//Instantiate Presentation class that represents PPTX file

	//SharedPtr<PresentationFactory> fact = MakeObject<PresentationFactory>();
	
	LoadFormat format = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath)->get_LoadFormat();


	//ExEnd:VerifyingPresentationWithoutloading

}