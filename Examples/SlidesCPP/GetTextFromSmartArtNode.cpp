#include <iostream>
#include <system/console.h>
#include <Export/SaveFormat.h>
#include <DOM/SmartArt/SmartArtQuickStyleType.h>
#include <DOM/SmartArt/SmartArtNode.h>
#include <DOM/SmartArt/SmartArtLayoutType.h>
#include <DOM/SmartArt/SmartArtColorType.h>
#include <DOM/SmartArt/SmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtShapeCollection.h>
#include <DOM/SmartArt/ISmartArtNode.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/SmartArt/ISmartArtShape.h>
#include <DOM/SmartArt/SmartArtShape.h>

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
const String outPath = u"../out/";

void GetTextFromSmartArtNode()
{

	// ExStart:GetTextFromSmartArtNode
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	//foreach(IShape shape in pres.Slides[0].Shapes)

	for (int x = 0; x<pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (System::ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			System::SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			// Traverse through all nodes inside SmartArt
			for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
			{
				// Accessing SmartArt node at index i
				System::SharedPtr<Aspose::Slides::SmartArt::SmartArtNode> node = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArtNode>(smart->get_AllNodes()->idx_get(i));
				
				int iNodeShapeCount = node->get_Shapes()->get_Count();

				for(int j=0; j < iNodeShapeCount;j++)
				{
					System::SharedPtr<Aspose::Slides::SmartArt::SmartArtShape> nodeShape=System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArtShape>(node->get_Shapes()->idx_get(j));
					//auto nodeShape = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArtShape>(node->get_Shapes()->idx_get(j));

					if (nodeShape->get_TextFrame() != NULL)
					{
						// Printing the SmartArt nodeShape parameters
						System::Console::WriteLine(u"NodeShape Text is: {0}", nodeShape->get_TextFrame()->get_Text());

					}
				}


			}
		}
	}
	// ExEnd:GetTextFromSmartArtNode
}
