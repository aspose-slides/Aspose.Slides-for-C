#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void LayoutPlaceholderManagerExample()
{
    //ExStart:LayoutPlaceholderManagerExample

    const String outFilePath = Path::Combine(GetOutPath(), u"placeholders.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Getting the Blank layout slide.
    SharedPtr<ILayoutSlide> layout = pres->get_LayoutSlides()->GetByType(SlideLayoutType::Blank);

    // Getting the placeholder manager of the layout slide.
    SharedPtr<ILayoutPlaceholderManager> placeholderManager = layout->get_PlaceholderManager();

    // Adding different placeholders to the Blank layout slide.
    placeholderManager->AddContentPlaceholder(10, 10, 300, 200);
    placeholderManager->AddVerticalTextPlaceholder(350, 10, 200, 300);
    placeholderManager->AddChartPlaceholder(10, 350, 300, 300);
    placeholderManager->AddTablePlaceholder(350, 350, 300, 200);

    // Adding the new slide with Blank layout.
    SharedPtr<ISlide> newSlide = pres->get_Slides()->AddEmptySlide(layout);

    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:LayoutPlaceholderManagerExample
}
