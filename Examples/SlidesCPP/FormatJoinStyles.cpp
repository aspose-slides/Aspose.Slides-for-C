#include <iostream>
#include <system/console.h>

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
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAutofitType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/IGroupShape.h>
#include <DOM/GroupShape.h>
#include <DOM/LineStyle.h>
#include <DOM/LineDashStyle.h>
#include <DOM/LineArrowheadLength.h>
#include <DOM/LineArrowheadStyle.h>
#include <DOM/LineStyle.h>
#include <DOM/LineJoinStyle.h>

#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>

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


void FormatJoinStyles()
{

	// ExStart:FormatJoinStyles
	// The path to the documents directory.
	const String outPath = u"../out/FormatJoinStyles_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	SharedPtr<IAutoShape> shape1 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 150, 75);
	SharedPtr<IAutoShape> shape2 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 300, 100, 150, 75);
	SharedPtr<IAutoShape> shape3 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 250, 150, 75);

	// Set the fill color of the rectangle shape
	shape1->get_FillFormat()->set_FillType(FillType::Solid);
	shape1->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape1->get_LineFormat()->set_Width(15);
	shape1->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape1->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Set the fill color of the rectangle shape
	shape2->get_FillFormat()->set_FillType(FillType::Solid);
	shape2->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape2->get_LineFormat()->set_Width(15);
	shape2->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape2->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());


	// Set the fill color of the rectangle shape
	shape3->get_FillFormat()->set_FillType(FillType::Solid);
	shape3->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	shape3->get_LineFormat()->set_Width(15);
	shape3->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape3->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Blue());

	// Set the Join Style
	shape2->get_LineFormat()->set_JoinStyle(LineJoinStyle::Miter);
	shape2->get_LineFormat()->set_JoinStyle(LineJoinStyle::Bevel);
	shape3->get_LineFormat()->set_JoinStyle(LineJoinStyle::Round);

	// Add text to each rectangle
	shape1->get_TextFrame()->set_Text(u"This is Miter Join Style");
	shape2->get_TextFrame()->set_Text(u"This is Bevel Join Style");
	shape3->get_TextFrame()->set_Text(u"This is Round Join Style");

	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:FormatJoinStyles

}
