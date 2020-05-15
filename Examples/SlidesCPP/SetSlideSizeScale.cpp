#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetSlideSizeScale()
{
	//ExStart:SetSlideSizeScale
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessSlides.pptx";
	const String outPath = u"../out/SetSlideSizeScale_out.pptx";

	SharedPtr<Presentation> presentation = MakeObject<Presentation>(templatePath);
	SharedPtr<Presentation> auxPresentation = MakeObject<Presentation>();

	// Instantiate SlideCollection calss
	SharedPtr<ISlide> slide = presentation->get_Slides()->idx_get(0);

	// Set the slide size of generated presentations to that of source
	auxPresentation->get_SlideSize()->SetSize(540, 720, SlideSizeScaleType::EnsureFit); // Method SetSize is used for set slide size with scale content to ensure fit
	auxPresentation->get_SlideSize()->SetSize(SlideSizeType::A4Paper, SlideSizeScaleType::Maximize); // Method SetSize is used for set slide size with maximize size of content

	auxPresentation->get_Slides()->InsertClone(0, slide);
	auxPresentation->get_Slides()->RemoveAt(0);

	presentation->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetSlideSizeScale
}
