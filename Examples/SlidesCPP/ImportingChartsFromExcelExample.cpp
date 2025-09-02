#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Excel;
using namespace Import;
using namespace System;
using namespace IO;

void ImportingChartsFromExcelExample()
{
    //ExStart:ImportingChartsFromExcelExample

    // Path to excel file
    const String externalWbPath = Path::Combine(GetDataPath(), u"book1.xlsx");

    // Path to output file
    const String outFileName = Path::Combine(GetOutPath(), u"ImportExcelChart.pptx");

    // Initializes a new instance using the specified file path
    SharedPtr<IExcelDataWorkbook> workbook = MakeObject<ExcelDataWorkbook>(externalWbPath);

    SharedPtr<Presentation> pres = MakeObject<Presentation>();
    SharedPtr<ILayoutSlide> blankLayout = pres->get_LayoutSlides()->GetByType(SlideLayoutType::Blank);

    // Gets the names of all worksheets contained in the Excel workbook
    auto worksheetNames = workbook->GetWorksheetNames();
    for (auto&& name : worksheetNames)
    {
        // Gets a dictionary containing the indexes and names of all charts in the specified worksheet of an Excel workbook
        auto worksheetCharts = workbook->GetChartsFromWorksheet(name);

        for (auto&& chart : worksheetCharts)
        {
            SharedPtr<ISlide> slide = pres->get_Slides()->AddEmptySlide(blankLayout);

            // Imports the chart from a workbook file by its name and worksheet name
            ExcelWorkbookImporter::AddChartFromWorkbook(slide->get_Shapes(), 10, 10, workbook, name, chart.get_Key(), false);
        }
    }

    // Save the result
    pres->Save(outFileName, SaveFormat::Pptx);

    //ExEnd:ImportingChartsFromExcelExample
}
