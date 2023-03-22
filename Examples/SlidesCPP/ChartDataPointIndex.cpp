#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

void ChartPointDataIndex()
{
    //ExStart:ChartPointDataIndex

    const System::String pptxFile = u"../templates/ChartIndex.pptx";

    auto presentation = System::MakeObject<Presentation>(pptxFile);

    System::SharedPtr<Chart> chart = System::ExplicitCast<Chart>(presentation->get_Slide(0)->get_Shape(0));
    for (auto&& dataPoint : chart->get_ChartData()->get_ChartSeries(0)->get_DataPoints())
    {
        System::Console::WriteLine(u"Point with index {0} is applied to {1}", dataPoint->get_Index(), dataPoint->get_Value());
    }

    // ExEnd:ChartPointDataIndex
}
