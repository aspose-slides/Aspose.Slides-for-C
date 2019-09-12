#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IChart.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IChartPlotArea.h>
#include <DOM/Chart/LayoutTargetType.h>
#include <DOM/Chart/ILayoutable.h>
#include <DOM/Chart/IChartPlotArea.h>

#include <Export/SaveFormat.h>

#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace System;

void SetLayoutMode() {

	//ExStart:SetLayoutMode

	// The path to the documents directory.
	const String outPath = u"../out/SetLayoutMode_out.pptx";

	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();
	System::SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);
	System::SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::ClusteredColumn, 20.0f, 100.0f, 600.0f, 400.0f);

	chart->get_PlotArea()->set_X(0.2f);
	chart->get_PlotArea()->set_Y(0.2f);
	chart->get_PlotArea()->set_Width(0.7f);
	chart->get_PlotArea()->set_Height(0.7f);

	

	chart->get_PlotArea()->set_LayoutTargetType(Aspose::Slides::Charts::LayoutTargetType::Inner);

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetLayoutMode

}