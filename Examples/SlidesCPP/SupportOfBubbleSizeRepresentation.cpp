#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void SupportOfBubbleSizeRepresentation()
{
	//ExStart:SupportOfBubbleSizeRepresentation

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::Bubble, 50.0f, 50.0f, 600.0f, 400.0f, true);

	chart->get_ChartData()->get_SeriesGroups()->idx_get(0)->set_BubbleSizeRepresentation(BubbleSizeRepresentationType::Width);

	pres->Save(u"../out/Presentation.pptx", Export::SaveFormat::Pptx);

	//ExEnd:SupportOfBubbleSizeRepresentation
}
