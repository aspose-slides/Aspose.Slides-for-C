#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IShape.h>
#include <DOM/IGroupShape.h>
#include <DOM/FillType.h>
#include <DOM/GroupShape.h>
#include <DOM/LineStyle.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/IColorFormat.h>

#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IChartSeriesGroupCollection.h>
#include <DOM/Chart/IChartSeriesGroup.h>

#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>

#include <Export/SaveFormat.h>

#include <iostream>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace System::Drawing;


void AddingCustomLines() {

	//ExStart:AddingCustomLines


	// The path to the documents directory.
	const String outPath = u"../out/AddCustomLines.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();



	SharedPtr<IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(ChartType::ClusteredColumn, 100, 100, 500, 400);
	SharedPtr<IAutoShape> shape = chart->get_UserShapes()->get_Shapes()->AddAutoShape(ShapeType::Line, 0, chart->get_Height() / 2, chart->get_Width(), 0);

	shape->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	shape->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());

	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	
	//ExEnd:AddingCustomLines
}