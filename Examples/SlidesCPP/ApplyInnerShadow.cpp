#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/IEffectFormat.h>
#include <DOM/Effects/IInnerShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>


#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

const int NodesCount = 5;

void ApplyInnerShadow()
{

	// ExStart:ApplyInnerShadow
	// The path to the documents directory.
	const String outPath = L"../out/ApplyInnerShadow_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(L" ");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(L"Aspose TextBox");
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	portion->get_PortionFormat()->set_FontHeight(50);

	SharedPtr<IPortionFormat> pf = portion->get_PortionFormat();

	// Enable InnerShadowEffect    
	SharedPtr<IEffectFormat> ef = pf->get_EffectFormat();
	ef->EnableInnerShadowEffect();

	// Set all necessary parameters
	ef->get_InnerShadowEffect()->set_BlurRadius ( 8.0);
	ef->get_InnerShadowEffect()->set_Direction(90.0);
	ef->get_InnerShadowEffect()->set_Distance ( 6.0);
	ef->get_InnerShadowEffect()->get_ShadowColor()->set_B (189);

	// Set ColorType as Scheme
	ef->get_InnerShadowEffect()->get_ShadowColor()->set_ColorType (ColorType::Scheme);

	// Set Scheme Color
	ef->get_InnerShadowEffect()->get_ShadowColor()->set_SchemeColor ( SchemeColor::Accent1);

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:ApplyInnerShadow
}
