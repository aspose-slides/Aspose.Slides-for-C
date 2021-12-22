#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::Drawing;
using namespace IO;

void SetSlideBackground(SharedPtr<ISlide> slide, Color color)
{
    slide->get_Background()->get_FillFormat()->set_FillType(FillType::Solid);
    slide->get_Background()->get_FillFormat()->get_SolidFillColor()->set_Color(color);
    slide->get_Background()->set_Type(BackgroundType::OwnBackground);
}

void CreateSummaryZoom()
{
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"SummaryZoomPresentation.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Adds a new slide to the presentation
    SharedPtr<ISlide> slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    SetSlideBackground(slide, Color::get_Brown());

    // Adds a new section to the presentation
    pres->get_Sections()->AddSection(u"Section 1", slide);

    // Adds a new slide to the presentation
    slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    SetSlideBackground(slide, Color::get_Aqua());

    // Adds a new section to the presentation
    pres->get_Sections()->AddSection(u"Section 2", slide);

    // Adds a new slide to the presentation
    slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    SetSlideBackground(slide, Color::get_Chartreuse());

    // Adds a new section to the presentation
    pres->get_Sections()->AddSection(u"Section 3", slide);

    // Adds a new slide to the presentation
    slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    SetSlideBackground(slide, Color::get_DarkGreen());

    // Adds a new section to the presentation
    pres->get_Sections()->AddSection(u"Section 4", slide);

    // Adds a SummaryZoomFrame object
    SharedPtr<ISummaryZoomFrame> summaryZoomFrame = pres->get_Slides()->idx_get(0)->get_Shapes()->AddSummaryZoomFrame(150.0f, 50.0f, 300.0f, 200.0f);

    // Saves the presentation
    pres->Save(resultPath, SaveFormat::Pptx);
}
