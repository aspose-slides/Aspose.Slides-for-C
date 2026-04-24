#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace Export;
using namespace System;
using namespace IO;

void EmbeddedWorkbookTypeExample()
{
    //ExStart:EmbeddedWorkbookTypeExample

    // Source file name
    const String sourcePath = Path::Combine(GetDataPath(), u"EmbeddedWorkbook.pptx");
    // Output file name
    const String outPath = Path::Combine(GetOutPath(), u"EmbeddedWorkbook-out.pptx");

    auto presentation = MakeObject<Presentation>(sourcePath);

    for (auto&& shape : presentation->get_Slide(0)->get_Shapes())
    {
        auto chart = AsCast<IChart>(shape);
        if (chart == nullptr)
            continue;

        auto chartData = chart->get_ChartData();

        // Skip charts whose embedded workbook format is not supported.
        if (chartData->get_DataSourceType() == ChartDataSourceType::InternalWorkbook &&
            chartData->get_EmbeddedWorkbookType() == WorkbookType::WorkbookBinaryMacro)
        {
            Console::WriteLine(u"\nSkip charts whose embedded workbook format is {0}", chartData->get_EmbeddedWorkbookType());
            continue;
        }

        Console::WriteLine(u"\nWork with charts whose embedded workbook format is {0}:", chartData->get_EmbeddedWorkbookType());

        // Read or modify chart workbook data.
        Console::WriteLine(u"\tChart old data: {0}", chartData->get_ChartSeries(0)->get_Name()->get_AsCells().GetHashCode());

        auto cell = chartData->get_ChartSeries(0)->get_DataPoint(0)->get_Value()->get_AsCell();
        Console::WriteLine(u"\tChart new data: {0}", cell->get_Value());
    }

    presentation->Save(outPath, SaveFormat::Pptx);

    //ExEnd:EmbeddedWorkbookTypeExample
}
