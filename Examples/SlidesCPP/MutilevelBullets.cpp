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
#include <DOM/IParagraphFormat.h>
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
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/Paragraph.h>
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAlignment.h>
#include <DOM/ISlidesPicture.h>


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


void MutilevelBullets()
{

	// ExStart:MutilevelBullets
	// The path to the documents directory.
	const String outPath = u"../out/MutilevelBullets_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 200, 300);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();
	
	//Clearing exisiting default paragraph
	txtFrame->get_Paragraphs()->Clear();

	// Create the first level bullet paragraph
	SharedPtr<Paragraph> Para1 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para1 = DynamicCast<IParagraph>(Para1);
	para1->set_Text(u"Content");
	// Setting paragraph bullet style 
	para1->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para1->get_ParagraphFormat()->get_Bullet()->set_Char(Convert::ToChar(8226));
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para1->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para1->get_ParagraphFormat()->set_Depth(0);


	// Create the second level bullet paragraph
	SharedPtr<Paragraph> Para2 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para2 = DynamicCast<IParagraph>(Para2);
	para2->set_Text(u"Second level");
	// Setting paragraph bullet style 
	para2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para2->get_ParagraphFormat()->get_Bullet()->set_Char('-');
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para2->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para2->get_ParagraphFormat()->set_Depth(1);

	// Create the third level bullet paragraph
	SharedPtr<Paragraph> Para3 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para3 = DynamicCast<IParagraph>(Para3);
	para3->set_Text(u"Content");
	// Setting paragraph bullet style 
	para3->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para3->get_ParagraphFormat()->get_Bullet()->set_Char(Convert::ToChar(8226));
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para3->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para3->get_ParagraphFormat()->set_Depth(0);


	// Create the fourth level bullet paragraph
	SharedPtr<Paragraph> Para4 = MakeObject<Paragraph>();
	SharedPtr<IParagraph> para4 = DynamicCast<IParagraph>(Para4);
	para4->set_Text(u"Fourth level");
	// Setting paragraph bullet style 
	para4->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Symbol);
	para4->get_ParagraphFormat()->get_Bullet()->set_Char('-');
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	para4->get_ParagraphFormat()->get_DefaultPortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());
	//Setting bullet level
	para4->get_ParagraphFormat()->set_Depth(3);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:MutilevelBullets
}
