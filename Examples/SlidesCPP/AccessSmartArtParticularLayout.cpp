#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace SmartArt;
using namespace System;

void AccessSmartArtParticularLayout()
{
	// ExStart:AccessSmartArtParticularLayout
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide
	for (int x = 0; x < pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			Console::WriteLine(u"Smart Art Name = " + smart->get_Name());

			// Checking SmartArt Layout
			if (smart->get_Layout() == SmartArtLayoutType::BasicBlockList)
			{
				Console::WriteLine(u"Do some thing here....");
			}
		}
	}

	// ExEnd:AccessSmartArtParticularLayout
}
