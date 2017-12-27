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

void TableWithCellBorders()
{

	// ExStart:TableFromScratch
	// The path to the documents directory.
	const String outPath = L"../out/TableWithCellBorders_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	System::ArrayPtr<double> dblCols = System::MakeObject<System::Array<double>>(4, 70);
	System::ArrayPtr<double> dblRows = System::MakeObject<System::Array<double>>(4, 70);

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
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:TableWithCellBorders
}
