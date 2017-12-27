
#include <system/object_ext.h>
#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/NullableBool.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/ITextFrame.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IAxis.h>
#include <DOM/Chart/IAxesManager.h>
#include <DOM/Chart/IChartCategoryCollection.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/DisplayUnitType.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/ErrorBarValueType.h>
#include <DOM/Chart/IErrorBarsFormat.h>
#include <DOM/Chart/DataSourceType.h>
#include <DOM/Chart/DataSourceTypeForErrorBarsCustomValues.h>
#include <DOM/Chart/ErrorBarsCustomValues.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/ErrorBarType.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/IFormat.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartDataCell.h>
#include <DOM/ILineFormat.h>
#include <DOM/IFillFormat.h>
#include <DOM/FillType.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/Chart/ITrendline.h>
#include <DOM/Chart/ITrendlineCollection.h>
#include <DOM/Chart/TrendlineType.h>

#include <DOM/ITextFrame.h>
#include <DOM/IParagraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraphFormat.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/IFontData.h>

#include <DOM/Animation/AnimationTimeLine.h>
#include <DOM/Animation/ISequence.h>
#include <drawing/imaging/image_format.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void ChartTrendLines()
{
	//ExStart:ChartTrendLines

	// The path to the documents directory.
	const String outPath = L"../out/ChartTrendLines_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::ClusteredColumn, 0, 0, 500, 500);


	// Adding ponential trend line for chart series 1
	SharedPtr<ITrendline> tredLinep = chart->get_ChartData()->get_Series()->idx_get(0)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::Exponential);
	tredLinep->set_DisplayEquation (false);
	tredLinep->set_DisplayRSquaredValue( false);

	// Adding Linear trend line for chart series 1
	SharedPtr<ITrendline> tredLineLin = chart->get_ChartData()->get_Series()->idx_get(0)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::Linear);
	tredLineLin->set_TrendlineType(TrendlineType::Linear);
	tredLineLin->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
	tredLineLin->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());


	// Adding Logarithmic trend line for chart series 2
	SharedPtr<ITrendline> tredLineLog = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::Logarithmic);
	tredLineLog->set_TrendlineType(TrendlineType::Logarithmic);
	tredLineLog->AddTextFrameForOverriding(L"New log trend line");

	// Adding MovingAverage trend line for chart series 2
	SharedPtr<ITrendline> tredLineMovAvg = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::MovingAverage);
	tredLineMovAvg->set_TrendlineType(TrendlineType::MovingAverage);
	tredLineMovAvg->set_Period(3);
	tredLineMovAvg->set_TrendlineName(L"New TrendLine Name");

	// Adding Polynomial trend line for chart series 3
	SharedPtr<ITrendline> tredLinePol = chart->get_ChartData()->get_Series()->idx_get(2)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::Polynomial);
	tredLinePol->set_TrendlineType(TrendlineType::Polynomial);
	tredLinePol->set_Forward (1);
	tredLinePol->set_Order (3);

	// Adding Power trend line for chart series 3
	SharedPtr<ITrendline> tredLinePower = chart->get_ChartData()->get_Series()->idx_get(1)->get_TrendLines()->Add(Aspose::Slides::Charts::TrendlineType::Power);
	tredLinePower->set_TrendlineType( TrendlineType::Power);
	tredLinePower->set_Backward( 1);


	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ChartTrendLines
}
