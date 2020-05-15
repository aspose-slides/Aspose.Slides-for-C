#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AccessOLEObjectFrame()
{
    // ExStart:AccessOLEObjectFrame
	// The path to the documents directory.
	const String outPath = u"../out/excelFromOLE_out.xlsx";
	const String templatePath = u"../templates/AccessingOLEObjectFrame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Cast the shape to OleObjectFrame
	SharedPtr<OleObjectFrame> oof = DynamicCast<OleObjectFrame>(slide->get_Shapes()->idx_get(0));

	// Read the OLE Object and write it to disk
	if (oof != nullptr)
	{
		ArrayPtr<uint8_t> buffer = oof->get_ObjectData();
		{
			SharedPtr<IO::FileStream> stream = System::MakeObject<IO::FileStream>(outPath, IO::FileMode::Create, IO::FileAccess::Write, IO::FileShare::Read);

			stream->Flush();
			stream->Close();
		}
	}
	//ExEnd:AccessOLEObjectFrame
}
