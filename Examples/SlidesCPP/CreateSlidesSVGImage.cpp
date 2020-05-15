#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void CreateSlidesSVGImage()
{
	//ExStart:CreateSlidesSVGImage

	// The path to the documents directory.
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String outPath = u"../out/Aspose_out.svg";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Create a memory stream object
	SharedPtr<MemoryStream> SvgStream = MakeObject<MemoryStream>();

	// Generate SVG image of slide and save in memory stream
	slide->WriteAsSvg(SvgStream);
	SvgStream->set_Position(0);

	// Save memory stream to file
	try
	{
		SharedPtr<Stream> fileStream = File::OpenWrite(outPath);

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

	//ExEnd:CreateSlidesSVGImage
}
