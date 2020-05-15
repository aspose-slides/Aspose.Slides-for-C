#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SetChartDataCellFormulas()
{
    //ExStart:SetChartDataCellFormulas
    String outpptxFile = Path::Combine(GetOutPath(), u"ChartDataCell_Formulas_out.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();

    SharedPtr<IChart> chart = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::ClusteredColumn, 150.0f, 150.0f, 500.0f, 300.0f);
    SharedPtr<IChartDataWorkbook> workbook = chart->get_ChartData()->get_ChartDataWorkbook();

    SharedPtr<IChartDataCell> cell1 = workbook->GetCell(0, u"B2");
    cell1->set_Formula(u"1 + SUM(F2:H5)");

    SharedPtr<IChartDataCell> cell2 = workbook->GetCell(0, u"C2");
    cell2->set_R1C1Formula(u"MAX(R2C6:R5C8) / 3");

    presentation->Save(outpptxFile, Export::SaveFormat::Pptx);
    // ExEnd:SetChartDataCellFormulas
}
