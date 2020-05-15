#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void ChangingSeriesColor()
{
	//ExStart:ChangingSeriesColor

	// The path to the documents directory.
	const String outPath = u"../out/ChangingSeriescolor.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::Pie, 0, 0, 500, 500);

	// Take  chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	SharedPtr<IChartDataPoint> point = series->get_DataPoints()->idx_get(1);

	point->set_Explosion(30);

	point->get_Format()->get_Fill()->set_FillType(FillType::Solid);

	point->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Blue());

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ChangingSeriesColor
}
