#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void NumberFormat()
{
	//ExStart:NumberFormat

	// The path to the documents directory.
	const String outPath = u"../out/NumberFormat_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	// Accessing the chart series collection
	SharedPtr<IChartSeriesCollection> seriesCollection = chart->get_ChartData()->get_Series();

	// Setting the preset number format
	// Traverse through every chart series
	for(int i = 0; i < seriesCollection->get_Count(); i++)
	{
		auto series = seriesCollection->idx_get(i);
		// Traverse through every data cell in series
		for(int j = 0; j<series->get_DataPoints()->get_Count(); j++)
		{
			auto cell = series->get_DataPoints()->idx_get(j);
			// Setting the number format
			cell->get_Value()->get_AsCell()->set_PresetNumberFormat (10); //0.00%
		}
	}

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:NumberFormat
}
