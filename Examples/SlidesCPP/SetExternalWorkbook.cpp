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


void SetExternalWorkbook()
{
	//ExStart:SetExternalWorkbook

	const String templatePath = u"../templates/externalWorkbook.xlsx";
	const String outPath = u"../out/Presentation_with_externalWorkbook.pptx";


	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	System::SharedPtr<Aspose::Slides::Charts::IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f, false);
	System::SharedPtr<Aspose::Slides::Charts::IChartData> chartData = chart->get_ChartData();

	chartData->SetExternalWorkbook(templatePath);

	

	chartData->get_Series()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"B1"), Aspose::Slides::Charts::ChartType::Pie);
	chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B2"));
	chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B3"));
	chartData->get_Series()->idx_get(0)->get_DataPoints()->AddDataPointForPieSeries(chartData->get_ChartDataWorkbook()->GetCell(0, u"B4"));

	chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A2"));
	chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A3"));
	chartData->get_Categories()->Add(chartData->get_ChartDataWorkbook()->GetCell(0, u"A4"));
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetExternalWorkbook
}