#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void GeometryShapeCompositeObjects()
{
    //ExStart:GeometryShapeCompositeObjects
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"GeometryShapeCompositeObjects.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SharedPtr<IGeometryShape> shape = shapes->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, 200.0f, 100.0f);

    // Create first geometry path
    SharedPtr<IGeometryPath> geometryPath0 = System::MakeObject<GeometryPath>();
    geometryPath0->MoveTo(0.0f, 0.0f);
    geometryPath0->LineTo(shape->get_Width(), 0.0f);
    geometryPath0->LineTo(shape->get_Width(), shape->get_Height() / 3);
    geometryPath0->LineTo(0.0f, shape->get_Height() / 3);
    geometryPath0->CloseFigure();

    // Create second geometry path
    SharedPtr<IGeometryPath> geometryPath1 = System::MakeObject<GeometryPath>();
    geometryPath1->MoveTo(0.0f, shape->get_Height() / 3 * 2);
    geometryPath1->LineTo(shape->get_Width(), shape->get_Height() / 3 * 2);
    geometryPath1->LineTo(shape->get_Width(), shape->get_Height());
    geometryPath1->LineTo(0.0f, shape->get_Height());
    geometryPath1->CloseFigure();

    // Set shape geometry as composition of two geometry path
    shape->SetGeometryPaths(System::MakeArray<SharedPtr<IGeometryPath>>({ geometryPath0, geometryPath1 }));

    // Save the presentation
    pres->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:GeometryShapeCompositeObjects
}
