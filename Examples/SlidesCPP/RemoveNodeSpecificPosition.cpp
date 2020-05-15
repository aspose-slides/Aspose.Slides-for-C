#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void RemoveNodeSpecificPosition()
{
	// ExStart:RemoveNodeSpecificPosition
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";
	const String outPath = u"../out/RemoveSmartArtNodeByPosition_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	for (int x = 0; x < pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			if (smart->get_AllNodes()->get_Count() > 0)
			{
				// Accessing SmartArt node at index 0
				SharedPtr<SmartArtNode> node0 = System::DynamicCast_noexcept<SmartArtNode>(smart->get_AllNodes()->idx_get(0));
				if (node0->get_ChildNodes()->get_Count() >= 2)
				{
					// Removing the child node at position 1
					node0->get_ChildNodes()->RemoveNode(1);
				}
			}
		}
	}

	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);
	
	// ExEnd:RemoveNodeSpecificPosition
}
