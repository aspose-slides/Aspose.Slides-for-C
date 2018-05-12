
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
#include <DOM/IShapeFrame.h>

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
#include <DOM/IAnimationTimeLine.h>
#include <DOM/Animation/ISequence.h>
#include <DOM/Animation/ISequenceCollection.h>
#include <DOM/Animation/EffectType.h>
#include <DOM/Animation/EffectSubtype.h>
#include <DOM/Animation/EffectTriggerType.h>
#include <DOM/Animation/IEffect.h>
#include <DOM/Animation/Sequence.h>
#include <DOM/Animation/IMotionEffect.h>
#include <DOM/Animation/MotionEffect.h>
#include <DOM/Animation/IBehaviorCollection.h>
#include <DOM/Animation/MotionCommandPathType.h>
#include <DOM/Animation/MotionPathPointsType.h>
#include <DOM/Animation/IMotionPath.h>
#include <DOM/IOleObjectFrame.h>
#include <DOM/Animation/EffectPresetClassType.h>

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
using namespace Aspose::Slides::Animation;
using namespace System;
using namespace System::Drawing;


void AnimationsOnOLEObject()
{
	// ExStart:AnimationsOnOLEObject

	// The path to the documents directory.
	const String outPath = u"../out/AnimationsOnOLEObject_out.pptx";
	const String templatePath = u"../templates/AccessingOLEObjectFrame.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	//Accessing OLE Object
	System::SharedPtr<IOleObjectFrame> ole = System::DynamicCast<Aspose::Slides::IOleObjectFrame>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	
	//Applying animation effects
	System::SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, Aspose::Slides::Animation::EffectType::OLEObjectOpen, Aspose::Slides::Animation::EffectSubtype::None, Aspose::Slides::Animation::EffectTriggerType::OnClick);
	//System::SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, Aspose::Slides::Animation::EffectType::OLEObjectEdit, Aspose::Slides::Animation::EffectSubtype::None, Aspose::Slides::Animation::EffectTriggerType::OnClick);
	//System::SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, Aspose::Slides::Animation::EffectType::OLEObjectShow, Aspose::Slides::Animation::EffectSubtype::None, Aspose::Slides::Animation::EffectTriggerType::OnClick);

	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//Now loading the presentaiton with effects

	System::SharedPtr<Presentation> pres2 = System::MakeObject<Presentation>(outPath);

	System::SharedPtr<IShape> shape = pres2->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0);

	System::ArrayPtr<System::SharedPtr<IEffect>> effects = pres2->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->GetEffectsByShape(shape);

	if (effects->get_Length() > 0 && effects[0]->get_PresetClassType() == Aspose::Slides::Animation::EffectPresetClassType::OLEActionVerbs)
		
		System::Console::WriteLine(u"This shape has the OLE Action Verb effect");

	//ExEnd:AnimationsOnOLEObject

}


