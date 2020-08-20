#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void ChartGetRange()
{
    //ExStart:ChartGetRange
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
    SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 10.0f, 10.0f, 400.0f, 300.0f);

    String result = chart->get_ChartData()->GetRange();
    Console::WriteLine(u"GetRange result : {0}", result);
    //ExEnd:ChartGetRange
}
