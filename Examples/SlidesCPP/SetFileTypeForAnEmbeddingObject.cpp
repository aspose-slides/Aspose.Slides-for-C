#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetFileTypeForAnEmbeddingObject()
{
	//ExStart:SetFileTypeForAnEmbeddingObject
	// The path to the documents directory.	
	const String templatePath = u"../templates/test.zip";
	const String outPath = u"../out/SetFileTypeForAnEmbeddingObject.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	// Add known Ole objects
	ArrayPtr<uint8_t> fileBytes = IO::File::ReadAllBytes(templatePath);

	// Create Ole embedded file info
	SharedPtr<IOleEmbeddedDataInfo> dataInfo = System::MakeObject<DOM::Ole::OleEmbeddedDataInfo>(fileBytes, u"zip");

	// Create OLE object
	SharedPtr<IOleObjectFrame> oleFrame = pres->get_Slides()->idx_get(0)->get_Shapes()->AddOleObjectFrame(150.0f, 20.0f, 50.0f, 50.0f, dataInfo);
	oleFrame->set_IsObjectIcon(true);
    
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:SetFileTypeForAnEmbeddingObject
}
