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
#include <DOM/ILineFormat.h>

#include <DOM/Chart/IDataLabelFormat.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void AddErrorBars()
{
	//ExStart:AddErrorBars

	// The path to the documents directory.
	const String outPath = L"../out/ErrorBars_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = sld->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Bubble, 0, 0, 500, 500, true);

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
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:AddErrorBars

}
