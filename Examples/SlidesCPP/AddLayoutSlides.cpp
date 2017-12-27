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

void AddLayoutSlides()
{
	//ExStart:AddLayoutSlides

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/AddLayoutSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);


	// Try to search by layout slide type
	SharedPtr<IMasterLayoutSlideCollection> layoutSlides = pres->get_Masters()->idx_get(0)->get_LayoutSlides();


	SharedPtr<ILayoutSlide> layoutSlide;
	if (layoutSlides->GetByType(SlideLayoutType::TitleAndObject) != NULL)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::TitleAndObject);
	}
	else if (layoutSlides->GetByType(SlideLayoutType::Title) != NULL)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::Title);
	}

	if (layoutSlide == NULL)
	{
		// The situation when a presentation doesn't contain some type of layouts.
		// presentation File only contains Blank and Custom layout types.
		// But layout slides with Custom types has different slide names,
		// like "Title", "Title and Content", etc. And it is possible to use these
		// names for layout slide selection.
		// Also it is possible to use the set of placeholder shape types. For example,
		// Title slide should have only Title pleceholder type, etc.

		for (int i = 0; i<layoutSlides->get_Count(); i++)
		{
			SharedPtr<ILayoutSlide> titleAndObjectLayoutSlide = layoutSlides->idx_get(i);

			if (titleAndObjectLayoutSlide->get_Name().Equals(L"Title and Object"))
			{
				layoutSlide = titleAndObjectLayoutSlide;
				break;
			}
		}

		if (layoutSlide == NULL)
		{
			for (int i = 0; i < layoutSlides->get_Count(); i++)
			{
				SharedPtr<ILayoutSlide> titleLayoutSlide = layoutSlides->idx_get(i);

				if (titleLayoutSlide->get_Name().Equals(L"Title"))
				{
					layoutSlide = titleLayoutSlide;
					break;
				}
			}

			if (layoutSlide == NULL)
			{
				layoutSlide = layoutSlides->GetByType(SlideLayoutType::Blank);
				if (layoutSlide == NULL)
				{
					layoutSlide = layoutSlides->Add(SlideLayoutType::TitleAndObject, L"Title and Object");
				}
			}
		}
	}

	// Adding empty slide with added layout slide 
	pres->get_Slides()->InsertEmptySlide(0, layoutSlide);

	// Save the PPTX file to the Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddLayoutSlides
}