#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/INotesSlide.h>
#include <DOM/IHyperlinkQueries.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void RemoveHyperlinks()
{
	//ExStart:RemoveHyperlinks

	// The path to the documents directory.
	const String templatePath = L"../templates/Hyperlinks.pptx";
	const String outPath = L"../out/RemoveHyperlinks.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>(templatePath);


	// Removing the hyperlinks from presentation
	pres->get_HyperlinkQueries()->RemoveAllHyperlinks();

	//Writing the presentation as a PPTX file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:RemoveHyperlinks
}