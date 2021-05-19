#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void CreateZoomFrame()
{
    //ExStart:CreateZoomFrame
    String resultPath = Path::Combine(GetOutPath(), u"ZoomFramePresentation.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    //Add new slides to the presentation
    SharedPtr<ISlide> slide2 = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    SharedPtr<ISlide> slide3 = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());

    // Create a background for the second slide
    slide2->get_Background()->set_Type(BackgroundType::OwnBackground);
    slide2->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
    slide2->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Cyan());

    // Create a text box for the second slide
    SharedPtr<IAutoShape> autoshape = slide2->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100.0f, 200.0f, 500.0f, 200.0f);
    autoshape->get_TextFrame()->set_Text(u"Second Slide");

    // Create a background for the third slide
    slide3->get_Background()->set_Type(BackgroundType::OwnBackground);
    slide3->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
    slide3->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DarkKhaki());

    // Create a text box for the third slide
    autoshape = slide3->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100.0f, 200.0f, 500.0f, 200.0f);
    autoshape->get_TextFrame()->set_Text(u"Trird Slide");

    //Add ZoomFrame objects
    pres->get_Slides()->idx_get(0)->get_Shapes()->AddZoomFrame(20.0f, 20.0f, 250.0f, 200.0f, slide2);
    pres->get_Slides()->idx_get(0)->get_Shapes()->AddZoomFrame(200.0f, 250.0f, 250.0f, 200.0f, slide3);

    // Save the presentation
    pres->Save(resultPath, SaveFormat::Pptx);
    //ExEnd:CreateZoomFrame
}
