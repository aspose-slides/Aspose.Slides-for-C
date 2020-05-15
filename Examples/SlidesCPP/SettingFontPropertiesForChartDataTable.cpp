#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;

using namespace System;

void SettingFontPropertiesForChartDataTable()
{
	//ExStart:SettingFontPropertiesForChartDataTable

	// The path to the documents directory.
	const String outPath = u"../out/SettingFontPropertiesForChartDataTable_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);
	
	//Setting chart data table
	chart->set_HasDataTable(true);

	//Setting font properties
	chart->get_ChartDataTable()->get_TextFormat()->get_PortionFormat()->set_FontBold (NullableBool::True);
	chart->get_ChartDataTable()->get_TextFormat()->get_PortionFormat()->set_FontHeight ( 20);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SettingFontPropertiesForChartDataTable
}
