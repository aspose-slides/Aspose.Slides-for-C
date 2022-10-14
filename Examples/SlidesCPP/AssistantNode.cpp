#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AssistantNode()
{
	// ExStart:AssistantNode
	// The path to the documents directory.
	const String templatePath = u"../templates/AssistantNode.pptx";
	const String outPath = u"../out/ChangeAssitantNode_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	for (int x = 0; x < pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::AsCast<Aspose::Slides::SmartArt::SmartArt>(shape);

			for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
			{
				// Accessing SmartArt node at index i
				SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(i);

				if (node->get_IsAssistant())
				{
					// Setting Assitant node to false and making it normal node
					node->set_IsAssistant(false);
				}
			}
		}
	}
	// Save Presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);
	// ExEnd:AssistantNode
}
