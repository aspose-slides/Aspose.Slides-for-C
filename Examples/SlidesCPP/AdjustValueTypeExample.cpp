#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void AdjustValueTypeExample()
{
    //ExStart:AdjustValueTypeExample

    // Path for presentation
    const String presentationName = Path::Combine(GetDataPath(), u"PresetGeometry.pptx");

    // Path to output document
    const String outFilePath = Path::Combine(GetOutPath(), u"PresetGeometry_out.pptx");

    auto pres = MakeObject<Presentation>(presentationName);
    auto shape = ExplicitCast<IAutoShape>(pres->get_Slide(0)->get_Shape(0));

    // Show all adjustment point and its types for a RoundRectangle
    Console::WriteLine(u"Adjustment types for a Rectangle:");

    for (int i = 0; i < shape->get_Adjustments()->get_Count(); i++)
    {
        Console::WriteLine(u"Type for point {0} is \"{1}\"", i, shape->get_Adjustment(i)->get_Type());
    }

    // Change value of an adjustment point
    if (shape->get_Adjustment(0)->get_Type() == ShapeAdjustmentType::CornerSize)
    {
        float angleValue = shape->get_Adjustment(0)->get_AngleValue();
        shape->get_Adjustment(0)->set_AngleValue(angleValue * 2);
    }

    // Show all adjustment point and its types for an RightArrow
    auto shape1 = ExplicitCast<IAutoShape>(pres->get_Slide(0)->get_Shape(1));
    Console::WriteLine(u"Adjustment types for an Arrow:");

    for (int i = 0; i < shape1->get_Adjustments()->get_Count(); i++)
    {
        Console::WriteLine(u"Type for point {0} is \"{1}\"", i, shape1->get_Adjustment(i)->get_Type());
    }

    // Change value of adjustment points
    if (shape1->get_Adjustment(0)->get_Type() == ShapeAdjustmentType::ArrowTailThickness)
    {
        float angleValue = shape1->get_Adjustment(0)->get_AngleValue();
        shape1->get_Adjustment(0)->set_AngleValue(angleValue / 3);
    }
    if (shape1->get_Adjustment(1)->get_Type() == ShapeAdjustmentType::ArrowheadLength)
    {
        float angleValue = shape1->get_Adjustment(1)->get_AngleValue();
        shape1->get_Adjustment(1)->set_AngleValue(angleValue / 2);
    }

    // Save the presentation
    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:AdjustValueTypeExample
}
