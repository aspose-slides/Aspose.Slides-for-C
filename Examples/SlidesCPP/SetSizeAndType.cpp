#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetSizeAndType()
{
	//ExStart:SetSizeAndType
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/SetSizeAndType_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>(templatePath);
	SharedPtr<Presentation> auxPresentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);

	// Set the slide size of generated presentations to that of source
	auxPresentation->get_SlideSize()->SetSize(presentation->get_SlideSize()->get_Type(), SlideSizeScaleType::EnsureFit);

	auxPresentation->get_Slides()->InsertClone(0, slide);
	auxPresentation->get_Slides()->RemoveAt(0);

	presentation->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetSizeAndType
}
