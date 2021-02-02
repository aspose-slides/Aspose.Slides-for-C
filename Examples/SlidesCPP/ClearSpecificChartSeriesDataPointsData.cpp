#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace Charts;

void ClearSpecificChartSeriesDataPointsData()
{
	//ExStart:ClearSpecificChartSeriesDataPointsData

	// The path to the documents directory.
	const String templateFile = u"../templates/TestChart.pptx";
	const String outPath = u"../out/ClearSpecificChartSeriesDataPointsData.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templateFile);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<IChart> chart = System::DynamicCast<IChart>(slide->get_Shapes()->idx_get(0));

	// Take  chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	for (int i = 0; i < series->get_DataPoints()->get_Count(); i++) {

		SharedPtr<IChartDataPoint> dataPoint = series->get_DataPoints()->idx_get(i);
		dataPoint->get_XValue()->get_AsCell()->set_Value(nullptr);
		dataPoint->get_YValue()->get_AsCell()->set_Value(nullptr);
	}

	chart->get_ChartData()->get_Series()->idx_get(0)->get_DataPoints()->Clear();

	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ClearSpecificChartSeriesDataPointsData
}
