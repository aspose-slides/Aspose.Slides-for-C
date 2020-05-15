#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddImageinsideTableCell()
{
	// ExStart:AddImageinsideTableCell
	// The path to the documents directory.
	const String outPath = u"../out/Image_In_TableCell_out.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Define columns with widths and rows with heights
	ArrayPtr<double> dblCols = System::MakeObject<Array<double>>(4,150 );
	ArrayPtr<double> dblRows = System::MakeObject<Array<double>>(4,100 );
	ArrayPtr<double> total_for_Cat = System::MakeObject<Array<double>>(5, 0);

	// Add table shape to slide
	auto tbl = islide->get_Shapes()->AddTable(50, 50, dblCols, dblRows);

	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	// Add image to first table cell
	tbl->idx_get(0,0)->get_FillFormat()->set_FillType(FillType::Picture);
	tbl->idx_get(0,0)->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode ( PictureFillMode::Stretch);
	tbl->idx_get(0,0)->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:AddImageinsideTableCell
}
