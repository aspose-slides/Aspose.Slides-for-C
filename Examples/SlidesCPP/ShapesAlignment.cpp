#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Util;
using namespace System;
using namespace IO;

void ShapesAlignment()
{
    //ExStart:ShapesAlignment
    // Path for output presentation
    String outpptxFile = Path::Combine(GetOutPath(), u"ShapesAlignment_out.pptx");
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
    // Create some shapes
    slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100.0f, 100.0f, 100.0f, 100.0f);
    slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 200.0f, 200.0f, 100.0f, 100.0f);
    slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 300.0f, 300.0f, 100.0f, 100.0f);
    // Aligning all shapes within IBaseSlide.
    SlideUtil::AlignShapes(ShapesAlignmentType::AlignBottom, true, pres->get_Slides()->idx_get(0));

    slide = pres->get_Slides()->AddEmptySlide(slide->get_LayoutSlide());
    // Add group shape
    SharedPtr<IGroupShape> groupShape = slide->get_Shapes()->AddGroupShape();
    // Create some shapes to the group shape
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 350.0f, 50.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 450.0f, 150.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 550.0f, 250.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 650.0f, 350.0f, 50.0f, 50.0f);
    // Aligning all shapes within IGroupShape.
    SlideUtil::AlignShapes(ShapesAlignmentType::AlignLeft, false, groupShape);

    slide = pres->get_Slides()->AddEmptySlide(slide->get_LayoutSlide());
    // Add group shape
    groupShape = slide->get_Shapes()->AddGroupShape();
    // Create some shapes to the group shape
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 350.0f, 50.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 450.0f, 150.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 550.0f, 250.0f, 50.0f, 50.0f);
    groupShape->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 650.0f, 350.0f, 50.0f, 50.0f);
    // Aligning shapes with specified indexes within IGroupShape.
    SlideUtil::AlignShapes(ShapesAlignmentType::AlignLeft, false, groupShape, System::MakeArray<int32_t>({ 0, 2 }));

    // Save presentation
    pres->Save(outpptxFile, Export::SaveFormat::Pptx);
    // ExEnd:ShapesAlignment
}
