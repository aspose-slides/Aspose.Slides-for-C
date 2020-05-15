#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveHyperlinks()
{
	//ExStart:RemoveHyperlinks

	// The path to the documents directory.
	const String templatePath = u"../templates/Hyperlinks.pptx";
	const String outPath = u"../out/RemoveHyperlinks.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);

	// Removing the hyperlinks from presentation
	pres->get_HyperlinkQueries()->RemoveAllHyperlinks();

	//Writing the presentation as a PPTX file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:RemoveHyperlinks
}
