#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetTextFrameFormatEffectiveData()
{
	//ExStart:GetTextFrameFormatEffectiveData

	// The path to the documents directory.	
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
    auto shape = System::AsCast<IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    auto effectiveTextFrameFormat = shape->get_TextFrame()->get_TextFrameFormat()->GetEffective();

	Console::WriteLine(String(u"Anchoring type: ") + ObjectExt::ToString((int)effectiveTextFrameFormat->get_AnchoringType()));
	Console::WriteLine(String(u"Autofit type: ") + ObjectExt::ToString((int)effectiveTextFrameFormat->get_AutofitType()));
	Console::WriteLine(String(u"Text vertical type: ") + ObjectExt::ToString((int)effectiveTextFrameFormat->get_TextVerticalType()));
	Console::WriteLine(u"Margins");
	Console::WriteLine(String(u"   Left: ") + effectiveTextFrameFormat->get_MarginLeft());
	Console::WriteLine(String(u"   Top: ") + effectiveTextFrameFormat->get_MarginTop());
	Console::WriteLine(String(u"   Right: ") + effectiveTextFrameFormat->get_MarginRight());
	Console::WriteLine(String(u"   Bottom: ") + effectiveTextFrameFormat->get_MarginBottom());

	//ExEnd:GetTextFrameFormatEffectiveData
}
