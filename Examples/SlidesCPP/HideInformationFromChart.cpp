#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IShape.h>
#include <DOM/IGroupShape.h>
#include <DOM/FillType.h>
#include <DOM/GroupShape.h>
#include <DOM/LineStyle.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/LineDashStyle.h>

#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IChartLinesFormat.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IChartSeriesGroupCollection.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartSeriesGroup.h>
#include <DOM/Chart/IAxesManager.h>
#include <DOM/Chart/IAxis.h>
#include <DOM/Chart/IMarker.h>
#include <DOM/Chart/MarkerStyleType.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/Chart/LegendDataLabelPosition.h>
#include <DOM/Chart/IFormat.h>

#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>

#include <Export/SaveFormat.h>

#include <iostream>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace System::Drawing;


void HideInformationFromChart() {

	//ExStart:HideInformationFromChart


	// The path to the documents directory.
	const String outPath = u"../out/HideInformationFromChart.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();



	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::LineWithMarkers, 140, 118, 320, 370);
	

	//Hiding chart Title
	chart->set_HasTitle(false);

	///Hiding Values axis
	chart->get_Axes()->get_VerticalAxis()->set_IsVisible(false);

	//Category Axis visibility
	chart->get_Axes()->get_HorizontalAxis()->set_IsVisible(false);

	//Hiding Legend
	chart->set_HasLegend(false);

	//Hiding MajorGridLines
	chart->get_Axes()->get_HorizontalAxis()->get_MajorGridLinesFormat()->get_Line()->get_FillFormat()->set_FillType(FillType::NoFill);

	for (int i = 0; i < chart->get_ChartData()->get_Series()->get_Count(); i++)
	{
		chart->get_ChartData()->get_Series()->RemoveAt(i);
	}

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	

	series->get_Marker()->set_Symbol(MarkerStyleType::Circle);
	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	series->get_Labels()->get_DefaultDataLabelFormat()->set_Position(LegendDataLabelPosition::Top);
	series->get_Marker()->set_Size(15);

	//Setting series line color
	series->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
	series->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Magenta());
	series->get_Format()->get_Line()->set_DashStyle(LineDashStyle::Solid);

	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:HideInformationFromChart
}