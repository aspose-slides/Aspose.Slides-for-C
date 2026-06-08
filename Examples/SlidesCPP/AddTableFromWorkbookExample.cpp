#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Excel;
using namespace Export;
using namespace Import;

using namespace System;
using namespace IO;

void AddTableFromWorkbookExample()
{
    // ExStart:AddTableFromWorkbookExample

    // Path to the source Excel file
    const String excelFilePath = Path::Combine(GetDataPath(), u"Budget.xlsx");
    // Path to the output presentation
    const String outPath = Path::Combine(GetOutPath(), u"TableFromWorkbook.pptx");

    auto presentation = MakeObject<Presentation>();

    // Get the layout of the first slide to reuse when adding new slides
    SharedPtr<ILayoutSlide> slideLayout = presentation->get_Slide(0)->get_LayoutSlide();

    // Create workbook instance from file
    SharedPtr<IExcelDataWorkbook> workbook = MakeObject<ExcelDataWorkbook>(excelFilePath);

    // Import the table using an IExcelDataWorkbook instance
    ExcelWorkbookImporter::AddTableFromWorkbook(presentation->get_Slide(0)->get_Shapes(), 10, 10, workbook, u"Month", u"D4:H17");

    // Add a new slide
    SharedPtr<ISlide> secondSlide = presentation->get_Slides()->AddEmptySlide(slideLayout);

    // Import the table directly from an Excel file path
    ExcelWorkbookImporter::AddTableFromWorkbook(secondSlide->get_Shapes(), 10, 10, excelFilePath, u"Budget", u"B21:E43");

    // Add a new slide
    SharedPtr<ISlide> thirdSlide = presentation->get_Slides()->AddEmptySlide(slideLayout);

    // Import the table from an Excel stream
    SharedPtr<FileStream> fStream = MakeObject<FileStream>(excelFilePath, FileMode::Open, FileAccess::Read);
    ExcelWorkbookImporter::AddTableFromWorkbook(thirdSlide->get_Shapes(), 10, 10, fStream, u"Budget", u"B47:E55");

    // Save the presentation
    presentation->Save(outPath, SaveFormat::Pptx);

    // ExEnd:AddTableFromWorkbookExample
}
