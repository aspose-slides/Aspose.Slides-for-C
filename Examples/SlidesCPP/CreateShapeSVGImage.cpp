#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CreateShapeSVGImage()
{
	// ExStart:CreateShapeSVGImage

	// The path to the documents directory.
	const String outPath = u"../out/CreateShapeSVGImage_out.svg";
	const String templatePath = u"../templates/HelloWorld.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Create a memory stream object
	SharedPtr<IO::MemoryStream> SvgStream = MakeObject<IO::MemoryStream>();

	// Generate SVG image of slide shape at index 0 and save in memory stream
	slide->get_Shapes()->idx_get(0)->WriteAsSvg(SvgStream);
	SvgStream->set_Position(0);

	// Save memory stream to file
	try
	{
		SharedPtr<IO::Stream> fileStream = IO::File::OpenWrite(outPath);

		ArrayPtr<uint8_t> buffer = System::MakeObject<Array<uint8_t>>(8 * 1024, 0);
		int32_t len;
		while ((len = SvgStream->Read(buffer, 0, buffer->get_Length())) > 0)
		{
			fileStream->Write(buffer, 0, len);
		}
	}
	catch (Exception e)
	{

	}
	SvgStream->Close();

	//ExEnd:CreateShapeSVGImage

}
