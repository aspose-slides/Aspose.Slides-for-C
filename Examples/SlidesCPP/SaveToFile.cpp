#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SaveToFile()
{
	//ExStart:SaveToFile

	const String outPath = u"../out/SaveToFile_out.ppt";
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
    	
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SaveToFile
}
