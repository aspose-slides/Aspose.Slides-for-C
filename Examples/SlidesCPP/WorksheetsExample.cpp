#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Charts;
using namespace System;

void WorksheetsExample()
{
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::Pie, 50.0f, 50.0f, 400.0f, 500.0f);

    SharedPtr<IChartDataWorkbook> workbook = chart->get_ChartData()->get_ChartDataWorkbook();
    for (int32_t i = 0; i < workbook->get_Worksheets()->get_Count(); i++)
    {
        Console::WriteLine(workbook->get_Worksheets()->idx_get(i)->get_Name());
    }
}
