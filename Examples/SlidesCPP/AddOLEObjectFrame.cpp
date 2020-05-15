#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddOLEObjectFrame()
{
	// ExStart:AddOLEObjectFrame
	// The path to the documents directory.
	const String outPath = u"../out/AddOLEObjectFrame_out.pptx";
	const String filePath = u"../templates/book1.xlsx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Save file to memory stream 
	{
		SharedPtr<IO::Stream> fileStream = IO::File::OpenRead(filePath);
		SharedPtr<IO::MemoryStream> MemStream = MakeObject< IO::MemoryStream>();

		ArrayPtr<uint8_t> buffer = System::MakeObject<Array<uint8_t>>(4 * 1024, 0);
		int32_t len;
		while ((len = fileStream->Read(buffer, 0, buffer->get_Length())) > 0)
		{
			MemStream->Write(buffer, 0, len);
		}
		MemStream->set_Position(0);

		// Add an Ole Object Frame shape
		SharedPtr<IOleObjectFrame> oof = slide->get_Shapes()->AddOleObjectFrame(0, 0, 720, 540, u"Excel.Sheet.12", MemStream->ToArray());
	}

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddOLEObjectFrame
}
