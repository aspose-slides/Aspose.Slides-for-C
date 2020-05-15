#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ShadowEffects()
{
	// ExStart:ShadowEffects
	// The path to the documents directory.
	const String outPath = u"../out/ShadowEffects_out.pptx";
	const String templatePath = u"../templates/DefaultFonts_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u" ");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(u"Aspose TextBox");
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	portion->get_PortionFormat()->set_FontHeight(50);

	SharedPtr<IPortionFormat> pf = portion->get_PortionFormat();

	// Enable OuterShadowEffect    
	SharedPtr<IEffectFormat> ef = pf->get_EffectFormat();
	ef->EnableOuterShadowEffect();

	// Set all necessary parameters
	ef->get_OuterShadowEffect()->set_BlurRadius(8.0);
	ef->get_OuterShadowEffect()->set_Direction(90.0);
	ef->get_OuterShadowEffect()->set_Distance(6.0);
	ef->get_OuterShadowEffect()->get_ShadowColor()->set_B(189);

	// Set ColorType as Scheme
	ef->get_OuterShadowEffect()->get_ShadowColor()->set_ColorType(ColorType::Scheme);

	// Set Scheme Color
	ef->get_OuterShadowEffect()->get_ShadowColor()->set_SchemeColor(SchemeColor::Accent1);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ShadowEffects
}
