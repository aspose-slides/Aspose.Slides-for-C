#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace System::Drawing;
using namespace IO;

void CreateSectionZoom()
{
    // Output file name
    String resultPath = Path::Combine(GetOutPath(), u"SectionZoomPresentation.pptx");

    auto pres = System::MakeObject<Presentation>();

    //Adds a new slide to the presentation
    SharedPtr<ISlide> slide = pres->get_Slides()->AddEmptySlide(pres->get_Slides()->idx_get(0)->get_LayoutSlide());
    auto background = slide->get_Background();
    background->get_FillFormat()->set_FillType(FillType::Solid);
    background->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_YellowGreen());
    background->set_Type(BackgroundType::OwnBackground);

    // Adds a new Section to the presentation
    pres->get_Sections()->AddSection(u"Section 1", slide);

    // Adds a SectionZoomFrame object
    auto shapes = pres->get_Slides()->idx_get(0)->get_Shapes();
    auto sectionZoomFrame = shapes->AddSectionZoomFrame(20.0f, 20.0f, 300.0f, 200.0f, pres->get_Sections()->idx_get(1));

    // Saves the presentation
    pres->Save(resultPath, SaveFormat::Pptx);
}
