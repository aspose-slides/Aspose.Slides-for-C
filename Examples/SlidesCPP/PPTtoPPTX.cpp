#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void PPTtoPPTX()
{
	//ExStart:PPTtoPPTX

	// The path to the documents directory.
	const String outPath = u"../out/PPTtoPPTX_out.pptx";
	const String dataDir = u"../templates/SampleChart.ppt";
	
	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(dataDir);
	
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:PPTtoPPTX
}
