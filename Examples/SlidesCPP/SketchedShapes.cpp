#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Util;
using namespace System;
using namespace System::IO;

using System::Drawing::Imaging::ImageFormat;

void SketchedShapes()
{
    //ExStart:SketchedShapes
    //Path for output presentation
    String outPptxFile = Path::Combine(GetOutPath(), u"SketchedShapes_out.pptx");
    String outPngFile = Path::Combine(GetOutPath(), u"SketchedShapes_out.png");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 20.0f, 20.0f, 300.0f, 150.0f);
    shape->get_FillFormat()->set_FillType(FillType::NoFill);

    // Transform shape to sketch of a freehand style
    shape->get_LineFormat()->get_SketchFormat()->set_SketchType(LineSketchType::Scribble);

    pres->get_Slides()->idx_get(0)->GetThumbnail(4 / 3.f, 4 / 3.f)->Save(outPngFile, ImageFormat::get_Png());
    pres->Save(outPptxFile, SaveFormat::Pptx);

    //ExEnd:SketchedShapes
}
