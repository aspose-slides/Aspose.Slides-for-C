#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void StretchOffsetLeftForPictureFrame()
{
	// ExStart:StretchOffsetLeftForPictureFrame

	// The path tos the documents directory.
	const String outPath = u"../out/StretchOffsetLeftForPictureFrame_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 100, 300, 300);

	// Apply some picture formatting to rectangle shape
	autoShape->get_FillFormat()->set_FillType(FillType::Picture);
	
	// Set the picture fill mode
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_PictureFillMode(PictureFillMode::Stretch);

	// Get the picture
	auto bitmap = MakeObject<System::Drawing::Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(bitmap);

	//Set picture to shape
	autoShape->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(imgx);

	// Specify image offsets from the corresponding edge of the shape's bounding box
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetLeft(25);
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetRight(25);
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetTop(-20);
	autoShape->get_FillFormat()->get_PictureFillFormat()->set_StretchOffsetBottom(-10);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:StretchOffsetLeftForPictureFrame
}
