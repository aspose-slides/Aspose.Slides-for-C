#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IOleEmbeddedDataInfo.h>
#include <DOM/OleObjectFrame.h>

#include <Export/SaveFormat.h>

#include <system/string.h>
#include <system/console.h>
#include <system/io/file.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetFileTypeForAnEmbeddingObject() {

	//ExStart:SetFileTypeForAnEmbeddingObject
	// The path to the documents directory.	
	const String templatePath = u"../templates/test.zip";
	const String outPath = u"../out/SetFileTypeForAnEmbeddingObject.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	// Add known Ole objects
	System::ArrayPtr<uint8_t> fileBytes = System::IO::File::ReadAllBytes(templatePath);

	// Create Ole embedded file info
	System::SharedPtr<IOleEmbeddedDataInfo> dataInfo = System::MakeObject<IOleEmbeddedDataInfo>(fileBytes, u"zip");

	// Create OLE object
	System::SharedPtr<IOleObjectFrame> oleFrame = pres->get_Slides()->idx_get(0)->get_Shapes()->AddOleObjectFrame(150.0f, 20.0f, 50.0f, 50.0f, dataInfo);
	oleFrame->set_IsObjectIcon(true);


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:SetFileTypeForAnEmbeddingObject

}
