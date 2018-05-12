#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <DOM/SlideSize.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/io/memory_stream.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <cstdint>


#include <system/string.h>
#include <system/IO/file.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::IO;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;

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
	SharedPtr<System::IO::MemoryStream> SvgStream = MakeObject<System::IO::MemoryStream>();

	// Generate SVG image of slide and save in memory stream
	slide->WriteAsSvg(SvgStream);
	SvgStream->set_Position(0);

	// Save memory stream to file
	try
	{
		System::SharedPtr<System::IO::Stream> fileStream = System::IO::File::OpenWrite(outPath);

		System::ArrayPtr<uint8_t> buffer = System::MakeObject<System::Array<uint8_t>>(8 * 1024, 0);
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

