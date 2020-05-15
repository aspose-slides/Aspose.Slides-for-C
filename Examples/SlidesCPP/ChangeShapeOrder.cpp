#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ChangeShapeOrder()
{
	// ExStart:ChangeShapeOrder
	// The path to the documents directory.
	const String outPath = u"../out/ChangeShapeOrder_out.pptx";
	const String templatePath = u"../templates/HelloWorld.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IAutoShape>  ashp = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 150, 75, 150, 50);

	ashp->get_FillFormat()->set_FillType(FillType::NoFill);

	// Add TextFrame to the Rectangle
	ashp->AddTextFrame(u" ");

	// Accessing the text frame
	SharedPtr<ITextFrame> txtFrame = ashp->get_TextFrame();

	// Create the Paragraph object for text frame
	SharedPtr<IParagraph> paragraph = txtFrame->get_Paragraphs()->idx_get(0);

	// Create Portion object for paragraph
	SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(0);
	portion->set_Text(u"Watermark Text Watermark Text Watermark Text");

	//Adding another shape
	SharedPtr<IAutoShape> ashape2 = slide->get_Shapes()->AddAutoShape(ShapeType::Triangle, 200, 365, 400, 150);

	//Reorder shape
	slide->get_Shapes()->Reorder(2, ashape2);

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ChangeShapeOrder
}
