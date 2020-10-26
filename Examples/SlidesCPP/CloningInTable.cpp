#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void CloningInTable()
{
	// ExStart:CloningInTable
	// The path to the documents directory.
	const String outPath = u"../out/CloningInTable_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	ArrayPtr<double> dblCols = System::MakeObject<Array<double>>(4, 70);
	ArrayPtr<double> dblRows = System::MakeObject<Array<double>>(4, 70);

	// Add table shape to slide
	SharedPtr<ITable> table = islide->get_Shapes()->AddTable(100, 50, dblCols, dblRows);

	// Set border format for each cell
	for (int x = 0; x < table->get_Rows()->get_Count(); x++)
	{
		SharedPtr<IRow> row = table->get_Rows()->idx_get(x);
		for (int y = 0; y < row->get_Count(); y++)
		{
			SharedPtr<ICell> cell = row->idx_get(y);

			cell->get_CellFormat()->get_BorderTop()->get_FillFormat()->set_FillType(FillType::Solid);
			cell->get_CellFormat()->get_BorderTop()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());
			cell->get_CellFormat()->get_BorderTop()->set_Width(5);

			cell->get_CellFormat()->get_BorderBottom()->get_FillFormat()->set_FillType(FillType::Solid);
			cell->get_CellFormat()->get_BorderBottom()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());
			cell->get_CellFormat()->get_BorderBottom()->set_Width(5);

			cell->get_CellFormat()->get_BorderLeft()->get_FillFormat()->set_FillType(FillType::Solid);
			cell->get_CellFormat()->get_BorderLeft()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());
			cell->get_CellFormat()->get_BorderLeft()->set_Width(5);

			cell->get_CellFormat()->get_BorderRight()->get_FillFormat()->set_FillType(FillType::Solid);
			cell->get_CellFormat()->get_BorderRight()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Red());
			cell->get_CellFormat()->get_BorderRight()->set_Width(5);
		}
	}

	table->idx_get(0, 0)->get_TextFrame()->set_Text(u"00");
	table->idx_get(0, 1)->get_TextFrame()->set_Text(u"01");
	table->idx_get(0, 2)->get_TextFrame()->set_Text(u"02");
	table->idx_get(0, 3)->get_TextFrame()->set_Text(u"03");
	table->idx_get(1, 0)->get_TextFrame()->set_Text(u"10");
	table->idx_get(2, 0)->get_TextFrame()->set_Text(u"20");
	table->idx_get(1, 1)->get_TextFrame()->set_Text(u"11");
	table->idx_get(2, 1)->get_TextFrame()->set_Text(u"21");

	//AddClone adds a row in the end of the table
	table->get_Rows()->AddClone(table->get_Rows()->idx_get(0), false);

	//InsertClone adds a row at specific position in a table
	table->get_Rows()->InsertClone(2, table->get_Rows()->idx_get(0), false);

	//AddClone adds a column in the end of the table
	table->get_Columns()->AddClone(table->get_Columns()->idx_get(0), false);

	//InsertClone adds a column at specific position in a table
	table->get_Columns()->InsertClone(2, table->get_Columns()->idx_get(0), false);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:CloningInTable
}
