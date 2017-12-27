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
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>


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

void VerticallyAlignText()
{

	// ExStart:VerticallyAlignText
	// The path to the documents directory.
	const String outPath = L"../out/VerticallyAlignText_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	System::ArrayPtr<double> dblCols = System::MakeObject<System::Array<double>>(4, 70);
	System::ArrayPtr<double> dblRows = System::MakeObject<System::Array<double>>(4, 70);

	// Add table shape to slide
	SharedPtr<ITable> table = islide->get_Shapes()->AddTable(100, 50, dblCols, dblRows);

	// Set the text of the first column of second row
	table->idx_get(1, 0)->get_TextFrame()->set_Text(L"10");
	table->idx_get(2, 0)->get_TextFrame()->set_Text(L"20");
	table->idx_get(3, 0)->get_TextFrame()->set_Text(L"30");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = table->idx_get(0, 0)->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(L"Text here");
	portion->get_PortionFormat()->get_FillFormat()->set_FillType(FillType::Solid);
	portion->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(Color::get_Black());

	// Aligning the text vertically
	SharedPtr<ICell> cell = table->idx_get(0, 0);
	cell->set_TextAnchorType(TextAnchorType::Center);
	cell->set_TextVerticalType ( TextVerticalType::Vertical270);


	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:VerticallyAlignText
}
