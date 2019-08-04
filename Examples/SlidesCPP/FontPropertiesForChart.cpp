#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/IChartTextFormat.h>
#include <DOM/Chart/IChartPortionFormat.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/IDataLabelFormat.h>


#include "SlidesExamples.h"
#include <Export/SaveFormat.h>

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

void FontPropertiesForChart() {

	//ExStart:FontPropertiesForChart
	// The path to the documents directory.
	const String outPath = u"../out/FontPropertiesForChart.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::ClusteredColumn, 100, 100, 500, 400);
	chart->get_TextFormat()->get_PortionFormat()->set_FontHeight(20);
	chart->get_ChartData()->get_Series()->idx_get(0)->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:FontPropertiesForChart
}