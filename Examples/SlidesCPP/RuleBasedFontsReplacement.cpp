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
#include <DOM/IFontsManager.h>
#include <DOM/Fonts/FontSubstRuleCollection.h>
#include <DOM/Fonts/FontSubstRule.h>
#include <DOM/FontSubstCondition.h>


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


void RuleBasedFontsReplacement()
{

	// ExStart:RuleBasedFontsReplacement
	// The path to the documents directory.
	const String outPath = L"../out/RuleBasedFontsReplacement_out.pptx";
	const String templatePath = L"../templates/DefaultFonts.pptx";


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Define new fonts
	SharedPtr<IFontData> sourceFont = MakeObject<FontData>(L"SomeRareFont");
	SharedPtr<IFontData> destFont = MakeObject<FontData>(L"Arial");
	
	// Add font rule for font replacement
	SharedPtr<FontSubstRule> fontSubstRule = MakeObject<FontSubstRule>(sourceFont, destFont, FontSubstCondition::WhenInaccessible);

	// Add rule to font substitute rules collection
	SharedPtr<FontSubstRuleCollection> fontSubstRuleCollection = MakeObject<FontSubstRuleCollection>();
	fontSubstRuleCollection->Add(fontSubstRule);

	// Add font rule collection to rule list
	pres->get_FontsManager()->set_FontSubstRuleList ( fontSubstRuleCollection);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:RuleBasedFontsReplacement
}
