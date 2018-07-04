
#include <system/object_ext.h>
#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/NullableBool.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/ITextFrame.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/IChart.h>
#include <DOM/Chart/IAxis.h>
#include <DOM/Chart/IAxesManager.h>
#include <DOM/Chart/IChartCategoryCollection.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/DisplayUnitType.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/ErrorBarValueType.h>
#include <DOM/Chart/IErrorBarsFormat.h>
#include <DOM/Chart/DataSourceType.h>
#include <DOM/Chart/DataSourceTypeForErrorBarsCustomValues.h>
#include <DOM/Chart/ErrorBarsCustomValues.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/ErrorBarType.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/IFormat.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartDataCell.h>
#include <DOM/ILineFormat.h>
#include <DOM/IFillFormat.h>
#include <DOM/FillType.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/Chart/ITrendline.h>
#include <DOM/Chart/TrendlineType.h>
#include <DOM/Chart/IRotation3D.h>
#include <DOM/Chart/IMarker.h>

#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/IPictureFillFormat.h>
#include <DOM/ISlidesPicture.h>

#include <DOM/Chart/IChartSeriesGroupCollection.h>
#include <DOM/Chart/IChartSeriesGroup.h>
#include <DOM/Chart/IChartTextFormat.h>
#include <DOM/Chart/IChartTextBlockFormat.h>

#include <DOM/ITextFrame.h>
#include <DOM/IParagraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraphFormat.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/IFontData.h>

#include <DOM/Animation/AnimationTimeLine.h>
#include <DOM/Animation/ISequence.h>
#include <drawing/imaging/image_format.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void SetMarkerOptionsonSeries()
{
	//ExStart:SetMarkerOptionsonSeries

	// The path to the documents directory.
	const String outPath = u"../out/SetMarkerOptionsonSeries_out.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";
	const String ImagePath2 = u"../templates/aspose - logo.jpg";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::LineWithMarkers, 0, 0, 500, 500);

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();

	// Delete default generated series and categories
	chart->get_ChartData()->get_Series()->Clear();

	// Now, Adding a new series
	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(fact->GetCell(defaultWorksheetIndex, 1, 1, ObjectExt::Box<System::String>(u"Series 1")), chart->get_Type());

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
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetMarkerOptionsonSeries
}
