#include <iostream>
#include <system/console.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/SlideLayoutType.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IMasterLayoutSlideCollection.h>
#include <DOM/ICommentAuthorCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>
#include <DOM/ISection.h>
#include <DOM/ISectionCollection.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void ManageSlidesSections()
{
	//ExStart:ManageSlidesSections

	// The path to the documents directory.
	const String templatePath = u"../templates/AddSlides.pptx";
	const String outPath = u"../out/ManageSlidesSections_out.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<ISection> section = pres->get_Sections()->idx_get(2);
	pres->get_Sections()->ReorderSectionWithSlides(section, 0);
	pres->get_Sections()->RemoveSectionWithSlides(pres->get_Sections()->idx_get(0));
	pres->get_Sections()->AppendEmptySection(u"Last empty section");
	pres->get_Sections()->idx_get(0)->set_Name(u"New section name");
	pres->get_Sections()->AddSection(u"First empty", pres->get_Slides()->idx_get(2));


	// Save the PPTX file to the Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ManageSlidesSections
}