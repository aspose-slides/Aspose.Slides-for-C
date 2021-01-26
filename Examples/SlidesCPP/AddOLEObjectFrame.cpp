#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace DOM::Ole;
using namespace System;
using namespace System::Drawing;

void AddOLEObjectFrame()
{
	// ExStart:AddOLEObjectFrame
	// The path to the documents directory.
	const String outPath = u"../out/AddOLEObjectFrame_out.pptx";
	const String filePath = u"../templates/book1.xlsx";

    // Instantiate Prseetation class that represents the PPTX
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Access the first slide
    SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

    // Load an cel file to stream
    SharedPtr<MemoryStream> mstream = System::MakeObject<MemoryStream>();
    
    SharedPtr<FileStream> fs = System::MakeObject<FileStream>(filePath, FileMode::Open, FileAccess::Read);

    ArrayPtr<uint8_t> buf = System::MakeArray<uint8_t>(4096, 0);

    while (true)
    {
        int32_t bytesRead = fs->Read(buf, 0, buf->get_Length());
        if (bytesRead <= 0)
        {
            break;
        }
        mstream->Write(buf, 0, bytesRead);
    }
            
    // Create data object for embedding
    SharedPtr<IOleEmbeddedDataInfo> dataInfo = System::MakeObject<OleEmbeddedDataInfo>(mstream->ToArray(), u"xlsx");

    SizeF slideSize = pres->get_SlideSize()->get_Size();
    // Add an Ole Object Frame shape
    SharedPtr<IOleObjectFrame> oleObjectFrame = sld->get_Shapes()->AddOleObjectFrame(0.0f, 0.0f, slideSize.get_Width(), slideSize.get_Height(), dataInfo);

    //Write the PPTX to disk
    pres->Save(outPath, Export::SaveFormat::Pptx);

    //ExEnd:AddOLEObjectFrame
}
