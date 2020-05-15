#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;
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
	pres->Save(outPath, Export::SaveFormat::Pptx);
	
	//ExEnd:AddingCustomLines
}
