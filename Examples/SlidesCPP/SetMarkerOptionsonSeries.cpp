#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Charts;

using namespace System;

void SetMarkerOptionsonSeries()
{
	//ExStart:SetMarkerOptionsonSeries

	// The path to the documents directory.
	const String outPath = u"../out/SetMarkerOptionsonSeries_out.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";
	const String ImagePath2 = u"../templates/aspose-logo.jpg";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::LineWithMarkers, 0, 0, 500, 500);

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	// Delete default generated series and categories
	chart->get_ChartData()->get_Series()->Clear();

	// Now, Adding a new series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<String>(u"Series 1")), chart->get_Type());

	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(ImagePath);
	auto bitmap2 = MakeObject<System::Drawing::Bitmap>(ImagePath2);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx1 = pres->get_Images()->AddImage(bitmap);
	SharedPtr<IPPImage> imgx2 = pres->get_Images()->AddImage(bitmap2);

	// Add new point (1:3) there.
	SharedPtr<IChartDataPoint> point = series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<double>(4.5)));
	point->get_Marker()->get_Format()->get_Fill()->set_FillType(FillType::Picture);
	point->get_Marker()->get_Format()->get_Fill()->get_PictureFillFormat()->get_Picture()->set_Image(imgx1);

	point = series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(defaultWorksheetIndex, 2, 1, ObjectExt::Box<double>(2.5)));
	point->get_Marker()->get_Format()->get_Fill()->set_FillType(FillType::Picture);
	point->get_Marker()->get_Format()->get_Fill()->get_PictureFillFormat()->get_Picture()->set_Image(imgx2);

	point = series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(defaultWorksheetIndex, 3, 1, ObjectExt::Box<double>(3.5)));
	point->get_Marker()->get_Format()->get_Fill()->set_FillType(FillType::Picture);
	point->get_Marker()->get_Format()->get_Fill()->get_PictureFillFormat()->get_Picture()->set_Image(imgx1);

	point = series->get_DataPoints()->AddDataPointForLineSeries(fact->GetCell(defaultWorksheetIndex, 4, 1, ObjectExt::Box<double>(4.5)));
	point->get_Marker()->get_Format()->get_Fill()->set_FillType(FillType::Picture);
	point->get_Marker()->get_Format()->get_Fill()->get_PictureFillFormat()->get_Picture()->set_Image(imgx2);

	// Changing the chart series marker
	series->get_Marker()->set_Size (15);

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetMarkerOptionsonSeries
}
