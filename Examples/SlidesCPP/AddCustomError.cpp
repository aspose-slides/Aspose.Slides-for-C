#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void AddCustomError()
{
	//ExStart:AddCustomError

	// The path to the documents directory.
	const String outPath = u"../out/ErrorBarsCustomValues_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = sld->get_Shapes()->AddChart(ChartType::Bubble, 0, 0, 500, 500,true);

	// Adding custom Error chart and setting its format
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	SharedPtr<IErrorBarsFormat> errBarX = series->get_ErrorBarsXFormat();
	SharedPtr<IErrorBarsFormat> errBarY = series->get_ErrorBarsYFormat();
	errBarX->set_IsVisible(true);
	errBarY->set_IsVisible(true);
	errBarX->set_ValueType(ErrorBarValueType::Custom);
	errBarY->set_ValueType(ErrorBarValueType::Custom);

	// Accessing chart series data point and setting error bars values for individual point
	SharedPtr<IChartDataPointCollection> points = series->get_DataPoints();
	points->get_DataSourceTypeForErrorBarsCustomValues()->set_DataSourceTypeForXPlusValues(DataSourceType::DoubleLiterals);
	points->get_DataSourceTypeForErrorBarsCustomValues()->set_DataSourceTypeForXMinusValues(DataSourceType::DoubleLiterals);
	points->get_DataSourceTypeForErrorBarsCustomValues()->set_DataSourceTypeForYPlusValues (DataSourceType::DoubleLiterals);
	points->get_DataSourceTypeForErrorBarsCustomValues()->set_DataSourceTypeForYMinusValues(DataSourceType::DoubleLiterals);

	// Setting error bars for chart series points
	for (int i = 0; i < points->get_Count(); i++)
	{
		points->idx_get(i)->get_ErrorBarsCustomValues()->get_XMinus()->set_AsLiteralDouble(i + 1);
		points->idx_get(i)->get_ErrorBarsCustomValues()->get_XPlus()->set_AsLiteralDouble (i + 1);
		points->idx_get(i)->get_ErrorBarsCustomValues()->get_YMinus()->set_AsLiteralDouble( i + 1);
		points->idx_get(i)->get_ErrorBarsCustomValues()->get_YPlus()->set_AsLiteralDouble ( i + 1);
	}

	// Saving presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:AddCustomError
}
