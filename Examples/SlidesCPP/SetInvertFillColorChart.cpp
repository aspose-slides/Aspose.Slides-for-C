
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
#include <DOM/Chart/TrendlineType.h>
#include <DOM/Chart/IRotation3D.h>

#include <DOM/Chart/IChartSeriesGroupCollection.h>
#include <DOM/Chart/IChartSeriesGroup.h>

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
//#include <DOM/Animation/EffectChartMinorGroupingType.h>
//#include <DOM/Animation/EffectChartMinorGroupingType.h>


#include <drawing/imaging/image_format.h>

#include <Export/SaveFormat.h>


#include "SetInvertFillColorChart.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void ::SetInvertFillColorChart::Run()
{
	//ExStart:SetInvertFillColorChart

	// The path to the documents directory.
	const String outPath = L"../out/InvertFillColorChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::ClusteredColumn, 0, 0, 500, 500);
	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();


	// Delete default generated series and categories
	chart->get_ChartData()->get_Series()->Clear();
	chart->get_ChartData()->get_Categories()->Clear();


	// Now, Adding a new series
	chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 1, ObjectExt::Box<System::String>(L"Series 1")), chart->get_Type());
	chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 2, ObjectExt::Box<System::String>(L"Series 2")), chart->get_Type());

	// Add Catrgories
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 1, 0, ObjectExt::Box<System::String>(L"Caetegoty 1")));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 2, 0, ObjectExt::Box<System::String>(L"Caetegoty 2")));
	chart->get_ChartData()->get_Categories()->Add(fact->GetCell(defaultWorksheetIndex, 3, 0, ObjectExt::Box<System::String>(L"Caetegoty 3")));


	// Take first chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	// Now populating series data
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<double>(-20)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 2, 1, ObjectExt::Box<double>(50)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 3, 1, ObjectExt::Box<double>(-30)));

	// Setting fill color for series
	System::Drawing::Color inverColor = System::Drawing::Color::get_Red();
	auto seriesColor = series->GetAutomaticSeriesColor();
	series->set_InvertIfNegative(true);
	series->get_Format()->get_Fill()->set_FillType(FillType::Solid);
	series->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(seriesColor);
	
//	not working
	//series->GetInvertedSolidFillColor()->set_Color(inverColor);
	
	
	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetInvertFillColorChart
}
