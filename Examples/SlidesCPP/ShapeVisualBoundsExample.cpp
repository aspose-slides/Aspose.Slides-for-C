#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::Drawing;
using namespace IO;

void ShapeVisualBoundsExample()
{
    //ExStart:ShapeVisualBoundsExample

    const String presentationPath = Path::Combine(GetDataPath(), u"Shapes.pptx");

    auto presentation = MakeObject<Presentation>(presentationPath);
    SharedPtr<Shape> shape = ExplicitCast<Shape>(presentation->get_Slide(0)->get_Shape(0));
    RectangleF visualBounds = shape->GetVisualBounds();

    Console::WriteLine(u"Visual bounds : X = {0}, Y = {1}, Width={2}, Height={3}",
        visualBounds.get_X(), visualBounds.get_Y(), visualBounds.get_Width(), visualBounds.get_Height());

    //ExEnd:ShapeVisualBoundsExample
}
