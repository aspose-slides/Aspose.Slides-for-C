#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ShapePathPointsExample()
{
    //ExStart:ShapePathPointsExample

    const String pptxPath = Path::Combine(GetDataPath(), u"PresetGeometry.pptx");

    auto pres = MakeObject<Presentation>(pptxPath);
    auto shape = ExplicitCast<AutoShape>(pres->get_Slide(0)->get_Shape(0));
    auto elements = shape->CreateShapeElements();

    for (auto&& element : elements)
    {
        auto elementImpl = ExplicitCast<ShapeElement>(element);

        Console::WriteLine(u"Start element");
        auto types = elementImpl->get_PathTypes();
        auto points = elementImpl->get_PathPoints();

        for (int i = 0; i < types->get_Length(); i++)
        {
            switch (types[i])
            {
            case 0:
                Console::WriteLine(u"Start point {0}", points[i]);
                break;
            case 1:
                Console::WriteLine(u"LineTo point {0}", points[i]);
                break;
            case 3:
                Console::WriteLine(u"Bezier spline point {0}", points[i]);
                break;
            case 128:
                Console::WriteLine(u"Close subpath point {0}", points[i]);
                break;
            case 129:
                Console::WriteLine(u"End point {0}", points[i]);
                break;
            }
        }
    }
    
    //ExEnd:ShapePathPointsExample
}
