#include "stdafx.h"
#include "SlidesExamples.h"
#include <LowCode/Compress.h>

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void RemoveUnusedLayoutMaster()
{
    //ExStart:RemoveUnusedLayoutMaster

    auto pres = System::MakeObject<Presentation>(Path::Combine(GetDataPath(), u"MultipleMaster.pptx"));
    
    Console::WriteLine(String(u"Master slides number in source presentation = ") + pres->get_Masters()->get_Count());
    Console::WriteLine(String(u"Layout slides number in source presentation = ") + pres->get_LayoutSlides()->get_Count());

    Aspose::Slides::LowCode::Compress::RemoveUnusedMasterSlides(pres);
    Aspose::Slides::LowCode::Compress::RemoveUnusedLayoutSlides(pres);

    Console::WriteLine(String(u"Master slides number in source presentation = ") + pres->get_Masters()->get_Count());
    Console::WriteLine(String(u"Layout slides number in source presentation = ") + pres->get_LayoutSlides()->get_Count());

    //ExEnd:RemoveUnusedLayoutMaster
}
