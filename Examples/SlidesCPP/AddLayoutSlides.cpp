#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddLayoutSlides()
{
	//ExStart:AddLayoutSlides

	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/AddLayoutSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Try to search by layout slide type
	SharedPtr<IMasterLayoutSlideCollection> layoutSlides = pres->get_Masters()->idx_get(0)->get_LayoutSlides();

	SharedPtr<ILayoutSlide> layoutSlide;
	if (layoutSlides->GetByType(SlideLayoutType::TitleAndObject) != nullptr)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::TitleAndObject);
	}
	else if (layoutSlides->GetByType(SlideLayoutType::Title) != nullptr)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::Title);
	}

	if (layoutSlide == nullptr)
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

			if (titleAndObjectLayoutSlide->get_Name().Equals(u"Title and Object"))
			{
				layoutSlide = titleAndObjectLayoutSlide;
				break;
			}
		}

		if (layoutSlide == nullptr)
		{
			for (int i = 0; i < layoutSlides->get_Count(); i++)
			{
				SharedPtr<ILayoutSlide> titleLayoutSlide = layoutSlides->idx_get(i);

				if (titleLayoutSlide->get_Name().Equals(u"Title"))
				{
					layoutSlide = titleLayoutSlide;
					break;
				}
			}

			if (layoutSlide == nullptr)
			{
				layoutSlide = layoutSlides->GetByType(SlideLayoutType::Blank);
				if (layoutSlide == nullptr)
				{
					layoutSlide = layoutSlides->Add(SlideLayoutType::TitleAndObject, u"Title and Object");
				}
			}
		}
	}

	// Adding empty slide with added layout slide 
	pres->get_Slides()->InsertEmptySlide(0, layoutSlide);

	// Save the PPTX file to the Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddLayoutSlides
}
