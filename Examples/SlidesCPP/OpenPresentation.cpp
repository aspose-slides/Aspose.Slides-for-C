#include <system/object_ext.h>
#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
#include<ILoadOptions.h>
#include<DOM/LoadOptions.h>
#include<DOM/ISlideCollection.h>
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

void OpenPresentation()
{

	//ExStart:OpenPresentation
	// The path to the documents directory.

	const String templatePath = u"../templates/AccessSlides.pptx";
	//Instantiate Presentation class that represents PPTX file

	SharedPtr < Aspose::Slides::LoadOptions > loadOptions = MakeObject <Aspose::Slides::LoadOptions>();

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	printf("Total slides inside presentation are : %d\n", pres->get_Slides()->get_Count());

	//ExEnd:OpenPresentation

}