#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Shape.h>
#include <DOM/IAutoShape.h>
#include <DOM/ISlide.h>
#include <DOM/OleObjectFrame.h>
#include <DOM/IOleObjectFrame.h>
#include <system/object.h>
#include <Export/SaveFormat.h>

#include <string>

#include <Export/SaveFormat.h>
#include <system/io/file.h>

#include "SlidesExamples.h"


using namespace Aspose::Slides;
using namespace System;

void ExtractEmbeddedFileDataFromOLEObject() {


	//ExStart:ExtractEmbeddedFileDataFromOLEObject

	const String templatePath = u"../templates/TestOlePresentation.pptx";
	

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	

	SharedPtr<ISlide> slide;
	SharedPtr<IShape> shape;

	for (int slideCount = 0; slideCount < pres->get_Slides()->get_Count(); slideCount++) {

		slide = pres->get_Slides()->idx_get(slideCount);

		for (int count = 0; count < slide->get_Shapes()->get_Count(); count++) {
		
			shape = slide->get_Shapes()->idx_get(count);

			if (System::ObjectExt::Is<OleObjectFrame>(shape)) {
			 
				
				// Cast the shape to OleObjectFrame
				SharedPtr<OleObjectFrame> oof = DynamicCast<Aspose::Slides::OleObjectFrame>(shape);

				System::ArrayPtr<uint8_t> buffer = oof->get_EmbeddedFileData();
				{
					String fileExtention = oof->get_EmbeddedFileExtension();				
					
					 String extractedPath = u"../out/ExtractedObject_out" + fileExtention;
					

					System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(extractedPath, System::IO::FileMode::Create, System::IO::FileAccess::Write, System::IO::FileShare::Read);

					

					stream->Flush();
					stream->Close();
				}
			}
		
		}
	}
	

	//ExEnd:ExtractEmbeddedFileDataFromOLEObject
}