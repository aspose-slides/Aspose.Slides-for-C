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






void SetCustomBulletsNumber() {

	//ExStart:SetCustomBulletsNumber
	// The path to the documents directory.
	const String outPath = u"../out/SetCustomBulletsNumber_out.pptx";

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


	// First list
	SharedPtr<Paragraph> paragraph1 = MakeObject<Paragraph>();
	paragraph1->set_Text(u"bullet 2");
	paragraph1->get_ParagraphFormat()->set_Depth((short)4);
	paragraph1->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)2);
	paragraph1->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);
	txtFrame->get_Paragraphs()->Add(paragraph1);

	SharedPtr<Paragraph> paragraph2 = MakeObject<Paragraph>();
	paragraph2->set_Text(u"bullet 3");
	paragraph2->get_ParagraphFormat()->set_Depth((short)4);
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)3); 
	paragraph2->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);  
	txtFrame->get_Paragraphs()->Add(paragraph2);

	// Second list
	SharedPtr<Paragraph> paragraph5 = MakeObject<Paragraph>();
	paragraph5->set_Text(u"bullet 5");
	paragraph5->get_ParagraphFormat()->set_Depth((short)4);
	paragraph5->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStartWith((short)5);
	paragraph5->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Numbered);
	txtFrame->get_Paragraphs()->Add(paragraph5);



	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetCustomBulletsNumber
}