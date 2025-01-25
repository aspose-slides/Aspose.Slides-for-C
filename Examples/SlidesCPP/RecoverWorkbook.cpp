#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void RecoverWorkbook()
{
    //ExStart:RecoverWorkbook

    const String pptxFile = Path::Combine(GetDataPath(), u"ExternalWB.pptx");
    const String outPptxFile = Path::Combine(GetOutPath(), u"ExternalWB_out.pptx");

    File::Copy(pptxFile, outPptxFile, true);
    File::Copy(Path::Combine(GetDataPath(), u"book1.xlsx"), Path::Combine(GetOutPath(), u"book1.xlsx"), true);

    SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();
    loadOptions->get_SpreadsheetOptions()->set_RecoverWorkbookFromChartCache(true);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(outPptxFile, loadOptions);
    
    SharedPtr<Charts::IChart> chart = ExplicitCast<Charts::IChart>(pres->get_Slide(0)->get_Shape(0));
    SharedPtr<Charts::IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();

    pres->Save(outPptxFile, Export::SaveFormat::Pptx);

    //ExEnd:RecoverWorkbook
}
