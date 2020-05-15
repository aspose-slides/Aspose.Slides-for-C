#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void FillShapesPicture()
{
	// ExStart:FillShapesPicture

	// The path tos the documents directory.
	const String outPath = u"../out/FillShapesPicture_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 150, 75, 150);

	// Apply some picture formatting to rectangle shape
	autoShape->get_FillFormat()->set_FillType(FillType::Picture);
	// Set the picture fill mode
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Tile);

	// Get the picture
	auto bitmap = MakeObject<Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	//Set picture to shape
	autoShape->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:FillShapesPicture
}
