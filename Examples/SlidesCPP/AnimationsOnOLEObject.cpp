#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Animation;
using namespace System;

void AnimationsOnOLEObject()
{
    // ExStart:AnimationsOnOLEObject

    // The path to the documents directory.
    const String outPath = u"../out/AnimationsOnOLEObject_out.pptx";
    const String templatePath = u"../templates/AccessingOLEObjectFrame.pptx";

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    //Accessing OLE Object
    SharedPtr<IOleObjectFrame> ole = System::DynamicCast<IOleObjectFrame>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    //Applying animation effects
    SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, EffectType::OLEObjectOpen, EffectSubtype::None, EffectTriggerType::OnClick);
    //System::SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, Aspose::Slides::Animation::EffectType::OLEObjectEdit, Aspose::Slides::Animation::EffectSubtype::None, Aspose::Slides::Animation::EffectTriggerType::OnClick);
    //System::SharedPtr<IEffect> effect = pres->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->AddEffect(ole, Aspose::Slides::Animation::EffectType::OLEObjectShow, Aspose::Slides::Animation::EffectSubtype::None, Aspose::Slides::Animation::EffectTriggerType::OnClick);

    //Write the PPTX to Disk
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //Now loading the presentaiton with effects

    SharedPtr<Presentation> pres2 = System::MakeObject<Presentation>(outPath);

    SharedPtr<IShape> shape = pres2->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0);

    ArrayPtr<SharedPtr<IEffect>> effects = pres2->get_Slides()->idx_get(0)->get_Timeline()->get_MainSequence()->GetEffectsByShape(shape);

    if (effects->get_Length() > 0 && effects[0]->get_PresetClassType() == EffectPresetClassType::OLEActionVerbs)
    {
        Console::WriteLine(u"This shape has the OLE Action Verb effect");
    }
	//ExEnd:AnimationsOnOLEObject
}
