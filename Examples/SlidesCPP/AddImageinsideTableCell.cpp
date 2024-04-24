#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void AddImageinsideTableCell()
{
    // ExStart:AddImageinsideTableCell
    // The path to the documents directory.
    const System::String outPath = Path::Combine(GetOutPath(), u"Image_In_TableCell_out.pptx");
    const System::String imagePath = Path::Combine(GetDataPath(), u"Tulips.jpg");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access first slide
    System::SharedPtr<ISlide> islide = pres->get_Slide(0);

    // Define columns with widths and rows with heights
    System::ArrayPtr<double> dblCols = System::MakeObject<System::Array<double>>(4, 150);
    System::ArrayPtr<double> dblRows = System::MakeObject<System::Array<double>>(4, 100);
    System::ArrayPtr<double> total_for_Cat = System::MakeObject<System::Array<double>>(5, 0);

    // Add table shape to slide
    auto tbl = islide->get_Shapes()->AddTable(50, 50, dblCols, dblRows);

    // Get the picture
    auto image = Images::FromFile(imagePath);

    // Add image to presentation's images collection
    System::SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(image);

    // Add image to first table cell
    tbl->idx_get(0, 0)->get_CellFormat()->get_FillFormat()->set_FillType(FillType::Picture);
    tbl->idx_get(0, 0)->get_CellFormat()->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(
        PictureFillMode::Stretch);
    tbl->idx_get(0, 0)->get_CellFormat()->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

    // Save PPTX to Disk
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:AddImageinsideTableCell
}
