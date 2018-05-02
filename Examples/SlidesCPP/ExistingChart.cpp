
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
#include <DOM/Chart/Chart.h>
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
#include <DOM/Chart/CategoryAxisType.h>
#include <DOM/Chart/TimeUnitType.h>
#include <DOM/IColorFormat.h>


#include <DOM/Animation/ISequence.h>
#include <DOM/Animation/EffectType.h>
#include <DOM/Animation/EffectSubtype.h>
#include <DOM/Animation/EffectTriggerType.h>
#include <DOM/Animation/EffectChartMinorGroupingType.h>
#include <DOM/Animation/EffectChartMajorGroupingType.h>

#include <DOM/Animation/AnimationTimeLine.h>
#include <DOM/Animation/ISequence.h>
#include <drawing/imaging/image_format.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void ExistingChart()
{
	//ExStart:ExistingChart

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/ExistingChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<Chart> chart = DynamicCast<Aspose::Slides::Charts::Chart>(slide->get_Shapes()->idx_get(0));

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	// Changing chart Category Name
	fact->GetCell(defaultWorksheetIndex, 1, 0, ObjectExt::Box<String>(u"Modified Category 1"));
	fact->GetCell(defaultWorksheetIndex, 2, 0, ObjectExt::Box<String>(u"Modified Category 2"));

	// Take first chart series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	
	// Now updating series data
	fact->GetCell(defaultWorksheetIndex, 0, 1, ObjectExt::Box<String>(u"New_Series1"));// Modifying series name

	series->get_DataPoints()->idx_get(0)->get_Value()->set_Data(System::ObjectExt::Box<double>(90));
	series->get_DataPoints()->idx_get(1)->get_Value()->set_Data(System::ObjectExt::Box<double>(123));
	series->get_DataPoints()->idx_get(2)->get_Value()->set_Data(System::ObjectExt::Box<double>(44));

	// Take Second chart series
	series = chart->get_ChartData()->get_Series()->idx_get(1);

	// Now updating series data
	fact->GetCell(defaultWorksheetIndex, 0, 2, ObjectExt::Box<System::String>(u"New_Series2"));// Modifying series name
	
	series->get_DataPoints()->idx_get(0)->get_Value()->set_Data(System::ObjectExt::Box<double>(20));
	series->get_DataPoints()->idx_get(1)->get_Value()->set_Data(System::ObjectExt::Box<double>(67));
	series->get_DataPoints()->idx_get(2)->get_Value()->set_Data(System::ObjectExt::Box<double>(99));

	// Now, Adding a new serie
	chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 0, 3, ObjectExt::Box<System::String>(u"Series 3")), chart->get_Type());

	// Take 3rd chart series
	series = chart->get_ChartData()->get_Series()->idx_get(2);

	// Now populating series data
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 1, 3, ObjectExt::Box<double>(20)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 2, 3, ObjectExt::Box<double>(50)));
	series->get_DataPoints()->AddDataPointForBarSeries(fact->GetCell(defaultWorksheetIndex, 3, 3, ObjectExt::Box<double>(30)));
	
	chart->set_Type(Aspose::Slides::Charts::ChartType::ClusteredCylinder);

	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ExistingChart
}
