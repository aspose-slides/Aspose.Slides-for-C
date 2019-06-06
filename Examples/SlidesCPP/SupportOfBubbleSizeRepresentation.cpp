#include "SlidesExamples.h"

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/BubbleSizeRepresentationType.h>
#include <DOM/Chart/IChartSeriesGroupCollection.h>


using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void SupportOfBubbleSizeRepresentation()
{
	//ExStart:SupportOfBubbleSizeRepresentation

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	System::SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Bubble, 50.0f, 50.0f, 600.0f, 400.0f, true);

	chart->get_ChartData()->get_SeriesGroups()->idx_get(0)->set_BubbleSizeRepresentation(Aspose::Slides::Charts::BubbleSizeRepresentationType::Width);

	pres->Save(u"../out/Presentation.pptx", Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SupportOfBubbleSizeRepresentation

}