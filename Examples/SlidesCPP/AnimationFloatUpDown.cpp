#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides::Animation;
using namespace System;

void AnimationFloatUpDown()
{
    //ExStart:AnimationFloatUpDown

    EffectType type = EffectType::Descend;
    Console::WriteLine(type == EffectType::Descend); // Should return true
    Console::WriteLine(type == EffectType::FloatDown); // Should return true

    type = EffectType::FloatDown;
    Console::WriteLine(type == EffectType::Descend); // Should return true
    Console::WriteLine(type == EffectType::FloatDown); // Should return true

    type = EffectType::Ascend;
    Console::WriteLine(type == EffectType::Ascend); // Should return true
    Console::WriteLine(type == EffectType::FloatUp); // Should return true

    type = EffectType::FloatUp;
    Console::WriteLine(type == EffectType::Ascend); // Should return true
    Console::WriteLine(type == EffectType::FloatUp); // Should return true

    // ExEnd:AnimationFloatUpDown
}
