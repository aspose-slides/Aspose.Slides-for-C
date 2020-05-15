#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CheckSlidesComparison()
{
	//ExStart:CheckSlidesComparison

	// The path to the documents directory.
	const String templatePath1 = u"../templates/AccessSlides.pptx";
	const String templatePath2 = u"../templates/AccessSlides.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> presentation1 = MakeObject<Presentation>(templatePath1);
	SharedPtr<Presentation> presentation2 = MakeObject<Presentation>(templatePath2);

	for (int i = 0; i < presentation1->get_Masters()->get_Count(); i++)
	{
		for (int j = 0; j <presentation2->get_Masters()->get_Count(); j++)
		{
            if (presentation1->get_Masters()->idx_get(i)->Equals(presentation2->get_Masters()->idx_get(j)))
            {
                Console::WriteLine(String::Format(u"SomePresentation1 MasterSlide#{0} is equal to SomePresentation2 MasterSlide#{1}\n", i, j));
            }
        }
	}

	//ExEnd:CheckSlidesComparison
}
