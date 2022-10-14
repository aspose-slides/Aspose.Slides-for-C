#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AccessSmartArt()
{
	// ExStart:AccessSmartArt
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	for (int x = 0; x<pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::AsCast<Aspose::Slides::SmartArt::SmartArt>(shape);

			// Traverse through all nodes inside SmartArt
			for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
			{
				// Accessing SmartArt node at index i
				SharedPtr<SmartArtNode> node = System::AsCast<SmartArtNode>(smart->get_AllNodes()->idx_get(i));

				// Printing the SmartArt node parameters
				Console::WriteLine(u"j = " + node->get_TextFrame()->get_Text() + u", Text = " + node->get_Level() + u", Position = " + node->get_Position());
			}
		}
	}
	// ExEnd:AccessSmartArt
}
