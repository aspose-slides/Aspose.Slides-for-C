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
//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void AddSlides()
{
	//ExStart:AddSlides

	// The path to the documents directory.
	const String outPath = L"../templates/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	for (int i = 0; i < pres->get_LayoutSlides()->get_Count(); i++)
	{
		// Add an empty slide to the Slides collection
		slds->AddEmptySlide(pres->get_LayoutSlides()->idx_get(i));

	}

	// Save the PPTX file to the Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddSlides
}

