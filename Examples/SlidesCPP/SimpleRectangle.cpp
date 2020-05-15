#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void SimpleRectangle()
{
    // ExStart:SimpleRectangle
    // The path to the documents directory.
    const String outPath = u"../out/SimpleRectangle.pptx";
    const String templatePath = u"../templates/HelloWorld.pptx";

    // Load the desired the presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    // Access first slide
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    // Add autoshape of ellipse type
    SharedPtr<IAutoShape>  ashp = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 150, 50);

    // Save PPTX to Disk
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:SimpleRectangle
}
