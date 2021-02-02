#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Charts;
using namespace System;

void AddColorToDataPoints()
{
    //ExStart:AddColorToDataPoints
		
	const String outPath = u"../out/AddColorToDataPoints.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::Sunburst, 100.0f, 100.0f, 450.0f, 400.0f);

	SharedPtr<IChartDataPointCollection> dataPoints = chart->get_ChartData()->get_Series()->idx_get(0)->get_DataPoints();
	dataPoints->idx_get(3)->get_DataPointLevels()->idx_get(0)->get_Label()->get_DataLabelFormat()->set_ShowValue(true);

	SharedPtr<IDataLabel> branch1Label = dataPoints->idx_get(0)->get_DataPointLevels()->idx_get(2)->get_Label();
	branch1Label->get_DataLabelFormat()->set_ShowCategoryName(false);
	branch1Label->get_DataLabelFormat()->set_ShowSeriesName(true);

	branch1Label->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	branch1Label->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Yellow());
 
	SharedPtr<IFormat> steam4Format = dataPoints->idx_get(9)->get_DataPointLevels()->idx_get(1)->get_Format();
	steam4Format->get_Fill()->set_FillType(FillType::Solid);
	steam4Format->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::FromArgb(255, 0, 176, 240));

	pres->Save(outPath, SaveFormat::Pptx);
	//ExEnd:AddColorToDataPoints
}
