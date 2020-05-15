#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void AccessOpenDoc()
{
	//ExStart:AccessOpenDoc
	// The path to the documents directory.
	const String outPath = u"../out/AccessOpenDoc_out.pptx";
	const String dataDir = u"../templates/AccessOpenDoc.odp";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(dataDir);

	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:AccessOpenDoc
}
