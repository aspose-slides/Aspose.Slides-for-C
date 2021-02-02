#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Util;
using namespace System;
using namespace System::IO;

void ShapesAlignment()
{
    //ExStart:ShapesAlignment
    // Path for output presentation
    String outpptxFile = Path::Combine(GetOutPath(), u"ShapesAlignment_out.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create some shapes
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
    SharedPtr<IAutoShape> shape1 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, 100.0f, 100.0f);
    SharedPtr<IAutoShape> shape2 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 250.0f, 200.0f, 100.0f, 100.0f);
    SharedPtr<IAutoShape> shape3 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 400.0f, 300.0f, 100.0f, 100.0f);

    // Here we align two shapes using their indexes
    ArrayPtr<int32_t> shapeIndexes = MakeArray<int32_t>(2);
    shapeIndexes[0] = slide->get_Shapes()->IndexOf(shape1);
    shapeIndexes[1] = slide->get_Shapes()->IndexOf(shape2);

    SlideUtil::AlignShapes(ShapesAlignmentType::AlignMiddle, true, slide, shapeIndexes);

    // Here we aling all shapes int the slide
    SharedPtr<IShapeCollection> shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    SlideUtil::AlignShapes(ShapesAlignmentType::AlignMiddle, true, shapes);

    pres->Save(outpptxFile, Export::SaveFormat::Pptx);
    // ExEnd:ShapesAlignment
}
