#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System::Drawing;
using namespace System;

void HideInformationFromChart()
{
	//ExStart:HideInformationFromChart

	// The path to the documents directory.
	const String outPath = u"../out/HideInformationFromChart.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
       
	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::LineWithMarkers, 140, 118, 320, 370);

	//Hiding chart Title
	chart->set_HasTitle(false);

	//Hiding Values axis
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
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:HideInformationFromChart
}
