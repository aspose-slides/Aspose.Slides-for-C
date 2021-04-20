#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;

void AccessOLEObjectFrame()
{
    // ExStart:AccessOLEObjectFrame
	// The path to the documents directory.
	const String templatePath = u"../templates/AccessingOLEObjectFrame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    // Access the first slide
    SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

    // Cast the shape to OleObjectFrame
    SharedPtr<OleObjectFrame> oleObjectFrame = System::DynamicCast_noexcept<OleObjectFrame>(sld->get_Shapes()->idx_get(0));

    // Read the OLE Object and write it to disk
    if (oleObjectFrame != nullptr)
    {
        // Get embedded file data
        ArrayPtr<uint8_t> data = oleObjectFrame->get_EmbeddedData()->get_EmbeddedFileData();

        // Get embedded file extention
        String fileExtention = oleObjectFrame->get_EmbeddedData()->get_EmbeddedFileExtension();

        // Create path for saving the extracted file
        String extractedPath = Path::Combine(GetOutPath(), u"excelFromOLE_out" + fileExtention);

        // Save extracted data
        SharedPtr<FileStream> fstr = System::MakeObject<FileStream>(extractedPath, FileMode::Create, FileAccess::Write);
        fstr->Write(data, 0, data->get_Length());
    }
    
	//ExEnd:AccessOLEObjectFrame
}
