#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AccessChildNodes()
{
	// ExStart:AccessChildNodes
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	for(int x = 0; x < pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);
		
		if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::AsCast<Aspose::Slides::SmartArt::SmartArt>(shape);
		
			// Traverse through all nodes inside SmartArt
			for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
			{
				// Accessing SmartArt node at index i
				SharedPtr<SmartArtNode> node0 = System::AsCast<SmartArtNode>(smart->get_AllNodes()->idx_get(i));

				// Traversing through the child nodes in SmartArt node at index i
				for (int j = 0; j < node0->get_ChildNodes()->get_Count(); j++)
				{
					// Accessing the child node in SmartArt node
					SharedPtr<SmartArtNode> node = System::AsCast<SmartArtNode>(node0->get_ChildNodes()->idx_get(j));

					// Printing the SmartArt child node parameters
					Console::WriteLine(u"j = " + node->get_TextFrame()->get_Text() + u", Text = " + node->get_Level() + u", Position = "+ node->get_Position());
				}
			}
		}
	}
	// ExEnd:AccessChildNodes
}
