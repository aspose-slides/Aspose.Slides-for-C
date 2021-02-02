#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Charts;
using namespace System;
using namespace System::IO;

void RecoverWorkbook()
{
    //ExStart:RecoverWorkbook
    String pptxFile = Path::Combine(GetDataPath(), u"ExternalWB.pptx");
    String outPptxFile = Path::Combine(GetOutPath(), u"ExternalWB_out.pptx");

    SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();
    loadOptions->get_SpreadsheetOptions()->set_RecoverWorkbookFromChartCache(true);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFile, loadOptions);
    
    SharedPtr<IChart> chart = DynamicCast<IChart>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    SharedPtr<IChartDataWorkbook> wb = chart->get_ChartData()->get_ChartDataWorkbook();

    pres->Save(outPptxFile, SaveFormat::Pptx);
    //ExEnd:RecoverWorkbook
}
