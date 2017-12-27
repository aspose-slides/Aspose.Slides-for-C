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
#include <DOM/ParagraphFormat.h>
#include <DOM/IBulletFormat.h>
#include <DOM/BulletType.h>

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
#include <DOM/Portion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/Paragraph.h>
#include <DOM/IParagraph.h>
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAlignment.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/NumberedBulletStyle.h>



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


void ParagraphBullets()
{

	// ExStart:ParagraphBullets
	// The path to the documents directory.
	const String outPath = L"../out/ParagraphBullets_out.pptx";
	const String templatePath = L"../templates/DefaultFonts.pptx";
	const String ImagePath = L"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(L"");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();
	txtFrame->get_Paragraphs()->Clear();

	// Create the Paragraph object for text frame
	SharedPtr<Paragraph> paragraph = MakeObject<Paragraph>();

	//Setting Text
	paragraph->set_Text(L"Welcome to Aspose.Slides");

	// Setting bullet indent
	paragraph->get_ParagraphFormat()->set_Indent (25);

	// Setting bullet color
	paragraph->get_ParagraphFormat()->get_Bullet()->get_Color()->set_ColorType ( ColorType::RGB);
	paragraph->get_ParagraphFormat()->get_Bullet()->get_Color()->set_Color(Color::get_Black());
	
	// set IsBulletHardColor to true to use own bullet color
	paragraph->get_ParagraphFormat()->get_Bullet()->set_IsBulletHardColor(NullableBool::True); 
																						
	// Setting Bullet Height
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Height(100);

	// Adding Paragraph to text frame
	txtFrame->get_Paragraphs()->Add(paragraph);

	// Creating second paragraph
	// Create the Paragraph object for text frame
	SharedPtr<Paragraph> paragraph2 = MakeObject<Paragraph>();

	//Setting Text
	paragraph2->set_Text(L"This is numbered bullet");

	// Setting paragraph bullet type and style
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Type ( BulletType::Numbered);
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStyle ( NumberedBulletStyle::BulletCircleNumWDBlackPlain);

	// Setting bullet indent
	paragraph2->get_ParagraphFormat()->set_Indent(25);

	// Setting bullet color
	paragraph2->get_ParagraphFormat()->get_Bullet()->get_Color()->set_ColorType(ColorType::RGB);
	paragraph2->get_ParagraphFormat()->get_Bullet()->get_Color()->set_Color(Color::get_Black());

	// set IsBulletHardColor to true to use own bullet color
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_IsBulletHardColor(NullableBool::True);

	// Setting Bullet Height
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Height(100);

	// Adding Paragraph to text frame
	txtFrame->get_Paragraphs()->Add(paragraph2);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ParagraphBullets
}
