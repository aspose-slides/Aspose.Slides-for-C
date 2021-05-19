#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void CreateSummaryZoom()
{
    //ExStart:CreateSummaryZoom
    String resultPath = Path::Combine(GetOutPath(), u"SummaryZoomPresentation.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    
    // Create slides array
    for (int32_t slideNumber = 0; slideNumber < 5; slideNumber++)
    {
        //Add new slides to presentation
        SharedPtr<ISlide> slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());

        // Create a background for the slide
        slide->get_Background()->set_Type(BackgroundType::OwnBackground);
        slide->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
        slide->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DarkKhaki());

        // Create a text box for the slide
        SharedPtr<IAutoShape> autoshape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100.0f, 200.0f, 500.0f, 200.0f);
        autoshape->get_TextFrame()->set_Text(String::Format(u"Slide - {0}", slideNumber + 2));
    }

    // Create zoom objects for all slides in the first slide
    for (int32_t slideNumber = 1; slideNumber < pres->get_Slides()->get_Count(); slideNumber++)
    {
        int32_t x = (slideNumber - 1) * 100;
        int32_t y = (slideNumber - 1) * 100;
        SharedPtr<IZoomFrame> zoomFrame = pres->get_Slides()->idx_get(0)->get_Shapes()->AddZoomFrame(static_cast<float>(x), static_cast<float>(y), 150.0f, 120.0f, pres->get_Slides()->idx_get(slideNumber));

        // Set the ReturnToParent property to return to the first slide
        zoomFrame->set_ReturnToParent(true);
    }

    // Save the presentation
    pres->Save(resultPath, SaveFormat::Pptx);
    //ExEnd:CreateSummaryZoom
}
