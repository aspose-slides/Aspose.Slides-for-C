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

void CheckSlidesComparison()
{
	//ExStart:CheckSlidesComparison

	// The path to the documents directory.
	const String templatePath1 = u"../templates/AccessSlides.pptx";
	const String templatePath2 = u"../templates/HelloWorld.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> presentation1 = MakeObject<Presentation>(templatePath1);
	SharedPtr<Presentation> presentation2 = MakeObject<Presentation>(templatePath2);

	for (int i = 0; i < presentation1->get_Masters()->get_Count(); i++)
	{
		for (int j = 0; j <presentation2->get_Masters()->get_Count(); j++)
		{
			
			
			if (presentation1->get_Masters()->idx_get(i)->Equals(presentation2->get_Masters()->idx_get(j)))
				printf("SomePresentation1 MasterSlide# %d is equal to SomePresentation2 MasterSlide #%d : %d\n",i,j);
		}

	}

	//ExEnd:CheckSlidesComparison
}

