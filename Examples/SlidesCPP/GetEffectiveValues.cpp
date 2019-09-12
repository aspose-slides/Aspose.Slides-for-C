
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/AutoShape.h>
#include <DOM/ITextFrame.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>



#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetEffectiveValues() 
{

	// ExStart:GetEffectiveValues
	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	System::SharedPtr<IAutoShape> shape = System::DynamicCast_noexcept<Aspose::Slides::IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

	System::SharedPtr<ITextFrameFormat> localTextFrameFormat = shape->get_TextFrame()->get_TextFrameFormat();
	System::SharedPtr<ITextFrameFormatEffectiveData> effectiveTextFrameFormat = localTextFrameFormat->GetEffective();

	System::SharedPtr<IPortionFormat> localPortionFormat = shape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat();
	System::SharedPtr<IPortionFormatEffectiveData> effectivePortionFormat = localPortionFormat->GetEffective();

	// ExEnd:GetEffectiveValues

}