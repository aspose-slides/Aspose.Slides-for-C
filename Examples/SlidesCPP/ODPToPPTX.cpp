
#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void ODPToPPTX()
{
	//ExStart:ODPToPPTX

	// The path to the documents directory.
	const String outPath = u"../out/AccessOpenDoc.pptx";
	const String dataDir = u"../templates/AccessOpenDoc.odp";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(dataDir);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ODPToPPTX

}