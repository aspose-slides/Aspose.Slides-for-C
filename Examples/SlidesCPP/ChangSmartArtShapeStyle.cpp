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
#include <DOM/SmartArt/SmartArtQuickStyleType.h>
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

void ChangSmartArtShapeStyle()
{

	// ExStart:ChangSmartArtShapeStyle
	// The path to the documents directory.
	const String templatePath = u"../templates/SmartArt.pptx";
	const String outPath = u"../out/ChangeSmartArtStyle_out.pptx";


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Traverse through every shape inside first slide

	for (int x = 0; x < pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count(); x++)
	{
		SharedPtr<IShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(x);

		if (System::ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape))
		{
			System::SharedPtr<Aspose::Slides::SmartArt::SmartArt> smart = System::DynamicCast_noexcept<Aspose::Slides::SmartArt::SmartArt>(shape);

			// Checking SmartArt style
			if (smart->get_QuickStyle() == SmartArtQuickStyleType::SimpleFill)
			{
				// Changing SmartArt Style
				smart->set_QuickStyle(SmartArtQuickStyleType::Cartoon);
			}
		}
	}
	// Save Presentation
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ChangSmartArtShapeStyle
}
