#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemovingRowColumn()
{
	// ExStart:RemovingRowColumn
	// The path to the documents directory.
	const String outPath = u"../out/RemovingRowColumn_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	ArrayPtr<double> dblCols = System::MakeObject<Array<double>>(4, 70);
	ArrayPtr<double> dblRows = System::MakeObject<Array<double>>(4, 70);

	// Add table shape to slide
	SharedPtr<ITable> table = islide->get_Shapes()->AddTable(100, 50, dblCols, dblRows);

	table->get_Rows()->RemoveAt(1, false);
	table->get_Columns()->RemoveAt(1, false);

	// Merging cells (1, 1) x (2, 1)
	table->MergeCells(table->idx_get(1, 1), table->idx_get(2, 1), false);

	// Merging cells (1, 2) x (2, 2)
	table->MergeCells(table->idx_get(1, 2), table->idx_get(2, 2), false);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:RemovingRowColumn
}
