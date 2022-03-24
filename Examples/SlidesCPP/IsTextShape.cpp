#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void IsTextShape()
{
    auto pres = System::MakeObject<Presentation>(Path::Combine(GetDataPath(), u"CheckTextShapes.pptx"));
    
    for (auto&& slide : pres->get_Slides())
    {
        for (auto&& shape : slide->get_Shapes())
        {
            auto autoShape = System::DynamicCast_noexcept<Aspose::Slides::AutoShape>(shape);
            if (autoShape != nullptr)
            {
                System::Console::WriteLine(autoShape->get_IsTextBox() 
                    ? System::String(u"shape is text box") 
                    : System::String(u"shape is not text box"));
            }
        }
    }

}
