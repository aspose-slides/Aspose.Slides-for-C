#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System::IO;

void GetChartImage()
{
    //ExStart:GetChartImage

    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"ChartImage_out.png");

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    //Access first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Add chart with default data
    System::SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::ClusteredColumn, 0, 0, 500, 500);

    //Generate chart image
    auto image = chart->GetImage();
    image->Save(outPath, ImageFormat::Png);

    //ExEnd:GetChartImage
}
