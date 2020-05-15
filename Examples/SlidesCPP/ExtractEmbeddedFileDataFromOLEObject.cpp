#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ExtractEmbeddedFileDataFromOLEObject()
{
	//ExStart:ExtractEmbeddedFileDataFromOLEObject

	const String templatePath = u"../templates/TestOlePresentation.pptx";
	
	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	SharedPtr<ISlide> slide;
	SharedPtr<IShape> shape;

	for (int slideCount = 0; slideCount < pres->get_Slides()->get_Count(); slideCount++)
    {
		slide = pres->get_Slides()->idx_get(slideCount);

		for (int count = 0; count < slide->get_Shapes()->get_Count(); count++)
        {
			shape = slide->get_Shapes()->idx_get(count);

			if (ObjectExt::Is<OleObjectFrame>(shape))
            {
				// Cast the shape to OleObjectFrame
				SharedPtr<OleObjectFrame> oof = DynamicCast<OleObjectFrame>(shape);

				ArrayPtr<uint8_t> buffer = oof->get_EmbeddedFileData();
				{
					String fileExtention = oof->get_EmbeddedFileExtension();				
					String extractedPath = u"../out/ExtractedObject_out" + fileExtention;

					SharedPtr<IO::FileStream> stream = System::MakeObject<IO::FileStream>(extractedPath, IO::FileMode::Create, IO::FileAccess::Write, IO::FileShare::Read);

					stream->Flush();
					stream->Close();
				}
			}
		}
	}

	//ExEnd:ExtractEmbeddedFileDataFromOLEObject
}
