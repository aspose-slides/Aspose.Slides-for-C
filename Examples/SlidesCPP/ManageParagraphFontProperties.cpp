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


void ManageParagraphFontProperties()
{

	// ExStart:ManageParagraphFontProperties
	// The path to the documents directory.
	const String outPath = L"../out/ManageParagraphFontProperties_out.pptx";
	const String templatePath = L"../templates/DefaultFonts.pptx";


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing the first and second placeholder in the slide and typecasting it as AutoShape
	SharedPtr<IShape> shape1 = slide->get_Shapes()->idx_get(0);
	SharedPtr<IShape> shape2 = slide->get_Shapes()->idx_get(1);


	SharedPtr<AutoShape> ashp1 = DynamicCast<Aspose::Slides::AutoShape>(shape1);
	SharedPtr<AutoShape> ashp2 = DynamicCast<Aspose::Slides::AutoShape>(shape2);


	SharedPtr<ITextFrame> tf1 = ashp1->get_TextFrame();
	SharedPtr<ITextFrame> tf2 = ashp2->get_TextFrame();


	// Accessing the first Paragraph
	SharedPtr<IParagraph> para1 = tf1->get_Paragraphs()->idx_get(0);
	SharedPtr<IParagraph> para2 = tf2->get_Paragraphs()->idx_get(0);

	// Justify the paragraph
	para2->get_ParagraphFormat()->set_Alignment (TextAlignment::JustifyLow);

	// Accessing the first portion
	SharedPtr<IPortion> port1 = para1->get_Portions()->idx_get(0);
	SharedPtr<IPortion> port2 = para2->get_Portions()->idx_get(0);

	// Define new fonts
	SharedPtr<IFontData> fd1 = MakeObject<FontData>(L"Elephant");
	SharedPtr<IFontData> fd2 = MakeObject<FontData>(L"Castellar");

	// Assign new fonts to portion
	port1->get_PortionFormat()->set_LatinFont(fd1);
	port2->get_PortionFormat()->set_LatinFont(fd2);

	// Set font to Bold
	port1->get_PortionFormat()->set_FontBold(NullableBool::True);
	port2->get_PortionFormat()->set_FontBold(NullableBool::True);

	// Set font to Italic
	port1->get_PortionFormat()->set_FontItalic(NullableBool::True);
	port2->get_PortionFormat()->set_FontItalic(NullableBool::True);

	// Set font color
	port1->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	port1->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Purple());
	port2->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	port2->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Peru());

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ManageParagraphFontProperties
}
