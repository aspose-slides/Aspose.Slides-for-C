
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Shape.h>
#include <DOM/IPlaceholder.h>
#include <DOM/PlaceholderType.h>
#include <Export/SaveFormat.h>
#include <DOM/ITextFrame.h>
#include <system/console.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;


void AddCustomPromptText() {

  //ExStart:AddCustomPromptText

	const String templatePath = u"../templates/Presentation2.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	System::SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	for (int x = 0; x < slide->get_Slide()->get_Shapes()->get_Count(); x++)
	{
		System::SharedPtr<IShape> shape = slide->get_Slide()->get_Shapes()->idx_get(x);

		if (shape->get_Placeholder() != NULL) {

			String text = u"";
			if (shape->get_Placeholder()->get_Type() == PlaceholderType::CenteredTitle) // title - the text is empty, PowerPoint displays "Click to add title". 
			{
				text = u"Click to add title";
			}
			else if (shape->get_Placeholder()->get_Type() == PlaceholderType::Subtitle) // the same for subtitle.
			{
				text = u"Click to add subtitle";
			}
					
			
			System::Console::WriteLine(u"Placeholder with text: {0}", text);
			
		}

	}

	pres->Save(u"../out/Placeholders_PromptText.pptx", Aspose::Slides::Export::SaveFormat::Pptx);

  //ExEnd:AddCustomPromptText

}