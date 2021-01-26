#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GeometryShapeRemoveSegment()
{
    //ExStart:GeometryShapeRemoveSegment
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"GeometryShapeRemoveSegment.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SharedPtr<IGeometryShape> shape = shapes->AddAutoShape(ShapeType::Heart, 100.0f, 100.0f, 300.0f, 300.0f);

    // Get geometry path of the shape
    SharedPtr<IGeometryPath> path = shape->GetGeometryPaths()->idx_get(0);

    // remove segment
    path->RemoveAt(2);

    // set new geometry path
    shape->SetGeometryPath(path);

    // Save the presentation
    pres->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:GeometryShapeRemoveSegment
}
