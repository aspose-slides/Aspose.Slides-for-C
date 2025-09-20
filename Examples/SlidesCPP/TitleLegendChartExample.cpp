#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
using namespace System;

void TitleLegendChartExample()
{
    //ExStart:TitleLegendChartExample

    SharedPtr<Presentation> pres = MakeObject<Presentation>();

    auto chart = ExplicitCast<Chart>(pres->get_Slide(0)->get_Shapes()->AddChart(ChartType::ClusteredColumn, 100, 100, 500, 350));
    chart->ValidateChartLayout();

    auto chartTitle = chart->get_ChartTitle();
    Console::WriteLine(u"ChartTitle.X = {0}, ChartTitle.Y = {1}", chartTitle->get_ActualX(), chartTitle->get_ActualY());
    Console::WriteLine(u"ChartTitle.Width = {0}, ChartTitle.Height = {1}", chartTitle->get_ActualWidth(), chartTitle->get_ActualHeight());

    auto legend = chart->get_Legend();
    Console::WriteLine(u"Legend.X = {0}, Legend.Y = {1}", legend->get_ActualX(), legend->get_ActualY());
    Console::WriteLine(u"Legend.Width = {0}, Legend.Height = {1}", legend->get_ActualWidth(), legend->get_ActualHeight());

    //ExEnd:TitleLegendChartExample
}
