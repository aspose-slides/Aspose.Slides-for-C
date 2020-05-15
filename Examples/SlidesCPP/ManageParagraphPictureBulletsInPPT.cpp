#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ManageParagraphPictureBulletsInPPT()
{
	// ExStart:ManageParagraphPictureBulletsInPPT
	// The path to the documents directory.
	const String outPath = u"../out/ManageParagraphPictureBulletsInPPT_out.pptx";
	const String templatePath = u"../templates/DefaultFonts.pptx";
	const String ImagePath = u"../templates/Tulips.jpg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = sld->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u"");

	// Accessing the text frame
	SharedPtr<ITextFrame>  txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(u"Welcome to Aspose.Slides");

	// Get the picture
	auto bitmap = MakeObject<Bitmap>(ImagePath);

	// Add image to presentation's images collection
	SharedPtr<IPPImage> ippxImage = pres->get_Images()->AddImage(bitmap);

	// Setting paragraph bullet style and image
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Type(BulletType::Picture);
	paragraph->get_ParagraphFormat()->get_Bullet()->get_Picture()->set_Image(ippxImage);

	// Setting Bullet Height
	paragraph->get_ParagraphFormat()->get_Bullet()->set_Height ( 100);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ManageParagraphPictureBulletsInPPT
}
