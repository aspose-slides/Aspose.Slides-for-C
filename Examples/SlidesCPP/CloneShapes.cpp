#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CloneShapes()
{
	// ExStart:CloneShapes

	// The path to the documents directory.
	const String outPath = u"../out/CloneShapes_out.pptx";
	const String templatePath = u"../templates/Source Frame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> sourceShapes = slide->get_Shapes();

	SharedPtr<ILayoutSlide> blankLayout = pres->get_Masters()->idx_get(0)->get_LayoutSlides()->GetByType(SlideLayoutType::Blank);
	SharedPtr<ISlide> destSlide = pres->get_Slides()->AddEmptySlide(blankLayout);
	SharedPtr<IShapeCollection> destShapes = destSlide->get_Shapes();
	destShapes->AddClone(sourceShapes->idx_get(1), 50, 150 + sourceShapes->idx_get(0)->get_Height());
	destShapes->AddClone(sourceShapes->idx_get(2));
	destShapes->InsertClone(0, sourceShapes->idx_get(0), 50, 150);

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:CloneShapes
}
