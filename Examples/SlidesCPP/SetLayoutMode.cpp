#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SetLayoutMode()
{
	//ExStart:SetLayoutMode

	// The path to the documents directory.
	const String outPath = u"../out/SetLayoutMode_out.pptx";

	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();
	SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 20.0f, 100.0f, 600.0f, 400.0f);

	chart->get_PlotArea()->set_X(0.2f);
	chart->get_PlotArea()->set_Y(0.2f);
	chart->get_PlotArea()->set_Width(0.7f);
	chart->get_PlotArea()->set_Height(0.7f);

	chart->get_PlotArea()->set_LayoutTargetType(LayoutTargetType::Inner);

	presentation->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetLayoutMode
}
