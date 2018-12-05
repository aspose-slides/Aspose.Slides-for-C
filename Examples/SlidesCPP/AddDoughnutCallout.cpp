
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
#include <DOM/ILineFillFormat.h>
#include <DOM/IFillFormat.h>
#include <DOM/FillType.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/Chart/ITrendline.h>
#include <DOM/Chart/TrendlineType.h>
#include <DOM/Chart/IRotation3D.h>
#include <DOM/LineStyle.h>
#include <DOM/LineDashStyle.h>
#include <DOM/TextAutofitType.h>
#include <DOM/Fonts/FontData.h>

#include <DOM/Chart/IChartSeriesGroupCollection.h>
#include <DOM/Chart/IChartSeriesGroup.h>

#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/IChartDataPoint.h>
#include <DOM/Chart/IFormat.h>
#include <DOM/Chart/IUpDownBarsManager.h>
#include <DOM/Chart/IChartLinesFormat.h>
#include <DOM/Chart/IChartTextFormat.h>
#include <DOM/Chart/IChartTextBlockFormat.h>
#include <DOM/Chart/IChartPortionFormat.h>

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
#include <drawing/color.h>
#include <Export/SaveFormat.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;

using namespace System;

void AddDoughnutCallout()
{
	//ExStart:AddDoughnutCallout

	// The path to the documents directory.
	const String outPath = u"../out/AddDoughnutCallout_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Doughnut, 0, 0, 500, 500);

	int seriesIndex = 0;

	// Setting the index of chart data sheet
	int defaultWorksheetIndex = 0;

	// Getting the chart data worksheet
	SharedPtr<IChartDataWorkbook> fact = chart->get_ChartData()->get_ChartDataWorkbook();


	// Delete default generated series and categories
	chart->get_ChartData()->get_Series()->Clear();
	chart->get_ChartData()->get_Categories()->Clear();
	chart->set_HasLegend(false);
	////////////

	while (seriesIndex < 15)
	{

		SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->Add(fact->GetCell(0, 0, seriesIndex + 1, ObjectExt::Box<System::String>(u"SERIES" + seriesIndex)), chart->get_Type());
		
		series->set_Explosion(0);
		series->get_ParentSeriesGroup()->set_DoughnutHoleSize (20);
		series->get_ParentSeriesGroup()->set_FirstSliceAngle ( 351);
		seriesIndex++;
	}
	int categoryIndex = 0;
	while (categoryIndex < 15)
	{
		chart->get_ChartData()->get_Categories()->Add(fact->GetCell(0, categoryIndex + 1, 0, ObjectExt::Box<System::String>(u"CATEGORY" + categoryIndex)));
		int i = 0;
		while (i < chart->get_ChartData()->get_Series()->get_Count())
		{
			SharedPtr<IChartSeries> iCS = chart->get_ChartData()->get_Series()->idx_get(i);
			SharedPtr<IChartDataPoint> dataPoint = iCS->get_DataPoints()->AddDataPointForDoughnutSeries(fact->GetCell(0, categoryIndex + 1, i + 1, ObjectExt::Box<double>(1)));
			dataPoint->get_Format()->get_Fill()->set_FillType (FillType::Solid);
			dataPoint->get_Format()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
			dataPoint->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_White());
			dataPoint->get_Format()->get_Line()->set_Width( 1);
			dataPoint->get_Format()->get_Line()->set_Style (LineStyle::Single);
			dataPoint->get_Format()->get_Line()->set_DashStyle(LineDashStyle::Solid);
			if (i == chart->get_ChartData()->get_Series()->get_Count() - 1)
			{
				SharedPtr<IDataLabel> lbl = dataPoint->get_Label();
				lbl->get_TextFormat()->get_TextBlockFormat()->set_AutofitType (TextAutofitType::Shape);
				lbl->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->set_FontBold (NullableBool::True);
				lbl->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->set_LatinFont(MakeObject<FontData>(u"DINPro-Bold"));

				lbl->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->set_FontHeight ( 12);
				lbl->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->set_FillType (FillType::Solid);
				lbl->get_DataLabelFormat()->get_TextFormat()->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color (System::Drawing::Color::get_LightGray());
				lbl->get_DataLabelFormat()->get_Format()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_White());
				lbl->get_DataLabelFormat()->set_ShowValue ( false);
				lbl->get_DataLabelFormat()->set_ShowCategoryName ( true);
				lbl->get_DataLabelFormat()->set_ShowSeriesName(false);
				//lbl.DataLabelFormat.ShowLabelAsDataCallout = true;
				lbl->get_DataLabelFormat()->set_ShowLeaderLines (true);
				lbl->get_DataLabelFormat()->set_ShowLabelAsDataCallout ( false);
				chart->ValidateChartLayout();
				lbl->set_X((float)lbl->get_X() + (float)0.5);
				lbl->set_Y((float)lbl->get_Y() + (float)0.5);
			}
			i++;
		}
		categoryIndex++;
	}

	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddDoughnutCallout
}
