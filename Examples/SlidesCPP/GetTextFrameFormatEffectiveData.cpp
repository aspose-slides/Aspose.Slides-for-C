
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


#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetTextFrameFormatEffectiveData() {

	//ExStart:GetTextFrameFormatEffectiveData

	// The path to the documents directory.	
	const String templatePath = u"../templates/Presentation1.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	System::SharedPtr<IAutoShape> shape = System::DynamicCast_noexcept<Aspose::Slides::IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	System::SharedPtr<ITextFrameFormatEffectiveData> effectiveTextFrameFormat = shape->get_TextFrame()->get_TextFrameFormat()->GetEffective();

	System::Console::WriteLine(System::String(u"Anchoring type: ") + System::ObjectExt::ToString((int)effectiveTextFrameFormat->get_AnchoringType()));
	System::Console::WriteLine(System::String(u"Autofit type: ") + System::ObjectExt::ToString((int)effectiveTextFrameFormat->get_AutofitType()));
	System::Console::WriteLine(System::String(u"Text vertical type: ") + System::ObjectExt::ToString((int)effectiveTextFrameFormat->get_TextVerticalType()));
	System::Console::WriteLine(u"Margins");
	System::Console::WriteLine(System::String(u"   Left: ") + effectiveTextFrameFormat->get_MarginLeft());
	System::Console::WriteLine(System::String(u"   Top: ") + effectiveTextFrameFormat->get_MarginTop());
	System::Console::WriteLine(System::String(u"   Right: ") + effectiveTextFrameFormat->get_MarginRight());
	System::Console::WriteLine(System::String(u"   Bottom: ") + effectiveTextFrameFormat->get_MarginBottom());

	//ExEnd:GetTextFrameFormatEffectiveData

}