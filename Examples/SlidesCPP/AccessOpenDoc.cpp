#include <system/object_ext.h>
#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
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

void AccessOpenDoc()
{

	//ExStart:AccessOpenDoc
	// The path to the documents directory.

	// The path to the documents directory.
	const String outPath = u"../out/AccessOpenDoc_out.pptx";
	const String dataDir = u"../templates/AccessOpenDoc.odp";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(dataDir);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	//ExEnd:AccessOpenDoc

}