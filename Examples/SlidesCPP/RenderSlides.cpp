#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/INotesSlide.h>
#include <DOM/SlideSize.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>



using namespace Aspose::Slides;

using namespace System;
using namespace System::IO;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;

void RenderSlides()
{
	//ExStart:RenderSlides

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
	SvgStream->set_Position ( 0);

	// Save memory stream to file
	try
	{
		auto fs = File::OpenWrite(outPath);

		//ArrayPtr<byte> buffer;// = ArrayPtr<byte>();
		//ArrayPtr<byte> buffer=  ArrayPtr<byte>();
		
//		int len;
	//	len = SvgStream->Read(buffer, 0, buffer->Count());
	///	while ((len = SvgStream->Read(buffer, 0, SvgStream->get_Capacity())) > 0)
		{
		//	fs->Write(buffer, 0, len);
			fs->Write(SvgStream->GetBuffer(), 0, SvgStream->get_Length());
		}
	}
	catch (Exception e)
	{
	}
	SvgStream->Close();
	//ExEnd:RenderSlides
}




