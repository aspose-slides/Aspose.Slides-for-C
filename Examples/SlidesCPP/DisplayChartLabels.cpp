
#include <system/object_ext.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/array.h>
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/Portion.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/IDataLabel.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartSeries.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IChartDataPoint.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IChartCategoryCollection.h>
#include <DOM/Chart/IChartCategory.h>
#include <DOM/Chart/ChartType.h>
#include <cstdint>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void DisplayChartLabels()
{
	//ExStart:DisplayChartLabels

	// The path to the documents directory.
	const String outPath = u"../out/DisplayChartLabels_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Pie, 0, 0, 500, 500);

	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue ( true);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowLabelAsDataCallout( true);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->idx_get(2)->get_DataLabelFormat()->set_ShowLabelAsDataCallout ( false);

	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:DisplayChartLabels
}
