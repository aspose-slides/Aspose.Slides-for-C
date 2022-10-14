#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetEffectiveValues() 
{
	// ExStart:GetEffectiveValues
	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	SharedPtr<IAutoShape> shape = System::AsCast<IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

	SharedPtr<ITextFrameFormat> localTextFrameFormat = shape->get_TextFrame()->get_TextFrameFormat();
	SharedPtr<ITextFrameFormatEffectiveData> effectiveTextFrameFormat = localTextFrameFormat->GetEffective();

	SharedPtr<IPortionFormat> localPortionFormat = shape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat();
	SharedPtr<IPortionFormatEffectiveData> effectivePortionFormat = localPortionFormat->GetEffective();

	// ExEnd:GetEffectiveValues
}
