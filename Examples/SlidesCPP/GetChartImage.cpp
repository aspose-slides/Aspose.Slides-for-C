#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System::Drawing::Imaging;
using namespace System;

void GetChartImage()
{
	//ExStart:GetChartImage

	// The path to the documents directory.
	const String outPath = u"../out/ChartImage_out.png";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

	//Generate chart image

	auto bitmap = chart->GetThumbnail();

	bitmap->Save(outPath, ImageFormat::get_Png());

	//ExEnd:GetChartImage
}
