#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void InsertSvgIntoPresentation()
{
	// ExStart:InsertSvgIntoPresentation

	// The path to the documents directory.
	const String outPath = u"../out/InsertSvgIntoPresentation_out.pptx";
	const String filePath = u"../templates/sample.svg";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	auto svgContent = File::ReadAllText(filePath);

	SharedPtr<ISvgImage> svgImage = MakeObject<SvgImage>(svgContent);

	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(svgImage);

	//Adding picture frame with EMZ image	
	auto m = slide->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 0, 0, pres->get_SlideSize()->get_Size().get_Width(), pres->get_SlideSize()->get_Size().get_Height(), imgx);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:InsertSvgIntoPresentation

}

