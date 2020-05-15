#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void SmartArtNodeLevel()
{
	// ExStart:SmartArtNodeLevel
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
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			// Traverse through all nodes inside SmartArt
			for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
			{
				// Accessing SmartArt node at index i
				SharedPtr<SmartArtNode> node0 = System::DynamicCast_noexcept<SmartArtNode>(smart->get_AllNodes()->idx_get(i));

				printf("Node Level =  : %d\n", node0->get_Level());

				// Traversing through the child nodes in SmartArt node at index i
				for (int j = 0; j < node0->get_ChildNodes()->get_Count(); j++)
				{
					// Accessing the child node in SmartArt node
					SharedPtr<SmartArtNode> node = System::DynamicCast_noexcept<SmartArtNode>(node0->get_ChildNodes()->idx_get(j));

					// Printing the SmartArt child node parameters
					printf("Child Node Level =  : %d\n", node->get_Level());
				}
			}
		}
	}
	// ExEnd:SmartArtNodeLevel
}
