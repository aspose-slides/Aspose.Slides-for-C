#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void InterlopShapeID()
{
	// ExStart:InterlopShapeID

	// The path to the documents directory.
	const String outPath = u"../out/FindShapeInSlide_out.pptx";
	const String templatePath = u"../templates/FindingShapeInSlide.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
	
	long officeInteropShapeId = 0;
	// Getting unique shape identifier in slide scope
	officeInteropShapeId = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_OfficeInteropShapeId();

	Console::WriteLine(u"Office Interop Shape ID: " + officeInteropShapeId);
	
	//ExEnd:InterlopShapeID
}
