#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

void LeaderLineColor()
{
    // ExStart:LeaderLineColor

    const System::String presentationName = System::IO::Path::Combine(GetDataPath(), u"LeaderLinesColor.pptx");
    const System::String outPath = System::IO::Path::Combine(GetOutPath(), u"LeaderLinesColor-out.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationName);

    // Get the chart from the first slide
    System::SharedPtr<Charts::IChart> chart = System::ExplicitCast<Charts::IChart>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    // Get series of the chart
    System::SharedPtr<Charts::IChartSeriesCollection> series = chart->get_ChartData()->get_Series();

    // Get lebels of the first serie
    System::SharedPtr<Charts::IDataLabelCollection> labels = series->idx_get(0)->get_Labels();

    // Change color of all leader lines in the collection
    labels->set_LeaderLinesColor(System::Drawing::Color::FromArgb(255, 255, 0, 0));

    // Save result
    pres->Save(outPath, Export::SaveFormat::Pptx);

    // ExEnd:LeaderLineColor
}
