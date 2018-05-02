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
#include <DOM/ITextFrameFormat.h>


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
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAlignment.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/NumberedBulletStyle.h>
#include <DOM/TextAutofitType.h>
#include <DOM/TextAlignment.h>


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


void ParagraphIndent()
{

	// ExStart:ParagraphBullets
	// The path to the documents directory.
	const String outPath = u"../out/ParagraphIndent.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"This is first line \rThis is second line \rThis is third line");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Set the text to fit the shape
	txtFrame->get_TextFrameFormat()->set_AutofitType ( TextAutofitType::Shape);

	// Hide the lines of the Rectangle
	ashp->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);

	// Setting paragraph bullet style and symbol
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');
	
	paragraph->get_ParagraphFormat()->set_Alignment( TextAlignment::Left);

	// Setting bullet indent
	paragraph->get_ParagraphFormat()->set_Depth(2);
	paragraph->get_ParagraphFormat()->set_Indent(30);


	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph2 = txtFrame->get_Paragraphs()->idx_get(1);

	// Setting paragraph bullet style and symbol
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');

	paragraph2->get_ParagraphFormat()->set_Alignment(TextAlignment::Left);

	// Setting bullet indent
	paragraph2->get_ParagraphFormat()->set_Depth(2);
	paragraph2->get_ParagraphFormat()->set_Indent(40);

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph3 = txtFrame->get_Paragraphs()->idx_get(2);

	// Setting paragraph bullet style and symbol
	paragraph3->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	//paragraph->get_ParagraphFormat()->get_Bullet()->set_Char(Convert.ToChar(8226));
	paragraph3->get_ParagraphFormat()->get_Bullet()->set_Char('\8226');

	paragraph3->get_ParagraphFormat()->set_Alignment(TextAlignment::Left);

	// Setting bullet indent
	paragraph3->get_ParagraphFormat()->set_Depth(2);
	paragraph3->get_ParagraphFormat()->set_Indent(50);

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ParagraphIndent
}
