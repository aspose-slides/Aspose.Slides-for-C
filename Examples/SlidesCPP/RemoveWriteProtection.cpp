#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void RemoveWriteProtection()
{
	//ExStart:RemoveWriteProtection

	const String outPath = u"../out/RemoveWriteProtection_out.ppt";
	const String templatePath = u"../templates/RemoveWriteProtection.pptx";
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	if (pres->get_ProtectionManager()->get_IsWriteProtected()) {

		pres->get_ProtectionManager()->RemoveWriteProtection();
	}
	pres->Save(outPath, SaveFormat::Pptx);
	
	//ExEnd:RemoveWriteProtection
}