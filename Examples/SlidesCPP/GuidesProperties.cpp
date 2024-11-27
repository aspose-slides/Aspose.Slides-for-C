#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void GuidesProperties()
{
    //ExStart:GuidesProperties

    const System::String outFilePath = Path::Combine(GetOutPath(), u"GuidesProperties-out.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Getting slide size
    auto slideSize = pres->get_SlideSize()->get_Size();

    // Getting the collection of the drawing guides
    System::SharedPtr<IDrawingGuidesCollection> guides = pres->get_ViewProperties()->get_SlideViewProperties()->get_DrawingGuides();

    // Adding the new vertical drawing guide to the right of the slide center
    guides->Add(Orientation::Vertical, slideSize.get_Width() / 2 + 12.5f);
    // Adding the new horizontal drawing guide below the slide center
    guides->Add(Orientation::Horizontal, slideSize.get_Height() / 2 + 12.5f);
    // Save presentation
    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:GuidesProperties
}
