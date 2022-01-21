#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace Export;
using namespace System;

void TimeUnitTypeEnum()
{
    // Output file name
    String resultPath = IO::Path::Combine(GetOutPath(), u"TimeUnitTypeEnum.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Area, 10.0f, 10.0f, 400.0f, 300.0f, true);
    chart->get_Axes()->get_HorizontalAxis()->set_MajorUnitScale(TimeUnitType::None);

    pres->Save(resultPath, SaveFormat::Pptx);
}
