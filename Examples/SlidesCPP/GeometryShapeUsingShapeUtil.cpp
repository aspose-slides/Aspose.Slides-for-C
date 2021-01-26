#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Util;
using namespace System;
using namespace System::Drawing;

void GeometryShapeUsingShapeUtil()
{
    //ExStart:GeometryShapeUsingShapeUtil
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"GeometryShapeUsingShapeUtil.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SharedPtr<IGeometryShape> shape = shapes->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, 300.0f, 100.0f);

    // Get geometry path of the shape
    SharedPtr<IGeometryPath> originalPath = shape->GetGeometryPaths()->idx_get(0);
    originalPath->set_FillMode(PathFillModeType::None);

    // Create new graphics path with text
    SharedPtr<Drawing2D::GraphicsPath> graphicsPath = System::MakeObject<Drawing2D::GraphicsPath>();
    graphicsPath->AddString(u"Text in shape", System::MakeObject<FontFamily>(u"Arial"), 1, 40.0f, PointF(10.0f, 10.0f), StringFormat::get_GenericDefault());

    // Convert graphics path to geometry path
    SharedPtr<IGeometryPath> textPath = ShapeUtil::GraphicsPathToGeometryPath(graphicsPath);
    textPath->set_FillMode(PathFillModeType::Normal);

    // Set combination of new geometry path and origin geometry path to the shape
    shape->SetGeometryPaths(System::MakeArray<SharedPtr<IGeometryPath>>({ originalPath, textPath }));

    // Save the presentation
    pres->Save(resultPath, Export::SaveFormat::Pptx);
    //ExEnd:GeometryShapeUsingShapeUtil
}
