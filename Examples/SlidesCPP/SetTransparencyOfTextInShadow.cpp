#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void SetTransparencyOfTextInShadow()
{
	//ExStart:SetTransparencyOfTextInShadow
	const String templatePath = u"../templates/transparency.pptx";
	const String outPath = u"../out/transparency-out.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
    auto shape = DynamicCast<IAutoShape>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)) ;

    auto effects = shape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_EffectFormat();

    auto outerShadowEffect = effects->get_OuterShadowEffect();

    auto shadowColor = outerShadowEffect->get_ShadowColor()->get_Color();

	// set transparency to zero percent
	outerShadowEffect->get_ShadowColor()->set_Color(Color(shadowColor.FromArgb(255, shadowColor)));
	
	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetTransparencyOfTextInShadow
}
