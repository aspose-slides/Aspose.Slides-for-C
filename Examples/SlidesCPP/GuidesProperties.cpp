#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;
using namespace System::Drawing;

void GuidesProperties()
{
    //ExStart:GuidesProperties

    const String outFilePath = Path::Combine(GetOutPath(), u"GuidesProperties-out.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Getting slide size
    auto slideSize = pres->get_SlideSize()->get_Size();

    // Getting the collection of the drawing guides
    SharedPtr<IDrawingGuidesCollection> guides = pres->get_ViewProperties()->get_SlideViewProperties()->get_DrawingGuides();

    // Adding the new vertical drawing guide to the right of the slide center
    guides->Add(Orientation::Vertical, slideSize.get_Width() / 2 + 12.5f);
    // Adding the new horizontal drawing guide below the slide center
    guides->Add(Orientation::Horizontal, slideSize.get_Height() / 2 + 12.5f);

    // Getting the collection of the drawing guides for first master slide
    guides = pres->get_Master(0)->get_DrawingGuides();
    // Adding the new vertical drawing guide to the right of the slide center
    guides->Add(Orientation::Vertical, slideSize.get_Width() / 2 + 20.0f);

    // Print the drawing guides of the first master slide
    for (auto&& guide : guides)
    {
        Console::WriteLine(u"{0} {1} {2}", guide->get_Orientation(), guide->get_Position(), guide->get_Color());
    }

    // Change the color of the first drawing guide of the master slide
    guides->idx_get(0)->set_Color(Color::get_ForestGreen());

    // Print the drawing guides of the first master slide
    for (auto&& guide : guides)
    {
        Console::WriteLine(u"{0} {1} {2}", guide->get_Orientation(), guide->get_Position(), guide->get_Color());
    }

    // Save presentation
    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:GuidesProperties
}
