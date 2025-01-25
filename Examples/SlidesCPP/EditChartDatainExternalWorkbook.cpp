#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void EditChartDatainExternalWorkbook()
{
    //ExStart:EditChartDatainExternalWorkbook

    const String templatePath = Path::Combine(GetDataPath(), u"presentation.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"presentation-out.pptx");

    File::Copy(templatePath, outPath, true);
    File::Copy(Path::Combine(GetDataPath(), u"externalWorkbook.xlsx"), Path::Combine(GetOutPath(), u"externalWorkbook.xlsx"), true);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(outPath);
    SharedPtr<Charts::IChart> chart = System::AsCast<Charts::IChart>(pres->get_Slide(0)->get_Shape(0));
    SharedPtr<Charts::ChartData> chartData = System::ExplicitCast<Charts::ChartData>(chart->get_ChartData());

    chartData->get_ChartSeries(0)->get_DataPoint(0)->get_Value()->get_AsCell()->set_Value(ObjectExt::Box<int32_t>(100));
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:EditChartDatainExternalWorkbook
}
