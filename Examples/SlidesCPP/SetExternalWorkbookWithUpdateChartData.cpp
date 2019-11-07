#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IChart.h>
#include <DOM/Chart/ChartData.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/IChartDataCell.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartCategoryCollection.h>

#include <Export/SaveFormat.h>


#include "SlidesExamples.h"


using namespace Aspose::Slides;
using namespace System;


void SetExternalWorkbookWithUpdateChartData()
{
	//ExStart:SetExternalWorkbookWithUpdateChartData  

	const String templatePath = u"../templates/externalWorkbook.xlsx";
	const String outPath = u"../out/Presentation_with_externalWorkbook1.pptx";


	auto pres = System::MakeObject<Presentation>();
	auto chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f, true);
	auto chartData = chart->get_ChartData();
	(System::DynamicCast_noexcept<Aspose::Slides::Charts::ChartData>(chartData))->SetExternalWorkbook(u"http://path/doesnt/exists", false);


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetExternalWorkbookWithUpdateChartData  
}