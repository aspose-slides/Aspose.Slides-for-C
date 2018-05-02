#include <iostream>
#include <system/console.h>
#include <Export/SaveFormat.h>
#include <DOM/SmartArt/SmartArtQuickStyleType.h>
#include <DOM/SmartArt/SmartArtNode.h>
#include <DOM/SmartArt/SmartArtLayoutType.h>
#include <DOM/SmartArt/SmartArtColorType.h>
#include <DOM/SmartArt/SmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtNode.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SmartArt;

using namespace System;

const int NodesCount = 5;

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

		if (System::ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			System::SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			if (smart->get_AllNodes()->get_Count() > 0)
			{
				// Accessing SmartArt node at index 0
				System::SharedPtr<Aspose::Slides::SmartArt::SmartArtNode> node0 = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArtNode>(smart->get_AllNodes()->idx_get(0));


				if (node0->get_ChildNodes()->get_Count() >= 2)
				{

					// Removing the child node at position 1
					node0->get_ChildNodes()->RemoveNode(1);
				}

			}
		}
	}
		// Save Presentation
		pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	
	// ExEnd:RemoveNodeSpecificPosition
}
