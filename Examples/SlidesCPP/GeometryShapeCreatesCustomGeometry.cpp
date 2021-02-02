#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;
using Collections::Generic::List;

SharedPtr<GeometryPath> CreateStarGeometry(float outerRadius, float innerRadiusr)
{
    SharedPtr<GeometryPath> starPath = System::MakeObject<GeometryPath>();
    SharedPtr<List<System::Drawing::PointF>> points = System::MakeObject<List<System::Drawing::PointF>>();

    int32_t step = 72;

    for (int32_t angle = -90; angle < 270; angle += step)
    {
        double radians = angle * (Math::PI / 180.f);
        double x = outerRadius * Math::Cos(radians);
        double y = outerRadius * Math::Sin(radians);
        points->Add(System::Drawing::PointF((float)x + outerRadius, (float)y + outerRadius));

        radians = Math::PI * (angle + step / 2) / 180.0;
        x = innerRadiusr * Math::Cos(radians);
        y = innerRadiusr * Math::Sin(radians);
        points->Add(System::Drawing::PointF((float)x + outerRadius, (float)y + outerRadius));
    }

    starPath->MoveTo(points->idx_get(0));

    for (int32_t i = 1; i < points->get_Count(); i++)
    {
        starPath->LineTo(points->idx_get(i));
    }

    starPath->CloseFigure();

    return starPath;
}

void GeometryShapeCreatesCustomGeometry()
{
    //ExStart:GeometryShapeCreatesCustomGeometry
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"GeometryShapeCreatesCustomGeometry.pptx");

    // Outer and inner star radius
    float R = 100.0f, r = 50.0f;
    
    // Create star geometry path
    SharedPtr<GeometryPath> starPath = CreateStarGeometry(R, r);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SharedPtr<IGeometryShape> shape = shapes->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, R * 2, R * 2);

    // Set new geometry path to the shape
    shape->SetGeometryPath(starPath);

    // Save the presentation
    pres->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:GeometryShapeCreatesCustomGeometry
}
