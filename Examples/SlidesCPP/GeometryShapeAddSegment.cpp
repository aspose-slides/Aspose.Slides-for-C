#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GeometryShapeAddSegment()
{
    //ExStart:GeometryShapeAddSegment
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"GeometryShapeAddSegment.pptx");
     
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SharedPtr<IGeometryShape> shape = shapes->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, 200.0f, 100.0f);

    // Get geometry path of the shape
    SharedPtr<IGeometryPath> geometryPath = shape->GetGeometryPaths()->idx_get(0);

    // Add two lines to geometry path
    geometryPath->LineTo(100.0f, 50.0f, 1);
    geometryPath->LineTo(100.0f, 50.0f, 4);

    // Assign edited geometry path to the shape
    shape->SetGeometryPath(geometryPath);

    // Save the presentation
    pres->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:GeometryShapeAddSegment
}
