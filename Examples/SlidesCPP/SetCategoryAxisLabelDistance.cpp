#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SetCategoryAxisLabelDistance()
{
	//ExStart:SetCategoryAxisLabelDistance

	// The path to the documents directory.
	const String outPath = u"../out/CategoryAxisLabelDistance_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Accessing the chart series collection
	SharedPtr<IChartSeriesCollection> seriesCollection = chart->get_ChartData()->get_Series();

	// Setting the position of label from axis
	chart->get_Axes()->get_HorizontalAxis()->set_LabelOffset ( 500);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetCategoryAxisLabelDistance
}
