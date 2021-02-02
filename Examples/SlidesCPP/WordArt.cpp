#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;
using namespace System::IO;

void WordArt()
{
    // ExStart:WordArt
    String resultPath = Path::Combine(GetOutPath(), u"WordArt_out.pptx");
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create shape and text frame
    SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 314.0f, 122.0f, 400.0f, 215.433f);

    SharedPtr<ITextFrame> textFrame = shape->get_TextFrame();

    SharedPtr<Portion> portion = System::DynamicCast<Portion>(textFrame->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0));
    portion->set_Text(u"Aspose.Slides");
    SharedPtr<FontData> fontData = System::MakeObject<FontData>(u"Arial Black");
    portion->get_PortionFormat()->set_LatinFont(fontData);
    portion->get_PortionFormat()->set_FontHeight(36.0f);

    // Set format of the text
    portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Pattern);
    portion->get_PortionFormat()->get_FillFormat()->get_PatternFormat()->get_ForeColor()->set_Color(Color::get_DarkOrange());
    portion->get_PortionFormat()->get_FillFormat()->get_PatternFormat()->get_BackColor()->set_Color(Color::get_White());
    portion->get_PortionFormat()->get_FillFormat()->get_PatternFormat()->set_PatternStyle(PatternStyle::SmallGrid);

    portion->get_PortionFormat()->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
    portion->get_PortionFormat()->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

    // Add a shadow effect for the text
    portion->get_PortionFormat()->get_EffectFormat()->EnableOuterShadowEffect();
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->get_ShadowColor()->set_Color(Color::get_Black());
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_ScaleHorizontal(100);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_ScaleVertical(65);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_BlurRadius(4.73);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_Direction(230.0f);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_Distance(2);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_SkewHorizontal(30);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->set_SkewVertical(0);
    portion->get_PortionFormat()->get_EffectFormat()->get_OuterShadowEffect()->get_ShadowColor()->get_ColorTransform()->Add(ColorTransformOperation::SetAlpha, 0.32f);

    // Add reflection
    portion->get_PortionFormat()->get_EffectFormat()->EnableReflectionEffect();
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_BlurRadius(0.5);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_Distance(4.72);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_StartPosAlpha(0.f);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_EndPosAlpha(60.f);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_Direction(90.0f);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_ScaleHorizontal(100);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_ScaleVertical(-100);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_StartReflectionOpacity(60.f);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_EndReflectionOpacity(0.9f);
    portion->get_PortionFormat()->get_EffectFormat()->get_ReflectionEffect()->set_RectangleAlign(RectangleAlignment::BottomLeft);

    // Add glow effect
    portion->get_PortionFormat()->get_EffectFormat()->EnableGlowEffect();
    portion->get_PortionFormat()->get_EffectFormat()->get_GlowEffect()->get_Color()->set_R(255);
    portion->get_PortionFormat()->get_EffectFormat()->get_GlowEffect()->get_Color()->get_ColorTransform()->Add(ColorTransformOperation::SetAlpha, 0.54f);
    portion->get_PortionFormat()->get_EffectFormat()->get_GlowEffect()->set_Radius(7);

    // Add transformation
    textFrame->get_TextFrameFormat()->set_Transform(TextShapeType::ArchUpPour);

    // Add 3D effects to the shape
    shape->get_ThreeDFormat()->get_BevelBottom()->set_BevelType(BevelPresetType::Circle);
    shape->get_ThreeDFormat()->get_BevelBottom()->set_Height(10.5);
    shape->get_ThreeDFormat()->get_BevelBottom()->set_Width(10.5);

    shape->get_ThreeDFormat()->get_BevelTop()->set_BevelType(BevelPresetType::Circle);
    shape->get_ThreeDFormat()->get_BevelTop()->set_Height(12.5);
    shape->get_ThreeDFormat()->get_BevelTop()->set_Width(11);

    shape->get_ThreeDFormat()->get_ExtrusionColor()->set_Color(Color::get_Orange());
    shape->get_ThreeDFormat()->set_ExtrusionHeight(6);

    shape->get_ThreeDFormat()->get_ContourColor()->set_Color(Color::get_DarkRed());
    shape->get_ThreeDFormat()->set_ContourWidth(1.5);

    shape->get_ThreeDFormat()->set_Depth(3);

    shape->get_ThreeDFormat()->set_Material(MaterialPresetType::Plastic);

    shape->get_ThreeDFormat()->get_LightRig()->set_Direction(LightingDirection::Top);
    shape->get_ThreeDFormat()->get_LightRig()->set_LightType(LightRigPresetType::Balanced);
    shape->get_ThreeDFormat()->get_LightRig()->SetRotation(0.0f, 0.0f, 40.0f);

    shape->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::PerspectiveContrastingRightFacing);

    // Add 3D effects to the text
    textFrame = shape->get_TextFrame();

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelBottom()->set_BevelType(BevelPresetType::Circle);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelBottom()->set_Height(3.5);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelBottom()->set_Width(3.5);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelTop()->set_BevelType(BevelPresetType::Circle);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelTop()->set_Height(12.5);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_BevelTop()->set_Width(11);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_ExtrusionColor()->set_Color(Color::get_Orange());
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->set_ExtrusionHeight(6);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_ContourColor()->set_Color(Color::get_DarkRed());
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->set_ContourWidth(1.5);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->set_Depth(3);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->set_Material(MaterialPresetType::Plastic);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_LightRig()->set_Direction(LightingDirection::Top);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_LightRig()->set_LightType(LightRigPresetType::Balanced);
    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_LightRig()->SetRotation(0.0f, 0.0f, 40.0f);

    textFrame->get_TextFrameFormat()->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::PerspectiveContrastingRightFacing);

    pres->Save(resultPath, Export::SaveFormat::Pptx);
    // ExEnd:WordArt
}
