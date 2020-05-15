#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void TableWithCellBorders()
{
	// ExStart:TableFromScratch
	// The path to the documents directory.
	const String outPath = u"../out/TableWithCellBorders_out.pptx";

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

			cell->get_BorderTop()->get_FillFormat()->set_FillType(FillType::NoFill);
			cell->get_BorderBottom()->get_FillFormat()->set_FillType(FillType::NoFill);
			cell->get_BorderLeft()->get_FillFormat()->set_FillType(FillType::NoFill);
			cell->get_BorderRight()->get_FillFormat()->set_FillType(FillType::NoFill);
		}
	}

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:TableWithCellBorders
}
