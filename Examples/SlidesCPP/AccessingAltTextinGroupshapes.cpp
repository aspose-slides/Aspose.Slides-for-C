#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AccessingAltTextinGroupshapes()
{
	// ExStart:AccessingAltTextinGroupshapes
	// The path to the documents directory.
	//const String outPath = u"../out/EmbeddedVideoFrame_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	for (int i = 0; i < slide->get_Shapes()->get_Count(); i++)
	{
		// Accessing the shape collection of slides
		SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(i);

		if (ObjectExt::Is<GroupShape>(shape))
		{
			// Accessing the group shape.
			SharedPtr<GroupShape> grphShape = DynamicCast<GroupShape>(shape);

			for (int j = 0; j < grphShape->get_Shapes()->get_Count(); j++)
			{
				SharedPtr<IShape> shape2 = grphShape->get_Shapes()->idx_get(j);
				String st = shape2->get_AlternativeText();
				// Accessing the AltText property
				Console::WriteLine(u"Shape Name : " + st);
			}
		}
	}
	//ExEnd:AccessingAltTextinGroupshapes
}
