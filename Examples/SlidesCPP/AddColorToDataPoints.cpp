#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
#include<DOM/LoadOptions.h>
#include<DOM/ISlideCollection.h>
#include <Export/SaveFormat.h>
#include<DOM/ShapeType.h>
#include<DOM/IShapeCollection.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IChartTextFormat.h>
#include <DOM/Chart/IChartPortionFormat.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IFormat.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartSeries.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IChartDataPoint.h>
#include <DOM/Chart/IChartDataPointLevelsManager.h>
#include <DOM/Chart/IChartDataPointLevel.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/Chart/IDataLabel.h>
#include <DOM/IFillFormat.h>

#include <DOM/FillType.h>
#include <DOM/IColorFormat.h>

#include "SlidesExamples.h"


using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace Aspose::Slides::Charts;

void AddColorToDataPoints() {

		//ExStart:AddColorToDataPoints
		
	const String outPath = u"../out/AddColorToDataPoints.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	System::SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Sunburst, 100.0f, 100.0f, 450.0f, 400.0f);


	System::SharedPtr<IChartDataPointCollection> dataPoints = chart->get_ChartData()->get_Series()->idx_get(0)->get_DataPoints();
	dataPoints->idx_get(3)->get_DataPointLevels()->idx_get(0)->get_Label()->get_DataLabelFormat()->set_ShowValue(true);

	System::SharedPtr<IDataLabel> branch1Label = dataPoints->idx_get(0)->get_DataPointLevels()->idx_get(2)->get_Label();
	branch1Label->get_DataLabelFormat()->set_ShowCategoryName(false);
	branch1Label->get_DataLabelFormat()->set_ShowSeriesName(true);

	branch1Label->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->set_FillType(Aspose::Slides::FillType::Solid);
	branch1Label->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Yellow());
 
	System::SharedPtr<IFormat> steam4Format = dataPoints->idx_get(9)->get_DataPointLevels()->idx_get(1)->get_Format();
	steam4Format->get_Fill()->set_FillType(Aspose::Slides::FillType::Solid);
	steam4Format->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::FromArgb(255, 0, 176, 240));

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
		//ExEnd:AddColorToDataPoints

}