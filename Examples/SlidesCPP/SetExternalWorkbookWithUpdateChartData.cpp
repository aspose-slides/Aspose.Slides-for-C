#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetExternalWorkbookWithUpdateChartData()
{
	//ExStart:SetExternalWorkbookWithUpdateChartData  

	const String templatePath = u"../templates/externalWorkbook.xlsx";
	const String outPath = u"../out/Presentation_with_externalWorkbook1.pptx";

	auto pres = System::MakeObject<Presentation>();
	auto chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f, true);
	auto chartData = chart->get_ChartData();
	(System::AsCast<Charts::ChartData>(chartData))->SetExternalWorkbook(u"http://path/doesnt/exists", false);

	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetExternalWorkbookWithUpdateChartData  
}
