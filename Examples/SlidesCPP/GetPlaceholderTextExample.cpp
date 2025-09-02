#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Util;
using namespace System;
using namespace IO;

void GetPlaceholderTextExample()
{
    //ExStart:GetPlaceholderTextExample

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Add new slide based on LayoutSlides[0]
    SharedPtr<ISlide> slide = pres->get_Slides()->AddEmptySlide(pres->get_LayoutSlides()->idx_get(0));

    // Search for specified text in a slide, including its layout (layout template text)
    for (auto&& textFrame : SlideUtil::GetTextBoxesContainsText(slide, u"Click", true))
    {
        // Set text for TextFrame
        Console::WriteLine(u"A text block with the specified text was found.");
    }

    // Find all “Text” placeholders on a slide:
    for(auto&& shape : SlideUtil::FindShapesByPlaceholderType(slide, PlaceholderType::CenteredTitle))
    {
        Console::WriteLine(u"Placeholder of type PlaceholderType.CenteredTitle was found.");
    }

    //ExEnd:GetPlaceholderTextExample
}
