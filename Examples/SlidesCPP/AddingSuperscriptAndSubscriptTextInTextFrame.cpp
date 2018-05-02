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
#include <DOM/Portion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/PortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/Paragraph.h>
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAlignment.h>
#include <DOM/IParagraphFormat.h>


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


void AddingSuperscriptAndSubscriptTextInTextFrame()
{

	// ExStart:AddingSuperscriptAndSubscriptTextInTextFrame
	// The path to the documents directory.
	const String outPath = u"../out/AddingSuperscriptAndSubscriptTextInTextFrame_out.pptx";
	//const String templatePath = u"../templates/DefaultFonts.pptx";


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 300, 300);

	// Add TextFrame to the Rectangle
	SharedPtr<ITextFrame> tf = ashp->AddTextFrame(String::Empty);

	tf->get_Paragraphs()->Clear();

	// Adding the first Paragraph
	SharedPtr<Paragraph> superPar = MakeObject<Paragraph>();
	SharedPtr<Portion> portion1 = MakeObject<Portion>(u"SlideTitle");
	superPar->get_Portions()->Add(portion1);

	SharedPtr<Portion> superPortion = MakeObject<Portion>();
	superPortion->get_PortionFormat()->set_Escapement(30);
	superPortion->set_Text(u"TM");
	superPar->get_Portions()->Add(superPortion);


	// Adding the first Paragraph
	SharedPtr<Paragraph> subPar = MakeObject<Paragraph>();
	SharedPtr<Portion> portion2 = MakeObject<Portion>(u"a");
	subPar->get_Portions()->Add(portion2);

	SharedPtr<Portion> subPortion = MakeObject<Portion>();
	subPortion->get_PortionFormat()->set_Escapement(-25);
	subPortion->set_Text(u"i");
	subPar->get_Portions()->Add(subPortion);

	//Adding to text frame
	ashp->get_TextFrame()->get_Paragraphs()->Add(superPar);
	ashp->get_TextFrame()->get_Paragraphs()->Add(subPar);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:AddingSuperscriptAndSubscriptTextInTextFrame
}
