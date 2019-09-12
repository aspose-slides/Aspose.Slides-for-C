

#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IAutoShape.h>
#include <DOM/ITextFrameFormatEffectiveData.h>
#include <DOM/TextFrame.h>
#include <DOM/TextFrameFormat.h>
#include <DOM/TextStyle.h>
#include <DOM/ITextStyleEffectiveData.h>
#include <DOM/IParagraphFormatEffectiveData.h>

#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;


void GetTextStyleEffectiveData() {

	//ExStart:GetTextStyleEffectiveData

	// The path to the documents directory.	
	const String templatePath = u"../templates/Presentation1.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	System::SharedPtr<IAutoShape> shape = System::DynamicCast_noexcept<Aspose::Slides::IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	System::SharedPtr<ITextStyleEffectiveData> effectiveTextStyle = shape->get_TextFrame()->get_TextFrameFormat()->get_TextStyle()->GetEffective();

	for (int32_t i = 0; i <= 8; i++)
	{
		System::SharedPtr<IParagraphFormatEffectiveData> effectiveStyleLevel = effectiveTextStyle->GetLevel(i);
		System::Console::WriteLine(System::String(u"= Effective paragraph formatting for style level #") + i + u" =");

		System::Console::WriteLine(System::String(u"Depth: ") + effectiveStyleLevel->get_Depth());
		System::Console::WriteLine(System::String(u"Indent: ") + effectiveStyleLevel->get_Indent());
		System::Console::WriteLine(System::String(u"Alignment: ") + System::ObjectExt::ToString(effectiveStyleLevel->get_Alignment()));
		System::Console::WriteLine(System::String(u"Font alignment: ") + System::ObjectExt::ToString(effectiveStyleLevel->get_FontAlignment()));
	}

	//ExEnd:GetTextStyleEffectiveData

}