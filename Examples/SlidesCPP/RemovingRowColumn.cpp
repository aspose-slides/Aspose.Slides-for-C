#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/Table/ITable.h>
#include <DOM/Table/ICell.h>
#include <DOM/Table/ICellCollection.h>
#include <DOM/Table/IRow.h>
#include <DOM/Table/IRowCollection.h>
#include <DOM/Table/IColumn.h>
#include <DOM/Table/IColumnCollection.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

const int NodesCount = 5;

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
	System::ArrayPtr<double> dblCols = System::MakeObject<System::Array<double>>(4, 70);
	System::ArrayPtr<double> dblRows = System::MakeObject<System::Array<double>>(4, 70);

	// Add table shape to slide
	SharedPtr<ITable> table = islide->get_Shapes()->AddTable(100, 50, dblCols, dblRows);

	table->get_Rows()->RemoveAt(1, false);
	table->get_Columns()->RemoveAt(1, false);


	// Merging cells (1, 1) x (2, 1)
	table->MergeCells(table->idx_get(1, 1), table->idx_get(2, 1), false);

	// Merging cells (1, 2) x (2, 2)
	table->MergeCells(table->idx_get(1, 2), table->idx_get(2, 2), false);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:RemovingRowColumn
}
