#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/IEffectFormat.h>
#include <DOM/Paragraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/Portion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IPortionCollection.h>
#include <DOM/ITextFrame.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/Effects/IOuterShadowEffectiveData.h>
#include <DOM/IColorFormat.h>
#include <Export/SaveFormat.h>

#include <drawing/color.h>
#include <system/string.h>
#include <system/string.h>
#include <system/IO/file.h>
#include "SlidesExamples.h"
#include <system/console.h>

using namespace Aspose::Slides;
using namespace System;


void SetTransparencyOfTextInShadow()
{
	//ExStart:SetTransparencyOfTextInShadow
	const String templatePath = u"../templates/transparency.pptx";
	const String outPath = u"../out/transparency-out.pptx";
		

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
	SharedPtr<IAutoShape> shape = DynamicCast<IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)) ;

	SharedPtr<IEffectFormat> effects = shape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_EffectFormat();

	SharedPtr<Aspose::Slides::Effects::IOuterShadow> outerShadowEffect = effects->get_OuterShadowEffect();

	System::Drawing::Color shadowColor = outerShadowEffect->get_ShadowColor()->get_Color();

	
	// set transparency to zero percent
	outerShadowEffect->get_ShadowColor()->set_Color(System::Drawing::Color(shadowColor.FromArgb(255, shadowColor)));
	
	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:SetTransparencyOfTextInShadow
}