#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetTextStyleEffectiveData()
{
	//ExStart:GetTextStyleEffectiveData

	// The path to the documents directory.	
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	SharedPtr<IAutoShape> shape = System::AsCast<IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	SharedPtr<ITextStyleEffectiveData> effectiveTextStyle = shape->get_TextFrame()->get_TextFrameFormat()->get_TextStyle()->GetEffective();

	for (int32_t i = 0; i <= 8; i++)
	{
		SharedPtr<IParagraphFormatEffectiveData> effectiveStyleLevel = effectiveTextStyle->GetLevel(i);
		Console::WriteLine(String(u"= Effective paragraph formatting for style level #") + i + u" =");

		Console::WriteLine(String(u"Depth: ") + effectiveStyleLevel->get_Depth());
		Console::WriteLine(String(u"Indent: ") + effectiveStyleLevel->get_Indent());
		Console::WriteLine(String(u"Alignment: ") + ObjectExt::ToString(effectiveStyleLevel->get_Alignment()));
		Console::WriteLine(String(u"Font alignment: ") + ObjectExt::ToString(effectiveStyleLevel->get_FontAlignment()));
	}

	//ExEnd:GetTextStyleEffectiveData
}
