#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void AddErrorBars()
{
	//ExStart:AddErrorBars

	// The path to the documents directory.
	const String outPath = u"../out/ErrorBars_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = sld->get_Shapes()->AddChart(ChartType::Bubble, 0, 0, 500, 500, true);

	// Adding custom Error chart and setting its format
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	SharedPtr<IErrorBarsFormat> errBarX = series->get_ErrorBarsXFormat();
	SharedPtr<IErrorBarsFormat> errBarY = series->get_ErrorBarsYFormat();
	errBarX->set_IsVisible(true);
	errBarY->set_IsVisible(true);
	errBarX->set_ValueType(ErrorBarValueType::Fixed);
	errBarX->set_Value( 0.1f);
	errBarY->set_ValueType(ErrorBarValueType::Percentage);
	errBarX->set_Value(5);
	errBarX->set_Type (ErrorBarType::Plus);
	errBarY->get_Format()->get_Line()->set_Width(2);
	errBarX->set_HasEndCap ( true);

	// Saving presentation
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:AddErrorBars
}
