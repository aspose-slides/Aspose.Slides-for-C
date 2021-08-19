#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Charts;

using namespace System;

void CalculateFormulas()
{
    String resultPath = IO::Path::Combine(GetOutPath(), u"CalculateFormulas_out.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();

    SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);
    SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 10.0f, 10.0f, 600.0f, 300.0f);

    auto workbook = chart->get_ChartData()->get_ChartDataWorkbook();
    SharedPtr<IChartDataCell> cell = workbook->GetCell(0, u"A1");
    cell->set_Formula(u"ABS(A2) + MAX(B2:C2)");

    workbook->GetCell(0, u"A2")->set_Value(ObjectExt::Box<int32_t>(-1));
    workbook->CalculateFormulas();

    workbook->GetCell(0, u"B2")->set_Formula(u"2");
    workbook->CalculateFormulas();

    workbook->GetCell(0, u"C2")->set_Formula(u"A2 + 4");
    workbook->CalculateFormulas();

    cell->set_Formula(u"MAX(2:2)");
    workbook->CalculateFormulas();

    presentation->Save(resultPath, SaveFormat::Pptx);
}
