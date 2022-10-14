#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void GetTextFromSmartArtNode()
{
	// ExStart:GetTextFromSmartArtNode
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
				
				int iNodeShapeCount = node->get_Shapes()->get_Count();

				for(int j=0; j < iNodeShapeCount;j++)
				{
					SharedPtr<SmartArtShape> nodeShape=System::AsCast<SmartArtShape>(node->get_Shapes()->idx_get(j));
					//auto nodeShape = System::AsCast<Aspose::Slides::SmartArt::SmartArtShape>(node->get_Shapes()->idx_get(j));

					if (nodeShape->get_TextFrame() != nullptr)
					{
						// Printing the SmartArt nodeShape parameters
						Console::WriteLine(u"NodeShape Text is: {0}", nodeShape->get_TextFrame()->get_Text());
					}
				}
			}
		}
	}
	// ExEnd:GetTextFromSmartArtNode
}
