#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Charts;

using namespace System;

void ChartEntities()
{
	//ExStart:ChartEntities

	// The path to the documents directory.
	const String outPath = u"../out/FormatChart_out.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	SharedPtr<IChart> chart = slide->get_Shapes()->AddChart(ChartType::LineWithMarkers, 0, 0, 500, 500);

	// Setting Chart Titile
	chart->set_HasTitle(true);
	chart->get_ChartTitle()->AddTextFrameForOverriding(u"");
	SharedPtr<IPortion> chartTitle = chart->get_ChartTitle()->get_TextFrameForOverriding()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0);
	chartTitle->set_Text(u"Sample Chart");
	chartTitle->get_PortionFormat()->get_FillFormat()->set_FillType  (FillType::Solid);
	chartTitle->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color (System::Drawing::Color::get_Gray());
	chartTitle->get_PortionFormat()->set_FontHeight ( 20);
	chartTitle->get_PortionFormat()->set_FontBold ( NullableBool::True);
	chartTitle->get_PortionFormat()->set_FontItalic ( NullableBool::True);

	// Setting Major grid lines format for value axis
	chart->get_Axes()->get_VerticalAxis()->get_MajorGridLinesFormat()->get_Line()->get_FillFormat()->set_FillType (FillType::Solid);
	chart->get_Axes()->get_VerticalAxis()->get_MajorGridLinesFormat()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Blue());
	chart->get_Axes()->get_VerticalAxis()->get_MajorGridLinesFormat()->get_Line()->set_Width ( 5);
	chart->get_Axes()->get_VerticalAxis()->get_MajorGridLinesFormat()->get_Line()->set_DashStyle (LineDashStyle::DashDot);

	// Setting Minor grid lines format for value axis
	chart->get_Axes()->get_VerticalAxis()->get_MinorGridLinesFormat()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
	chart->get_Axes()->get_VerticalAxis()->get_MinorGridLinesFormat()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());
	chart->get_Axes()->get_VerticalAxis()->get_MinorGridLinesFormat()->get_Line()->set_Width(3);

	// Setting value axis number format
	chart->get_Axes()->get_VerticalAxis()->set_IsNumberFormatLinkedToSource ( false);
	chart->get_Axes()->get_VerticalAxis()->set_DisplayUnit ( DisplayUnitType::Thousands);
	chart->get_Axes()->get_VerticalAxis()->set_NumberFormat(u"0.0%");

	// Setting chart maximum, minimum values
	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMajorUnit(false);
	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMaxValue(false);
	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMinorUnit(false);
	chart->get_Axes()->get_VerticalAxis()->set_IsAutomaticMinValue(false);

	chart->get_Axes()->get_VerticalAxis()->set_MaxValue (15);
	chart->get_Axes()->get_VerticalAxis()->set_MinValue ( -2);
	chart->get_Axes()->get_VerticalAxis()->set_MinorUnit ( 0.5);
	chart->get_Axes()->get_VerticalAxis()->set_MajorUnit ( 2.0);

	// Setting Value Axis Text Properties
	SharedPtr<IChartPortionFormat> txtVal = chart->get_Axes()->get_VerticalAxis()->get_TextFormat()->get_PortionFormat();
	txtVal->set_FontBold ( NullableBool::True);
	txtVal->set_FontHeight( 16);
	txtVal->set_FontItalic ( NullableBool::True);
	txtVal->get_FillFormat()->set_FillType ( FillType::Solid) ;
	txtVal->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing:: Color::get_DarkGreen());
	SharedPtr<FontData> fontData = MakeObject<FontData>(u"Times New Roman");

	//FontDataFactory.CreateFontData	//txtVal->set_LatinFont(MakeObject<IFontData>(u"Times New Roman"));
	txtVal->set_LatinFont(fontData);

	// Setting value axis title
	chart->get_Axes()->get_VerticalAxis()->set_HasTitle(true);
	chart->get_Axes()->get_VerticalAxis()->get_Title()->AddTextFrameForOverriding(u"");
	SharedPtr<IPortion> valtitle = chart->get_Axes()->get_VerticalAxis()->get_Title()->get_TextFrameForOverriding()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0);
	valtitle->set_Text(u"Primary Axis");
	valtitle->get_PortionFormat()->get_FillFormat()->set_FillType( FillType::Solid);
	valtitle->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Gray());
	valtitle->get_PortionFormat()->set_FontHeight ( 20);
	valtitle->get_PortionFormat()->set_FontBold (NullableBool::True);
	valtitle->get_PortionFormat()->set_FontItalic ( NullableBool::True);

	
	// Setting Major grid lines format for Category axis
	chart->get_Axes()->get_HorizontalAxis()->get_MajorGridLinesFormat()->get_Line()->get_FillFormat()->set_FillType ( FillType::Solid);
	chart->get_Axes()->get_HorizontalAxis()->get_MajorGridLinesFormat()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Green());
	chart->get_Axes()->get_HorizontalAxis()->get_MajorGridLinesFormat()->get_Line()->set_Width( 5);

	// Setting Minor grid lines format for Category axis
	chart->get_Axes()->get_HorizontalAxis()->get_MinorGridLinesFormat()->get_Line()->get_FillFormat()->set_FillType(FillType::Solid);
	chart->get_Axes()->get_HorizontalAxis()->get_MinorGridLinesFormat()->get_Line()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Yellow());
	chart->get_Axes()->get_HorizontalAxis()->get_MinorGridLinesFormat()->get_Line()->set_Width(3);

	// Setting Category Axis Text Properties
	SharedPtr<IChartPortionFormat> txtCat = chart->get_Axes()->get_HorizontalAxis()->get_TextFormat()->get_PortionFormat();
	txtCat->set_FontBold (NullableBool::True);
	txtCat->set_FontHeight ( 16);
	txtCat->set_FontItalic ( NullableBool::True);
	txtCat->get_FillFormat()->set_FillType( FillType::Solid) ;
	txtCat->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Blue());
	SharedPtr<FontData> Arial = MakeObject<FontData>(u"Arial");

	txtCat->set_LatinFont(Arial);

	// Setting Category Titile
	chart->get_Axes()->get_HorizontalAxis()->set_HasTitle ( true);
	chart->get_Axes()->get_HorizontalAxis()->get_Title()->AddTextFrameForOverriding(u"");

	SharedPtr<IPortion> catTitle = chart->get_Axes()->get_HorizontalAxis()->get_Title()->get_TextFrameForOverriding()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0);
	catTitle->set_Text(u"Sample Category");
	catTitle->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	catTitle->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Gray());
	catTitle->get_PortionFormat()->set_FontHeight( 20);
	catTitle->get_PortionFormat()->set_FontBold (NullableBool::True);
	catTitle->get_PortionFormat()->set_FontItalic ( NullableBool::True);

	// Setting category axis lable position
	chart->get_Axes()->get_HorizontalAxis()->set_TickLabelPosition( TickLabelPositionType::Low);

	// Setting category axis lable rotation angle
	chart->get_Axes()->get_HorizontalAxis()->set_TickLabelRotationAngle ( 45);

	// Setting Legends Text Properties
	SharedPtr<IChartPortionFormat> txtleg = chart->get_Legend()->get_TextFormat()->get_PortionFormat();
	txtleg->set_FontBold ( NullableBool::True);
	txtleg->set_FontHeight ( 16);
	txtleg->set_FontItalic (NullableBool::True);
	txtleg->get_FillFormat()->set_FillType (FillType::Solid) ;
	txtleg->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_DarkRed());

	// Set show chart legends without overlapping chart

	chart->get_Legend()->set_Overlay( true);

	// Ploting first series on secondary value axis
	// Chart.ChartData.Series[0].PlotOnSecondAxis = true;

	// Setting chart back wall color
	chart->get_BackWall()->set_Thickness( 1);
	chart->get_BackWall()->get_Format()->get_Fill()->set_FillType( FillType::Solid);
	chart->get_BackWall()->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Orange());

	chart->get_Floor()->get_Format()->get_Fill()->set_FillType(FillType::Solid);
	chart->get_Floor()->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Red());
	// Setting Plot area color
	chart->get_PlotArea()->get_Format()->get_Fill()->set_FillType(FillType::Solid);
	chart->get_PlotArea()->get_Format()->get_Fill()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_LightCyan());

	// Write the presentation file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ChartEntities
}
