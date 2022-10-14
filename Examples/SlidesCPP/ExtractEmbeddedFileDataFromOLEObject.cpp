#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ExtractEmbeddedFileDataFromOLEObject()
{
	//ExStart:ExtractEmbeddedFileDataFromOLEObject
    String OutDir = GetOutPath();
    String pptxFileName = u"../templates/TestOlePresentation.pptx";
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);

    int32_t objectnum = 0;
    for (auto sld : IterateOver(pres->get_Slides()))
    {
        for (auto shape : IterateOver(sld->get_Shapes()))
        {
            if (ObjectExt::Is<OleObjectFrame>(shape))
            {
                objectnum++;
                SharedPtr<OleObjectFrame> oleFrame = System::AsCast<OleObjectFrame>(shape);
                ArrayPtr<uint8_t> data = oleFrame->get_EmbeddedData()->get_EmbeddedFileData();
                String fileExtention = oleFrame->get_EmbeddedData()->get_EmbeddedFileExtension();

                String extractedPath = OutDir + u"ExtractedObject_out" + objectnum + fileExtention;
                SharedPtr<IO::FileStream> fs = System::MakeObject<IO::FileStream>(extractedPath, IO::FileMode::Create);
                   
                fs->Write(data, 0, data->get_Length());
            }
        }
    }

	//ExEnd:ExtractEmbeddedFileDataFromOLEObject
}
