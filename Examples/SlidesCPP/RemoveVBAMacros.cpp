#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Vba;
using namespace System;

void RemoveVBAMacros()
{
	// ExStart:RemoveVBAMacros
	// The path to the documents directory.
	const String outPath = u"../out/RemoveVBAMacros_out.pptm";
	const String templatePath = u"../templates/vba.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> presentation = MakeObject<Presentation>(templatePath);

	// Access the Vba module and remove 
	presentation->get_VbaProject()->get_Modules()->Remove(presentation->get_VbaProject()->get_Modules()->idx_get(0));

	// Save PPTX to Disk
	presentation->Save(outPath, Export::SaveFormat::Pptm);

	// ExEnd:RemoveVBAMacros
}
