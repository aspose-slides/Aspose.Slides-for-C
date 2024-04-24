#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void SketchedShapes()
{
    //ExStart:SketchedShapes
    //Path for output presentation
    const System::String outPptxFile = Path::Combine(GetOutPath(), u"SketchedShapes_out.pptx");
    const System::String outPngFile = Path::Combine(GetOutPath(), u"SketchedShapes_out.png");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    System::SharedPtr<IAutoShape> shape = slide->get_Shapes()->AddAutoShape(
        ShapeType::Rectangle, 20.0f, 20.0f, 300.0f, 150.0f);
    shape->get_FillFormat()->set_FillType(FillType::NoFill);

    // Transform shape to sketch of a freehand style
    shape->get_LineFormat()->get_SketchFormat()->set_SketchType(LineSketchType::Scribble);

    float scale = 4 / 3.f;
    System::SharedPtr<IImage> image = slide->GetImage(scale, scale);
    image->Save(outPngFile, ImageFormat::Png);

    pres->Save(outPptxFile, SaveFormat::Pptx);
    //ExEnd:SketchedShapes
}
