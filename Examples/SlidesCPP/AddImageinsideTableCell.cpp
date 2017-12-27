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
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/Table/ITable.h>
#include <DOM/Table/ICell.h>

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

void AddImageinsideTableCell()
{

	// ExStart:AddImageinsideTableCell
	// The path to the documents directory.
	const String outPath = L"../out/Image_In_TableCell_out.pptx";
	const String ImagePath = L"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	System::ArrayPtr<double> dblCols= System::MakeObject<System::Array<double>>(4,150 );
	System::ArrayPtr<double> dblRows = System::MakeObject<System::Array<double>>(4,100 );
	System::ArrayPtr<double> total_for_Cat = System::MakeObject<System::Array<double>>(5, 0);

	// Add table shape to slide
	auto tbl = islide->get_Shapes()->AddTable(50, 50, dblCols, dblRows);

	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);


	// Add image to first table cell
	tbl->idx_get(0,0)->get_FillFormat()->set_FillType (FillType::Picture);
	tbl->idx_get(0,0)->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode ( PictureFillMode::Stretch);
	tbl->idx_get(0,0)->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:AddImageinsideTableCell
}
