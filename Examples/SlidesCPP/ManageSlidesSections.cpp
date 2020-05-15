#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void ManageSlidesSections()
{
	//ExStart:ManageSlidesSections

	// The path to the documents directory.
	const String templatePath = u"../templates/sections.pptx";
	const String outPath = u"../out/ManageSlidesSections_out.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<ISection> section = pres->get_Sections()->idx_get(2);
	pres->get_Sections()->ReorderSectionWithSlides(section, 0);
	pres->get_Sections()->RemoveSectionWithSlides(pres->get_Sections()->idx_get(0));
	pres->get_Sections()->AppendEmptySection(u"Last empty section");
    pres->get_Sections()->AddSection(u"First empty", pres->get_Slides()->idx_get(1));
    pres->get_Sections()->idx_get(0)->set_Name(u"New section name");

	// Save the PPTX file to the Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ManageSlidesSections
}
