#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;

void AnimationTargetShapes()
{
    // Path to source presentation
    String presentationFileName = IO::Path::Combine(GetDataPath(), u"AnimationShapesExample.pptx");
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationFileName);

    for (const auto& slide : pres->get_Slides())
    {
        for (const auto& effect : slide->get_Timeline()->get_MainSequence())
        {
            Console::WriteLine(ObjectExt::ToString(effect->get_Type()) 
                + u" animation effect is set to shape#" 
                + effect->get_TargetShape()->get_UniqueId() 
                + u" on slide#" 
                + slide->get_SlideNumber());
        }
    }
}
