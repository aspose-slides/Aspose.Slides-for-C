#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void AddPlainLineToSlide()
{
	// ExStart:AddPlainLineToSlide
	// The path to the documents directory.
	const String outPath = u"../out/AddPlainLineToSlide_out.pptx";
	const String templatePath = u"../templates/AltText.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add an autoshape of type line
	SharedPtr<IAutoShape> shape = slide->get_Shapes()->AddAutoShape(ShapeType::Line, 50, 150, 300, 0);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddPlainLineToSlide
}
