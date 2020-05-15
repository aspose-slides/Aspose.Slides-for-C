#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void EditChartDatainExternalWorkbook()
{
	//ExStart:EditChartDatainExternalWorkbook

	const String templatePath = u"../templates/presentation.pptx";
	const String outPath = u"../out/presentation-out.pptx";
	
	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	SharedPtr<Charts::IChart> chart = System::DynamicCast_noexcept<Charts::IChart>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	SharedPtr<Charts::ChartData> chartData = System::DynamicCast<Charts::ChartData>(chart->get_ChartData());

	chartData->get_Series()->idx_get(0)->get_DataPoints()->idx_get(0)->get_Value()->get_AsCell()->set_Value(ObjectExt::Box<int32_t>(100));
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:EditChartDatainExternalWorkbook
}
