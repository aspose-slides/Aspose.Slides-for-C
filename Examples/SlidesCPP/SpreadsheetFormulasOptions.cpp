#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Charts;
using namespace System;
using namespace IO;

void SpreadsheetFormulasOptions()
{
    //ExStart:SpreadsheetFormulasOptions
    SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();

    // Set preferred culture information for calculating some functions intended for use with languages 
    // that use the double-byte character set (DBCS).
    loadOptions->get_SpreadsheetOptions()->set_PreferredCulture(System::MakeObject<Globalization::CultureInfo>(u"ja-JP"));

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(loadOptions);

    SharedPtr<IChart> chart = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::ClusteredColumn, 150.0f, 150.0f, 500.0f, 300.0f);
    SharedPtr<IChartDataWorkbook> workbook = chart->get_ChartData()->get_ChartDataWorkbook();

    auto cell = workbook->GetCell(0, u"B2");

    // Use the Formula property of the IChartDataCell interface to write a formula in a cell.
    cell->set_Formula(u"FINDB(\"ス\", \"テキスト\")");

    workbook->CalculateFormulas();

    //Check calculation.
    if (Int32::Parse(ObjectExt::ToString(cell->get_Value())) == 5)
    {
        Console::WriteLine(u"Calculated value = 5.");
    }
    else
    {
        Console::WriteLine(u"Wrong calculation!");
    }
    //ExEnd:SpreadsheetFormulasOptions
}
