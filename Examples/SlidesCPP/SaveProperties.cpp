#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SaveProperties()
{
	//ExStart:SaveProperties

	const String outPath = u"../out/SaveProperties_out.pptx";
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	pres->get_ProtectionManager()->set_EncryptDocumentProperties(false);
	pres->get_ProtectionManager()->Encrypt(u"pass");
	
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SaveProperties
}
