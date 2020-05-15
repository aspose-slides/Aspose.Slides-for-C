#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void ChartTrendLines()
{
	//ExStart:ChartTrendLines

	// The path to the documents directory.
	const String outPath = u"../out/ChartTrendLines_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Adding ponential trend line for chart series 1
	SharedPtr<ITrendline> tredLinep = chart->get_ChartData()->get_Series()->idx_get(0)->get_TrendLines()->Add(TrendlineType::Exponential);
	tredLinep->set_DisplayEquation (false);
	tredLinep->set_DisplayRSquaredValue( false);

	// Adding Linear trend line for chart series 1
	SharedPtr<ITrendline> tredLineLin = chart->get_ChartData()->get_Series()->idx_get(0)->get_TrendLines()->Add(TrendlineType::Linear);
	tredLineLin->set_TrendlineType(TrendlineType::Linear);
	tredLineLin->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
	tredLineLin->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());

	// Adding Logarithmic trend line for chart series 2
	SharedPtr<ITrendline> tredLineLog = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(TrendlineType::Logarithmic);
	tredLineLog->set_TrendlineType(TrendlineType::Logarithmic);
	tredLineLog->AddTextFrameForOverriding(u"New log trend line");

	// Adding MovingAverage trend line for chart series 2
	SharedPtr<ITrendline> tredLineMovAvg = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(TrendlineType::MovingAverage);
	tredLineMovAvg->set_TrendlineType(TrendlineType::MovingAverage);
	tredLineMovAvg->set_Period(3);
	tredLineMovAvg->set_TrendlineName(u"New TrendLine Name");

	// Adding Polynomial trend line for chart series 3
	SharedPtr<ITrendline> tredLinePol = chart->get_ChartData()->get_Series()->idx_get(2)->get_TrendLines()->Add(TrendlineType::Polynomial);
	tredLinePol->set_TrendlineType(TrendlineType::Polynomial);
	tredLinePol->set_Forward (1);
	tredLinePol->set_Order (3);

	// Adding Power trend line for chart series 3
	SharedPtr<ITrendline> tredLinePower = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(TrendlineType::Power);
	tredLinePower->set_TrendlineType( TrendlineType::Power);
	tredLinePower->set_Backward( 1);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ChartTrendLines
}
