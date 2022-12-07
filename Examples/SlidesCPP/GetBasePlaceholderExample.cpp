#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Animation;

void GetBasePlaceholderExample()
{
    const String presentationName = Path::Combine(GetDataPath(), u"placeholder.pptx");

    auto presentation = System::MakeObject<Presentation>(presentationName);

    SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);
    SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(0);
    ArrayPtr<SharedPtr<IEffect>> shapeEffects = slide->get_LayoutSlide()->get_Timeline()->get_MainSequence()->GetEffectsByShape(shape);
    Console::WriteLine(u"Shape effects count = {0}", shapeEffects->get_Length());

    SharedPtr<IShape> layoutShape = shape->GetBasePlaceholder();
    ArrayPtr<SharedPtr<IEffect>> layoutShapeEffects = slide->get_LayoutSlide()->get_Timeline()->get_MainSequence()->GetEffectsByShape(layoutShape);
    Console::WriteLine(u"Layout shape effects count = {0}", layoutShapeEffects->get_Length());

    SharedPtr<IShape> masterShape = layoutShape->GetBasePlaceholder();
    ArrayPtr<SharedPtr<IEffect>> masterShapeEffects = slide->get_LayoutSlide()->get_MasterSlide()->get_Timeline()->get_MainSequence()->GetEffectsByShape(masterShape);
    Console::WriteLine(u"Master shape effects count = {0}", masterShapeEffects->get_Length());
}
