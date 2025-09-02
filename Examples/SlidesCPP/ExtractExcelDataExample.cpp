#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Excel;
using namespace System;
using namespace IO;

void ExtractExcelDataExample()
{
    //ExStart:ExtractExcelDataExample

    // Path to excel file
    const String externalWbPath = Path::Combine(GetDataPath(), u"book1.xlsx");

    // Extract a value from a cell
    SharedPtr<IExcelDataWorkbook> workbook = MakeObject<ExcelDataWorkbook>(externalWbPath);
    SharedPtr<IExcelDataCell> cell = workbook->GetCell(u"Sheet2", u"B2");
    Console::WriteLine(cell->get_Value());

    // Retrieve worksheet names and chart names from an Excel workbook
    auto sheetNames = workbook->GetWorksheetNames();

    for (auto&& name : sheetNames)
    {
        Console::WriteLine(u"Worksheet {0} has the following charts", name);
        auto sheetCharts = workbook->GetChartsFromWorksheet(name);
        for (auto&& chart : sheetCharts)
            Console::WriteLine(u"{0} - {1}", chart.get_Key(), chart.get_Value());
    }

    //ExEnd:ExtractExcelDataExample
}
