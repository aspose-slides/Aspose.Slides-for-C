#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace Export;
using namespace System;

void DisplayPercentageAsLabels()
{
	//ExStart:DisplayPercentageAsLabels

	// The path to the documents directory.
	const String outPath = u"../out/DisplayPercentageAsLabels_out.pptx";

	// Create an instance of Presentation class
	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();

	SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::StackedColumn, 20, 20, 400, 400);
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);
	SharedPtr<IChartCategory> cat;
	ArrayPtr<double> total_for_Cat = System::MakeObject<Array<double>>(chart->get_ChartData()->get_Categories()->get_Count(), 0);
	for (int32_t k = 0; k < chart->get_ChartData()->get_Categories()->get_Count(); k++)
	{
		cat = chart->get_ChartData()->get_Categories()->idx_get(k);

		for (int32_t i = 0; i < chart->get_ChartData()->get_Series()->get_Count(); i++)
		{
			total_for_Cat[k] = total_for_Cat[k] + Convert::ToDouble(chart->get_ChartData()->get_Series()->idx_get(i)->get_DataPoints()->idx_get(k)->get_Value()->get_Data());
		}
	}

	double dataPontPercent = 0.f;

	for (int32_t x = 0; x < chart->get_ChartData()->get_Series()->get_Count(); x++)
	{
		series = chart->get_ChartData()->get_Series()->idx_get(x);
		series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowLegendKey(false);

		for (int32_t j = 0; j < series->get_DataPoints()->get_Count(); j++)
		{
			SharedPtr<IDataLabel> lbl = series->get_DataPoints()->idx_get(j)->get_Label();
			dataPontPercent = (Convert::ToDouble(series->get_DataPoints()->idx_get(j)->get_Value()->get_Data()) / total_for_Cat[j]) * 100;

			SharedPtr<IPortion> port = System::MakeObject<Portion>();
			port->set_Text(String::Format(u"{0:F2} %", dataPontPercent));
			port->get_PortionFormat()->set_FontHeight(8.f);
			lbl->get_TextFrameForOverriding()->set_Text(u"");
			SharedPtr<IParagraph> para = lbl->get_TextFrameForOverriding()->get_Paragraphs()->idx_get(0);
			para->get_Portions()->Add(port);

			lbl->get_DataLabelFormat()->set_ShowSeriesName(false);
			lbl->get_DataLabelFormat()->set_ShowPercentage(false);
			lbl->get_DataLabelFormat()->set_ShowLegendKey(false);
			lbl->get_DataLabelFormat()->set_ShowCategoryName(false);
			lbl->get_DataLabelFormat()->set_ShowBubbleSize(false);
		}
	}

	// Save presentation with chart

	// Write the presentation file to disk
	presentation->Save(outPath, SaveFormat::Pptx);

	//ExEnd:DisplayPercentageAsLabels
}
