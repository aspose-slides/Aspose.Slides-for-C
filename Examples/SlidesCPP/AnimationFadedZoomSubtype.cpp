#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Animation;
using namespace System::IO;

void AnimationFadedZoomSubtype()
{
    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"AnimationFadedZoom-out.pptx");

    // Instantiate Presentation class that represents a presentation file
    auto pres = System::MakeObject<Presentation>();
    auto slide = pres->get_Slide(0);

    // Create shapes for demonstration
    auto shp1 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 0, 0, 50, 50);
    auto shp2 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 0, 50, 50);

    // Add FadedZoom effects
    auto ef1 = slide->get_Timeline()->get_MainSequence()->AddEffect(shp1, EffectType::FadedZoom, EffectSubtype::ObjectCenter, EffectTriggerType::OnClick);
    auto ef2 = slide->get_Timeline()->get_MainSequence()->AddEffect(shp2, EffectType::FadedZoom, EffectSubtype::SlideCenter, EffectTriggerType::OnClick);

    // Save presentation
    pres->Save(outPath, SaveFormat::Pptx);
}
