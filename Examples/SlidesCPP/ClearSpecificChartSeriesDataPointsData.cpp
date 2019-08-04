#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/NullableBool.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IChartDataCell.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IStringOrDoubleChartValue.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/NullableBool.h>
#include <Export/SaveFormat.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;


void ClearSpecificChartSeriesDataPointsData() {

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

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ClearSpecificChartSeriesDataPointsData
}