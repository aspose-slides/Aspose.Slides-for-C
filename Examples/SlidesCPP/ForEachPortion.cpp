#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Animation;
using namespace LowCode;

void ForEachPortion()
{
    //ExStart:ForEachPortion

    String pptxFileName = Path::Combine(GetDataPath(), u"ForEachPortion.pptx");

    auto pres = System::MakeObject<Presentation>(pptxFileName);

    auto lambda = [](SharedPtr<Portion> portion, SharedPtr<Paragraph> para, SharedPtr<BaseSlide> slide, int32_t index) -> void
    {
        if (ObjectExt::Is<NotesSlide>(slide) && !String::IsNullOrEmpty(portion->get_Text()))
        {
            Console::WriteLine(u"{0}, index: {1}", portion->get_Text(), index);
        }
    };

    auto callback = ForEach::ForEachPortionCallback(lambda);

    ForEach::Portion(pres, true, callback);

    //ExEnd:ForEachPortion
}
