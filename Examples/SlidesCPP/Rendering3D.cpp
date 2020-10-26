#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;
using namespace System::Drawing::Imaging;

void Rendering3D()
{
    // ExStart:Rendering3D
    String outPptxFile = Path::Combine(GetOutPath(), u"sandbox_3d.pptx");
    String outPngFile = Path::Combine(GetOutPath(), u"sample_3d.png");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 200.0f, 150.0f, 200.0f, 200.0f);
    shape->get_TextFrame()->set_Text(u"3D");
    shape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat()->get_DefaultPortionFormat()->set_FontHeight(64.0f);

    shape->get_ThreeDFormat()->get_Camera()->set_CameraType(CameraPresetType::OrthographicFront);
    shape->get_ThreeDFormat()->get_Camera()->SetRotation(20.0f, 30.0f, 40.0f);
    shape->get_ThreeDFormat()->get_LightRig()->set_LightType(LightRigPresetType::Flat);
    shape->get_ThreeDFormat()->get_LightRig()->set_Direction(LightingDirection::Top);
    shape->get_ThreeDFormat()->set_Material(MaterialPresetType::Powder);
    shape->get_ThreeDFormat()->set_ExtrusionHeight(100);
    shape->get_ThreeDFormat()->get_ExtrusionColor()->set_Color(System::Drawing::Color::get_Blue());

    pres->get_Slides()->idx_get(0)->GetThumbnail(2.0f, 2.0f)->Save(outPngFile, ImageFormat::get_Png());
    pres->Save(outPptxFile, SaveFormat::Pptx);
    // ExEnd:Rendering3D
}
